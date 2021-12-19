BOOTLOADER = caterina

ENCODER_ENABLE = no       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
AUDIO_ENABLE = no
COMBO_ENABLE = no

RGB_MATRIX_SUPPORTED = no

DYNAMIC_TAPPING_TERM_ENABLE = yes

ifdef RIGHT
OLED_ENABLE = no
else
OLED_ENABLE = yes
OLED_DRIVER = SSD1306   # Enables the use of OLED displays
endif

ifdef WITH_TRACKBALL
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pimoroni_trackball
endif

ifdef WITH_TRACKPOINT
PS2_MOUSE_ENABLE = yes
PS2_USE_INT = yes
endif
