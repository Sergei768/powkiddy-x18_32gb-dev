#!/usr/bin/env bash
set -Eeuo pipefail

DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd -P)"

LK_IMG="$DIR/lk.img"
MTKSU="$DIR/mtk-su"
BACKUPS="$DIR/backups"

LK_SHA="96edcbf3e6ce8034bcfa688100331935401cb9ee7349376f5292948839ae6d62"
LK_SIZE=393216

RMTK="/data/local/tmp/x18-mtksu"
RIMG="/data/local/tmp/x18-lk.img"
RBEFORE="/data/local/tmp/x18-lk-before.img"
RAFTER="/data/local/tmp/x18-lk-after.img"
RRESTORE="/data/local/tmp/x18-lk-restore.img"

die() {
    echo "ERROR: $*" >&2
    exit 1
}

sha() {
    sha256sum "$1" | awk '{print $1}'
}

cleanup() {
    adb shell \
        "rm -f '$RMTK' '$RIMG' '$RBEFORE' '$RAFTER' '$RRESTORE'" \
        >/dev/null 2>&1 || true
}

trap cleanup EXIT

for cmd in adb sha256sum awk wc tr grep date; do
    command -v "$cmd" >/dev/null || die "$cmd not found"
done

[[ -f "$LK_IMG" ]] || die "lk.img not found"
[[ -f "$MTKSU" ]] || die "mtk-su not found"

[[ "$(wc -c < "$LK_IMG" | tr -d ' ')" -eq "$LK_SIZE" ]] ||
    die "invalid lk.img size"

[[ "$(sha "$LK_IMG")" == "$LK_SHA" ]] ||
    die "invalid lk.img SHA256"

COUNT="$(
    adb devices |
        awk 'NR>1 && $2=="device"{n++} END{print n+0}'
)"

[[ "$COUNT" -eq 1 ]] ||
    die "connect exactly one ADB device"

prop() {
    adb shell getprop "$1" 2>/dev/null | tr -d '\r'
}

DEVICE="$(prop ro.product.device)"
PRODUCT="$(prop ro.build.product)"
NAME="$(prop ro.product.name)"
MODEL="$(prop ro.product.model)"
PLATFORM="$(prop ro.board.platform | tr 'A-Z' 'a-z')"

printf '%s\n' "$DEVICE $PRODUCT $NAME $MODEL" |
    grep -Eiq 'x18|H55_MT8163_60_N' ||
    die "not a PowKiddy X18"

if [[ -n "$PLATFORM" && "$PLATFORM" != "mt8163" ]]; then
    die "unsupported platform: $PLATFORM"
fi

adb push "$MTKSU" "$RMTK" >/dev/null
adb shell "chmod 755 '$RMTK'" >/dev/null

adb shell "$RMTK -c id" |
    grep -q 'uid=0(root)' ||
    die "root failed"

rootsh() {
    {
        echo 'PATH=/sbin:/system/sbin:/system/bin:/system/xbin:/vendor/bin; export PATH'
        echo "$1"
    } | adb shell "$RMTK -c /system/bin/sh"
}

LK=""

for P in \
    /dev/block/platform/mtk-msdc.0/11230000.MSDC0/by-name/lk \
    /dev/block/bootdevice/by-name/lk \
    /dev/block/by-name/lk
do
    if rootsh "[ -e '$P' ] && echo OK" 2>/dev/null |
        grep -q OK
    then
        LK="$P"
        break
    fi
done

[[ -n "$LK" ]] ||
    die "LK partition not found"

SECTORS="$(
    rootsh "cat /sys/block/mmcblk0/size" 2>/dev/null |
        tr -dc '0-9'
)"

[[ -n "$SECTORS" ]] ||
    die "cannot detect eMMC size"

EMMC_BYTES=$((SECTORS * 512))

# Separates the 32GB model from the 16GB model.
(( EMMC_BYTES >= 25000000000 && EMMC_BYTES <= 36000000000 )) ||
    die "this does not appear to be the X18 32GB model"

echo "PowKiddy X18 32GB detected."

mkdir -p "$BACKUPS"

STAMP="$(date +%Y%m%d_%H%M%S)"
BEFORE="$BACKUPS/lk_before_$STAMP.img"
AFTER="$BACKUPS/lk_after_$STAMP.img"

echo "Backing up LK..."

rootsh \
    "dd if='$LK' of='$RBEFORE' bs=4096 2>/dev/null &&
     chmod 644 '$RBEFORE' &&
     sync" >/dev/null ||
    die "cannot backup LK"

adb pull "$RBEFORE" "$BEFORE" >/dev/null ||
    die "cannot pull LK backup"

BEFORE_SIZE="$(wc -c < "$BEFORE" | tr -d ' ')"

[[ "$BEFORE_SIZE" -eq "$LK_SIZE" ]] ||
    die "unexpected current LK size: $BEFORE_SIZE"

BEFORE_SHA="$(sha "$BEFORE")"

echo "Current LK SHA256: $BEFORE_SHA"
echo "Backup: $BEFORE"

if [[ "$BEFORE_SHA" == "$LK_SHA" ]]; then
    echo "Our LK is already installed."
    exit 0
fi

echo
read -r -p "Install our LK? [y/N] " ANSWER

[[ "$ANSWER" == "y" || "$ANSWER" == "Y" ]] ||
    exit 0

adb push "$LK_IMG" "$RIMG" >/dev/null ||
    die "cannot upload lk.img"

echo "Writing LK..."

rootsh \
    "dd if='$RIMG' of='$LK' bs=4096 2>/dev/null &&
     sync" >/dev/null ||
    die "write failed - DO NOT REBOOT"

echo "Verifying..."

rootsh \
    "dd if='$LK' of='$RAFTER' bs=4096 2>/dev/null &&
     chmod 644 '$RAFTER' &&
     sync" >/dev/null ||
    die "readback failed - DO NOT REBOOT"

adb pull "$RAFTER" "$AFTER" >/dev/null ||
    die "readback failed - DO NOT REBOOT"

AFTER_SIZE="$(wc -c < "$AFTER" | tr -d ' ')"
AFTER_SHA="$(sha "$AFTER")"

if [[ "$AFTER_SIZE" -ne "$LK_SIZE" ||
      "$AFTER_SHA" != "$LK_SHA" ]]
then
    echo "Verification failed."
    echo "Restoring original LK..."

    adb push "$BEFORE" "$RRESTORE" >/dev/null ||
        die "cannot upload backup - DO NOT REBOOT"

    rootsh \
        "dd if='$RRESTORE' of='$LK' bs=4096 2>/dev/null &&
         sync" >/dev/null ||
        die "RESTORE FAILED - DO NOT REBOOT"

    rootsh \
        "dd if='$LK' of='$RAFTER' bs=4096 2>/dev/null &&
         chmod 644 '$RAFTER' &&
         sync" >/dev/null ||
        die "RESTORE READBACK FAILED - DO NOT REBOOT"

    adb pull "$RAFTER" "$AFTER" >/dev/null ||
        die "RESTORE READBACK FAILED - DO NOT REBOOT"

    [[ "$(sha "$AFTER")" == "$BEFORE_SHA" ]] ||
        die "RESTORE VERIFICATION FAILED - DO NOT REBOOT"

    die "original LK restored"
fi

echo
echo "OK - LK installed and verified."
echo "SHA256: $AFTER_SHA"
echo "Backup: $BEFORE"
