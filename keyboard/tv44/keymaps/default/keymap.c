// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "tv44.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _TB 7

// Macro name shortcuts
#define QWERTY M(_QWERTY)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)



// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | TAB  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CTRL |  WIN  |  Alt  |     Space/Lower  |    Space/Raise  | ALT |  MENU  |  CTRL  |
 * `-----------------------------------------------------------------------------------'
 */

[_QWERTY] = { /* Qwerty */
  {KC_ESC,     KC_Q,       KC_W,       KC_E,        KC_R,     KC_T,    KC_Y,     KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC},
  {FUNC(0),    KC_A,       KC_S,       KC_D,        KC_F,     KC_G,    KC_H,     KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT},
  {KC_LSFT,    KC_Z,       KC_X,       KC_C,        KC_V,     KC_B,    KC_N,     KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    FUNC(3)},
  {KC_LCTL,    KC_LGUI,    KC_LALT,    FUNC(1),     XXXXXXX,  XXXXXXX, XXXXXXX,  FUNC(2),    KC_RALT,    KC_APP,     XXXXXXX,    KC_RCTL}
},

[_RAISE] = {
  {S(KC_GRV),  S(KC_1),    S(KC_2),    S(KC_3),     S(KC_4),  S(KC_5), S(KC_6),  S(KC_7),    S(KC_8),    S(KC_9),    S(KC_0),    KC_BSPC},
  {KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PAUSE,    KC_TRNS,  KC_TRNS, KC_TRNS,  S(KC_MINS), S(KC_EQL),  S(KC_LBRC), S(KC_RBRC), S(KC_BSLS)},
  {KC_TRNS,    KC_F1,      KC_F2,      KC_F3,       KC_F4,    KC_F5,   KC_F6,    KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_ENT},
  {KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     XXXXXXX,  XXXXXXX, XXXXXXX,  KC_TRNS,    KC_MNXT,    KC_MUTE,    XXXXXXX,    KC_MPLY}
},

[_LOWER] = {
  {KC_GRV,     KC_1,       KC_2,       KC_3,        KC_4,     KC_5,    KC_6,     KC_7,       KC_8,       KC_9,       KC_0,       KC_DELETE},
  {KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS,  KC_MINS,    KC_EQL,     KC_LBRC,    KC_RBRC,    KC_BSLS},
  {KC_TRNS,    KC_F11,     KC_F12,     KC_F13,      KC_F14,   KC_F15,  KC_F16,   KC_F17,     KC_F18,     KC_PGUP,    KC_F20,     KC_ENT},
  {KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     XXXXXXX,  XXXXXXX, XXXXXXX,  KC_TRNS,    KC_HOME,    KC_PGDN,    XXXXXXX,    KC_END}
},

[_TB] = { /* Tab */
  {KC_ESC,     KC_CALC,    KC_WHOM,    KC_MAIL,     KC_MYCM,  KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_PSCR,    KC_TRNS},
  {KC_TRNS,    BL_STEP,    KC_TRNS,    KC_TRNS,     RESET,    KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS},
  {KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_UP,      KC_TRNS,    KC_ENT},
  {KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,     XXXXXXX,  XXXXXXX, XXXXXXX,  KC_TRNS,    KC_LEFT,    KC_DOWN,    XXXXXXX,    KC_RGHT}
}
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_LAYER_TAP_KEY(_TB, KC_TAB),
  [1]  = ACTION_LAYER_TAP_KEY(_RAISE, KC_SPC),
  [2]  = ACTION_LAYER_TAP_KEY(_LOWER, KC_SPC),
  [3]  = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {

}
