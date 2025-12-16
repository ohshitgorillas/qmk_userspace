/*
 * G-Tofu keymap
 *
 * This is the keymap for Garrett's Tofu60 2.0.
*/

#include QMK_KEYBOARD_H

// OS Awareness
// macOS/iOS uses layer 1, everything else uses layer 0
bool process_detected_host_os_user(os_variant_t detected_os) {
    if (detected_os == OS_MACOS || detected_os == OS_IOS) {
        set_single_persistent_default_layer(1);
    } else {
        set_single_persistent_default_layer(0);
    }
    return true;
}

// keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        // Windows/Linux main layer
        KC_ESC,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6, KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRAVE,
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y, KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_CAPS, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H, KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,          MO(2),
        KC_LCTL, KC_LWIN, KC_LALT,                         KC_SPC,                           KC_RALT, KC_RWIN, KC_RCTL
    ),
    [1] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        // macOS main layer
        KC_ESC,  KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6, KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRAVE,
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y, KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_CAPS, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H, KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C, KC_V, KC_B, KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,          MO(2),
        KC_LCTL, KC_LOPT, KC_LCMD,                         KC_SPC,                           KC_RCMD, KC_ROPT, KC_RCTL
    ),
    [2] = LAYOUT_60_ansi_tsangan_split_bs_rshift(
        // Nav/Media/F-keys layer
        XXXXXXX,   KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,   KC_F12,  KC_INS,  KC_DEL,
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SCRL,  KC_PAUS, KC_UP,    XXXXXXX, _______,
        XXXXXXX,  KC_LCTL, KC_LALT, KC_LWIN, KC_LSFT, XXXXXXX, KC_ASTR, KC_SLSH, KC_HOME, KC_PGUP,  KC_LEFT, KC_RIGHT, _______,
        _______,  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, KC_PLUS, KC_MINS, KC_END,  KC_PGDN,  KC_DOWN, _______,           XXXXXXX,
        _______,  _______, _______,                                     _______,                             _______,  _______, _______
    ),
};
