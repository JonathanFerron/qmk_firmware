# MCU name
MCU = atmega328p

# Bootloader selection
BOOTLOADER = usbasploader

# Build Options
CUSTOM_MATRIX = lite

BOOTMAGIC_ENABLE = no       # Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
COMMAND_ENABLE = no         # Commands for debug and configuration
BACKLIGHT_ENABLE = no       # keyboard backlight functionality
RGBLIGHT_ENABLE = no        # keyboard RGB underglow
ENCODER_ENABLE = no         # rotary encoder
OLED_ENABLE = no
WPM_ENABLE = no

SRC += matrix.c \
    mcp23017.c

QUANTUM_LIB_SRC += i2c_master.c
