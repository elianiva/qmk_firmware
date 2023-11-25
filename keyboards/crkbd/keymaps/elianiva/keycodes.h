#pragma once

enum layer_names {
    _QWERTY,
    // _COLEMAK,
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
// #define L_COLEMAK TG(_COLEMAK)
#define L_GAMING TG(_GAMING)
