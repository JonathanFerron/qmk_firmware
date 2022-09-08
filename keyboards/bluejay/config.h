/*
 * Copyright 2022 Jonathan Ferron https://github.com/JonathanFerron
 * Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com)
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

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 12

/*
 * Keyboard Matrix Assignments
 *
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 */
#define MATRIX_ROW_PINS \
    { D0, D1, B1, B2, B3 } // Left hand (master side), scan from top (row 1) to bottom (row 5)
#define MATRIX_COL_PINS \
    { C0, C1, C2, C3, D7, B0 } // Left hand (master side), sacn from left (col F) to right (col A)
#define UNUSED_PINS

#define SECONDARY_ROW_PINS \
    { (1 << 7), (1 << 6), (1 << 1), (1 << 0), (1 << 15) } // Right hand (MCP side), scan from top (row 1) to bottom (row 5): A7, A6, A1, A0, B7 (8+7)
#define SECONDARY_COL_PINS \
    { (1 << 2), (1 << 3), (1 << 8), (1 << 9), (1 << 10), (1 << 11) } // Right hand (MCP side), scan from left (col A) to right (col F): A2, A3, B0, B1, B2, B3

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION ROW2COL

#define USB_MAX_POWER_CONSUMPTION 100

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
