@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "DIR=%~dp0"

set "LKIMG=%DIR%lk.img"
set "MTKSU=%DIR%mtk-su"
set "BACKUPS=%DIR%backups"

set "LK_SHA=96edcbf3e6ce8034bcfa688100331935401cb9ee7349376f5292948839ae6d62"
set "LK_SIZE=393216"

set "RMTK=/data/local/tmp/x18-mtksu"
set "RIMG=/data/local/tmp/x18-lk.img"
set "RBEFORE=/data/local/tmp/x18-lk-before.img"
set "RAFTER=/data/local/tmp/x18-lk-after.img"
set "RRESTORE=/data/local/tmp/x18-lk-restore.img"

where adb >nul 2>nul || (
    echo ERROR: adb not found
    exit /b 1
)

where powershell >nul 2>nul || (
    echo ERROR: PowerShell not found
    exit /b 1
)

if not exist "%LKIMG%" (
    echo ERROR: lk.img not found
    exit /b 1
)

if not exist "%MTKSU%" (
    echo ERROR: mtk-su not found
    exit /b 1
)

for %%F in ("%LKIMG%") do set "SIZE=%%~zF"

if not "%SIZE%"=="%LK_SIZE%" (
    echo ERROR: invalid lk.img size
    exit /b 1
)

for /f %%H in ('powershell -NoProfile -Command "(Get-FileHash -Algorithm SHA256 -LiteralPath '%LKIMG%').Hash.ToLower()"') do (
    set "HASH=%%H"
)

if /i not "%HASH%"=="%LK_SHA%" (
    echo ERROR: invalid lk.img SHA256
    exit /b 1
)

set /a COUNT=0

for /f "skip=1 tokens=1,2" %%A in ('adb devices') do (
    if "%%B"=="device" set /a COUNT+=1
)

if not "%COUNT%"=="1" (
    echo ERROR: connect exactly one ADB device
    exit /b 1
)

for /f "delims=" %%A in ('adb shell getprop ro.product.device') do set "DEVICE=%%A"
for /f "delims=" %%A in ('adb shell getprop ro.build.product') do set "PRODUCT=%%A"
for /f "delims=" %%A in ('adb shell getprop ro.product.name') do set "NAME=%%A"
for /f "delims=" %%A in ('adb shell getprop ro.product.model') do set "MODEL=%%A"
for /f "delims=" %%A in ('adb shell getprop ro.board.platform') do set "PLATFORM=%%A"

echo %DEVICE% %PRODUCT% %NAME% %MODEL% |
    findstr /i /c:"x18" /c:"H55_MT8163_60_N" >nul

if errorlevel 1 (
    echo ERROR: not a PowKiddy X18
    exit /b 1
)

if defined PLATFORM (
    if /i not "%PLATFORM%"=="mt8163" (
        echo ERROR: unsupported platform: %PLATFORM%
        exit /b 1
    )
)

adb push "%MTKSU%" "%RMTK%" >nul || goto :error
adb shell "chmod 755 '%RMTK%'" >nul

adb shell "%RMTK% -c id" |
    findstr /c:"uid=0(root)" >nul

if errorlevel 1 (
    echo ERROR: root failed
    exit /b 1
)

set "LK="

for %%P in (
"/dev/block/platform/mtk-msdc.0/11230000.MSDC0/by-name/lk"
"/dev/block/bootdevice/by-name/lk"
"/dev/block/by-name/lk"
) do (
    if not defined LK (
        call :exists %%~P
    )
)

if not defined LK (
    echo ERROR: LK partition not found
    exit /b 1
)

for /f "delims=" %%S in ('call :getsectors') do (
    set "SECTORS=%%S"
)

if not defined SECTORS (
    echo ERROR: cannot detect eMMC size
    exit /b 1
)

set "SECTORS=%SECTORS%"

powershell -NoProfile -Command ^
 "$s=[int64]$env:SECTORS;" ^
 "$b=$s*512;" ^
 "if($b -lt 25000000000 -or $b -gt 36000000000){exit 1}"

if errorlevel 1 (
    echo ERROR: this does not appear to be the X18 32GB model
    exit /b 1
)

echo PowKiddy X18 32GB detected.

if not exist "%BACKUPS%" mkdir "%BACKUPS%"

for /f %%T in ('powershell -NoProfile -Command "Get-Date -Format yyyyMMdd_HHmmss"') do (
    set "STAMP=%%T"
)

set "BEFORE=%BACKUPS%\lk_before_%STAMP%.img"
set "AFTER=%BACKUPS%\lk_after_%STAMP%.img"

echo Backing up LK...

call :rootsh "dd if='%LK%' of='%RBEFORE%' bs=4096 2>/dev/null && chmod 644 '%RBEFORE%' && sync"

if errorlevel 1 (
    echo ERROR: cannot backup LK
    exit /b 1
)

adb pull "%RBEFORE%" "%BEFORE%" >nul || goto :error

for %%F in ("%BEFORE%") do set "BEFORE_SIZE=%%~zF"

if not "%BEFORE_SIZE%"=="%LK_SIZE%" (
    echo ERROR: unexpected current LK size
    exit /b 1
)

for /f %%H in ('powershell -NoProfile -Command "(Get-FileHash -Algorithm SHA256 -LiteralPath '%BEFORE%').Hash.ToLower()"') do (
    set "BEFORE_SHA=%%H"
)

echo Current LK SHA256: %BEFORE_SHA%
echo Backup: %BEFORE%

if /i "%BEFORE_SHA%"=="%LK_SHA%" (
    echo Our LK is already installed.
    exit /b 0
)

echo.
set /p "ANSWER=Install our LK? [y/N] "

if /i not "%ANSWER%"=="y" (
    exit /b 0
)

adb push "%LKIMG%" "%RIMG%" >nul || goto :error

echo Writing LK...

call :rootsh "dd if='%RIMG%' of='%LK%' bs=4096 2>/dev/null && sync"

if errorlevel 1 (
    echo ERROR: write failed - DO NOT REBOOT
    exit /b 1
)

echo Verifying...

call :rootsh "dd if='%LK%' of='%RAFTER%' bs=4096 2>/dev/null && chmod 644 '%RAFTER%' && sync"

if errorlevel 1 (
    echo ERROR: readback failed - DO NOT REBOOT
    exit /b 1
)

adb pull "%RAFTER%" "%AFTER%" >nul || (
    echo ERROR: readback failed - DO NOT REBOOT
    exit /b 1
)

for %%F in ("%AFTER%") do set "AFTER_SIZE=%%~zF"

for /f %%H in ('powershell -NoProfile -Command "(Get-FileHash -Algorithm SHA256 -LiteralPath '%AFTER%').Hash.ToLower()"') do (
    set "AFTER_SHA=%%H"
)

if not "%AFTER_SIZE%"=="%LK_SIZE%" goto :restore
if /i not "%AFTER_SHA%"=="%LK_SHA%" goto :restore

echo.
echo OK - LK installed and verified.
echo SHA256: %AFTER_SHA%
echo Backup: %BEFORE%

exit /b 0

:restore

echo Verification failed.
echo Restoring original LK...

adb push "%BEFORE%" "%RRESTORE%" >nul || goto :restorefail

call :rootsh "dd if='%RRESTORE%' of='%LK%' bs=4096 2>/dev/null && sync"

if errorlevel 1 goto :restorefail

call :rootsh "dd if='%LK%' of='%RAFTER%' bs=4096 2>/dev/null && chmod 644 '%RAFTER%' && sync"

if errorlevel 1 goto :restorefail

adb pull "%RAFTER%" "%AFTER%" >nul || goto :restorefail

for /f %%H in ('powershell -NoProfile -Command "(Get-FileHash -Algorithm SHA256 -LiteralPath '%AFTER%').Hash.ToLower()"') do (
    set "RESTORE_SHA=%%H"
)

if /i not "%RESTORE_SHA%"=="%BEFORE_SHA%" goto :restorefail

echo Original LK restored and verified.
exit /b 1

:restorefail

echo ERROR: RESTORE FAILED - DO NOT REBOOT
exit /b 1

:error

echo ERROR: operation failed
exit /b 1

:exists

call :rootsh "[ -e '%~1' ] && echo FOUND" |
    findstr /c:"FOUND" >nul

if not errorlevel 1 set "LK=%~1"

exit /b 0

:getsectors

call :rootsh "cat /sys/block/mmcblk0/size" 2>nul
exit /b 0

:rootsh

set "RCMD=%~1"

(
    echo PATH=/sbin:/system/sbin:/system/bin:/system/xbin:/vendor/bin; export PATH
    echo(!RCMD!
) | adb shell "%RMTK% -c /system/bin/sh"

exit /b %errorlevel%
