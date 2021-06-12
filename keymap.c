/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "keymap_swedish.h"

enum preonic_layers {
  _QWERTY,
  _RAISE,
  _FN
};

enum preonic_keycodes {
  RAISE = SAFE_RANGE,
  FN,
  DB_TILD,
  DB_CIRC,
  DB_ACUT,
  DB_GRV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   Å  |   Ä  |  UP  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  FN  | Alt  | GUI  | Ctrl |Raise |    Space    |Raise |Shift | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid(
  KC_ESC,  SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_6,    SE_7,    SE_8,    SE_9,    SE_0,    KC_BSPC,
  KC_TAB,  SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,    SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,    KC_DEL,
  KC_ESC,  SE_A,    SE_S,    SE_D,    SE_F,    SE_G,    SE_H,    SE_J,    SE_K,    SE_L,    SE_ODIA, KC_BSPC,
  KC_LSFT, SE_Z,    SE_X,    SE_C,    SE_V,    SE_B,    SE_N,    SE_M,    SE_ARNG, SE_ADIA, KC_UP,   KC_ENT,
  FN,      KC_LALT, KC_LGUI, KC_LCTL, RAISE,   KC_SPC,  KC_SPC,  RAISE,   KC_RSFT, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   ½  |   §  |   ¤  |   £  |   €  |   µ  |   <  |   >  |   %  |   ^  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   |  |   \  |   ;  |   :  |   @  |   #  |   [  |   ]  |   +  |   *  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ~  |   /  |   ,  |   .  |   '  |   "  |   (  |   )  |   -  |   _  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   &  |   $  |   ?  |   !  |   ´  |   `  |   {  |   }  |   =  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid(
  _______, SE_HALF, SE_SECT, SE_CURR, SE_PND,  SE_EURO, SE_MICR, SE_LABK, SE_RABK, SE_PERC, DB_CIRC, _______,
  _______, SE_PIPE, SE_BSLS, SE_SCLN, SE_COLN, SE_AT,   SE_HASH, SE_LBRC, SE_RBRC, SE_PLUS, SE_ASTR, _______,
  _______, DB_TILD, SE_SLSH, SE_COMM, SE_DOT,  SE_QUOT, SE_DQUO, SE_LPRN, SE_RPRN, SE_MINS, SE_UNDS, _______,
  _______, SE_AMPR, SE_DLR,  SE_QUES, SE_EXLM, DB_ACUT, DB_GRV,  SE_LCBR, SE_RCBR, SE_EQL,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Fn
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Caps |Aud cy|Aud on|AudOff|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      | Vol +|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      | Vol -|      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, _______,
  _______, KC_CAPS, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, _______, _______, RGB_TOG, RGB_MOD, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, KC__VOLUP, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC__VOLDOWN, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      return false;
      break;
    case DB_TILD:
      if (record->event.pressed) {
        tap_code16(SE_TILD);
        tap_code16(SE_TILD);
      }
      return false;
      break;
    case DB_CIRC:
      if (record->event.pressed) {
        tap_code16(SE_CIRC);
        tap_code16(SE_CIRC);
      }
      return false;
      break;
    case DB_ACUT:
      if (record->event.pressed) {
        tap_code16(SE_ACUT);
        tap_code16(SE_ACUT);
      }
      return false;
      break;
    case DB_GRV:
      if (record->event.pressed) {
        tap_code16(SE_GRV);
        tap_code16(SE_GRV);
      }
      return false;
      break;
  }
  return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
  if (index == 1) {
    if (active) {
      muse_mode = true;
    } else {
      muse_mode = false;
    }
  }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
      return false;
    default:
      return true;
  }
}
