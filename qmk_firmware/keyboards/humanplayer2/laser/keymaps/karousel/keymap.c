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
 // _LMOD_NOTUSED = 1,
 _RMOD = 1,
 _SYM = 2,
 _NUM = 3,
};

enum custom_keycodes {
    DK_E_AIGU = SAFE_RANGE,
//    S_DK_E_AIGU,
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
RCTL_ESC = (MT(MOD_RCTL,KC_ESC)),
RCTL_EXEC = (MT(MOD_RCTL,KC_EXECUTE)),
RCTL_P7 = (MT(MOD_RCTL,KC_P7)), // rigth index ctrl

SH_SPC = (MT(MOD_RSFT,KC_SPACE)),
ALT_Q = (MT(MOD_LALT,KC_Q)),

OE_NUM = (LT(_NUM,DK_OE)),

RM_SPC = (LT(_RMOD,KC_SPACE)),
LT_ENTER = (LT(_SYM, KC_ENTER))
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
//
  {KC_BSLS, DK_DQUO}, // ' is "
  {KC_HASH, KC_PERC}, // # is %
  {DK_SLSH, DK_BSLS}, // Shift / is \ .
  {DK_LPRN, DK_RPRN}, // Shift  is
  {DK_LBRC, DK_RBRC}, // Shift  is
  {DK_LCBR, DK_RCBR}, // Shift  is
  {DK_LABK, DK_RABK}, // Shift  is
  {DK_GRV, DK_AIGU}, // Shift  is
  {KC_BTN3, KC_BTN2},
  {VOL_UP, VOL_DN},
  // {DK_STAR, DK_DOL}, // Shift * is $
  // {KC_SPACE, G(KC_SPACE)},
  //  {KC_EXLM, DK_QUES}, // Shift ! is ?
  //  {DK_TILDE, DK_AT}, // Shift ~ is @
  //  {DK_AMPR, DK_PIPE}, // Shift & is
  //  {DK_EQUAL, DK_TILDE},
  //  {DK_MINUS, DK_PLUS}, // Shift - is +.
  //  {DK_E_AIGU, S_DK_E_AIGU},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_custom_shift_keys(keycode, record)) { return false; }
  // Your macros ...
  switch (keycode) {
    case DK_E_AIGU:
      if (record->event.pressed) {
        // when keycode DK_E_AIGU is pressed // requires compose key set to scroll lock
        SEND_STRING(SS_TAP(X_SCRL) SS_TAP(X_EQUAL) SS_TAP(X_E));
      } else {
          // when keycode DK_E_AIGU is released
      }
      break;
//    case S_DK_E_AIGU: // this doesn't work as expected. F8 is send...?
//    if (record->event.pressed) {
//        SEND_STRING(SS_TAP(X_SCRL) SS_TAP(X_EQUAL) SS_DOWN(X_LSFT) SS_TAP(X_E) SS_UP(X_LSFT));
//      } else {
//      }
//      break;
  }
  return true;
}
// LAYERS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
      KC_F1,       KC_F2,      KC_F3,     KC_F4,       KC_F5,      KC_F6,                                     KC_F7,       KC_F8,      KC_F9,      KC_F10,    KC_F11,     KC_PSCR,
      KC_TAB,      ALT_Q,      KC_W,      KC_F,        KC_P,       KC_B,                                      KC_J,        KC_L,       KC_U,       KC_Y,      DK_AE,      KC_Z,
      OE_NUM,      KC_A,       KC_R,      KC_S,        KC_T,       KC_G,       VOL_UP,            VOL_MU,     KC_M,        KC_N,       KC_E,       KC_I,      KC_O,       DK_AA,
                               KC_X,      KC_C,        KC_D,       KC_V,       DK_E_AIGU,                     KC_K,       KC_H,        KC_COMMA,   KC_DOT,
                                                       RCTL_ESC,   SH_SPC,     KC_BTN1,           KC_BTN3,    RM_SPC,      LT_ENTER
    ),

    [_RMOD] = LAYOUT(
      G(KC_ESC),   G(KC_F2),   G(KC_F3),    G(KC_F4),  G(KC_F5),   G(KC_F6),                                  G(KC_F7),   G(KC_F8),    G(KC_F9),   G(KC_F10),  G(KC_F11), G(KC_PSCR),
      G(KC_TAB),   G(ALT_Q),   C(KC_PGUP),  KC_P1,     C(KC_PGDN), C(KC_W),                                   KC_DEL,     KC_HOME,     KC_UP,      KC_END,     G(DK_AE),  G(KC_Z),
      A(KC_LEFT),  _______,    KC_P3,       KC_P5,     RCTL_P7,    C(KC_T),    G(VOL_UP),         G(VOL_MU),  KC_BSPC,    KC_LEFT,     KC_DOWN,    KC_RIGHT,   _______,   C(KC_Z),
                               G(DK_MINUS), G(KC_C),   G(DK_PLUS), G(KC_V),    G(DK_E_AIGU),                  KC_APP,     C(KC_INS),   S(KC_INS),  C(KC_X),
                                                       RCTL_EXEC,  _______,    G(KC_SPACE),       _______,    _______,    G(KC_ENTER)
    ),

    [_SYM] = LAYOUT(
      KC_NO,       KC_NO,      KC_NO,       KC_NO,     KC_NO,      KC_NO,                         KC_NO,      KC_NO,      KC_NO,     KC_NO,        KC_NO,      KC_NO,
      CW_TOGG,     _______,    DK_AMPR,     KC_EXLM,   DK_QUES,    DK_DOL,                        DK_STAR,    KC_HASH,    KC_BSLS,   DK_GRV,       DK_AT,      DK_PIPE,
      _______,     _______,    _______,     _______,   _______,    _______,    _______,           _______,    DK_SLSH,    DK_LPRN,   DK_LBRC,      DK_LCBR,    DK_LABK,   DK_TILDE,
                               _______,     _______,   _______,    _______,    _______,                       DK_PLUS,    DK_MINUS,  S(DK_MINUS),  DK_EQUAL,
                                                       _______,    _______,    _______,           _______,    _______,    _______
    ),

    [_NUM] = LAYOUT(
      _______,     _______,    _______,     _______,   _______,    _______,                                  _______,    _______,    _______,      _______,   _______,   _______,
      _______,     _______,    _______,     _______,   _______,    _______,                                  _______,    KC_1,       KC_2,         KC_3,      _______,   _______,
      _______,     _______,    _______,     _______,   _______,    _______,    _______,           _______,   _______,    KC_4,       KC_5,         KC_6,      KC_0,      _______,
                               _______,     _______,   _______,    _______,    _______,                      _______,    KC_7,       KC_8,         KC_9,
                                                       _______,    _______,    _______,           _______,   _______,    _______
    ),
};