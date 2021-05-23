EXTRAFLAGS += -flto

SRC += balerio.c \
	   tap_dances.c \
       process_records.c

# ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
# 	SRC += rgb_underglow.c
# endif

	ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
		SRC += rgb_stuff.c
	endif
	endif

	ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
		SRC += oled_stuff.c
	endif

MOUSEKEY_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
DYNAMIC_MACRO_ENABLE = no


TAP_DANCE_ENABLE = yes

# ifeq ($(strip $(RGBLIGHT_ENABLE)), no)
# 	NKRO_ENABLE = no
# else
# 	NKRO_ENABLE = yes
# endif

NKRO_ENABLE ?= yes
# NKRO_ENABLE = yes
# ifeq ($(strip $(PROTOCOL)), VUSB)
#     NKRO_ENABLE       = no
# endif
# ifdef FORCE_NO_NKRO
#     NKRO_ENABLE       = no
# endif

KEY_LOCK_ENABLE = no

LEADER_ENABLE = yes




