#include QMK_KEYBOARD_H
#include "../../keycodes.h"

#ifdef OLED_ENABLE
#include "features/oled/bocchi.h"

led_t led_usb_state = {
    .num_lock = false,
    .caps_lock = false,
    .scroll_lock = false
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return OLED_ROTATION_270;
}

void oled_render_layer_state(void) {
    oled_write_ln_P(PSTR("Layer"), false);
    switch (get_highest_layer(default_layer_state | layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWRTY"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("COLMK"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("GAME "), false);
            break;
        case _NUM:
            oled_write_P(PSTR(" NUM "), false);
            break;
        case _SYM:
            oled_write_P(PSTR(" SYM "), false);
            break;
        case _NAV:
            oled_write_P(PSTR(" NAV "), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("MEDIA"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("MOUSE"), false);
            break;
        case _FUN:
            oled_write_P(PSTR(" FUN "), false);
            break;
        default:
            oled_write_P(PSTR("UNDEF"), false);
    }

    oled_write_ln_P(PSTR("-----"), false);
    oled_write_ln_P(PSTR("Stats"), false);
    oled_write_P(PSTR("CAP:"), false);

    if (led_usb_state.caps_lock) {
        oled_write_ln_P(PSTR("L"), false);
    } else if (is_caps_word_on()) {
        oled_write_ln_P(PSTR("W"), false);
    } else {
        oled_write_ln_P(PSTR("-"), false);
    }
}

void oled_render_wpm(void) {
    oled_write_P(PSTR("WPM: "), false);

    char wpm[6];
    itoa(get_current_wpm(), wpm, 10);
    oled_write_ln(wpm, false);
}

bool oled_task_user(void) {
    led_usb_state = host_keyboard_led_state();
    if (is_keyboard_master()) {
        oled_render_layer_state();
        render_bocchi(0, 10);
    } else {
        render_bocchi_logo();
    }
    return false;
}

#endif  // OLED_ENABLE
