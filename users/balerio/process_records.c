#include "balerio.h"
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }
__attribute__((weak)) bool matrix_init_keymap(void) { return true; }
__attribute__((weak)) bool matrix_scan_keymap(void) { return true; }
// __attribute__((weak)) void matrix_render_keymap(struct CharacterMatrix *matrix) { return true; }

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

#ifdef AUDIO_ENABLE
#    include "muse.h"

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool     is_alt_tab_active = false;
uint16_t alt_tab_timer     = 0;
uint16_t copy_paste_timer;

bool was_raise_last = false;
uint16_t raise_timer;
bool was_lower_last = false;
uint16_t lower_timer;
bool was_F_last = false;
uint16_t F_timer;

uint16_t accent_timer;

bool LShiftPressed = false;
bool RShiftPressed = false;

bool process_record_italian(uint16_t keycode, keyrecord_t *record) {
    // bool isShiftPressed = get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT) || LShiftPressed || RShiftPressed;
    switch (keycode){
        case IT_2:
            if (record->event.pressed) {
                if (LShiftPressed || RShiftPressed){
                    unregister_code(keycode);
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    register_code(KC_ALGR);
                    register_code(IT_OGRV);
                    return false;
                }
            }else{
                unregister_code(keycode);
                unregister_code(KC_ALGR);
                unregister_code(IT_OGRV);
                    if(LShiftPressed){
                        register_code(KC_LSHIFT);
                    }
                    if(RShiftPressed){
                        register_code(KC_RSHIFT);
                    }
                return false;
            }
            break;
        case IT_3:
            if (record->event.pressed) {
                if (LShiftPressed || RShiftPressed){
                    unregister_code(keycode);
                    unregister_code(KC_LSHIFT);
                    unregister_code(KC_RSHIFT);
                    register_code(KC_ALGR);
                    register_code(IT_AGRV);
                    return false;
                }
            }else{
                unregister_code(keycode);
                unregister_code(KC_ALGR);
                unregister_code(IT_AGRV);
                    if(LShiftPressed){
                        register_code(KC_LSHIFT);
                    }
                    if(RShiftPressed){
                        register_code(KC_RSHIFT);
                    }
                return false;
            }
            break;
        case IT_6:
            if (record->event.pressed) {
                if (LShiftPressed || RShiftPressed){
                    unregister_code(keycode);
                    register_code(IT_IGRV);
                    return false;
                }
            }else{
                unregister_code(keycode);
                unregister_code(IT_IGRV);
                return false;
            }
            break;
        case IT_7:
            if (record->event.pressed) {
                if (LShiftPressed || RShiftPressed){
                    unregister_code(keycode);
                    register_code(IT_6);
                    return false;
                }
            }else{
                unregister_code(keycode);
                unregister_code(IT_6);
                return false;
            }
            break;
        case IT_9:
            if (record->event.pressed) {
                if (LShiftPressed || RShiftPressed){
                    unregister_code(keycode);
                    register_code(IT_8);
                    return false;
                }
            }else{
                unregister_code(keycode);
                unregister_code(IT_8);
                return false;
            }
            break;
        case IT_0:
            if (record->event.pressed) {
                if (LShiftPressed || RShiftPressed){
                    unregister_code(keycode);
                    register_code(IT_9);
                    return false;
                }
            }else{
                unregister_code(keycode);
                unregister_code(IT_9);
                return false;
            }
            break;
        case IT_8:
            if (record->event.pressed) {
                if (LShiftPressed || RShiftPressed){
                    unregister_code(keycode);
                    register_code(IT_IGRV);
                    return false;
                }
            }else{
                unregister_code(keycode);
                unregister_code(IT_PLUS);
                return false;
            }
            break;
        case CU_SCLN:
            if (record->event.pressed) {
                if (isShifted) {
                    register_code16(IT_COLN);
                } else {
                    register_code16(IT_SCLN);
                }
            } else {
                unregister_code16(IT_COLN);
                unregister_code16(IT_SCLN);
            }
            return false;
            break;

        case CU_COMM:
            if (record->event.pressed) {
                if (isShifted) {
                    unregister_code16(KC_LSFT);
                    register_code16(IT_LESS);
                    register_code16(KC_LSFT);
                } else {
                    register_code16(IT_COMM);
                }
            } else {
                unregister_code16(IT_LESS);
                unregister_code16(IT_COMM);
            }
            return false;
            break;

        case CU_DOT:
            if (record->event.pressed) {
                if (isShifted) {
                    register_code16(IT_MORE);
                } else {
                    register_code16(IT_DOT);
                }
            } else {
                unregister_code16(IT_MORE);
                unregister_code16(IT_DOT);
            }
            return false;
            break;

        case CU_SLSH:
            if (record->event.pressed) {
                if (isShifted) {
                    register_code16(IT_QST);
                } else {
                    register_code16(IT_SLSH);
                }
            } else {
                unregister_code16(IT_QST);
                unregister_code16(IT_SLSH);
            }
            return false;
            break;
        case CU_QUOT:
            if (record->event.pressed) {
                if (isShifted) {
                    register_code16(IT_DQUO);
                } else {
                    register_code16(IT_QUOT);
                }
            } else {
                unregister_code16(IT_DQUO);
                unregister_code16(IT_QUOT);
            }
            return false;
            break;


        case CU_GRV:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_9) SS_TAP(X_KP_6)));
            }
            break;
        case CU_TILD:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_6)));
            }
            break;

        // case CU_A:
        //     if(record->event.pressed){
        //         accent_timer = timer_read();
        //         register_code16(IT_A);
        //     }else{
        //         unregister_code16(IT_A);
        //         if (timer_elapsed(accent_timer) > TAPPING_TERM && timer_elapsed(accent_timer) < (TAPPING_TERM * 2)) {
        //             tap_code16(KC_BSPC);
        //             tap_code16(IT_AGRV);
        //             unregister_code16(IT_AGRV);
        //         }
        //     }
        //     break;
        // case CU_E:
        //     if(record->event.pressed){
        //         accent_timer = timer_read();
        //         register_code16(IT_E);
        //     }else{
        //         unregister_code16(IT_E);
        //         if (timer_elapsed(accent_timer) > TAPPING_TERM && timer_elapsed(accent_timer) < (TAPPING_TERM * 2)) {
        //             tap_code16(KC_BSPC);
        //             tap_code16(IT_EGRV);
        //         }
        //     }
        //     break;
        // case CU_I:
        //     if(record->event.pressed){
        //         accent_timer = timer_read();
        //         register_code16(IT_I);
        //     }else{
        //         unregister_code16(IT_I);
        //         if (timer_elapsed(accent_timer) > TAPPING_TERM && timer_elapsed(accent_timer) < (TAPPING_TERM * 2)) {
        //             tap_code16(KC_BSPC);
        //             tap_code16(IT_IGRV);
        //         }
        //     }
        //     break;
        // case CU_O:
        //     if(record->event.pressed){
        //         accent_timer = timer_read();
        //         register_code16(IT_O);
        //     }else{
        //         unregister_code16(IT_O);
        //         if (timer_elapsed(accent_timer) > TAPPING_TERM && timer_elapsed(accent_timer) < (TAPPING_TERM * 2)) {
        //             tap_code16(KC_BSPC);
        //             tap_code16(IT_OGRV);
        //         }
        //     }
        //     break;
        // case CU_U:
        //     if(record->event.pressed){
        //         accent_timer = timer_read();
        //         register_code16(IT_U);
        //     }else{
        //         unregister_code16(IT_U);
        //         if (timer_elapsed(accent_timer) > TAPPING_TERM && timer_elapsed(accent_timer) < (TAPPING_TERM * 2)) {
        //             tap_code16(KC_BSPC);
        //             tap_code16(IT_IGRV);
        //         }
        //     }
        //     break;
        // case CU_P:
        //     if(record->event.pressed){
        //         accent_timer = timer_read();
        //         register_code16(IT_P);
        //     }else{
        //         unregister_code16(IT_P);
        //         if (timer_elapsed(accent_timer) > TAPPING_TERM && timer_elapsed(accent_timer) < (TAPPING_TERM * 2)) {
        //             tap_code16(KC_BSPC);
        //             tap_code16(IT_EURO);
        //         }
        //     }
        //     break;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef OLED_DRIVER_ENABLE
        process_record_user_oled(keycode, record);
    #endif
    if(record->event.pressed){
        was_lower_last = false;
        was_raise_last = false;
    }


    LShiftPressed = get_mods() & MOD_BIT(KC_LSHIFT);
    RShiftPressed = get_mods() & MOD_BIT(KC_RSHIFT);
    if(!process_record_keymap(keycode, record)){ return false; };
    if(!process_record_italian(keycode, record)){ return false; };
    switch (keycode) {
        case SFT_CAP:
        case SFT_ENT:
            if (record->event.pressed){
                LShiftPressed = true;
            }else{
                LShiftPressed = false;
            }

            break;
        case TD_SCLN:
            if (record->event.pressed) {
                if(LShiftPressed || RShiftPressed){
                    register_code16(IT_COLN);
                    return false;
                }
            }else{
                unregister_code16(IT_COLN);
            }
            break;

        case LOWER:
            if (record->event.pressed) {
                lower_timer = timer_read();
                was_lower_last = true;
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);

                if (was_lower_last && timer_elapsed(lower_timer) < TAPPING_TERM) {
                    tap_code16(KC_DEL);
                }
            }
            break;
        case RAISE:
            if (record->event.pressed) {
                raise_timer = timer_read();
                was_raise_last = true;
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
                if (was_raise_last && timer_elapsed(raise_timer) < TAPPING_TERM) {
                    tap_code16(KC_TAB);
                }
            }
            break;
        case FLEAD:
            if (record->event.pressed) {
                F_timer = timer_read();
                was_F_last = true;
                layer_on(_F);
            } else {
                layer_off(_F);
                if (was_F_last && timer_elapsed(F_timer) < TAPPING_TERM) {
                    tap_code16(KC_LEAD);
                }
            }
            break;


        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;

        case KC_CCCV:  // One key copy/paste
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold, copy
                    register_code(KC_LCTL);
                    tap_code(KC_C);
                    unregister_code(KC_LCTL);
                } else {  // Tap, paste
                    register_code(KC_LCTL);
                    tap_code(KC_V);
                    unregister_code(KC_LCTL);
                }
            }
            break;
            case KC_MAKE:

                if (!record->event.pressed) {
                    send_string_with_delay_P(PSTR("qmk flash /kb " QMK_KEYBOARD " /km " QMK_KEYMAP), MACRO_TIMER);
                }

            break;


    }
    return true;
}


void matrix_init_user(void){
    matrix_init_keymap();
}

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    // keyboard_post_init_rgb_lights();
#endif
}

LEADER_EXTERNS();

void matrix_scan_user(void) {

    matrix_scan_keymap();

    if (is_alt_tab_active && timer_elapsed(alt_tab_timer) > 1000) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
    }
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    }
    SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
      SEND_STRING("https://start.duckduckgo.com\n");
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}

// uint32_t layer_state_set_user(uint32_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        //   #ifdef MOUSEKEY_ENABLE
        //     tap_code(KC_MS_WH_DOWN);
        //   #else
        // tap_code(KC_PGDN);
        tap_code(KC_VOLU);
        //   #endif
    } else {
        //   #ifdef MOUSEKEY_ENABLE
        //     tap_code(KC_MS_WH_UP);
        //   #else
        // tap_code(KC_PGUP);
        tap_code(KC_VOLD);
        //   #endif
    }
}

#endif


uint32_t layer_state_set_user(uint32_t state) {

    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
#ifdef RGBLIGHT_ENABLE
    // state = layer_state_set_rgb(state);
#endif
    return state;
}

void suspend_power_down_user(void) {
    #ifdef RGB_MATRIX_ENABLE
        rgb_matrix_set_suspend_state(true);
    #endif
}

void suspend_wakeup_init_user(void) {
    #ifdef RGB_MATRIX_ENABLE
        rgb_matrix_set_suspend_state(false);
    #endif
}



bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case D_PAD:
        case F_VIM:
            return true;
        default:
            return false;
    }
}
