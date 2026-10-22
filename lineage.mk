PRODUCT_RELEASE_NAME := x18
CM_VENDOR := vendor/cm

$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base.mk)
$(call inherit-product, $(CM_VENDOR)/config/common_full_tablet_wifionly.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)

$(call inherit-product, device/powkiddy/x18/device.mk)

TARGET_SCREEN_WIDTH := 1280
TARGET_SCREEN_HEIGHT := 720

PRODUCT_CHARACTERISTICS := tablet

TARGET_BOOTANIMATION_PRELOAD := true
TARGET_BOOTANIMATION_TEXTURE_CACHE := true

PRODUCT_DEVICE := x18
PRODUCT_NAME := lineage_x18
PRODUCT_BRAND := google
PRODUCT_MANUFACTURER := Powkiddy
PRODUCT_MODEL := x18

