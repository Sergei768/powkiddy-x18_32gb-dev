# PowKiddy X18 32GB — Custom LK

Modified **LK (Little Kernel) bootloader** for the original **PowKiddy X18 2GB / 32GB** based on MediaTek MT8163.

## What was wrong with the stock LK?

The stock LK contains the standard MediaTek boot menu logic that expects **Volume Up / Volume Down** key events for navigation.

On the PowKiddy X18 these key inputs are not properly implemented inside LK, so the boot menu cannot be controlled normally even though the device itself has physical buttons.

Because of this, access to:

- Recovery
- Fastboot
- Normal boot selection

was unreliable or unavailable from the stock LK menu.

## What was changed?

The LK boot menu input logic was modified to use only the **Power button**.

The original volume-key navigation was replaced with a simple Power-button state machine:

```text
Short Power press = next menu item
Hold Power        = select current item
```

The available boot modes are:

```text
Recovery
Fastboot
Normal
```

Menu order:

```text
Recovery
↓
Fastboot
↓
Normal
↓
Recovery
```

## Installation

Clone the `LK-Patch` branch:

```bash
git clone -b LK-Patch https://github.com/Sergei768/powkiddy-x18_32gb-dev.git
cd powkiddy-x18_32gb-dev
```

### Linux

```bash
chmod +x install_x18_lk.sh
./install_x18_lk.sh
```

### Windows

```text
install_x18_lk.bat
```

The installer backs up the current LK before flashing and verifies the new image after installation.

## Using the LK menu

After entering the LK boot menu:

```text
Short Power press
→ next option

Hold Power
→ select option
```

Use:

- **Recovery** — boot TWRP
- **Fastboot** — enter Fastboot mode
- **Normal** — boot Android

## Compatibility

Intended for:

```text
PowKiddy X18 original
2 GB RAM
32 GB eMMC
MediaTek MT8163
Board: vWC10000D
```

Do not use this LK image on the 16GB X18 or unrelated MT8163 devices.
