/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

//#define USE_MATRIX_I2C

// Make tap-hold keys trigger whenever another key is pressed.
#define PERMISSIVE_HOLD_PER_KEY
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// prevents repeating the same key when tapping the key twice
#define QUICK_TAP_TERM 0

// Sets the duration in milliseconds before a tap becomes a hold
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 200

// Saves memory by reducing layers count
#define LAYER_STATE_16BIT

// Sets the mouse key speed to constant
#define MK_3_SPEED
// Hold to accelerate mouse keys
#define MK_MOMENTARY_ACCEL
// combined acceleration
#define MK_COMBINED

// Mouse key acceleration
#define MK_C_INTERVAL_0 8
#define MK_C_INTERVAL_1 16
#define MK_C_INTERVAL_2 32

// enable wpm counter
#define SPLIT_WPM_ENABLE

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 64

#define OLED_BRIGHTNESS 0
