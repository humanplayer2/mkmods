# Build Options
#
#
#TAP_DANCE_ENABLE = no
#KEY_OVERRIDE_ENABLE = no
#BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output

# TrackPoint
PS2_MOUSE_ENABLE = yes
PS2_ENABLE = yes
PS2_DRIVER = usart

# Custom shift keys:
SRC += features/custom_shift_keys.c # https://getreuer.info/posts/keyboards/custom-shift-keys/index.html

# Caps Words:
CAPS_WORD_ENABLE = yes