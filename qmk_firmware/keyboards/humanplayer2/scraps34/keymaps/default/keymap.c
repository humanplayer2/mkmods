/* Copyright 2024 humanplayer2
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
#include "features/custom_shift_keys.h"

// Layer names and numbers
// used in keycodes names below
enum my_layers {
 _BASE = 0,
 _LMOD = 1,
 _RMOD = 2,
 _ENTER_MOD = 3,
 _COMM = 4,
 _EMPTY = 5
};
// Keycode names:
enum my_keycodes {
  // DK keycodes
DK_AE = KC_SEMICOLON,
DK_OE = KC_QUOTE,
DK_AA = KC_LEFT_BRACKET,
  //
DK_DQUO = S(KC_2),
DK_AT = ALGR(KC_2),
DK_DOL = ALGR(KC_4),
DK_AMPR = S(KC_6),
DK_SLSH = S(KC_7),
DK_BSLS = ALGR(KC_NUBS),
DK_LPRN = S(KC_8),
DK_RPRN = S(KC_9),
DK_LBRC = ALGR(KC_8),
DK_RBRC = ALGR(KC_9),
DK_LCBR = ALGR(KC_7),
DK_RCBR = ALGR(KC_0),
DK_PLUS = KC_MINUS,
DK_QUES = S(KC_MINUS),
DK_LABK = KC_NUBS,
DK_RABK = S(KC_NUBS),
DK_GRV = S(KC_EQUAL),
DK_AIGU = KC_EQUAL,
DK_EQUAL = S(KC_0),
DK_TILDE = ALGR(KC_RBRC),
DK_PIPE = ALGR(KC_EQUAL),
DK_MINUS = KC_SLSH,
DK_STAR = S(KC_BSLS),
  // Browser navigation
FF_LEFT = C(KC_PGDN),
FF_RGHT = C(KC_PGUP),
FF_BACK = A(KC_LEFT),
FF_CLSE = C(KC_W),
  // Shorthands
VOL_UP = KC_KB_VOLUME_UP,
VOL_DN = KC_KB_VOLUME_DOWN,
VOL_MU = KC_KB_MUTE,
  // Tap-mods
LCTL_ESC = (MT(MOD_LCTL,KC_ESC)), // custom LCTL
RCTL_ESC = (MT(MOD_RCTL,KC_ESC)), // default RCTL
RCTL_Z = (MT(MOD_RCTL,KC_Z)),
RCTL_OE = (MT(MOD_RCTL,DK_OE)),
SH_A = (MT(MOD_RSFT,KC_A)),
SH_O = (MT(MOD_RSFT,KC_O)),
SH_Z = (MT(MOD_LSFT,KC_Z)),
SH_OE = (MT(MOD_RSFT,DK_OE)),
SH_0 = (MT(MOD_RSFT,KC_0)),
SH_LABK = (MT(MOD_RSFT,KC_NUBS)),
SH_MINUS = (MT(MOD_RSFT,DK_MINUS)),
ALT_Q = (MT(MOD_LALT,KC_Q)),
ALT_AE = (MT(MOD_LALT,DK_AE)),
  // Tap-mods
LM_SPC = (LT(_LMOD,KC_SPACE)),
RM_SPC = (LT(_RMOD,KC_SPACE)),
LT_ENT = (LT(_ENTER_MOD, KC_ENTER)),
LT_COM = (LT(_COMM, KC_COMMA))
};

// Caps Words
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case DK_MINUS:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

//////////
// Custom shift keys
const custom_shift_key_t custom_shift_keys[] = {
// Experimental:
  {KC_BSLS, DK_DQUO}, // ' is "
//
  {KC_EXLM, DK_QUES}, // Shift ! is ?
  {DK_TILDE, DK_AT}, // Shift ~ is @
  {KC_HASH, KC_PERC}, // # is $
  {DK_AMPR, DK_PIPE}, // Shift & is |
  //
  {DK_EQUAL, DK_TILDE},
  {KC_BTN3, KC_BTN2},
  //
  {DK_MINUS, DK_PLUS}, // Shift - is +.
  //
  {DK_SLSH, DK_BSLS}, // Shift / is \ .
  {DK_LPRN, DK_RPRN}, // Shift : is ;
  {DK_LBRC, DK_RBRC}, // Shift : is ;
  {DK_LCBR, DK_RCBR}, // Shift : is ;
  {DK_LABK, DK_RABK}, // Shift : is ;
  {DK_GRV, DK_AIGU} // Shift : is ;
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
//

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_custom_shift_keys(keycode, record)) { return false; }
  // Your macros ...
  return true;
}

//////////

// LAYERS


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT(
     ALT_Q,    KC_W,      KC_F,      KC_P,      KC_G,             KC_M,       KC_L,    KC_U,      KC_Y,     KC_J,
     SH_A,     KC_R,      KC_S,      KC_T,      LT_COM,           KC_DOT,     KC_N,    KC_E,      KC_I,     SH_O,
     KC_Z,     KC_V,      KC_C,      KC_D,                                    KC_H,    KC_B,      KC_K,     KC_X,
                          RCTL_ESC,  LM_SPC,    MO(_COMM),        MO(_COMM),  RM_SPC,  LT_ENT
    ),
   [_LMOD] = LAYOUT(
     G(KC_ESC),C(KC_PGUP),G(KC_F),   C(KC_PGDN),C(KC_T),          _______,    KC_1,    KC_2,      KC_3,     G(KC_F11),
     _______,  G(KC_R),   G(KC_S),   G(KC_T),   C(KC_W),          _______,    KC_4,    KC_5,      KC_6,     _______,
     _______,  LAG(KC_R), A(KC_LEFT),LAG(KC_T),                               KC_7,    KC_8,      KC_9,     _______,
                          _______,   _______,   _______,          _______,  G(KC_SPC), G(KC_ENT)
    ),
   [_RMOD] = LAYOUT(
     KC_PSCR,   _______,   KC_F3,     KC_F2,    VOL_UP,           KC_DEL,     KC_HOME, KC_UP,     KC_END,   KC_SCRL,
     _______,   _______,   _______,   KC_TAB,   VOL_DN,           KC_BSPC,    KC_LEFT, KC_DOWN,   KC_RIGHT, _______,
     _______,   _______,   _______,   _______,                    C(KC_C),    C(KC_V), C(KC_X),   KC_NO,
                           _______,   _______,   _______,         _______,    KC_SPC,  KC_ENT
    ),
   [_ENTER_MOD] = LAYOUT(
     KC_EXLM,  DK_AT,     _______,  _______,   DK_QUES,        DK_SLSH,   KC_HASH,    KC_BSLS,    DK_GRV,    DK_PIPE,
     _______,  _______,   _______,  _______,   DK_PLUS,        DK_MINUS,  DK_LPRN,    DK_LBRC,    DK_LCBR,   SH_LABK,
     _______,  _______,   _______,  _______,                              S(DK_MINUS),DK_EQUAL,   DK_TILDE,   _______,
                          _______,  _______,   _______,        _______,   _______,   _______
    ),
   [_COMM] = LAYOUT(
     _______,  _______,   _______,   KC_WH_U,   _______,        KC_WH_U,   KC_BTN1,   KC_MS_U,   KC_BTN2,   _______,
     _______,  _______,   KC_BTN2,   KC_BTN1,   _______,        KC_WH_D,   KC_MS_L,   KC_MS_D,   KC_MS_R,   _______,
     _______,  _______,   _______,   KC_WH_D,                              KC_APP,    DK_AE,     DK_OE,     DK_AA,
                          _______,   _______,   _______,        _______,   _______,   _______
    ),
   [_EMPTY] = LAYOUT(
     _______,  _______,   _______,   _______,   _______,        _______,   _______,   _______,   _______,   _______,
     _______,  _______,   _______,   _______,   _______,        _______,   _______,   _______,   _______,   _______,
     _______,  _______,   _______,   _______,                              _______,   _______,   _______,   _______,
                          _______,   _______,   _______,        _______,   _______,   _______
    ),
};
