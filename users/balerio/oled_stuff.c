#include "balerio.h"
#include "oled_stuff.h"

extern uint8_t is_master;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_master) {
        return OLED_ROTATION_270;
    }
    return OLED_ROTATION_180;
}

static uint32_t oled_timer = 0;
bool process_record_user_oled(uint16_t keycode, keyrecord_t *record) {
    oled_timer = timer_read32();
    return true;
}




void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR(" NUM "), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR(" CAP "), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR(" SCR "), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
    oled_write_P(PSTR("-----"), false);

    // oled_write_P(PSTR("-----"), false);
    // oled_write_P(PSTR("N"), led_usb_state & (1 << USB_LED_NUM_LOCK));
    // oled_write_P(PSTR(" "), false);
    // oled_write_P(PSTR("C"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    // oled_write_P(PSTR(" "), false);
    // oled_write_P(PSTR("S"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
    // oled_write_P(PSTR("-----"), false);
}

void render_layer_state(void) {
    oled_write_P(PSTR("LOWER"), layer_state_is(_LOWER));
    oled_write_P(PSTR("RAISE"), layer_state_is(_RAISE));
    oled_write_P(PSTR(" NAV "), layer_state_is(_VIM));
    oled_write_P(PSTR("N PAD"), layer_state_is(_PAD_R));
    oled_write_P(PSTR("GAMES"), layer_state_is(_GAMES));
    oled_write_P(PSTR("FUNCT"), layer_state_is(_F));
    oled_write_P(PSTR(" ADJ "), layer_state_is(_ADJUST));
    oled_write_P(PSTR("-----"), false);
}

__attribute__((weak)) void oled_driver_render_logo(void) {
    // clang-format off
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    // clang-format on
    oled_write_P(qmk_logo, false);
}

void render_status_main(void) {
    render_keylock_status(host_keyboard_leds());
    render_layer_state();
}

void render_status_secondary(void) { oled_driver_render_logo(); }

void            oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > OLED_OFF_TIMEOUT) {
        oled_off();
        return;
    }
#ifndef SPLIT_KEYBOARD
    else {
        oled_on();
    }
#endif

    if (is_master) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}
