/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2023 @elianiva

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum layer_names {
    _QWERTY,
    _COLEMAK,
    _GAMING,
    _NUM,
    _NAV,
    _MEDIA,
    _MOUSE,
    _SYM,
    _FUN,
};

// HOLD MODIFIERS
#define TAB_NAV LT(_NAV, KC_TAB)
#define DEL_FUN LT(_FUN, KC_DEL)
#define BSPC_NUM LT(_NUM, KC_BSPC)
#define ESC_MEDIA LT(_MEDIA, KC_ESC)
#define ENT_MOUSE LT(_MOUSE, KC_ENT)
#define SPC_SYM LT(_SYM, KC_SPC)

// QMK ALIAS
#define KC_CAPW QK_CAPS_WORD_TOGGLE

// HOME ROW MODS
// LEFT - QWERTY
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)
// LEFT - COLEMAK
#define ALT_R LALT_T(KC_R)
#define CTL_S LCTL_T(KC_S)
#define SHFT_T LSFT_T(KC_T)
// RIGHT - QWERTY
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_QUOT RGUI_T(KC_QUOT)
// RIGHT - COLEMAK
#define SFT_N RSFT_T(KC_N)
#define CTL_E RCTL_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

// Layer Toggle
#define L_QWERTY TG(_QWERTY)
#define L_COLEMAK TG(_COLEMAK)
#define L_GAMING TG(_GAMING)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   GUI_A,   ALT_S,   CTL_D,   SFT_F,    KC_G,                         KC_H,   SFT_J,   CTL_K,   ALT_L,GUI_QUOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        ESC_MEDIA,TAB_NAV,ENT_MOUSE,    SPC_SYM,BSPC_NUM, DEL_FUN
                                      //`--------------------------'  `--------------------------'
  ),

    [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   GUI_A,   ALT_R,   CTL_S,  SHFT_T,    KC_G,                         KC_M,   SFT_N,   CTL_E,   ALT_I,   GUI_O, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        ESC_MEDIA,TAB_NAV,ENT_MOUSE,    SPC_SYM,BSPC_NUM, DEL_FUN
                                      //`--------------------------'  `--------------------------'
  ),

    [_GAMING] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        ESC_MEDIA,TAB_NAV,ENT_MOUSE,    SPC_SYM,BSPC_NUM, DEL_FUN
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_DOT,    KC_0, KC_MINS,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                     XXXXXXX,L_QWERTY,L_COLEMAK,L_GAMING, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, XXXXXXX,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_APP,  KC_TAB, KC_ENT,    KC_SPC,  KC_BSPC,  KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LPRN, KC_RPRN, KC_UNDS,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_PASTE, KC_COPY, KC_CUT, KC_CAPW, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_CAPS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_SPC,  KC_BSPC,  KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0,                      XXXXXXX, KC_PASTE, KC_COPY, KC_CUT, XXXXXXX, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_ACL1,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MNXT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, KC_ACL2,                      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_BTN1, KC_BTN2, KC_BTN3
                                      //`--------------------------'  `--------------------------'
  ),

  [_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_TOG, RGB_HUD, RGB_HUI, RGB_MOD,RGB_RMOD, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      RGB_VAI, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_VAD, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_MSTP, KC_MPLY, KC_MUTE
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }
    return true;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_A:
        case GUI_QUOT:
            return false;
        default:
            return true;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_F:
        case SFT_J:
            return TAPPING_TERM - 50;
        case GUI_A:
        case GUI_QUOT:
            return TAPPING_TERM + 200;
        default:
            return TAPPING_TERM;
    }
}

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally consider the following chords as holds, even though they're the same hand
    // I want to be able to press these chords with the same hand.
    switch (tap_hold_keycode) {
        case CTL_D: // ctrl+s, ctrl+f, ctrl+c, ctrl+v
            if (other_keycode == SFT_F || other_keycode == ALT_S || other_keycode == KC_C || other_keycode == KC_V) {
                return true;
            }
            break;
    }

    // Also allow same-hand holds when the other key is in the rows below the
    // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
    if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 3) {
        return true;
    }

    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LSFT:
        case MOD_RSFT:
        case MOD_LCTL:
        case MOD_RCTL:
            return true; // Eagerly apply Shift and Ctrl mods.
        default:
            return false;
    }
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case TAB_NAV:
        case ESC_MEDIA:
        case ENT_MOUSE:
        case SPC_SYM:
        case BSPC_NUM:
        case DEL_FUN:
        case SFT_F:
        case SFT_J:
            return 0;
    }
    return 1000;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_270; // flips the display 180 degrees if offhand
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

    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock) {
        oled_write_ln_P(PSTR("L"), false);
    } else if (is_caps_word_on()) {
        oled_write_ln_P(PSTR("W"), false);
    } else {
        oled_write_ln_P(PSTR("-"), false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

#define FRAME_SIZE 128
#define FRAME_DURATION 200
#define FRAME_X 0
#define FRAME_Y 10
#define FRAME_COUNT 12

uint8_t current_frame = 0;
uint8_t anim_timer = 0;

static void render_bocchi(void) {
    static const char PROGMEM bocchi[FRAME_COUNT][FRAME_SIZE] = {{0xff, 0x7f, 0xff, 0xff, 0x1f, 0x0f, 0x7f, 0xfd, 0xf7, 0xbf, 0xff, 0xff, 0xff, 0xfd, 0xf3, 0xc6, 0x0c, 0x99, 0x99, 0x99, 0x8f, 0xe7, 0xf6, 0xf7, 0xf1, 0xf9, 0x79, 0x03, 0x8f, 0xee, 0xfd, 0xdb, 0xbf, 0xfc, 0x07, 0x3f, 0x30, 0x38, 0x1e, 0x8e, 0xd5, 0xfb, 0xfa, 0x73, 0x03, 0x87, 0xef, 0xff, 0xcd, 0xc1, 0xf3, 0xf3, 0x33, 0x33, 0x33, 0x3b, 0x79, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xf9, 0xf0, 0x1f, 0xbf, 0xdf, 0xdf, 0xcf, 0xef, 0xf7, 0xf1, 0xf8, 0xfe, 0x8f, 0x8f, 0x8f, 0xc1, 0xe0, 0x79, 0xbd, 0xfe, 0xf7, 0xfb, 0xfb, 0x7a, 0x3f, 0x9f, 0xdf, 0xdf, 0xcf, 0xef, 0xe3, 0xff, 0xef, 0xff, 0xff, 0xff, 0x7f, 0xfc, 0xf9, 0xf7, 0xcf, 0x9f, 0x3f, 0x7f, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x9f, 0xcf, 0xf7, 0xf3, 0xf9, 0xfc, 0xfe, 0x7f, 0x1f, 0x8d, 0x8f, 0xc7, 0xc7, 0xc7},
                                                                 {0xff, 0xbf, 0xf3, 0xe7, 0x8f, 0x1f, 0x7d, 0x73, 0xcf, 0x9f, 0xff, 0xff, 0xfd, 0x02, 0x1a, 0x39, 0x39, 0x79, 0x79, 0x7c, 0x7e, 0x7e, 0x3e, 0x3e, 0x9f, 0x80, 0xe1, 0xff, 0xff, 0xf7, 0x8e, 0x3f, 0x3c, 0x0f, 0x07, 0xf3, 0xf9, 0xfc, 0xde, 0xfe, 0x7c, 0x01, 0x80, 0xf9, 0xff, 0xfe, 0xe8, 0xfc, 0x7c, 0x3c, 0x3e, 0x9e, 0xde, 0xce, 0x4f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0xfb, 0xe7, 0xe7, 0xe7, 0x73, 0xf3, 0xf1, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xe3, 0xe1, 0xd9, 0xf8, 0xcc, 0xee, 0xff, 0xff, 0x7d, 0x7e, 0x3f, 0x3f, 0x9f, 0x9f, 0xef, 0xe7, 0xf3, 0xf0, 0xf4, 0xe6, 0xff, 0xff, 0xff, 0xef, 0x7f, 0xdc, 0xb9, 0x73, 0xe7, 0xcf, 0xdf, 0xbf, 0xbf, 0xbf, 0x1f, 0x1f, 0x1f, 0xe7, 0xf9, 0xfc, 0xfe, 0xfe, 0x7f, 0xff, 0xe7, 0xf3, 0xf9, 0xfd, 0xfe, 0xfe, 0xff, 0xf7},
                                                                 {0xef, 0xff, 0xff, 0xf9, 0xe3, 0x1f, 0x7f, 0xf9, 0xf7, 0xcf, 0x3f, 0xff, 0xfd, 0xf3, 0x07, 0x4e, 0xe4, 0xe7, 0xe3, 0xf3, 0xfb, 0xf8, 0x79, 0x3d, 0x1d, 0x0d, 0xc1, 0xf3, 0xf7, 0xef, 0xef, 0x9f, 0xf9, 0x07, 0x9f, 0x9e, 0xcf, 0xcf, 0xc6, 0xf8, 0xfd, 0x3f, 0x07, 0xa8, 0xe3, 0x9f, 0x60, 0xf8, 0xfc, 0x7c, 0x1c, 0x3c, 0xbc, 0x8c, 0x8e, 0x9e, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1b, 0xf4, 0xec, 0xc7, 0x9f, 0x6f, 0xc8, 0xe5, 0xf3, 0xf0, 0xfc, 0xfe, 0xff, 0xf7, 0xe3, 0x90, 0x9c, 0xde, 0xce, 0xee, 0xf7, 0xf9, 0xfe, 0x7f, 0x7f, 0x3f, 0x1f, 0x9f, 0xcf, 0xe3, 0xe1, 0xe4, 0xe7, 0x79, 0xc7, 0x3f, 0xff, 0xfe, 0xf9, 0xe7, 0xdf, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x9f, 0xe3, 0xf1, 0xf9, 0xfc, 0x3e, 0x9e, 0xcf, 0xe7, 0xf3, 0xf9, 0xf9, 0xfd, 0xfc, 0xfe},
                                                                 {0xff, 0xff, 0x1f, 0xff, 0xff, 0xff, 0xc1, 0x0f, 0x3f, 0xff, 0xfb, 0xcf, 0xff, 0xff, 0xff, 0x47, 0x1e, 0xf8, 0xc9, 0xcf, 0xcf, 0xc6, 0xc0, 0xf9, 0xfb, 0xfb, 0xc9, 0x79, 0x3b, 0x0f, 0x1f, 0xaf, 0xff, 0xff, 0x3c, 0x80, 0xcf, 0xcf, 0x47, 0xe6, 0xe3, 0xf1, 0xfd, 0xff, 0x23, 0x0f, 0xc7, 0x70, 0x78, 0x79, 0x3c, 0x1d, 0x0d, 0x89, 0x89, 0x99, 0x99, 0x99, 0xfc, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xf1, 0xbe, 0xc0, 0xf7, 0xe7, 0xb7, 0x66, 0xe7, 0xe7, 0xf7, 0xf3, 0xf9, 0xfc, 0xff, 0xe4, 0xe0, 0xcc, 0xee, 0xe7, 0xf7, 0xf7, 0xf3, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x9f, 0xcf, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xfc, 0xfb, 0xf7, 0xcf, 0x9f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x9f, 0xcf, 0xe7, 0xf3, 0xf9, 0xfb, 0x79, 0xbc, 0xdc, 0xce, 0xee, 0xe4, 0xf7, 0xf7},
                                                                 {0xff, 0xef, 0xff, 0x01, 0x8f, 0x3f, 0xff, 0xf7, 0xff, 0xff, 0xff, 0x01, 0x1e, 0x73, 0x1b, 0x39, 0x3d, 0x39, 0x39, 0x7c, 0x7e, 0x3e, 0x3e, 0x1e, 0x86, 0xc7, 0xf0, 0xf9, 0xf3, 0xe7, 0xcf, 0x1e, 0xb3, 0xcf, 0xc7, 0xc0, 0xe4, 0xfc, 0xfe, 0xfe, 0x7c, 0x01, 0x83, 0xe0, 0xfc, 0xfe, 0xfe, 0x3f, 0x3e, 0x3e, 0x3e, 0x9e, 0x8e, 0x9f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xf3, 0xe7, 0xc7, 0xb7, 0x33, 0x79, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xc3, 0xf1, 0xfc, 0xde, 0xcf, 0xcf, 0xe7, 0xf7, 0xfe, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0xdf, 0xcf, 0xef, 0xe5, 0x7f, 0xfc, 0xe3, 0x9f, 0x3f, 0x7f, 0xfe, 0xfd, 0xfb, 0xe7, 0xcf, 0x9f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0xcf, 0xe7, 0xf3, 0xf9, 0x7c, 0xbe, 0x9e, 0xcf, 0xee, 0xec, 0xf7, 0xf3, 0xf9},
                                                                 {0xff, 0xf3, 0x8f, 0x3f, 0x7b, 0xe7, 0xdf, 0xbf, 0xff, 0xff, 0xff, 0xfb, 0xe6, 0xa6, 0x71, 0xf3, 0xf1, 0xf1, 0xfe, 0xfe, 0x7f, 0x7f, 0x3f, 0x8f, 0xc0, 0xfe, 0xfd, 0xfb, 0xf3, 0xcf, 0x9f, 0x7f, 0x7f, 0x1f, 0x2f, 0xe6, 0xf0, 0x98, 0xbc, 0xf9, 0x03, 0x33, 0xf3, 0xe3, 0xf3, 0xff, 0xe4, 0xfc, 0x7c, 0x3c, 0x1c, 0x1c, 0x9c, 0x9e, 0x9f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x00, 0xde, 0x9e, 0x9f, 0xcf, 0xcf, 0xc7, 0xe3, 0xf1, 0xf8, 0xfe, 0xff, 0xff, 0xc7, 0x83, 0xbb, 0xfc, 0xee, 0xef, 0xe7, 0xf7, 0xf7, 0xf9, 0x7f, 0x3f, 0x9f, 0x1f, 0xcf, 0xcf, 0xe7, 0xf3, 0xf0, 0xf3, 0xdf, 0x9f, 0xbf, 0x7e, 0x7d, 0x7d, 0xfb, 0xf7, 0xe7, 0xef, 0xdf, 0x9f, 0xbf, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0xe7, 0xf3, 0xf9, 0xfc, 0xfe, 0x9f, 0xcf, 0xe7, 0xf3, 0xf9, 0xf9, 0xfc, 0xfe, 0xee},
                                                                 {0x7f, 0xff, 0xff, 0x9f, 0xdf, 0x1f, 0x3e, 0x76, 0x6f, 0xdf, 0xdf, 0xbf, 0xff, 0x7f, 0x7d, 0xeb, 0xe6, 0xe5, 0xf3, 0xf3, 0xf3, 0xfb, 0xf9, 0xfd, 0x78, 0x7d, 0x3c, 0x81, 0xc7, 0xef, 0xc3, 0x9c, 0xef, 0xf1, 0x0f, 0x3f, 0x9f, 0x88, 0xf2, 0xfb, 0xf8, 0xfc, 0x78, 0x10, 0x98, 0xfe, 0xf2, 0xfa, 0xf8, 0xf9, 0xf2, 0xfc, 0x7c, 0x1c, 0x9c, 0x9e, 0x3e, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0x91, 0xf6, 0xcf, 0x9f, 0x8f, 0xc7, 0xc7, 0xe3, 0xf8, 0xfc, 0xfe, 0xff, 0xef, 0x87, 0x87, 0xe3, 0xf3, 0xb9, 0xdc, 0xee, 0xf7, 0xf3, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0xbf, 0x8f, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf9, 0xe7, 0x9f, 0x7f, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x9f, 0xc7, 0xf3, 0xf9, 0xfc, 0xfe, 0x7e, 0x1e, 0xcf, 0xe7, 0xf7, 0xf7, 0xff},
                                                                 {0xff, 0xff, 0xff, 0x07, 0x1f, 0xbf, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf1, 0xc3, 0x06, 0x32, 0x79, 0x7d, 0x79, 0x79, 0x78, 0x7e, 0x3e, 0x3e, 0x1e, 0xc0, 0xff, 0xff, 0xf9, 0xf1, 0xc7, 0x0f, 0x78, 0x3f, 0x1f, 0xe0, 0xf0, 0xf9, 0xfc, 0xfe, 0x7c, 0x01, 0xf1, 0xf9, 0xfb, 0xfb, 0xfb, 0x70, 0x3d, 0x1c, 0x1c, 0x0c, 0x0c, 0x1e, 0x9e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0xc6, 0xee, 0xcf, 0xcf, 0xe7, 0xe3, 0xf1, 0xf0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xe0, 0xd0, 0xd8, 0xdc, 0xdc, 0xec, 0xfe, 0xf6, 0xff, 0x7f, 0x7f, 0x3f, 0xbf, 0x9f, 0xdf, 0xe7, 0xe1, 0xf0, 0xe4, 0xff, 0xef, 0xff, 0xfe, 0xfd, 0xf3, 0xef, 0x9f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x1f, 0x8f, 0x8f, 0xe7, 0xf3, 0xf9, 0xfe, 0xfe, 0xff, 0xfe, 0xbf, 0xcf, 0xe7, 0xf7, 0xf3, 0xfb, 0xdd},
                                                                 {0xff, 0xff, 0xc7, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xf0, 0xc1, 0x0b, 0xcf, 0xcf, 0xef, 0xe7, 0xe7, 0xe3, 0xfb, 0xfb, 0xf9, 0xf9, 0x39, 0x83, 0xf7, 0xef, 0xef, 0xdc, 0x32, 0xf7, 0x3f, 0x3f, 0x18, 0x0f, 0xf7, 0xf2, 0xf9, 0xf9, 0xfb, 0x23, 0x03, 0xef, 0xff, 0x98, 0xf8, 0xf9, 0xf1, 0x71, 0x73, 0x73, 0x7b, 0x39, 0x7c, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xde, 0xdf, 0x9f, 0x0f, 0xcf, 0xcf, 0xe7, 0xe3, 0xf1, 0xfc, 0xff, 0xff, 0x0f, 0x0f, 0xf1, 0xf9, 0xbd, 0xde, 0xce, 0xe6, 0xfe, 0xfe, 0x7e, 0x7f, 0x3f, 0x3f, 0x9f, 0x9f, 0xcf, 0xe7, 0xe0, 0xe7, 0xcf, 0x9f, 0x3f, 0x7f, 0xfc, 0xf9, 0xf7, 0xcf, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0x7e, 0x7e, 0x7f, 0x7f, 0x1f, 0xc7, 0xe3, 0xf9, 0xfc, 0xfc, 0xfe, 0xff, 0xff, 0xfb, 0xfd, 0xff, 0xff, 0xff},
                                                                 {0xff, 0x5f, 0xff, 0xff, 0x1f, 0x0f, 0x7f, 0xfc, 0xf7, 0x9f, 0xff, 0xff, 0xff, 0xfd, 0xf3, 0xc6, 0x0c, 0x99, 0x99, 0x99, 0x8f, 0xe7, 0xf6, 0xf5, 0xf1, 0xf9, 0x79, 0x03, 0x8f, 0xee, 0xfd, 0xdb, 0xbf, 0xfc, 0x07, 0x3f, 0x30, 0x18, 0x1e, 0x8e, 0xd5, 0xfb, 0xfa, 0x73, 0x03, 0x87, 0xef, 0xff, 0xcd, 0xd1, 0xf3, 0xf3, 0x33, 0x33, 0x33, 0x3b, 0x79, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xfd, 0xf0, 0x9f, 0xbf, 0xdf, 0xdf, 0xcf, 0xef, 0xe7, 0xf1, 0xf8, 0xfe, 0x8f, 0x8f, 0x8f, 0xc1, 0xf0, 0x79, 0xbd, 0xfe, 0xf7, 0xfb, 0xfb, 0x7a, 0x3f, 0xbf, 0x9f, 0xdf, 0xcf, 0xef, 0xe3, 0xff, 0xff, 0xdf, 0xff, 0xff, 0x7f, 0xfc, 0xf9, 0xf7, 0xcf, 0x9f, 0x3f, 0x7f, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x9f, 0xcf, 0xe7, 0xf3, 0xf9, 0xfc, 0xfe, 0x7f, 0x9e, 0x8f, 0x8f, 0xc7, 0xc7, 0xc7},
                                                                 {0xff, 0xff, 0xf3, 0xe7, 0x8f, 0x1f, 0x7d, 0x73, 0xcf, 0x3f, 0xff, 0xff, 0xfd, 0x03, 0x12, 0x39, 0x39, 0x79, 0x79, 0x7c, 0x7e, 0x7e, 0x3e, 0x3e, 0x9f, 0x80, 0xe1, 0xff, 0xff, 0xe5, 0x8e, 0x3f, 0x3c, 0x0f, 0x07, 0xf3, 0xf9, 0xfc, 0xde, 0xfe, 0x7c, 0x01, 0x80, 0xf1, 0xff, 0xfe, 0xe8, 0xfc, 0x7c, 0x3c, 0x3e, 0x9e, 0xde, 0xce, 0x4f, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0xf3, 0xe7, 0xe7, 0xe7, 0x73, 0xf3, 0xf9, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xe3, 0xe1, 0xd9, 0xf8, 0xcc, 0xee, 0xff, 0xff, 0x7d, 0x7e, 0x3f, 0x3f, 0x9f, 0x5f, 0xef, 0xe7, 0xf3, 0xf0, 0xf4, 0xe6, 0xff, 0xff, 0xf7, 0xef, 0x6f, 0xde, 0x99, 0x73, 0xe7, 0xcf, 0xdf, 0xbf, 0xbf, 0xbf, 0x1f, 0x1f, 0x1f, 0xe7, 0xf9, 0xfc, 0xfe, 0xff, 0x7f, 0xff, 0xef, 0xf3, 0xf9, 0xfd, 0xfc, 0xfe, 0xff, 0xf7},
                                                                 {0xff, 0xff, 0xff, 0xc7, 0x1f, 0x3f, 0xff, 0xff, 0xf7, 0xdf, 0xff, 0xff, 0xff, 0xf7, 0x0e, 0x30, 0x73, 0x73, 0xf1, 0xf9, 0xfc, 0x7e, 0x7e, 0x7e, 0x1e, 0x8d, 0xc3, 0xfb, 0xf7, 0xe3, 0xcf, 0x0f, 0xfc, 0x1f, 0x0f, 0x8f, 0xf3, 0xf9, 0x38, 0xfc, 0xfc, 0x79, 0x03, 0x03, 0xff, 0xf7, 0xf0, 0xf8, 0xf8, 0x7c, 0x3c, 0x3c, 0x8c, 0x8c, 0x9c, 0xbe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0xfc, 0xee, 0xcf, 0x67, 0xef, 0xe7, 0xe7, 0xf3, 0xf9, 0xfc, 0xfe, 0xff, 0xe7, 0xc1, 0xd8, 0xfc, 0xec, 0xfe, 0xf7, 0xfb, 0xff, 0xff, 0x7f, 0x3f, 0x3f, 0x9f, 0x1f, 0xdf, 0xe7, 0xe1, 0xe0, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfd, 0xfb, 0xe7, 0xcf, 0xdf, 0xbf, 0xbf, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x9f, 0xdf, 0xf3, 0xf9, 0xfc, 0xfe, 0xbe, 0xff, 0xff, 0xf7, 0xfb, 0xf9, 0xfd, 0xff, 0xf7}};

    void animate_bocchi(void) {
        /* clear */
        oled_set_cursor(FRAME_X, FRAME_Y - 1);
        oled_write("     ", false);
        oled_set_cursor(FRAME_X, FRAME_Y);

        /* switch frame */
        current_frame = (current_frame + 1) % FRAME_COUNT;
        /* current status */
        oled_write_raw_P(bocchi[current_frame], FRAME_SIZE);
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_bocchi();
    }
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        render_bocchi();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE
