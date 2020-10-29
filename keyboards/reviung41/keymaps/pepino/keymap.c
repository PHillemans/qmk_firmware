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
                        
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 
 * Base Layer: QWERTY
 *
 *       ,-------------------------------------------.          ,-----------------------------------------.
 *       |RAIS/ESC|   Q  |   W  |   E  |   R  |   T  |          |  Y   |   U  |   I  |   O  |   P  |  |\  |
 *       |--------+------+------+------+------+------|          |------+-----+------+------+------+-------|
 *       |Ctrl/BS |   A  |   S  |  D   |   F  |   G  |          |  H   |   J  |   K  |   L  | ;  : |  ' " |
 *       |--------+------+------+------+------+------+          +------+-----+------+------+------+------+|
 *       | LShift |   Z  |   X  |   C  |   V  |   B  |          |  N   |   M  | ,  < | . >  | /  ? |  - _ |
 *       `----------------------+------+------+------+----------+------+-----+------+---------------------'
 *                                     | GUI  | BckSp|   Space  | Entr | ??  |
 *                                     |      | Lower|          | Raise| ??  |
 *                                     '-------------------------------------'
 */
  [_BASE] = LAYOUT_reviung41(
    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_MINS,
                               KC_LGUI, LT(_LOWER, KC_BSPC),    KC_SPC,   LT(_RAISE, KC_ENT),  KC_TAB
  ),
  
/* 
 * Lower Layer: Symbols
 *
 *       ,-------------------------------------------.          ,----------------------------------------.
 *       |        |   !   |  @   |  {   |  }   |  |  |          |       |     |      |      |      |  | \|
 *       |--------+-------+------+------+------+-----|          |-------+-----+------+------+------+-----|
 *       |  LALT  |   #   |  $   |  (   |  )   |  `  |          |    +  |  -  |  /   |  *   |  %   |  ' "|
 *       |--------+-------+------+------+------+-----+          +-------+-----+------+------+------+-----|
 *       |        |   %   |  ^   |  [   |  ]   |  ~  |          |    &  |  =  |  ,   |  .   |  / ? | - _ |
 *       `----------------------+------+------+------+----------+-------+-----+------+-------------------'
 *                                     | Del  | BckSp|   Space  |  Tab  |  ?? |
 *                                     |      | Lower|          | Raise |  ?? |
 *                                     '--------------------------------------'
 */
  [_LOWER] = LAYOUT_reviung41(
    _______,  KC_EXLM,  KC_AT,    KC_LCBR,  KC_RCBR,   KC_PIPE,            _______,  _______,  _______,  _______,  _______, KC_BSLS,
    KC_LALT,  KC_HASH,   KC_DLR,  KC_LPRN,  KC_RPRN,    KC_GRV,            KC_PLUS,  KC_MINS,  KC_SLSH,  KC_ASTR,  KC_PERC, KC_QUOT,
    _______,  KC_PERC,   KC_CIRC, KC_LBRC,  KC_RBRC,   KC_TILD,            KC_AMPR,  KC_EQL,   KC_COMM,  KC_DOT,  KC_SLSH,  KC_MINS,
                                            _______,   _______,  KC_ENT,   _______,  _______
  ),
  
/*
 * Raise Layer: Number keys, media, navigation
 *
 *       ,-------------------------------------------.           ,----------------------------------------.
 *       |        |   1  |  2   |  3   |  4   |  5   |           |  6   |  7   |  8   |  9   |  0   |     |
 *       |--------+------+------+------+------+------|           |------+------+------+------+------+-----|
 *       |        |      | Prev | Play | Next | VolUp|           | Left | Down | Up   | Right|      |     |
 *       |--------+------+------+------+------+------+           |-------------+------+------+------+-----+
 *       |        |      |      |      | Mute | VolDn|           | MLeft| Mdown| MUp  |MRight|      |     |
 *       `----------------------+------+------+------+-----------+------+------+------+------+------+-----'
 *                                     |      |      |           |      |      |
 *                                     |      |      |           |      |      |
 *                                     '---------------------------------------'
 */
  [_RAISE] = LAYOUT_reviung41(
    _______,     KC_1,     KC_2,     KC_3,     KC_4,      KC_5,                     KC_6,       KC_7,     KC_8,        KC_9,    KC_0, _______,
    _______,  _______,  KC_MPRV,   KC_MPLY,  KC_MNXT,  KC__VOLUP,                 KC_LEFT,    KC_DOWN,    KC_UP,    KC_RIGHT, _______, _______,
    _______,  _______,  _______,  _______,  KC_CAPS,  KC__VOLDOWN,            KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, _______, _______,
                                               _______,   _______,  _______,  _______,  _______
  ),
/*
 * Adjust Layer: Function keys, RGB
 *
 *       ,----------------------------------------------           ,-----------------------------------------.
 *       |       |  F1   |  F2   |   F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 *       |-------+-------+-------+-------+------+------+           |------+------+------+------+------+------|
 *       |       |  VAI  |  SAI  |  HUI  | MOD  | TOG  |           |      |      |      | F11  |  F12 |      |
 *       |-------+-------+-------+-------+------+------+           |------+------+------+------+------+------+
 *       |       |  VAD  |RBG_SAD|  HUD  | RMOD        |           | RESET|      |      |      |      |      |
 *       `--------------------------------------+------+-----------+------+------+------+------+------+------'
 *                                     |        |      |           |      |      |
 *                                     |        |      |           |      |      |
 *                                     '-----------------------------------------'
 */
  
  [_ADJUST] = LAYOUT_reviung41(
    XXXXXXX,    KC_F1,   KC_F2,     KC_F3,    KC_F4,     KC_F5,              KC_F6,       KC_F7,       KC_F8,       KC_F9,      KC_F10,  XXXXXXX,
    XXXXXXX,    RGB_VAI, RGB_SAI,  RGB_HUI, RGB_MOD,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,      KC_F11,      KC_F12,  XXXXXXX,
    XXXXXXX,   RGB_VAD, RGB_SAD,  RGB_HUD, RGB_RMOD,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                            _______,   _______,  XXXXXXX,  _______,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

