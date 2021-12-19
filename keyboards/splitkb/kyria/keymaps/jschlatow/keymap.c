/* Copyright 2021 Johannes Schlatow
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

#include "keymap_german.h"
#include "keymap_us_international.h"

enum custom_keycodes {
    VIM_TABN = SAFE_RANGE,
    VIM_TABP,
    VIM_BUFN,
    VIM_BUFP,
    VIM_WUP,
    VIM_WDN,
    VIM_WL,
    VIM_WR
};

enum layers {
#ifdef PS2_MOUSE_ENABLE
    _QWERTY = 0,
    _QWERTZ,
#else
    _QWERTZ = 0,
    _QWERTY,
#endif
    _NAV,
    _NUMPAD,
    _SYMDE,
    _SYM,
    _FUNCTIONDE,
    _FUNCTION,
    _VIM,
    _ADJUST,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define QWERTZ   DF(_QWERTZ)

#define SYM        MO(_SYM)
#define SYMDE      MO(_SYMDE)
#define NAV        MO(_NAV)
#define NUM        TT(_NUMPAD)
#define ADJUST     MO(_ADJUST)
#define FUNCTIONDE MO(_FUNCTIONDE)

#define KC_WWW   KC_WWW_HOME

// Jorun
#define CTL_MINS RCTL_T(DE_MINS)
#define CTL_DEL  LCTL_T(KC_DEL)
#define SFT_ADIA RSFT_T(DE_ADIA)
#define ALT_APP  LALT_T(KC_APP)
#define ADJ_UDIA LT(_ADJUST, DE_UDIA)

// Johannes
#define SFT_TAB  LSFT_T(KC_TAB)
#define FN_ESC   LT(_FUNCTION, KC_ESC)
#define CTL_BSLS RCTL_T(KC_BSLS)
#define VIM_ENT  LT(_VIM, KC_ENT)
#define RALT_F11 RALT_T(KC_F11)
#define SFT_QUOT RSFT_T(KC_QUOT)
#define ADJ_MINS LT(_ADJUST,   KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTZ] = LAYOUT(
     FN_ESC  , DE_Q ,  DE_W   ,  DE_E  ,   DE_R ,   DE_T ,                                        DE_Z,   DE_U ,  DE_I ,   DE_O ,  DE_P ,ADJ_UDIA,
     SFT_TAB , DE_A ,  DE_S   ,  DE_D  ,   DE_F ,   DE_G ,                                        DE_H,   DE_J ,  DE_K ,   DE_L ,DE_ODIA,SFT_ADIA,
     CTL_DEL , DE_Y ,  DE_X   ,  DE_C  ,   DE_V ,   DE_B ,FUNCTIONDE, NUM ,KC_MS_BTN1,KC_MS_BTN2, DE_N,   DE_M ,DE_COMM, DE_DOT , DE_SS ,CTL_MINS,
                                KC_LGUI, KC_RALT,  KC_ENT, ALT_APP, NAV   , KC_BSPC  ,SYMDE   ,KC_SPC ,DE_QUOT, DE_DQUO
    ),
    [_QWERTY] = LAYOUT(
     FN_ESC  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P ,ADJ_MINS,
     SFT_TAB , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,SFT_QUOT,
     CTL_DEL , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B ,KC_MS_BTN2,NUM,   KC_MS_BTN1,KC_MS_BTN3,KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH,CTL_BSLS,
                                KC_RGUI,KC_LGUI , KC_LALT, KC_BSPC, NAV   ,     SYM    ,KC_SPC,VIM_ENT,RALT_F11,KC_F12
    ),

    [_NAV] = LAYOUT(
      _______, _______, KC_WWW , KC_MAIL, KC_CALC, KC_WH_U,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, KC_PAUSE,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_WH_D,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_SCRL,
      _______, _______, _______, KC_WBAK, KC_WFWD, KC_F5  , KC_WH_L, KC_WH_R, KC_WH_L, KC_WH_R, KC_INS , KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSCR,
                                 _______, _______, _______, _______, _______, KC_DEL , _______, _______, KC_BRID, KC_BRIU
    ),

    [_SYMDE] = LAYOUT(
     DE_CIRC ,   DE_1 ,   DE_2 ,   DE_3 ,   DE_4 ,   DE_5 ,                                       DE_6 ,   DE_7 ,   DE_8 ,   DE_9 ,   DE_0 , DE_PLUS,
     DE_TILD , DE_EXLM,  DE_AT , DE_SECT,  DE_DLR, DE_PERC,                                     DE_AMPR, DE_SLSH, DE_LPRN, DE_RPRN, DE_EQL , DE_ASTR,
     _______ , DE_DEG , DE_PIPE, DE_LCBR, DE_LBRC, DE_EURO, _______, _______, _______, _______, _______, DE_RCBR, DE_RBRC, DE_BSLS, _______, DE_HASH,
                                 _______, _______, _______, _______, _______, _______, _______, _______, DE_LABK, DE_RABK
    ),

    [_SYM] = LAYOUT(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
     KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
     _______ , _______, US_EURO, KC_LCBR, KC_LBRC, KC_LPRN, _______, _______, _______, _______, KC_RPRN, KC_RBRC, KC_RCBR, _______, KC_SPC , KC_ENT ,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NUMPAD] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                    KC_PAST,    KC_7,    KC_8,    KC_9,  KC_PMNS, _______,
      _______, _______, _______, _______, _______, _______,                                    KC_PSLS,    KC_4,    KC_5,    KC_6,  KC_PPLS, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, KC_BSPC,    KC_1,    KC_2,    KC_3, KC_ENTER, _______,
                                 _______, _______, _______,_______, _______, _______, _______, KC_0   , KC_COMM, KC_DOT
    ),

    [_FUNCTIONDE] = LAYOUT(
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , KC_F5  ,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 ,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F11,  KC_F12,  KC_F13,  KC_F14, KC_F15 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_FUNCTION] = LAYOUT(
      _______,  KC_F9 ,  KC_F10,  KC_F11,  KC_F12, KC_F13 ,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , KC_F14 ,                                     _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______,
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , KC_F15 , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_VIM] = LAYOUT(
      _______, _______, _______,VIM_BUFP,VIM_BUFN, _______,                                    _______, _______, VIM_WUP, _______,  _______, _______,
      _______, _______, _______,VIM_TABP,VIM_TABN, _______,                                    _______, VIM_WL , VIM_WDN, VIM_WR ,  _______, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, _______, _______, _______, _______ , _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                    _______, _______, DT_PRNT, _______, _______ , _______,
      _______, KC_CAPS, _______, QWERTZ , _______, _______,                                    _______, _______, DT_UP  , _______, _______ , _______,
      _______, _______, _______, QWERTY , _______, _______,_______, _______, _______, _______, _______, _______, DT_DOWN, _______, _______ , _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE

bool oled_task_user(void) {
    if (is_keyboard_left()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTZ:
                oled_write_P(PSTR("QWERTZ\n"), false);
                break;
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _NUMPAD:
                oled_write_P(PSTR("Num\n"), false);
                break;
            case _SYMDE:
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTIONDE:
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _VIM:
                oled_write_P(PSTR("vim\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    }
    return false;
}


#endif

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FN_ESC:
        case ADJ_UDIA:
        case ADJ_MINS:
            // Do not select the hold action for adjust and function.
            return false;
        default:
            // Immediately select the hold action when another key is pressed.
            return true;
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case VIM_TABN:
        if (record->event.pressed)
           SEND_STRING("gt");
        break;
    case VIM_TABP:
        if (record->event.pressed)
           SEND_STRING("gT");
        break;
    case VIM_BUFN:
        if (record->event.pressed)
           SEND_STRING(":bn\n");
        break;
    case VIM_BUFP:
        if (record->event.pressed)
           SEND_STRING(":bp\n");
        break;
    case VIM_WUP:
        if (record->event.pressed)
           SEND_STRING(SS_LCTL("w") SS_TAP(X_UP));
        break;
    case VIM_WDN:
        if (record->event.pressed)
           SEND_STRING(SS_LCTL("w")SS_TAP(X_DOWN));
        break;
    case VIM_WL:
        if (record->event.pressed)
           SEND_STRING(SS_LCTL("w")SS_TAP(X_LEFT));
        break;
    case VIM_WR:
        if (record->event.pressed)
           SEND_STRING(SS_LCTL("w")SS_TAP(X_RIGHT));
        break;
    }
    return true;
};
