#include "tap_dances.h"

int cur_dance(qk_tap_dance_state_t *state);

void colons_oneach(qk_tap_dance_state_t *state, void *user_data);
void colons_finished(qk_tap_dance_state_t *state, void *user_data);
void colons_reset(qk_tap_dance_state_t *state, void *user_data);

void quotes_oneach(qk_tap_dance_state_t *state, void *user_data);
void quotes_finished(qk_tap_dance_state_t *state, void *user_data);
void quotes_reset(qk_tap_dance_state_t *state, void *user_data);

void raise_finished(qk_tap_dance_state_t *state, void *user_data);
void raise_reset(qk_tap_dance_state_t *state, void *user_data);

void curly_braces_finished(qk_tap_dance_state_t *state, void *user_data);
void curly_braces_reset(qk_tap_dance_state_t *state, void *user_data);

void square_braces_finished(qk_tap_dance_state_t *state, void *user_data);
void square_braces_reset(qk_tap_dance_state_t *state, void *user_data);

void accents_oneach(qk_tap_dance_state_t *state, void *user_data);
void accents_finished(qk_tap_dance_state_t *state, void *user_data);
void accents_reset(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
    // [TD_SEMICOLON_COLON]    = ACTION_TAP_DANCE_DOUBLE(IT_SCLN, IT_COLN),
    // [TD_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_COLONS]     = ACTION_TAP_DANCE_FN_ADVANCED(colons_oneach, colons_finished, colons_reset),
    [TD_QUOTES]     = ACTION_TAP_DANCE_FN_ADVANCED(quotes_oneach, quotes_finished, quotes_reset),
    [TD_ACCENTS]     = ACTION_TAP_DANCE_FN_ADVANCED(accents_oneach, accents_finished, accents_reset),
    //   [TD_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,right_shift_finished, right_shift_reset),
    // [TD_RAISE]        = ACTION_TAP_DANCE_FN_ADVANCED(NULL, raise_finished, raise_reset),
    // [TD_CURLY_BRACES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, curly_braces_finished, curly_braces_reset),
    // //   [TD_ROUND_PAREN],
    // [TD_SQUARE_BRACES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, square_braces_finished, square_braces_reset)
    //   [TD_LESS_MORE]
};
typedef struct {
    bool is_press_action;
    int  state;
    bool is_shift_pressed;
} tap;

enum {
    SINGLE_TAP        = 1,
    SINGLE_HOLD       = 2,
    DOUBLE_TAP        = 3,
    DOUBLE_HOLD       = 4,
    DOUBLE_SINGLE_TAP = 5,  // send two single taps
    TRIPLE_TAP        = 6,
    TRIPLE_HOLD       = 7
};

int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        /*
         * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
         * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
         * keystrokes of the key, and not the 'double tap' action/macro.
         */
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TRIPLE_TAP;
        else
            return TRIPLE_HOLD;
    } else
        return 8;  // magic number. At some point this method will expand to work for more presses
}

// ----- QUOTES TAP -----
static tap quotes_tap_state = {.is_press_action = true, .state = 0, .is_shift_pressed = false};

void quotes_oneach(qk_tap_dance_state_t *state, void *user_data){
                quotes_tap_state.is_shift_pressed = isShifted;
}
void quotes_finished(qk_tap_dance_state_t *state, void *user_data) {
    quotes_tap_state.state = cur_dance(state);
    switch (quotes_tap_state.state) {
        case SINGLE_TAP:
            if (quotes_tap_state.is_shift_pressed) {
                bool leftShift = get_mods() & MOD_BIT(KC_LSHIFT);
                bool rightShift = get_mods() & MOD_BIT(KC_RSHIFT);
                unregister_code(KC_LSHIFT);
                unregister_code(KC_RSHIFT);
                register_code16(IT_DQUO);
                if(leftShift) { register_code(KC_LSHIFT);};
                if(rightShift) { register_code(KC_RSHIFT);};

            } else {
                register_code16(IT_QUOT);
            }
            break;
        case SINGLE_HOLD:
            // register_code(KC_RALT);
            layer_on(_ACCENTS);
            break;
        case DOUBLE_TAP:
            register_code(KC_LSHIFT);
            register_code(IT_2);
            break;
        case DOUBLE_HOLD:
            register_code(KC_RALT);
            // register_code(KC_RGUI);
            break;
        case DOUBLE_SINGLE_TAP: // A key has been pressed before the tapping_term after double tap
            register_code16(IT_QUOT);
            unregister_code16(IT_QUOT);
            register_code16(IT_QUOT);
    }
}

void quotes_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (quotes_tap_state.state) {
        case SINGLE_TAP:
            unregister_code16(IT_DQUO);
            unregister_code16(IT_QUOT);
            break;
        case SINGLE_HOLD:
            layer_off(_ACCENTS);
            // unregister_code(KC_RALT);
            break;
        case DOUBLE_TAP:
            unregister_code16(IT_SLSH);
            unregister_code(IT_2);
            unregister_code(KC_LSHIFT);
            break;
        case DOUBLE_HOLD:
            unregister_code(KC_RALT);
            // unregister_code(KC_RGUI);
        case DOUBLE_SINGLE_TAP:
            unregister_code(KC_QUOTE);
    }
    quotes_tap_state.state = 0;
}
// ---------------------------

// ----- COLONS TAP -----
static tap colons_tap_state = {.is_press_action = true, .state = 0, .is_shift_pressed = false};

void colons_oneach(qk_tap_dance_state_t *state, void *user_data){
                colons_tap_state.is_shift_pressed = isShifted;
}

void colons_finished(qk_tap_dance_state_t *state, void *user_data) {
    colons_tap_state.state = cur_dance(state);
    switch (colons_tap_state.state) {
        case SINGLE_TAP:
        case SINGLE_HOLD:
            if (colons_tap_state.is_shift_pressed) {
                register_code16(IT_COLN);
            } else {
                register_code16(IT_SCLN);
            }
            break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP:
            register_code16(IT_COLN);
            break;
    }
}

void colons_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (colons_tap_state.state) {
        case SINGLE_TAP:
        case SINGLE_HOLD:
            unregister_code16(IT_COLN);
            unregister_code16(IT_SCLN);
            break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP:
            unregister_code16(IT_COLN);
            break;
    }
    colons_tap_state.state = 0;
}


static tap accents_tap_state = {.is_press_action = true, .state = 0, .is_shift_pressed = false};

void accents_oneach(qk_tap_dance_state_t *state, void *user_data){
                accents_tap_state.is_shift_pressed = isShifted;
}

void accents_finished(qk_tap_dance_state_t *state, void *user_data) {
    accents_tap_state.state = cur_dance(state);
    switch (accents_tap_state.state) {
        case SINGLE_HOLD:
            layer_on(_ACCENTS);
            break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_CAPS);
            break;
    }
}

void accents_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (accents_tap_state.state) {
        case SINGLE_HOLD:
            layer_off(_ACCENTS);
            break;
    }
    accents_tap_state.state = 0;
}

// ---------------------------

// // ----- START RAISE ------

// static tap raise_tap_state = {.is_press_action = true, .state = 0};

// void raise_finished(qk_tap_dance_state_t *state, void *user_data) {
//     raise_tap_state.state = cur_dance(state);
//     switch (raise_tap_state.state) {
//         case SINGLE_TAP:
//             register_code(KC_TAB);
//             break;
//         case SINGLE_HOLD:
//             layer_on(_RAISE);
//             break;
//         case DOUBLE_TAP:
//             register_code(KC_LSHIFT);
//             register_code(KC_QUOTE);
//             break;
//         case DOUBLE_HOLD:
//             layer_on(_VIM);
//             break;
//     }
// }

// void raise_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (raise_tap_state.state) {
//         case SINGLE_TAP:
//             unregister_code(KC_TAB);
//             break;
//         case SINGLE_HOLD:
//             layer_off(_RAISE);
//             break;
//         case DOUBLE_TAP:
//             unregister_code(KC_QUOTE);
//             unregister_code(KC_LSHIFT);
//             break;
//         case DOUBLE_HOLD:
//             layer_off(_VIM);
//     }
//     raise_tap_state.state = 0;
// }
// // ----- END RAISE ------

// // ----- START CURLY BRACES ------
// static tap curly_tap_state = {.is_press_action = true, .state = 0};
// void       curly_braces_finished(qk_tap_dance_state_t *state, void *user_data) {
//     curly_tap_state.state = cur_dance(state);
//     switch (curly_tap_state.state) {
//         case SINGLE_TAP:
//             register_code(KC_LSHIFT);
//             register_code(KC_LBRC);
//             break;
//         case DOUBLE_TAP:
//             register_code(KC_LSHIFT);
//             register_code(KC_RBRC);
//             break;
//     }
// }

// void curly_braces_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (curly_tap_state.state) {
//         case SINGLE_TAP:
//             unregister_code(KC_LBRC);
//             unregister_code(KC_LSHIFT);
//             break;
//         case DOUBLE_TAP:
//             unregister_code(KC_RBRC);
//             unregister_code(KC_LSHIFT);
//             break;
//     }
//     curly_tap_state.state = 0;
// }
// // ----- END CURLY BRACES ------

// // ----- START SQUARE BRACES ------
// static tap square_tap_state = {.is_press_action = true, .state = 0};
// void       square_braces_finished(qk_tap_dance_state_t *state, void *user_data) {
//     square_tap_state.state = cur_dance(state);
//     switch (square_tap_state.state) {
//         case SINGLE_TAP:
//             register_code(KC_LBRC);
//             break;
//         case DOUBLE_TAP:
//             register_code(KC_RBRC);
//             break;
//     }
// }

// void square_braces_reset(qk_tap_dance_state_t *state, void *user_data) {
//     switch (square_tap_state.state) {
//         case SINGLE_TAP:
//             unregister_code(KC_LBRC);
//             break;
//         case DOUBLE_TAP:
//             unregister_code(KC_RBRC);
//             break;
//     }
//     square_tap_state.state = 0;
// }
// // ----- END CURLY BRACES ------
