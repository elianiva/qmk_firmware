/* Copyright 2020 gtips
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
#include "features/achordion/achordion.h"
#include "keycodes.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, XXXXXXX,                      XXXXXXX,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //|------+--------+--------+--------+--------| -------+                      -------|--------+--------+--------+--------+--------+-
      GUI_A,   ALT_S,   CTL_D,   SFT_F,    KC_G, XXXXXXX,                      XXXXXXX,    KC_H,   SFT_J,   CTL_K,   ALT_L,GUI_QUOT,
  //|------+--------+--------+--------+--------| -------+                      -------|--------+--------+--------+--------+--------+-
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,                      XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               TAB_NAV,ENT_MOUSE, XXXXXXX, SPC_SYM,BSPC_NUM
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUM] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC, QK_BOOT,                      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|-------+-                    |--------+--------+--------+--------+--------+--------|
      KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
  //|--------+--------+--------+--------+--------|-------+-                    |--------| -------+--------+--------+--------+--------+-
       KC_GRV,    KC_1,    KC_2,    KC_3, KC_BSLS, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                   KC_0, KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYM] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,QK_BOOT,                      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|-------+                    |--------| -------+--------+--------+--------+--------+-
      KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,XXXXXXX,                      XXXXXXX, XXXXXXX, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
  //|--------+--------+--------+--------+--------|-------+                    |--------| -------+--------+--------+--------+--------+-
      KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  ESC_MEDIA, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  QK_BOOT,                       QK_BOOT, XXXXXXX, KC_PASTE, KC_COPY, KC_CUT, KC_CAPW,
  //-------+--------+--------+--------+--------||--------+-                   |---------| -------+--------+--------+--------+--------+
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,  XXXXXXX,                       XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_CAPS,
  //-------+--------+--------+--------+--------||--------+-                   |---------| -------+--------+--------+--------+--------+
    XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,                       XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_ACL0, QK_BOOT,                       QK_BOOT, XXXXXXX, KC_PASTE, KC_COPY, KC_CUT, XXXXXXX,
  //|------+--------+--------+--------+--------|--------+-                    |--------| -------+--------+--------+--------+--------+-
     KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_ACL1, XXXXXXX,                       XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MNXT,
  //|------+--------+--------+--------+--------|--------+-                    |--------| -------+--------+--------+--------+--------+-
     KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_ACL2, XXXXXXX,                       XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               XXXXXXX, KC_BTN3, XXXXXXX, KC_BTN1, KC_BTN2
                                      //`--------------------------'  `--------------------------'
  ),

  [_MEDIA] = LAYOUT(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,QK_BOOT,                       QK_BOOT,RGB_TOG, RGB_HUD, RGB_HUI, RGB_MOD,RGB_RMOD,
  //|--------+--------+--------+--------+--------|-------+-                    |--------|-------+--------+--------+--------+--------+-
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,XXXXXXX,                       XXXXXXX,RGB_VAI, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
  //|--------+--------+--------+--------+--------|-------+-                    |--------|-------+--------+--------+--------+--------+-
      XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,                       XXXXXXX,RGB_VAD, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                XXXXXXX, KC_MSTP, XXXXXXX, KC_MPLY, KC_MUTE
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
