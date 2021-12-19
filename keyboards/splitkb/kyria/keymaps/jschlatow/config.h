/* Copyright 2021 Johannes Schlatow
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

#pragma once

// Lets you roll mod-tap keys
#define IGNORE_MOD_TAP_INTERRUPT
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// customise tapping term and toggle
#define TAPPING_TOGGLE 2
#define TAPPING_TERM   300

/**
 * using the right side as master to allow for trackpoint/trackball
 *
 * As a consequence of this, we must disable synching the OLED state and add
 * synching the layer state.
 */
#define MASTER_RIGHT
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#undef  SPLIT_OLED_ENABLE

#define PS2_MOUSE_X_MULTIPLIER 3
#define PS2_MOUSE_Y_MULTIPLIER 3
#define PS2_MOUSE_H_MULTIPLIER 1
#define PS2_MOUSE_V_MULTIPLIER 1
#define PS2_MOUSE_ROTATE 180

#ifdef PS2_USE_INT
#define PS2_MOUSE_DEBUG_RAW
#define PS2_CLOCK_PIN  D0
#define PS2_DATA_PIN   D1
#define PS2_INT_INIT()  do {    \
    EICRA |= ((1<<ISC01) |      \
              (0<<ISC00));      \
} while (0)
#define PS2_INT_ON()  do {      \
    EIMSK |= (1<<INT0);         \
} while (0)
#define PS2_INT_OFF() do {      \
    EIMSK &= ~(1<<INT0);        \
} while (0)
#define PS2_INT_VECT   INT0_vect
#endif
