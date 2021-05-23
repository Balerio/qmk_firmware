

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

int RGB_current_mode;

void matrix_init_keymap(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_keymap(void) {
   iota_gfx_task();
}
// const char *read_layer_state_old(void) {
//   uint8_t layer = biton32(layer_state);

//   strcpy(matrix_line_str, "Layer: ");
//   char* layer_names[] = { "Default", "Lower", "Raise", "Vim", "Games", "F", "Adjust" };
//   if(layer < 5){
//       strcat(matrix_line_str, layer_name[layer]);
//   } else {
//       sprintf(matrix_line_str + strlen(matrix_line_str), "Unknown (%d)", layer);
//   }
//   return matrix_line_str;
// }
void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    #ifdef SSD1306OLED
        set_keylog(keycode, record);
    #endif
    // set_timelog();
  }
  return true;
}
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
//     #ifdef SSD1306OLED
//         set_keylog(keycode, record);
//     #endif
//     // set_timelog();
//   }

//   switch (keycode) {
//     // case QWERTY:
//     //   if (record->event.pressed) {
//     //     persistent_default_layer_set(1UL<<_QWERTY);
//     //   }
//     //   return false;
//     // case LOWER:
//     //   if (record->event.pressed) {
//     //     layer_on(_LOWER);
//     //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
//     //   } else {
//     //     layer_off(_LOWER);
//     //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
//     //   }
//     //   return false;
//     // case RAISE:
//     //   if (record->event.pressed) {
//     //     layer_on(_RAISE);
//     //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
//     //   } else {
//     //     layer_off(_RAISE);
//     //     update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
//     //   }
//     //   return false;
//     // case ADJUST:
//     //     if (record->event.pressed) {
//     //       layer_on(_ADJUST);
//     //     } else {
//     //       layer_off(_ADJUST);
//     //     }
//     //     return false;
//       #ifdef RGBLIGHT_ENABLE
//     case RGB_MOD:
//         if (record->event.pressed) {
//           rgblight_mode(RGB_current_mode);
//           rgblight_step();
//           RGB_current_mode = rgblight_config.mode;
//         }
//       return false;
//       #endif
//     // case RGBRST:
//     //    #ifdef RGB_MATRIX_ENABLE
//     //     if (record->event.pressed) {
//     //       eeconfig_update_rgb_matrix_default();
//     //       rgblight_enable();
//     //     //   RGB_current_mode = rgblight_config.mode;
//     //     }
//     //    #endif
//     //   break;
//     // case LT_SING:
//     // #ifdef RGB_MATRIX_ENABLE
//     //     rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
//     //     rgb_matrix_set_color_all(0, 0, 0);
//     //     rgb_matrix_set_color_all(0, 0, 200);
//     //     rgb_matrix_set_color(17, 200, 0, 0);
//     //     rgb_matrix_set_color(19, 200, 0, 0);
//     //     rgb_matrix_set_color(20, 200, 0, 0);
//     //     rgb_matrix_set_color(23, 200, 0, 0);
//     // #endif
//     // break;
//   };
//   return true;
// }
