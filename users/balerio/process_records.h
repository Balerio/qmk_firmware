#pragma once
#include "balerio.h"


#include "quantum.h"
#include "action.h"
#include "version.h"

#if defined(KEYMAP_SAFE_RANGE)
  #define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
  #define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  VIM,
  ADJUST,

  ALT_TAB,
  KC_CCCV,
  KC_MAKE,
  CU_TILD,
  CU_GRV,

  CU_SCLN,
  CU_COMM,
  CU_DOT,
  CU_SLSH,
  CU_QUOT,

  CU_8,

  FLEAD,

  CU_A,
  CU_E,
  CU_I,
  CU_O,
  CU_U,
  CU_P,

  KEYMAP_SAFE_RANGE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
// double function keys
#define WIN_TAB RWIN_T(KC_TAB)
#define CTL_ESC LCTL_T(KC_ESC)
#define SFT_BCK SFT_T(KC_BSPC)
#define SFT_ENT SFT_T(KC_ENT)
#define F_VIM LT(_VIM, IT_F)
#define D_PAD LT(_PAD_R, IT_D)
// TAB on press, RAISE layer on hold
#define RAI_TAB LT(_RAISE, KC_TAB)
#define LOW_TAB LT(_LOWER, KC_TAB)
// DEL on press, LOWER layer on hold
#define LOW_DEL LT(_LOWER, KC_DEL)
#define LOW_DOT LT(_LOWER, KC_PDOT)
// #define F_LAYER MO(_F)
#define F_LAYER LT(_F, KC_LEAD)
#define ADJ_ENT LT(_ADJUST, KC_ENT)

#define VIM_SPC LT(_VIM, KC_SPACE)

#define PAD_RGH MO(_PAD_R)
#define ACCENTS MO(_ACCENTS)
// Arrow Mods Keys
#define CTL_LFT RCTL_T(KC_LEFT)

// TAP DANCES
#define TD_SCLN TD(TD_COLONS)
#define SFT_CAP TD(TD_SHIFT_CAPS)
#define TD_QUOT TD(TD_QUOTES)
#define TD_RAIS TD(TD_RAISE)
#define TD_CURL TD(TD_CURLY_BRACES)
#define TD_SQUR TD(TD_SQUARE_BRACES)
#define TD_ACC  TD(TD_ACCENTS)

#define SF_LEAD LSFT(KC_LEAD)

// #define RAISE   TD(TD_RAISE)
#define SFT_SPC SFT_T(KC_SPC)
#define ALT_LFT LALT_T(KC_LEFT)

#define AUD_SWI LCTL(LALT(KC_F12))
#define FRC_RLD LCTL(LSFT(KC_R))

#define isShifted get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);


