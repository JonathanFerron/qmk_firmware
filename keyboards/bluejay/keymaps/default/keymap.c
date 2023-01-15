/* Copyright 2022 Jonathan Ferron
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

// Version 0.1

#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"
//#include "print.h"

#define x_____x XXXXXXX

// Layer Declarations
enum bluejay_layers { 
    _BASE = 0, 
    _NAV, 
    _NUM, 
    _FUN, 
    _EXC,
    _INT
};

enum {
  _PSTVALUE = SAFE_RANGE,
  _PSTFORMAT,
  _PSTFORMULA,
  _PSTLINK,
  _PSTSPECIAL
};

// mod tap keys
#define _MT_G_A GUI_T(KC_A)
#define _MT_A_S ALT_T(KC_S)
#define _MT_C_R CTL_T(KC_R)
#define _MT_S_T SFT_T(KC_T)

#define _MT_S_N RSFT_T(KC_N)
#define _MT_C_E RCTL_T(KC_E)
#define _MT_A_O ALT_T(KC_O)
#define _MT_G_I RGUI_T(KC_I)

#define _FMT_NUM0 RCS(KC_N)
#define _FMT_NUM2 RCS(KC_1)
#define _FMT_PCT RCS(KC_5)
#define _FMT_DATE RCS(KC_D)

// unicode for accented letters
enum unicode_names {
    _eaigu,
    _Eaigu,
    _egrav,
    _Egrav,
    _agrav,
    _Agrav,
    _ugrav,
    _Ugrav,
    _ecirc,
    _Ecirc,
    _acirc,
    _Acirc,
    _ucirc,
    _Ucirc,
    _ocirc,
    _Ocirc,
    _icirc,
    _Icirc,
    _ccedi,
    _Ccedi,
    _utrem,
    _Utrem,
    _etrem,
    _Etrem,
    _itrem,
    _Itrem,
    _quest,
    _excla,
    _midot,
    _aaigu,
    _Aaigu,
    _iaigu,
    _Iaigu,
    _igrav,
    _Igrav,
    _oaigu,
    _Oaigu,
    _ograv,
    _Ograv,
    _ntild,
    _Ntild,
    _uaigu,
    _Uaigu,
    _yaigu,
    _Yaigu,
    _ubrev,
    _Ubrev,
    _cgrav,
    _Cgrav,
    _ggrav,
    _Ggrav,
    _hgrav,
    _Hgrav,
    _jgrav,
    _Jgrav,
    _sgrav,
    _Sgrav
};

const uint32_t PROGMEM unicode_map[] = {
    [_eaigu] = 0x00E9, // é
    [_Eaigu] = 0x00C9, // É
   
    [_egrav] = 0x00E8, // è
    [_Egrav] = 0x00C8, // È
   
    [_agrav] = 0x00E0, // à
    [_Agrav] = 0x00C0, // À
   
    [_ugrav] = 0x00F9, // ù
    [_Ugrav] = 0x00D9, // Ù
   
    [_ecirc] = 0x00EA, // ê
    [_Ecirc] = 0x00CA, // Ê
   
    [_acirc] = 0x00E2, // â
    [_Acirc] = 0x00C2, // Â
   
    [_ucirc] = 0x00FB, // û
    [_Ucirc] = 0x00DB, // Û
   
    [_ocirc] = 0x00F4, // ô
    [_Ocirc] = 0x00D4, // Ô
   
    [_icirc] = 0x00EE, // î
    [_Icirc] = 0x00CE, // Î
   
    [_ccedi] = 0x00E7, // ç
    [_Ccedi] = 0x00C7, // Ç
   
    [_utrem] = 0x00FC, // ü
    [_Utrem] = 0x00DC, // Ü
   
    [_etrem] = 0x00EB, // ë
    [_Etrem] = 0x00CB, // Ë
   
    [_itrem] = 0x00EF, // ï
    [_Itrem] = 0x00CF, // Ï

    [_quest] = 0x00BF, // ¿
    [_excla] = 0x00A1, // ¡

    [_midot] = 0x00B7, // · MIDDLE DOT

    [_aaigu] = 0x00E1, // á
    [_Aaigu] = 0x00C1, // Á

    [_iaigu] = 0x00ED, // í
    [_Iaigu] = 0x00CD, // Í

    [_igrav] = 0x00EC, // ì
    [_Igrav] = 0x00CC, // Ì

    [_oaigu] = 0x00F3, // ó
    [_Oaigu] = 0x00D3, // Ó

    [_ograv] = 0x00F2, // ò
    [_Ograv] = 0x00D2, // Ò

    [_ntild] = 0x00F1, // ñ
    [_Ntild] = 0x00D1, // Ñ

    [_uaigu] = 0x00FA, // ú
    [_Uaigu] = 0x00DA, // Ú

    [_yaigu] = 0x00FD, // ý
    [_Yaigu] = 0x00DD, // Ý

    [_ubrev] = 0x016D, // ŭ
    [_Ubrev] = 0x016C, // Ŭ

    [_cgrav] = 0x0109, // ĉ
    [_Cgrav] = 0x0108, // Ĉ

    [_ggrav] = 0x011D, // ĝ
    [_Ggrav] = 0x011C, // Ĝ

    [_hgrav] = 0x0125, // ĥ
    [_Hgrav] = 0x0124, // Ĥ

    [_jgrav] = 0x0135, // ĵ 
    [_Jgrav] = 0x0134, // Ĵ

    [_sgrav] = 0x015D, // ŝ
    [_Sgrav] = 0x015C // Ŝ
};

#define __aaigu XP(_aaigu, _Aaigu)
#define __agrav XP(_agrav, _Agrav)
#define __acirc XP(_acirc, _Acirc)

#define __eaigu XP(_eaigu, _Eaigu)
#define __egrav XP(_egrav, _Egrav)
#define __ecirc XP(_ecirc, _Ecirc)
#define __etrem XP(_etrem, _Etrem)

#define __iaigu XP(_iaigu, _Iaigu)
#define __igrav XP(_igrav, _Igrav)
#define __icirc XP(_icirc, _Icirc)
#define __itrem XP(_itrem, _Itrem)

#define __oaigu XP(_oaigu, _Oaigu)
#define __ograv XP(_ograv, _Ograv)
#define __ocirc XP(_ocirc, _Ocirc)

#define __uaigu XP(_uaigu, _Uaigu)
#define __ugrav XP(_ugrav, _Ugrav)
#define __ucirc XP(_ucirc, _Ucirc)
#define __utrem XP(_utrem, _Utrem)

#define __yaigu XP(_yaigu, _Yaigu)

#define __ccedi XP(_ccedi, _Ccedi)

#define __ntild XP(_ntild, _Ntild)

#define __quest X(_quest)
#define __excla X(_excla)
#define __midot X(_midot)

#define __ubrev XP(_ubrev, _Ubrev)
#define __cgrav XP(_cgrav, _Cgrav)
#define __ggrav XP(_ggrav, _Ggrav)
#define __hgrav XP(_hgrav, _Hgrav)
#define __jgrav XP(_jgrav, _Jgrav)
#define __sgrav XP(_sgrav, _Sgrav)

// custom shift keys
const custom_shift_key_t custom_shift_keys[] = {
  {KC_DOT , KC_EXLM}, // Shift . is !
  {KC_COMM, KC_QUES}, // Shift , is ?
  {KC_LT, KC_PIPE},   // Shift < is | 
  {KC_GT, KC_HASH},   // Shift > is #
  {KC_COLN, KC_SCLN}, // Shift : is ; 
//  {KC_LCBR, KC_RCBR}, // Shift { is } 
  {LT(0,KC_LBRC), KC_RBRC}, // Shift [ is ] 
  {KC_SLSH, KC_BSLS}, // Shift slash is backslash
  {KC_ASTR, KC_PLUS} // Shift * is +
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_split_5_3x6_4(
                    KC_AT, KC_AMPR, KC_SLSH,          KC_LT,         KC_GT,                 KC_LPRN,        KC_RPRN, LT(0,KC_MINS), LT(0,KC_DLR), LT(0,KC_LBRC),
   LT(0, KC_TAB),    KC_Q,    KC_D,LT(0,KC_H),         KC_W,         KC_B,                     KC_J,           KC_F,    LT(0,KC_U),   LT(0,KC_P), LT(0,__agrav), __egrav,
         KC_COLN, _MT_G_A, _MT_A_S, _MT_C_R,        _MT_S_T, LT(_NUM,KC_G),                     KC_M,        _MT_S_N,       _MT_C_E,      _MT_A_O,       _MT_G_I, KC_QUOT, 
         KC_GESC,LT(0,KC_Z),LT(0,KC_X),LT(0,KC_Y),LT(0,KC_C),   LT(0,KC_V),                    KC_K,           KC_L,       KC_COMM,       KC_DOT, LT(0,__eaigu), __ecirc, 
                       LT(0,KC_F4), LT(_INT,KC_DEL),LT(_NAV,KC_BSPC), OSM(MOD_LSFT),                 LT(_EXC,KC_ENT),       LT(_FUN,KC_SPC),   KC_ASTR,  KC_EQL
),

[_NAV] = LAYOUT_split_5_3x6_4(
                  x_____x, x_____x, x_____x,        x_____x,       x_____x,                 x_____x,        x_____x,       x_____x,      x_____x,       x_____x,
         x_____x, x_____x, x_____x, x_____x,        x_____x,       x_____x,                 x_____x,        KC_PGUP,       KC_UP,        x_____x,       x_____x, x_____x,
         x_____x, KC_LGUI, KC_LALT, KC_LCTL,        KC_LSFT,       x_____x,                 x_____x,        KC_LEFT,       KC_DOWN,      KC_RGHT,       x_____x, x_____x,
         x_____x, x_____x, x_____x, x_____x,        x_____x,       x_____x,                 x_____x,        KC_PGDN,       x_____x,      x_____x,       x_____x, x_____x,
                           x_____x, x_____x,        x_____x,       x_____x,                 KC_HOME,         KC_END,       x_____x,      x_____x  
),

[_NUM] = LAYOUT_split_5_3x6_4(
                  x_____x, x_____x, x_____x,        x_____x,       x_____x,                 KC_CIRC,        x_____x,       KC_MINS,      x_____x,       x_____x,
          KC_TAB, x_____x, x_____x, x_____x,        x_____x,       x_____x,                 x_____x,           KC_7,          KC_8,         KC_9,       x_____x, x_____x,
          UC_MOD, KC_LGUI, KC_LALT, KC_LCTL,        KC_LSFT,       x_____x,                 x_____x,           KC_4,          KC_5,         KC_6,       KC_PDOT, KC_PERC,
         x_____x, x_____x, x_____x, x_____x,        x_____x,       x_____x,                 x_____x,           KC_1,          KC_2,         KC_3,       x_____x, x_____x,
                           x_____x, x_____x,        KC_BSPC,       x_____x,                 KC_PENT,           KC_0,       x_____x,       KC_NUM  
),

[_FUN] = LAYOUT_split_5_3x6_4(
                   KC_INS, x_____x, x_____x,        x_____x,       KC_PAUS,                 x_____x,        x_____x,       x_____x,      x_____x,       x_____x,
         x_____x,   KC_F9,  KC_F10,  KC_F11,         KC_F12,       x_____x,                 x_____x,        x_____x,       x_____x,      x_____x,       x_____x,   DT_UP,
         x_____x,   KC_F5,   KC_F6,   KC_F7,          KC_F8,       x_____x,                  x_____x,        KC_RSFT,       KC_RCTL,      KC_LALT,       KC_RGUI, DT_DOWN,
         x_____x,   KC_F1,   KC_F2,   KC_F3,          KC_F4,       x_____x,                 x_____x,        x_____x,       x_____x,      x_____x,       x_____x, DT_PRNT,
                           x_____x, x_____x,        x_____x,       x_____x,                 x_____x,        x_____x,       x_____x,      x_____x  
),

[_EXC] = LAYOUT_split_5_3x6_4(
                _FMT_NUM0, _FMT_NUM2, _FMT_PCT,   _FMT_DATE,       x_____x,                 KC_LCBR,        KC_RCBR,       x_____x,      x_____x,       x_____x,
         x_____x, x_____x, x_____x, x_____x,    _PSTFORMULA,    _PSTFORMAT,                 x_____x,        x_____x,       x_____x,      x_____x,       x_____x, x_____x,
         x_____x, x_____x, x_____x, x_____x,        x_____x,     _PSTVALUE,                 x_____x,        KC_RSFT,       KC_RCTL,      KC_LALT,       KC_RGUI, x_____x,
         x_____x, x_____x, x_____x, x_____x,    _PSTSPECIAL,      _PSTLINK,                 x_____x,        x_____x,       x_____x,      x_____x,       x_____x, x_____x,
                           x_____x, x_____x,        x_____x,       _______,                 x_____x,        x_____x,       x_____x,      x_____x 
),

[_INT] = LAYOUT_split_5_3x6_4(
                  x_____x, x_____x, x_____x, x_____x, x_____x,                              x_____x,        x_____x,       __utrem,      x_____x,       __itrem,
         x_____x, x_____x, x_____x, __hgrav, x_____x, x_____x,                              __jgrav,        x_____x,       __ubrev,      __ograv,       __igrav, x_____x,
         x_____x, __aaigu, __sgrav, x_____x, x_____x, __ggrav,                              x_____x,        __ntild,       __uaigu,      __oaigu,       __iaigu, x_____x,
         x_____x, x_____x, x_____x, __yaigu, __cgrav, x_____x,                              x_____x,        x_____x,       __quest,      __excla,       __midot, x_____x,
                           x_____x, _______, x_____x, _______,                              OSM(MOD_LSFT),  x_____x,       x_____x,      x_____x 
)

};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
} // matrix_scan_user()

// this is called on each key press, relatively early on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // key logger - uncomment to enable
  // https://www.pjrc.com/teensy/hid_listen.html
  // https://docs.qmk.fm/#/cli_commands?id=qmk-console
  //xprintf ("KL: kc: 0x%04X, col=%02d, row=%02d, pressed=%d, layer state=%u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, layer_state);
  //if (record->event.pressed) {
  //  xprintf ("0x%04X\n", keycode);
  //}

  // layer change notice
  //static uint32_t prev_layer_state;
  //static uint8_t layer;
  //const static char *layer_lookup[] = {"BAS", "EXT"};

  /*
  if (layer_state != prev_layer_state) {
    prev_layer_state = layer_state;
    layer = biton32(layer_state); //returns highest significant bit
    if (layer_lookup[layer])
      xprintf("Layer: %s\n", layer_lookup[layer]);
  }
  */

  switch (keycode) {
    case LT(0,KC_F4):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(KC_F2);    // Intercept hold function to send F2
        return false;
      }
      break;
    case LT(0,KC_P):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(KC_PSCR);   // Intercept hold function to send print screen
        return false;
      }
      break;
    case LT(0,KC_MINS):
      if (!record->tap.count && record->event.pressed) {
        process_unicodemap(__ucirc, record);   // Intercept hold function to send û.        
        return false;
      }
      break;
    case LT(0,KC_LBRC):
      if (!record->tap.count && record->event.pressed) {
        process_unicodemap(__icirc, record);   // Intercept hold function to send î
        return false;
      }
      break;
    case LT(0,KC_U):
      if (!record->tap.count && record->event.pressed) {
        process_unicodemap(__ugrav, record);   // Intercept hold function to send ù
        return false;
      }
      break;
    case LT(0,KC_C):
      if (!record->tap.count && record->event.pressed) {
        process_unicodemap(__ccedi, record);   // Intercept hold function to send ç
        return false;
      }
      break;
    case LT(0,KC_Z):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(LCTL(KC_Z));   // Intercept hold function to send undo
        return false;
      }
      break;
    case LT(0,KC_X):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(LCTL(KC_X));   // Intercept hold function to send cut
        return false;
      }
      break;
    case LT(0,KC_Y):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(LCTL(KC_Y));   // Intercept hold function to send redo
        return false;
      }
      break;
    case LT(0,KC_V):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(LCTL(KC_V));   // Intercept hold function to send paste
        return false;
      }
      break;
    case LT(0,KC_H):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(LCTL(KC_C));   // Intercept hold function to send copy
        return false;
      }
      break;
    case LT(0,KC_DLR):
      if (!record->tap.count && record->event.pressed) {
        process_unicodemap(__ocirc, record);   // Intercept hold function to send ô
        return false;
      }
      else if (record->tap.count && record->event.pressed) {
        tap_code16(KC_DLR); // Send KC_DLR on tap
        return false;        // Return false to ignore further processing of key
      }
      break;
    case LT(0,__agrav): 
      if (!record->tap.count && record->event.pressed) {
        process_unicodemap(__acirc, record);   // Intercept hold function to send â
        return false;
      }
      else if (record->tap.count && record->event.pressed) {
        process_unicodemap(__agrav, record);   // Intercept tap function to send à
        return false;        // Return false to ignore further processing of key
      }
      break;
    case LT(0,__eaigu): 
      if (!record->tap.count && record->event.pressed) {
        process_unicodemap(__etrem, record);   // Intercept hold function to send ë
        return false;
      }
      else if (record->tap.count && record->event.pressed) {
        process_unicodemap(__eaigu, record);   // Intercept tap function to send é
        return false;        // Return false to ignore further processing of key
      }
      break;
    case LT(0, KC_TAB):
      if (!record->tap.count && record->event.pressed) {
        // Intercept hold function
        // Switch between windows with alt tab.
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(KC_TAB);
        return false;
      }
      else if (record->tap.count && record->event.pressed) {
        // Intercept tap function
        if (is_alt_tab_active) {
          alt_tab_timer = timer_read();
        }
        tap_code16(KC_TAB);
        return false;
      }      
      break;
    case _PSTVALUE:
      tap_code16(LCTL(LALT(KC_V))); tap_code16(KC_V); tap_code16(KC_ENT); return false; break;
    case _PSTFORMAT:
      tap_code16(LCTL(LALT(KC_V))); tap_code16(KC_T); tap_code16(KC_ENT); return false; break;
    case _PSTFORMULA:
      tap_code16(LCTL(LALT(KC_V))); tap_code16(KC_F); tap_code16(KC_ENT); return false; break;
    case _PSTLINK:
      tap_code16(LCTL(LALT(KC_V))); tap_code16(KC_L); return false; break;
    case _PSTSPECIAL:
      tap_code16(LCTL(LALT(KC_V))); return false; break;
    }

  if (!process_custom_shift_keys(keycode, record)) { return false; }

  return true;              // Return true for normal processing of tap keycode
} // process_record_user()

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _MT_G_A:
    case _MT_A_S:
    case _MT_C_R:
    case _MT_S_T:
    case _MT_S_N:
    case _MT_C_E:
    case _MT_A_O:
    case _MT_G_I:
//    case LT(_NAV, KC_G):
//    case LT(_NUM, KC_W):
//    case LT(_FUN, KC_M):
//    case LT(_SYM, KC_F):
//    case LT(_NUM,KC_DEL):
    //case LT(_NAV,KC_BSPC):
//    case LT(_SYM,KC_ENT):
//    case LT(_FUN,KC_SPC):
      return true;
    default:
      return false;
  }
}

/*
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}
*/