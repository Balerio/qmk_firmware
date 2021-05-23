/* Copyright 2019 Takuya Urakawa (dm9records.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "balerio.h"

extern keymap_config_t keymap_config;

//Setup consts for LED modes
#define LEDMODE_ON 1 //always on
#define LEDMODE_OFF 0 //always off
#define LEDMODE_MODS 2 //On with modifiers
#define LEDMODE_BLINKIN 3 //blinkinlights - % chance toggle on keypress
#define LEDMODE_KEY 4 //On with any keypress, off with key release
#define LEDMODE_ENTER 5 // On with enter key

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_plaid_grid_wrapper( /* QWERTY */
        _____________________2_QWERTY_L_____________________, _____________________2_QWERTY_R_____________________,
        _____________________3_QWERTY_L_____________________, _____________________3_QWERTY_R_____________________,
        _____________________4_QWERTY_L_____________________, _____________________4_QWERTY_R_____________________,
        _____________________5_QWERTY_L_____________________, _____________________5_QWERTY_R_____________________
    ),

    [_LOWER] = LAYOUT_plaid_grid_wrapper(
        _____________________2_LOWER_L______________________,  _____________________2_LOWER_R______________________,
        _____________________3_LOWER_L______________________,  _____________________3_LOWER_R______________________,
        _____________________4_LOWER_L______________________,  _____________________4_LOWER_R______________________,
        _____________________5_LOWER_L______________________,  _____________________5_LOWER_R______________________
    ),

    [_RAISE] = LAYOUT_plaid_grid_wrapper(
        _____________________2_RAISE_L______________________,   _____________________2_RAISE_R______________________,
        _____________________3_RAISE_L______________________,   _____________________3_RAISE_R______________________,
        _____________________4_RAISE_L______________________,   _____________________4_RAISE_R______________________,
        _____________________5_RAISE_L______________________,   _____________________5_RAISE_R______________________
    ),

    [_VIM] = LAYOUT_plaid_grid_wrapper(
        ______________________2_VIM_L_______________________,   ______________________2_VIM_R_______________________,
        ______________________3_VIM_L_______________________,   ______________________3_VIM_R_______________________,
        ______________________4_VIM_L_______________________,   ______________________4_VIM_R_______________________,
        ______________________5_VIM_L_______________________,   ______________________5_VIM_R_______________________
    ),

    [_PAD_R] = LAYOUT_plaid_grid_wrapper(
    __________________2_RIGHT_KEYPAD_L__________________,   __________________2_RIGHT_KEYPAD_R__________________,
    __________________3_RIGHT_KEYPAD_L__________________,   __________________3_RIGHT_KEYPAD_R__________________,
    __________________4_RIGHT_KEYPAD_L__________________,   __________________4_RIGHT_KEYPAD_R__________________,
    __________________5_RIGHT_KEYPAD_L__________________,   __________________5_RIGHT_KEYPAD_R__________________
    ),

    [_GAMES] =  LAYOUT_plaid_grid_wrapper(
        _____________________2_GAMES_L______________________,   _____________________2_GAMES_R______________________,
        _____________________3_GAMES_L______________________,   _____________________3_GAMES_R______________________,
        _____________________4_GAMES_L______________________,   _____________________4_GAMES_R______________________,
        _____________________5_GAMES_L______________________,   _____________________5_GAMES_R______________________
    ),

    [_F] =  LAYOUT_plaid_grid_wrapper(
        _______________________2_F_L________________________,   _______________________2_F_R________________________,
        _______________________3_F_L________________________,   _______________________3_F_R________________________,
        _______________________4_F_L________________________,   _______________________4_F_R________________________,
        _______________________5_F_L________________________,   _______________________5_F_R________________________

    ),

    [_ACCENTS] = LAYOUT_plaid_grid_wrapper(
        ____________________2_ACCENTS_L_____________________,   ____________________2_ACCENTS_R_____________________,
        ____________________3_ACCENTS_L_____________________,   ____________________3_ACCENTS_R_____________________,
        ____________________4_ACCENTS_L_____________________,   ____________________4_ACCENTS_R_____________________,
        ____________________5_ACCENTS_L_____________________,   ____________________5_ACCENTS_R_____________________

    ),


    [_ADJUST] = LAYOUT_plaid_grid_wrapper(
        _____________________2_ADJUST_L_____________________,   _____________________2_ADJUST_R_____________________,
        _____________________3_ADJUST_L_____________________,   _____________________3_ADJUST_R_____________________,
        _____________________4_ADJUST_L_____________________,   _____________________4_ADJUST_R_____________________,
        _____________________5_ADJUST_L_____________________,   _____________________5_ADJUST_R_____________________
    )
};

// array of keys considered modifiers for led purposes
const uint16_t modifiers[] = {
    KC_LCTL,
    KC_RCTL,
    KC_LALT,
    KC_RALT,
    KC_LSFT,
    KC_RSFT,
    KC_LGUI,
    KC_RGUI,
    _LOWER,
    _RAISE
};

enum plaid_keycodes {
  LED_1 = KEYMAP_SAFE_RANGE,
  LED_2,
  LED_3,
  LED_4,
  LED_5,
  LED_6,
  LED_7,
  LED_8,
  LED_9,
  LED_0
};
//Setup config struct for LED
typedef union {
  uint32_t raw;
  struct {
    uint8_t  red_mode :8;
    uint8_t  green_mode :8;
  };
} led_config_t;
led_config_t led_config;

//Set leds to saved state during powerup
void keyboard_post_init_keymap(void) {
  // Call the post init code.
  led_config.raw = eeconfig_read_user();

  if(led_config.red_mode == LEDMODE_ON) {
      writePinHigh(LED_RED);
  }

  if(led_config.green_mode == LEDMODE_ON) {
      writePinHigh(LED_GREEN);
  }
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  led_config.raw = 0;
  led_config.red_mode = LEDMODE_ON;
  led_config.green_mode = LEDMODE_MODS;
      eeconfig_update_user(led_config.raw);
  eeconfig_update_user(led_config.raw);
}


void led_keypress_update(uint8_t led, uint8_t led_mode, uint16_t keycode, keyrecord_t *record) {
    switch (led_mode) {
      case LEDMODE_MODS:
        for (int i=0;i<sizeof(modifiers) / sizeof(modifiers[0]);i++) {
          if(keycode==modifiers[i]) {
            if (record->event.pressed) {
              writePinHigh(led);
            }
            else {
              writePinLow(led);
            }
          }
        }
        break;
      case LEDMODE_BLINKIN:
        if (record->event.pressed) {
          if(rand() % 2 == 1) {
            if(rand() % 2 == 0) {
              writePinLow(led);
            }
            else {
              writePinHigh(led);
            }
          }
        }
        break;
      case LEDMODE_KEY:
        if (record->event.pressed) {
          writePinHigh(led);
          return;
        }
        else {
          writePinLow(led);
          return;
        }
        break;
      case LEDMODE_ENTER:
        if (keycode==KC_ENT) {
          writePinHigh(led);
        }
        else {
          writePinLow(led);
        }
        break;

    }
}

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  /* If the either led mode is keypressed based, call the led updater
     then let it fall through the keypress handlers. Just to keep
     the logic out of this procedure */
  if (led_config.red_mode >= LEDMODE_MODS && led_config.red_mode <= LEDMODE_ENTER) {
      led_keypress_update(LED_RED, led_config.red_mode, keycode, record);
  }
  if (led_config.green_mode >= LEDMODE_MODS && led_config.green_mode <= LEDMODE_ENTER) {
      led_keypress_update(LED_GREEN, led_config.green_mode, keycode, record);
  }
  switch (keycode) {
    case LED_1:
      if (record->event.pressed) {
        if (led_config.red_mode==LEDMODE_ON) {
            led_config.red_mode=LEDMODE_OFF;
            writePinLow(LED_RED);
        }
        else {
            led_config.red_mode=LEDMODE_ON;
            writePinHigh(LED_RED);
        }
      }
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_2:
      if (record->event.pressed) {
        if (led_config.green_mode==LEDMODE_ON) {
            led_config.green_mode=LEDMODE_OFF;
            writePinLow(LED_GREEN);
        }
        else {
            led_config.green_mode=LEDMODE_ON;
            writePinHigh(LED_GREEN);
        }
      }
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_3:
      led_config.red_mode=LEDMODE_MODS;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_4:
      led_config.green_mode=LEDMODE_MODS;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_5:
      led_config.red_mode=LEDMODE_BLINKIN;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_6:
      led_config.green_mode=LEDMODE_BLINKIN;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_7:
      led_config.red_mode=LEDMODE_KEY;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_8:
      led_config.green_mode=LEDMODE_KEY;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_9:
      led_config.red_mode=LEDMODE_ENTER;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
    case LED_0:
      led_config.green_mode=LEDMODE_ENTER;
      eeconfig_update_user(led_config.raw);
      return false;
      break;
  }
  return true;
}
