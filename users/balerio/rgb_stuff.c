#include "rgb_stuff.h"

// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM caps_lock[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 26, HSV_RED}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 2, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 21, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM game_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 26, HSV_RED}
);
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 3, HSV_RED}
);
// etc..
// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    caps_lock,
    lower_layer,
    raise_layer,
    game_layer,
    adjust_layer
);

 void keyboard_post_init_rgb_lights(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}


layer_state_t layer_state_set_rgb(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _GAMES));
    rgblight_set_layer_state(4, layer_state_cmp(state, _ADJUST));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

// #ifdef RGBLIGHT_ENABLE
// extern rgblight_config_t rgblight_config;
// #endif

// uint32_t layer_state_set_user(uint32_t state) {
//     state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

// #ifdef RGBLIGHT_ENABLE
//     static uint8_t prev  = -1;
//     uint8_t        layer = biton32(state);

//     if (prev != layer) {
//         switch (layer) {
//             case _GAMES:
//                 rgblight_mode_noeeprom(1);
//                 // rgblight_sethsv_noeeprom(240, rgblight_config.sat, rgblight_config.val);
//                 rgblight_sethsv_noeeprom(240, rgblight_config.sat, 0);
//                 rgblight_sethsv_at(0, rgblight_config.sat, 100, 16);
//                 rgblight_sethsv_at(0, rgblight_config.sat, 100, 18);
//                 rgblight_sethsv_at(0, rgblight_config.sat, 100, 19);
//                 rgblight_sethsv_at(0, rgblight_config.sat, 100, 22);
//                 // rgblight_sethsv_slave(240, rgblight_config.sat, rgblight_config.val);
//                 break;

//             case _LOWER:
//                 rgblight_mode_noeeprom(1);
//                 rgblight_sethsv_noeeprom(55, rgblight_config.sat, rgblight_config.val);
//                 break;

//             default:
//                 rgblight_config.raw = eeconfig_read_rgblight();
//                 rgblight_mode_noeeprom(rgblight_config.mode);
//                 rgblight_sethsv_noeeprom(rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
//                 break;
//         }
//     }

//     prev = layer;
// #endif
//     return state;
// }
