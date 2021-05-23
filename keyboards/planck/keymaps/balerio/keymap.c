/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "balerio.h"

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_planck_grid_wrapper( /* QWERTY */
  _____________________2_QWERTY_L_____________________, _____________________2_QWERTY_R_____________________,
  _____________________3_QWERTY_L_____________________, _____________________3_QWERTY_R_____________________,
  _____________________4_QWERTY_L_____________________, _____________________4_QWERTY_R_____________________,
  _____________________5_QWERTY_L_____________________, _____________________5_QWERTY_R_____________________
),

[_LOWER] = LAYOUT_planck_grid_wrapper(
  _____________________2_LOWER_L______________________,  _____________________2_LOWER_R______________________,
  _____________________3_LOWER_L______________________,  _____________________3_LOWER_R______________________,
  _____________________4_LOWER_L______________________,  _____________________4_LOWER_R______________________,
  _____________________5_LOWER_L______________________,  _____________________5_LOWER_R______________________
),

[_RAISE] = LAYOUT_planck_grid_wrapper(
  _____________________2_RAISE_L______________________,   _____________________2_RAISE_R______________________,
  _____________________3_RAISE_L______________________,   _____________________3_RAISE_R______________________,
  _____________________4_RAISE_L______________________,   _____________________4_RAISE_R______________________,
  _____________________5_RAISE_L______________________,   _____________________5_RAISE_R______________________
),

[_VIM] = LAYOUT_planck_grid_wrapper(
  ______________________2_VIM_L_______________________,   ______________________2_VIM_R_______________________,
  ______________________3_VIM_L_______________________,   ______________________3_VIM_R_______________________,
  ______________________4_VIM_L_______________________,   ______________________4_VIM_R_______________________,
  ______________________5_VIM_L_______________________,   ______________________5_VIM_R_______________________
),

[_PAD_R] = LAYOUT_planck_grid_wrapper(
  __________________2_RIGHT_KEYPAD_L__________________,   __________________2_RIGHT_KEYPAD_R__________________,
  __________________3_RIGHT_KEYPAD_L__________________,   __________________3_RIGHT_KEYPAD_R__________________,
  __________________4_RIGHT_KEYPAD_L__________________,   __________________4_RIGHT_KEYPAD_R__________________,
  __________________5_RIGHT_KEYPAD_L__________________,   __________________5_RIGHT_KEYPAD_R__________________
),

[_GAMES] =  LAYOUT_planck_grid_wrapper(
  _____________________2_GAMES_L______________________,   _____________________2_GAMES_R______________________,
  _____________________3_GAMES_L______________________,   _____________________3_GAMES_R______________________,
  _____________________4_GAMES_L______________________,   _____________________4_GAMES_R______________________,
  _____________________5_GAMES_L______________________,   _____________________5_GAMES_R______________________
),

[_F] =  LAYOUT_planck_grid_wrapper(
 _______________________2_F_L________________________,   _______________________2_F_R________________________,
 _______________________3_F_L________________________,   _______________________3_F_R________________________,
 _______________________4_F_L________________________,   _______________________4_F_R________________________,
 _______________________5_F_L________________________,   _______________________5_F_R________________________

),

[_ADJUST] = LAYOUT_planck_grid_wrapper(
  _____________________2_ADJUST_L_____________________,   _____________________2_ADJUST_R_____________________,
  _____________________3_ADJUST_L_____________________,   _____________________3_ADJUST_R_____________________,
  _____________________4_ADJUST_L_____________________,   _____________________4_ADJUST_R_____________________,
  _____________________5_ADJUST_L_____________________,   _____________________5_ADJUST_R_____________________
)

};


// void dip_update(uint8_t index, bool active) {
//   switch (index) {
//     case 0:
//       if (active) {
//         #ifdef AUDIO_ENABLE
//           PLAY_SONG(plover_song);
//         #endif
//         layer_on(_ADJUST);
//       } else {
//         #ifdef AUDIO_ENABLE
//           PLAY_SONG(plover_gb_song);
//         #endif
//         layer_off(_ADJUST);
//       }
//       break;
//     case 1:
//       if (active) {
//         muse_mode = true;
//       } else {
//         muse_mode = false;
//         #ifdef AUDIO_ENABLE
//           stop_all_notes();
//         #endif
//       }
//    }
// }

