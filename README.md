# PowKiddy X18 LineageOS 14.1 Device Tree

Device tree for the original **PowKiddy X18 2GB / 32GB** based on MediaTek MT8163.

This repository is a fork of:

https://github.com/turtleletortue/android_device_powkiddy_x18/tree/cm-14.1

The original device tree was adapted for the 32GB hardware revision and the working LineageOS 14.1 port.

## Target device

- Device: PowKiddy X18 original
- SoC: MediaTek MT8163
- Architecture: ARM64 / AArch64
- RAM: 2 GB
- eMMC: 32 GB
- Board: `vWC10000D`
- Stock Android: Android 7
- Stock kernel: Linux 3.18.35+

## Main changes

Compared with the original `cm-14.1` device tree, this fork includes the following changes:

- Adapted partition sizes for the 32GB X18 revision
- Correct 1.5 GiB `system` partition size
- Correct 16 MiB `boot` and `recovery` partition sizes
- Correct 112 MiB `cache` size
- Correct 32GB `userdata` size
- Changed bootloader board name to `vWC10000D`
- Replaced the donor kernel with the stock kernel from the 32GB X18
- Updated Android boot image parameters for the working 32GB configuration
- Removed dm-verity verification from the `/system` fstab entry
- Added OTA assert support for both:
  - `x18`
  - `powkiddy_x18`
- Updated screen configuration for the 1280x720 display
- Removed duplicate proprietary file entries
- Removed unused modem initialization import
- Removed the invalid `misc2` partition symlink
- Cleaned duplicate build configuration entries
- Cleaned duplicate package definitions
