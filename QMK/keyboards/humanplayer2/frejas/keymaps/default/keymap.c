// Copyright 2024 humanplayer2 (@humanplayer2)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_5x2(
        KC_ESC,
        KC_UP,
        KC_LEFT, KC_RIGHT,
        KC_DOWN,

        KC_ENTER,
        KC_Y,
        KC_X, KC_B,
        KC_A
    )
};
