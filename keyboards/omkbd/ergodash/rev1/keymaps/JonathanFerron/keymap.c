// version 3.2

#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"

#define x_____x XXXXXXX

// Layer Declarations
enum {
    _BAS = 0,
    _EXT,
    _NAV
};

enum {
  _PSTVALUE = SAFE_RANGE,
  _PSTFORMAT,
  _PSTFORMULA,
  _PSTLINK
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
    _Itrem
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
    [_Itrem] = 0x00CF  // Ï
};

#define __eaigu XP(_eaigu, _Eaigu)
#define __egrav XP(_egrav, _Egrav)
#define __agrav XP(_agrav, _Agrav)
#define __ugrav XP(_ugrav, _Ugrav)
#define __ecirc XP(_ecirc, _Ecirc)
#define __acirc XP(_acirc, _Acirc)
#define __ucirc XP(_ucirc, _Ucirc)
#define __ocirc XP(_ocirc, _Ocirc)
#define __icirc XP(_icirc, _Icirc)
#define __ccedi XP(_ccedi, _Ccedi)
#define __utrem XP(_utrem, _Utrem)
#define __etrem XP(_etrem, _Etrem)
#define __itrem XP(_itrem, _Itrem)

// custom shift keys
const custom_shift_key_t custom_shift_keys[] = {
  {KC_DOT , KC_EXLM}, // Shift . is !
  {KC_COMM, KC_QUES}, // Shift , is ?
  {KC_PERC, KC_PIPE}, // Shift % is |
  {KC_LPRN, KC_LT},   // Shift ( is <
  {KC_COLN, KC_SCLN}, // Shift : is ; 
  {KC_LCBR, KC_RCBR}, // Shift { is } 
  {LT(0,KC_LBRC), KC_RBRC}, // Shift [ is ] 
  {KC_SLSH, KC_BSLS}, // Shift slash is backslash
  {KC_RPRN, KC_GT} // Shift ) is >
};

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

/* KC_NO = XXXXXXX
   KC_TRANSPARENT = KC_TRNS = _______
*/

// tap dance
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD, // tap, release then hold
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD  // tap, release, tap, release, then hold
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    _TDUNDO,
    _TDCOPY,
    _TDPST,
    _TDRESET
};

td_state_t cur_dance(qk_tap_dance_state_t *state);

// For each tap dance. Declare it here so it can be used in any keymap.
void undo_finished(qk_tap_dance_state_t *state, void *user_data);
void undo_reset(qk_tap_dance_state_t *state, void *user_data);
void copy_finished(qk_tap_dance_state_t *state, void *user_data);
void copy_reset(qk_tap_dance_state_t *state, void *user_data);
void pst_finished(qk_tap_dance_state_t *state, void *user_data);
void pst_reset(qk_tap_dance_state_t *state, void *user_data);
void rst_finished(qk_tap_dance_state_t *state, void *user_data);
void rst_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  [_BAS] = LAYOUT_3key_2us(
    KC_HOME,       KC_AT,       KC_AMPR,    KC_SLSH,     KC_PERC,    KC_HASH,       KC_PGDN,                                       KC_PGUP, KC_LPRN, KC_RPRN, LT(0,KC_MINS),  LT(0,KC_DLR),  LT(0,KC_LBRC), KC_END, 
    LT(0, KC_TAB), KC_Q,        KC_D,       KC_H,        KC_W,       KC_B,          KC_EQL,                                        KC_LCBR, KC_J,    KC_F,    LT(0,KC_U),     LT(0,KC_P),    LT(0,__agrav), __egrav, 
    KC_COLN,       _MT_G_A,     _MT_A_S,    _MT_C_R,     _MT_S_T,    LT(_EXT,KC_G), LT(0,KC_PLUS),                                 KC_ASTR, KC_M,    _MT_S_N, _MT_C_E,        _MT_A_O,       _MT_G_I,       KC_QUOT, 
    KC_GESC,       KC_Z,        KC_X,       KC_Y,        LT(0,KC_C), KC_V,                                                                  KC_K,    KC_L,    KC_COMM,        KC_DOT,        LT(0,__eaigu), __ecirc, 
    TD(_TDUNDO),   TD(_TDCOPY), TD(_TDPST), LT(0,KC_F4),             KC_DEL,        LT(_NAV,KC_BSPC), OSM(MOD_LSFT),       KC_ENT, KC_SPC,  OSL(_EXT),        KC_LEFT,        KC_DOWN,       KC_UP,         KC_RGHT
  ),

  [_EXT] = LAYOUT_3key_2us(
    TD(_TDRESET), KC_INS,  x_____x, x_____x, x_____x, KC_PAUS,  x_____x,                           KC_ESC,  _______, _______, __utrem,  KC_DLR,  __itrem, KC_NUM, 
    DT_UP,        KC_F9,   KC_F10,  KC_F11,  KC_F12,  x_____x,  x_____x,                           KC_COMM, KC_PAST, KC_7,    KC_8,     KC_9,    KC_EQL,  x_____x, 
    DT_DOWN,      KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,  x_____x,                           KC_CIRC, KC_PPLS, KC_4,    KC_5,     KC_6,    KC_PDOT, KC_PERC, 
    DT_PRNT,      KC_F1,   KC_F2,   KC_F3,   KC_F4,   x_____x,                                              KC_PSLS, KC_1,    KC_2,     KC_3,    KC_PMNS, x_____x, 
    TO(_BAS),     UC_MOD,  x_____x, x_____x,          _______,  _______, _______,         KC_PENT, KC_0,    _______,          _______,  _______, _______, _______
  ),

  [_NAV] = LAYOUT_3key_2us(
    x_____x,      _FMT_NUM0, _FMT_NUM2, _FMT_PCT, _FMT_DATE,  x_____x,    x_____x,                           x_____x, x_____x,       LCTL(KC_HOME), LCTL(KC_UP),   LCTL(KC_END),  LCTL(KC_PGUP),  x_____x, 
    LALT(KC_TAB), x_____x,  KC_F9,   TD(_TDCOPY), _PSTFORMULA,_PSTFORMAT, x_____x,                           x_____x, x_____x,       KC_HOME,       KC_UP,         KC_END,        KC_PGUP,        LALT(KC_TAB), 
    LCTL(KC_TAB), KC_LGUI,  KC_LALT, KC_LCTL,     KC_LSFT,   _PSTVALUE,   x_____x,                           x_____x, LCTL(KC_LEFT), KC_LEFT,       KC_DOWN,       KC_RIGHT,      LCTL(KC_RIGHT), LCTL(KC_TAB), 
    KC_ESC,       x_____x,  x_____x, x_____x,     TD(_TDPST), _PSTLINK,                                               x_____x,       LALT(KC_PGUP), LCTL(KC_DOWN), LALT(KC_PGDN), KC_PGDN,        KC_TAB, 
    TO(_BAS),     x_____x,  x_____x, x_____x,                 _______,    _______, x_____x,         _______, x_____x, x_____x,                      x_____x,       x_____x,       LCTL(KC_PGDN),  x_____x
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
    case LT(0,KC_PLUS):
      if (!record->tap.count && record->event.pressed) {
        tap_code16(KC_F9);   // Intercept hold function to send f9
        return false;
      }
      else if (record->tap.count && record->event.pressed) {
        tap_code16(KC_PLUS); // Send KC_PLUS on tap
        return false;        // Return false to ignore further processing of key
      }
      break;
    case LT(0,KC_MINS):
      if (!record->tap.count && record->event.pressed) {
        process_unicodemap(__ucirc, record);   // Intercept hold function to send û, use send_unicode_string("û") if this doesn't work. qmkcombine with get_mods() & MOD_MASK_SHIFT (also test with get_oneshot_mods()), see https://docs.qmk.fm/#/feature_advanced_keycodes?id=checking-modifier-state
        // or try to call the process_unicode_common() function directly from here with _ucirc (only one underscore)
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
    }

  if (!process_custom_shift_keys(keycode, record)) { return false; }

  return true;              // Return true for normal processing of tap keycode
} // process_record_user()

td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t undotap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void undo_finished(qk_tap_dance_state_t *state, void *user_data) {
    undotap_state.state = cur_dance(state);
    switch (undotap_state.state) {
        case TD_SINGLE_TAP: register_code16(LCTL(KC_Z)); break;
        case TD_SINGLE_HOLD: register_code16(LCTL(KC_Y)); break;
        default: break;
//        case TD_DOUBLE_TAP: register_code(KC_ESC); break;
  //      case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
    //    case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X);
    }
}

void undo_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (undotap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(LCTL(KC_Z)); break;
        case TD_SINGLE_HOLD: unregister_code16(LCTL(KC_Y)); break;
        default: break;
//        case TD_DOUBLE_TAP: unregister_code(KC_ESC); break;
//        case TD_DOUBLE_HOLD: unregister_code(KC_LALT);
//        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X);
    }
    undotap_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t copytap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void copy_finished(qk_tap_dance_state_t *state, void *user_data) {
    copytap_state.state = cur_dance(state);
    switch (copytap_state.state) {
        case TD_SINGLE_TAP: register_code16(LCTL(KC_C)); break;
        case TD_SINGLE_HOLD: register_code16(LCTL(KC_X)); break;
        default: break;
    }
}

void copy_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (copytap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
        case TD_SINGLE_HOLD: unregister_code16(LCTL(KC_X)); break;
        default: break;
    }
    copytap_state.state = TD_NONE;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t psttap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void pst_finished(qk_tap_dance_state_t *state, void *user_data) {
    psttap_state.state = cur_dance(state);
    switch (psttap_state.state) {
        case TD_SINGLE_TAP: register_code16(LCTL(KC_V)); break;
        case TD_SINGLE_HOLD: register_code16(LCTL(LALT(KC_V))); break;
        default: break;
    }
}

void pst_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (psttap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(LCTL(KC_V)); break;
        case TD_SINGLE_HOLD: unregister_code16(LCTL(LALT(KC_V))); break;
        default: break;
    }
    psttap_state.state = TD_NONE;
}

// tap dance logic for the "safe reset" button
void rst_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    // Reset the keyboard if you tap the key more than three times
    reset_keyboard();
    reset_tap_dance(state);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [_TDUNDO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, undo_finished, undo_reset),
    [_TDCOPY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, copy_finished, copy_reset),
    [_TDPST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, pst_finished, pst_reset),
    [_TDRESET] = ACTION_TAP_DANCE_FN(rst_finished)
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _MT_G_A:
    case _MT_A_S:
    case _MT_C_R:
    case _MT_S_T:
    case LT(_EXT,KC_G):
    case _MT_S_N:
    case _MT_C_E:
    case _MT_A_O:
    case _MT_G_I:
      return true;
    default:
      return false;
  }
}