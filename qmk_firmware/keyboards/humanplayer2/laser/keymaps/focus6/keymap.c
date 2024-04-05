#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"
#include "ps2_mouse.h"
#include "ps2.h"

void ps2_mouse_init_user(void) {
// See documentation in TrackPointDocumentation.pdf
// TrackPoint sensitivity
// Set as high as possible without resulting drift/noise
PS2_MOUSE_SEND(0xE2, "trackpoint command");
PS2_MOUSE_SEND(0x81, "write byte");
PS2_MOUSE_SEND(0xFF, "sensitivity");
// PS2_MOUSE_SEND(0x4A, "sensitivity");
//PS2_MOUSE_SEND(0xA0, "data"); // default = x80 (1). range = 0x00 to 0xFF (0 to 1.99)
PS2_MOUSE_SEND(0x70, "data"); // default = x80 (1). range = 0x00 to 0xFF (0 to 1.99)
// PS2_MOUSE_SEND(0xE2, "trackpoint command");
// PS2_MOUSE_SEND(0x81, "write byte");
// PS2_MOUSE_SEND(0x4D, "negative inertia");
// PS2_MOUSE_SEND(0x00, "data"); // disabled = x00, default = 06, tror jeg: https://www.reddit.com/r/TrackPoint_Builders/comments/xkghxa/trackpoint_protocol_you_need_post_processing_for/
//
// value6 is "Transfer Function Upper Plateau Speed"
// https://www.reddit.com/r/MechanicalKeyboards/wiki/trackpoint/?v=a699e6a8-e706-11eb-b7c2-0eb8334becf3
PS2_MOUSE_SEND(0xE2, "trackpoint command");
PS2_MOUSE_SEND(0x81, "write byte");
PS2_MOUSE_SEND(0x60, "value6");
PS2_MOUSE_SEND(0x61, "data"); // default = x61
}


// Layer names and numbers
// used in keycodes names below
enum my_layers {
 _BASE = 0,
 _LMOD = 1,
 _RMOD = 2,
 _ENTER_MOD = 3
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
LT_ENTER = (LT(_ENTER_MOD, KC_ENTER))
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
    /*
    * Laser Prothetic
    */
    [_BASE] = LAYOUT(
        KC_F1,     KC_F3,    KC_F4,    KC_F5,     KC_F6,     KC_NO,       KC_NO,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F12,
        KC_F2,     KC_W,     KC_F,     KC_P,      KC_B,      KC_NO,       KC_NO,     KC_J,      KC_L,      KC_U,      KC_Y,      KC_F11,
        KC_TAB,    KC_R,     KC_S,     KC_T,      KC_G,      DK_EQUAL,    DK_STAR,   KC_M,      KC_N,      KC_E,      KC_I,      DK_AA,
        ALT_Q,     KC_X,     KC_C,     KC_D,      KC_V,      DK_MINUS,    KC_NO,     KC_K,      KC_H,      KC_COMMA,  KC_DOT,    ALT_AE,
        KC_Z,      SH_A,     KC_NO,    RCTL_ESC,  LM_SPC,    KC_BTN1,     KC_BTN3,   RM_SPC,    LT_ENTER,  KC_NO,     SH_O,      DK_OE
    ),
    [_LMOD] = LAYOUT(
      G(KC_ESC), G(KC_F3),  G(KC_F4), G(KC_F5),  G(KC_F6),    KC_NO,     KC_NO,    G(KC_F7),   G(KC_F8),  G(KC_F9),  G(KC_F10),G(KC_F12),
      G(KC_F2),  C(KC_PGUP),G(KC_F),  C(KC_PGDN),C(KC_T),  _______,      _______,  _______,    KC_1,      KC_2,      KC_3,     G(KC_F11),
      G(KC_TAB), G(KC_R),   G(KC_S),  G(KC_T),   C(KC_W),G(DK_EQUAL),    _______,  _______,    KC_4,      KC_5,      KC_6,     _______,
      G(ALT_Q),  LAG(KC_R), A(KC_LEFT),LAG(KC_T),G(KC_V),G(DK_MINUS),    KC_NO,    _______,    KC_7,      KC_8,      KC_9,     _______,
      G(KC_Z),  _______,    KC_NO,     _______,   _______,  _______,     _______,  G(KC_SPACE),G(KC_ENTER),KC_NO,    SH_0,     _______
    ),
    [_RMOD] = LAYOUT(
      _______,  _______,   _______,  _______,   _______,  VOL_MU,        _______,   _______,  _______,   _______,   _______,      KC_SCRL,
      _______,  _______,   _______,  C(KC_X),   _______,  _______,       _______,   KC_DEL,   KC_HOME,     KC_UP,      KC_END,    _______,
      _______,  _______,   S(KC_INS),C(KC_INS), KC_TAB,   VOL_UP,        _______,   KC_BSPC,  KC_LEFT,     KC_DOWN,    KC_RIGHT,  KC_PSCR,
      _______,  _______,   _______,  KC_F2,     _______,  VOL_DN,        KC_NO,     KC_APP,   C(KC_INS),   S(KC_INS),  C(KC_X),   _______,
      _______,  _______,   KC_NO,    _______,   _______,  _______,       _______,   _______,    _______,    KC_NO,     C(KC_Z),   _______
    ),
    [_ENTER_MOD] = LAYOUT(
        KC_NO,    KC_NO,     KC_NO,    KC_NO,     KC_NO,    KC_NO,        KC_NO,     KC_NO,      KC_NO,     KC_NO,     KC_NO,    KC_NO,
        KC_NO,    _______,   _______,  KC_EXLM,   DK_QUES, _______,      _______,    DK_STAR,    KC_HASH,   KC_BSLS,   DK_GRV,   KC_NO,
        CW_TOGG,  _______,   _______,  _______,   _______, _______,      _______,    DK_SLSH,    DK_LPRN,   DK_LBRC,   DK_LCBR,  DK_PIPE,
        _______,  _______,   _______,  _______,   _______, _______,       KC_NO,     DK_PLUS,    DK_MINUS, S(DK_MINUS),DK_EQUAL, DK_DOL,
        _______,  SH_A,     KC_NO,     _______,   _______, _______,      _______,    _______,    _______,   KC_NO,     SH_LABK,  DK_TILDE
    )
};
