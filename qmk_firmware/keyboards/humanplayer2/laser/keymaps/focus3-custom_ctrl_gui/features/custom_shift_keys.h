// Copyright 2021 Google LLC.
// SPDX-License-Identifier: Apache-2.0

#pragma once
#include QMK_KEYBOARD_H

// Shift
typedef struct {
  uint16_t keycode;
  uint16_t shifted_keycode;
} custom_shift_key_t;

extern const custom_shift_key_t custom_shift_keys[];
extern uint8_t NUM_CUSTOM_SHIFT_KEYS;

bool process_custom_shift_keys(uint16_t keycode, keyrecord_t *record);

// LCTL
typedef struct {
  uint16_t keycode;
  uint16_t lctled_keycode;
} custom_lctl_key_t;

extern const custom_lctl_key_t custom_lctl_keys[];
extern uint8_t NUM_CUSTOM_LCTL_KEYS;

bool process_custom_lctl_keys(uint16_t keycode, keyrecord_t *record);

// LGUI
typedef struct {
  uint16_t keycode;
  uint16_t lguied_keycode;
} custom_lgui_key_t;

extern const custom_lgui_key_t custom_lgui_keys[];
extern uint8_t NUM_CUSTOM_LGUI_KEYS;

bool process_custom_lgui_keys(uint16_t keycode, keyrecord_t *record);

// RGUI
typedef struct {
  uint16_t keycode;
  uint16_t rguied_keycode;
} custom_rgui_key_t;

extern const custom_rgui_key_t custom_rgui_keys[];
extern uint8_t NUM_CUSTOM_RGUI_KEYS;

bool process_custom_rgui_keys(uint16_t keycode, keyrecord_t *record);
