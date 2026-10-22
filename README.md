<p align="center">
  <img width="240" alt="logo" src="https://github.com/user-attachments/assets/d18a4db7-f426-46a5-a542-a03d215649e6" />
</p>

# PowKiddy X18 32GB — LineageOS 14.1

Unofficial firmware project for the **PowKiddy X18 2GB RAM / 32GB eMMC** based on **MediaTek MT8163**.

This project includes:

- **LineageOS 14.1 / Android 7.1.2**
- Custom **LK bootloader** with a Power-button boot menu
- **TWRP recovery** adapted for the X18 32GB
- Device tree adapted for the `vWC10000D` hardware revision

The goal of this project is to provide a working and easy-to-install custom Android setup for the original **PowKiddy X18 32GB**.

The device tree is based on and forked from:

https://github.com/turtleletortue/android_device_powkiddy_x18/tree/cm-14.1

The original source was adapted for the 32GB hardware revision, including the correct partition layout, stock X18 kernel, boot configuration, recovery support, and other device-specific fixes.

> **Important:** This project is intended for the original **PowKiddy X18 2GB / 32GB**.  
> Do not use these images on the 16GB model or other devices.

### 1. Install LK

The custom LK bootloader is required to access **Recovery**, **Fastboot**, and normal Android boot using only the Power button.

The stock X18 boot menu expects volume keys, which do not work reliably on this device.

Clone the LK installer repository:

```bash
git clone -b LK-Patch https://github.com/Sergei768/powkiddy-x18_32gb-dev.git
```

Enter the repository directory:

```bash
cd powkiddy-x18_32gb-dev
```

Then run the installer.

**Linux**
```bash
chmod +x install_x18_lk.sh
./install_x18_lk.sh
```

**Windows**
```text
install_x18_lk.bat
```

The installer automatically creates a backup of the original LK.

### LK Boot Menu

```text
Short Power press = next option
Hold Power        = select option
```

Available options:

```text
Recovery
Fastboot
Normal
```
---

### 2. Unlock the Bootloader

After installing LK, reboot into Fastboot:

```bash
adb reboot bootloader
```

Check the current unlock state:

```bash
fastboot getvar unlocked
```

Unlock the bootloader:

```bash
fastboot oem unlock
```

Confirm the unlock operation on the X18 if prompted.

Then verify:

```bash
fastboot getvar unlocked
```

It should report that the bootloader is unlocked.

> Unlocking may erase user data. Make a backup before continuing.

---

### 3. Install TWRP

While in Fastboot, flash TWRP:

```bash
fastboot flash recovery twrp_x18_32gb.img
```

Reboot the device and select:

```text
Recovery
```

from the LK boot menu.

---

### 4. Install LineageOS

Copy the ROM ZIP to the device and boot into TWRP.

In TWRP:

```text
Wipe → Advanced Wipe
```

Select:

```text
Dalvik / ART Cache
System
Data
Cache
```

Then install:

```text
lineage-14.1-20261022-UNOFFICIAL-x18_32gb.zip
```

Finally:

```text
Reboot → System
```

If TWRP cannot mount `/data`, use:

```text
Wipe → Format Data
```

After installation is complete, you can reboot into the newly installed firmware.
