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
#include "balerio.h"

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_ortho_5x12_wrapper( /* QWERTY */
  _____________________1_QWERTY_L_____________________, _____________________1_QWERTY_R_____________________,
  _____________________2_QWERTY_L_____________________, _____________________2_QWERTY_R_____________________,
  _____________________3_QWERTY_L_____________________, _____________________3_QWERTY_R_____________________,
  _____________________4_QWERTY_L_____________________, _____________________4_QWERTY_R_____________________,
  _____________________5_QWERTY_L_____________________, _____________________5_QWERTY_R_____________________
),

[_LOWER] = LAYOUT_ortho_5x12_wrapper(
  _____________________1_LOWER_L______________________,  _____________________1_LOWER_R______________________,
  _____________________2_LOWER_L______________________,  _____________________2_LOWER_R______________________,
  _____________________3_LOWER_L______________________,  _____________________3_LOWER_R______________________,
  _____________________4_LOWER_L______________________,  _____________________4_LOWER_R______________________,
  _____________________5_LOWER_L______________________,  _____________________5_LOWER_R______________________
),

[_RAISE] = LAYOUT_ortho_5x12_wrapper(
  _____________________1_RAISE_L______________________,   _____________________1_RAISE_R______________________,
  _____________________2_RAISE_L______________________,   _____________________2_RAISE_R______________________,
  _____________________3_RAISE_L______________________,   _____________________3_RAISE_R______________________,
  _____________________4_RAISE_L______________________,   _____________________4_RAISE_R______________________,
  _____________________5_RAISE_L______________________,   _____________________5_RAISE_R______________________
),

[_VIM] = LAYOUT_ortho_5x12_wrapper(
  ______________________1_VIM_L_______________________,   ______________________1_VIM_R_______________________,
  ______________________2_VIM_L_______________________,   ______________________2_VIM_R_______________________,
  ______________________3_VIM_L_______________________,   ______________________3_VIM_R_______________________,
  ______________________4_VIM_L_______________________,   ______________________4_VIM_R_______________________,
  ______________________5_VIM_L_______________________,   ______________________5_VIM_R_______________________
),

[_PAD_R] = LAYOUT_ortho_5x12_wrapper(
  __________________1_RIGHT_KEYPAD_L__________________,   __________________1_RIGHT_KEYPAD_R__________________,
  __________________2_RIGHT_KEYPAD_L__________________,   __________________2_RIGHT_KEYPAD_R__________________,
  __________________3_RIGHT_KEYPAD_L__________________,   __________________3_RIGHT_KEYPAD_R__________________,
  __________________4_RIGHT_KEYPAD_L__________________,   __________________4_RIGHT_KEYPAD_R__________________,
  __________________5_RIGHT_KEYPAD_L__________________,   __________________5_RIGHT_KEYPAD_R__________________
),

[_GAMES] =  LAYOUT_ortho_5x12_wrapper(
  _____________________1_GAMES_L______________________,   _____________________1_GAMES_R______________________,
  _____________________2_GAMES_L______________________,   _____________________2_GAMES_R______________________,
  _____________________3_GAMES_L______________________,   _____________________3_GAMES_R______________________,
  _____________________4_GAMES_L______________________,   _____________________4_GAMES_R______________________,
  _____________________5_GAMES_L______________________,   _____________________5_GAMES_R______________________
),

[_F] =  LAYOUT_ortho_5x12_wrapper(
 _______________________1_F_L________________________,   _______________________1_F_R________________________,
 _______________________2_F_L________________________,   _______________________2_F_R________________________,
 _______________________3_F_L________________________,   _______________________3_F_R________________________,
 _______________________4_F_L________________________,   _______________________4_F_R________________________,
 _______________________5_F_L________________________,   _______________________5_F_R________________________

),

[_ACCENTS] = LAYOUT_ortho_5x12_wrapper(
 ____________________1_ACCENTS_L_____________________,   ____________________1_ACCENTS_R_____________________,
 ____________________2_ACCENTS_L_____________________,   ____________________2_ACCENTS_R_____________________,
 ____________________3_ACCENTS_L_____________________,   ____________________3_ACCENTS_R_____________________,
 ____________________4_ACCENTS_L_____________________,   ____________________4_ACCENTS_R_____________________,
 ____________________5_ACCENTS_L_____________________,   ____________________5_ACCENTS_R_____________________

),

[_ADJUST] = LAYOUT_ortho_5x12_wrapper(
  _____________________1_ADJUST_L_____________________,   _____________________1_ADJUST_R_____________________,
  _____________________2_ADJUST_L_____________________,   _____________________2_ADJUST_R_____________________,
  _____________________3_ADJUST_L_____________________,   _____________________3_ADJUST_R_____________________,
  _____________________4_ADJUST_L_____________________,   _____________________4_ADJUST_R_____________________,
  _____________________5_ADJUST_L_____________________,   _____________________5_ADJUST_R_____________________
)

};
