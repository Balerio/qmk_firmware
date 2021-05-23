#include QMK_KEYBOARD_H
#include "balerio.h"



#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_crkbd_wrapper( /* QWERTY */
  _____________________2_QWERTY_L_____________________, _____________________2_QWERTY_R_____________________,
  _____________________3_QWERTY_L_____________________, _____________________3_QWERTY_R_____________________,
  _____________________4_QWERTY_L_____________________, _____________________4_QWERTY_R_____________________,
  _____________________5_QWERTY_L_____________________, _____________________5_QWERTY_R_____________________
),

[_LOWER] = LAYOUT_crkbd_wrapper(
  _____________________2_LOWER_L______________________,  _____________________2_LOWER_R______________________,
  _____________________3_LOWER_L______________________,  _____________________3_LOWER_R______________________,
  _____________________4_LOWER_L______________________,  _____________________4_LOWER_R______________________,
  _____________________5_LOWER_L______________________,  _____________________5_LOWER_R______________________
),

[_RAISE] = LAYOUT_crkbd_wrapper(
  _____________________2_RAISE_L______________________,   _____________________2_RAISE_R______________________,
  _____________________3_RAISE_L______________________,   _____________________3_RAISE_R______________________,
  _____________________4_RAISE_L______________________,   _____________________4_RAISE_R______________________,
  _____________________5_RAISE_L______________________,   _____________________5_RAISE_R______________________
),

[_VIM] = LAYOUT_crkbd_wrapper(
  ______________________2_VIM_L_______________________,   ______________________2_VIM_R_______________________,
  ______________________3_VIM_L_______________________,   ______________________3_VIM_R_______________________,
  ______________________4_VIM_L_______________________,   ______________________4_VIM_R_______________________,
  ______________________5_VIM_L_______________________,   ______________________5_VIM_R_______________________
),

[_PAD_R] = LAYOUT_crkbd_wrapper(
  __________________2_RIGHT_KEYPAD_L__________________,   __________________2_RIGHT_KEYPAD_R__________________,
  __________________3_RIGHT_KEYPAD_L__________________,   __________________3_RIGHT_KEYPAD_R__________________,
  __________________4_RIGHT_KEYPAD_L__________________,   __________________4_RIGHT_KEYPAD_R__________________,
  __________________5_RIGHT_KEYPAD_L__________________,   __________________5_RIGHT_KEYPAD_R__________________
),

[_GAMES] =  LAYOUT_crkbd_wrapper(
  _____________________2_GAMES_L______________________,   _____________________2_GAMES_R______________________,
  _____________________3_GAMES_L______________________,   _____________________3_GAMES_R______________________,
  _____________________4_GAMES_L______________________,   _____________________4_GAMES_R______________________,
  _____________________5_GAMES_L______________________,   _____________________5_GAMES_R______________________
),

[_F] =  LAYOUT_crkbd_wrapper(
 _______________________2_F_L________________________,   _______________________2_F_R________________________,
 _______________________3_F_L________________________,   _______________________3_F_R________________________,
 _______________________4_F_L________________________,   _______________________4_F_R________________________,
 _______________________5_F_L________________________,   _______________________5_F_R________________________
),

[_ADJUST] = LAYOUT_crkbd_wrapper(
  _____________________2_ADJUST_L_____________________,   _____________________2_ADJUST_R_____________________,
  _____________________3_ADJUST_L_____________________,   _____________________3_ADJUST_R_____________________,
  _____________________4_ADJUST_L_____________________,   _____________________4_ADJUST_R_____________________,
  _____________________5_ADJUST_L_____________________,   _____________________5_ADJUST_R_____________________
)


};

int RGB_current_mode;
