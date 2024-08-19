/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
#include "secrets.h"
#include "config.h"

enum layers{
	MAC_BASE,
	WIN_BASE,
	FN1,
	FN2,
	FN3,
};

enum {
    TD_MAIL,
    TD_TEL,
    TD_ADR,
    TD_NAME,
    TD_CRD,
    TD_LOG,
};

void send_email(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(PRIVATE_EMAIL);
    } else if (state->count == 2) {
        SEND_STRING(WORK_EMAIL);
    }
}

void send_tel(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        SEND_STRING(TEL_WITH_PREFIX);
    } else if (state->count == 2) {
        SEND_STRING(TEL);
    }
}

void send_address(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {    
        SEND_STRING(ADDRESS);
    } else if (state->count == 2) {    
        SEND_STRING(OFFICE);
    }
}

void send_name(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {    
        SEND_STRING(FULL_NAME);
    } else if (state->count == 2) {    
        SEND_STRING(FIRST_NAME);
    } else if (state->count == 3) {    
        SEND_STRING(LAST_NAME);
    }
}

void send_test_card(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {    
        SEND_STRING("4242 4242 4242 4242");
    } else if (state->count == 2) {
        SEND_STRING("04/42");
    } else if (state->count == 3) {
        SEND_STRING("424");
    }
}

void send_console_log(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {    
        SEND_STRING("console.log()");
        // tap_code(KC_LEFT);
    } else if (state->count == 2) {
        SEND_STRING("console.error()");
        // tap_code(KC_LEFT);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_MAIL] = ACTION_TAP_DANCE_FN(send_email),
    [TD_TEL] = ACTION_TAP_DANCE_FN(send_tel),
    [TD_ADR] = ACTION_TAP_DANCE_FN(send_address),
    [TD_NAME] = ACTION_TAP_DANCE_FN(send_name),
    [TD_CRD] = ACTION_TAP_DANCE_FN(send_test_card),
    [TD_LOG] = ACTION_TAP_DANCE_FN(send_console_log),
};

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

// Left-hand home row mods for FN1 layer
#define ALT_LFT LALT_T(KC_LEFT)
#define CTL_DWN LCTL_T(KC_DOWN)
#define SFT_RGT LSFT_T(KC_RIGHT)

// Right-hand home row mods for FN1 layer
#define SFT_4 RSFT_T(KC_P4)
#define CTL_5 RCTL_T(KC_P5)
#define ALT_6 LALT_T(KC_P6)
#define GUI_PLS RGUI_T(KC_PPLS)
	
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_69_ansi(
        KC_ESC,  KC_1,	   KC_2,	 KC_3,	  KC_4,    KC_5,	KC_6,	  KC_7,    KC_8,	KC_9,	 KC_0,	   KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,	   KC_W,	 KC_E,	  KC_R,    KC_T,	KC_Y,	  KC_U,    KC_I,	KC_O,	 KC_P,	   KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,	   KC_S,	 KC_D,	  KC_F,    KC_G,              KC_H,    KC_J,	KC_K,	 KC_L,	   KC_SCLN,  KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,	 KC_X,	  KC_C,    KC_V,	KC_B,	  KC_B,    KC_N,	KC_M,	 KC_COMM,  KC_DOT,	 KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPTN, KC_LCMMD,          LT(FN3, KC_SPC),  MO(FN1),  MO(FN2),          KC_SPC,             KC_RCMMD,           KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_69_ansi(
        KC_ESC,  KC_1,	   KC_2,	 KC_3,	  KC_4,    KC_5,	KC_6,	  KC_7,    KC_8,	KC_9,	 KC_0,	   KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,	   KC_W,	 KC_E,	  KC_R,    KC_T,	KC_Y,	  KC_U,    KC_I,	KC_O,	 KC_P,	   KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, GUI_A,    ALT_S,	 CTL_D,	  SFT_F,   KC_G,              KC_H,    SFT_J,	CTL_K,	 ALT_L,	   GUI_SCLN, KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,	 KC_X,	  KC_C,    KC_V,	KC_B,	  KC_B,    KC_N,	KC_M,	 KC_COMM,  KC_DOT,	 KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,           LT(FN3, KC_SPC),  MO(FN1),  MO(FN2),          KC_SPC,            KC_RALT,            KC_LEFT, KC_DOWN, KC_RGHT),
        
    [FN2] = LAYOUT_69_ansi(
        KC_TILD, KC_F1,    KC_F2,	 KC_F3,   KC_F4,   KC_F5,	KC_F6,	  KC_F7,   KC_F8,	KC_F9,	 KC_F10,   KC_F11,	 KC_F12,   _______,          _______,
        _______, _______,  KC_HOME,  KC_UP,   KC_END,  _______, KC_NUM,   KC_P7,   KC_P8,   KC_P9,   KC_SLSH,  KC_ASTR,  KC_PMNS,  _______,          _______,
        _______, _______,  ALT_LFT,  CTL_DWN, SFT_RGT, _______,           _______, SFT_4,   CTL_5,   ALT_6,    GUI_PLS,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, _______,  _______, _______, KC_P1,   KC_P2,    KC_P3,    KC_PEQL,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          KC_P0,             KC_PDOT,            _______, _______, _______),

    [FN1] = LAYOUT_69_ansi(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FILE, RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   BAT_LVL, _______,  _______, _______, _______, _______,  _______,	 _______,  _______,          KC_INS,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI,           _______, _______, _______, _______,  _______,  _______,  _______,          KC_END,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, KC_PGUP,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, KC_PGDN, _______),
        
    [FN3] = LAYOUT_69_ansi(
        _______, _______, _______,    _______,     _______,       _______, _______, _______, _______,    _______,    _______, _______, _______, _______,          _______,
        _______, _______, _______,    _______,     _______,       _______, _______, _______, _______,    _______,    _______, _______, _______, _______,          _______,
        _______, TD(TD_ADR), TD(TD_NAME), TD(TD_MAIL), TD(TD_LOG), _______,         _______, TD(TD_TEL), TD(TD_CRD), _______, _______, _______, _______,          _______,
        _______,          _______,    _______,     _______,       _______, _______, _______, _______,    _______,    _______, _______, _______, _______, _______,
        _______, _______, _______,                 _______,                _______, _______,             _______,             _______,          _______, _______, _______)
        
    // [EMPTY] = LAYOUT_69_ansi(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,          _______,
    //     _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______,          _______,          _______, _______,          _______,          _______,          _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
	const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
		[MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
		[WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
		[FN1]      = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
		[FN2]	   = {ENCODER_CCW_CW(_______, _______)},
		[FN3]	   = {ENCODER_CCW_CW(_______, _______)},
	};
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) { 
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_RED);
                }
            }
        }
    }
    return false;
}