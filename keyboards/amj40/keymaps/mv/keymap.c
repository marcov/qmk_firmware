


#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3



enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LAYER1,
  LAYER2,
  LAYER3,
};

/*
   kc when tap, right shift when held:
   MT(MOD_RRSFT, kc) == RSFT_T(kc)



*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        /* Default Layer
     * ,---------------------------------------------------------------.
     * | Esc|  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P | BS     |
     * | fn3|    |    |    |    |    |    |    |    |    |    |        |
     * |---------------------------------------------------------------|
     * | Tab |  A |  S |  D |  F |  G |  H |  J |  K |  L | Ent        |
     * |---------------------------------------------------------------|
     * | LSft   |  Z |  X |  C |  V |  B |  N |  M |  ,  |  . | /?(T)  |
     * |        |    |    |    |    |    |    |    |     |    | RSft(H)|
     * |---------------------------------------------------------------|
     * | LCtl | LAlt| LGui|  spc fn0  |  spc fn1    |RGui|RAlt|RCtl     |
     * `---------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT( \
        LT(_LAYER3,KC_ESC),  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,   KC_BSPC,\
        KC_TAB,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_ENT,\
        KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  RSFT_T(KC_SLSH),\
        KC_LCTL, KC_LALT,KC_LGUI,LT(_LAYER1, KC_SPC),LT(_LAYER2, KC_SPC),KC_RGUI, KC_RALT, KC_RCTL \
		),

    /* Function Layer 1 HHKB style
     * ,-----------------------------------------------------------.
     * |   ~  |   !   |  @  | # | $ | % | ^ | & | * | ( | ) | Bkspc|
     * |-----------------------------------------------------------|
     * |   F1   | F2 | F3 | F4 | F5 |  F6 | _ | + | [ | ] |  Pipe  |
     * |-----------------------------------------------------------|
     * |    F7    | F8 | F9 |  F10  |  F11 |  F12 | End|PgDn| ↓ |     |    |
     * |-----------------------------------------------------------|
     * |     |    |     |           |             | Stop| App|     |
     * `-----------------------------------------------------------'
     */
    [_LAYER1] = LAYOUT( \
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
		_______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
		KC_LSFT, _______, _______, _______, _______, _______, _______, _______,KC_COLN, KC_DQT, KC_QUES, \
		_______, _______, _______, _______, _______, _______, _______, _______ \
		),

	/* Function Layer 1 HHKB style
     * ,-----------------------------------------------------------.
     * |Caps|    |MSel| ⏮ | ⏯ | ⏭ |PSCR|SkLk|Paus|  ↑ | Ins| Del|
     * |-----------------------------------------------------------|
     * |      | 🔇 | ⏏ |    |  * |  / |Hone|PgUp|  ← |  → |       |
     * |-----------------------------------------------------------|
     * |        | 🔉 | 🔊 |    |  + |  - | End|PgDn| ↓ |     |    |
     * |-----------------------------------------------------------|
     * |     |    |     |           |             | Stop| App|     |
     * `-----------------------------------------------------------'
     */
    [_LAYER2] = LAYOUT( \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
		_______,   _______,   _______,   _______,   _______,   _______,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
		RESET,   _______,   _______,   _______,  _______,  _______,  _______, _______, KC_SCLN, KC_QUOT, KC_DEL, \
		_______, _______, _______, _______, _______, _______, _______, _______ \
		),

	/* Function Layer 1 HHKB style
     * ,-----------------------------------------------------------.
     * |Caps|    |MSel| ⏮ | ⏯ | ⏭ |PSCR|SkLk|Paus|  ↑ | Ins| Del|
     * |-----------------------------------------------------------|
     * |      | 🔇 | ⏏ |    |  * |  / |Hone|PgUp|  ← |  → |       |
     * |-----------------------------------------------------------|
     * |        | 🔉 | 🔊 |    |  + |  - | End|PgDn| ↓ |     |    |
     * |-----------------------------------------------------------|
     * |     |    |     |           |             | Stop| App|     |
     * `-----------------------------------------------------------'
     */
    [_LAYER3] = LAYOUT( \
        _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, \
		_______, _______, _______, _______,   _______,  _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,  KC_PGDN,  \
		_______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
		_______, _______, _______, _______, _______, _______, _______, _______ \
		),



};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

    case LAYER1:
      if (record->event.pressed) {
        layer_on(_LAYER1);
        update_tri_layer(_LAYER1, _LAYER2, _LAYER3);
      } else {
        layer_off(_LAYER1);
        update_tri_layer(_LAYER1, _LAYER2, _LAYER3);
      }
      return false;
      break;
    case LAYER2:
      if (record->event.pressed) {
        layer_on(_LAYER2);
        update_tri_layer(_LAYER1, _LAYER2, _LAYER3);
      } else {
        layer_off(_LAYER2);
        update_tri_layer(_LAYER1, _LAYER2, _LAYER3);
      }
      return false;
      break;
    case LAYER3:
      if (record->event.pressed) {
        layer_on(_LAYER3);
      } else {
        layer_off(_LAYER3);
      }
      return false;
      break;
  }
  return true;
}
