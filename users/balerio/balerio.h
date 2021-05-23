#pragma once

#include "quantum.h"
#include "version.h"
#include "eeprom.h"
#include "process_records.h"
#include "keymaps.h"
#include "keymap_italian.h"

#include "tap_dances.h"

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#    include "rgb_stuff.h"
#endif

#ifdef OLED_DRIVER_ENABLE
//   #include "ssd1306.h"
    #include "oled_stuff.h"
#endif
