/*
 * Copyright 2022 Jonathan Ferron https://github.com/JonathanFerron 
 * Copyright 2020 Richard Titmuss (richard.titmuss@gmail.com)
 * Copyright 2012-2018 Jun Wako, Jack Humbert, Yiancar
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
#include "mcp23017.h"

#define SPLIT_MATRIX_COLS (MATRIX_COLS / 2)
//#define SECONDARY_ROW_OFFSET (MATRIX_ROWS / 2)

typedef uint16_t mcp23017_pin_t;

static const pin_t          row_pins[MATRIX_ROWS]                 = MATRIX_ROW_PINS; // those are defined in config.h
static const pin_t          col_pins[SPLIT_MATRIX_COLS]           = MATRIX_COL_PINS;
static const mcp23017_pin_t secondary_row_pins[MATRIX_ROWS]       = SECONDARY_ROW_PINS;
static const mcp23017_pin_t secondary_col_pins[SPLIT_MATRIX_COLS] = SECONDARY_COL_PINS;
 
// custom matrix scanning code for Row2Col diode direction

static void select_col(uint8_t col) {
    setPinOutput(col_pins[col]);
    writePinLow(col_pins[col]);
}

static void unselect_col(uint8_t col) { setPinInputHigh(col_pins[col]); }

static void unselect_cols(void) {
    for (uint8_t y = 0; y < SPLIT_MATRIX_COLS; y++) {
        setPinInputHigh(col_pins[y]);
    }
}

static void select_secondary_col(uint8_t col) {
    uint8_t gpioa = 0xFF & ~secondary_col_pins[col];
    mcp23017_writeReg(GPIOA, &gpioa, 1);
}

static void init_pins(void) {
    unselect_cols();
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        setPinInputHigh(row_pins[x]);
    }
}

static matrix_col_t read_rows(void) {
    matrix_col_t state = 0;

    // For each row...
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        // Select the row pin to read (active low)
        uint8_t pin_state = readPin(row_pins[row_index]);

        // Populate the matrix col with the state of the row pin
        state |= pin_state ? 0 : (MATRIX_COL_SHIFTER << row_index);
    }

    return state;
}

static matrix_col_t read_secondary_rows(void) {
    matrix_col_t state = 0;

    uint8_t mcp23017_pin_state[2];
    if (mcp23017_readReg(GPIOA, mcp23017_pin_state, 2)) {
        return 0;
    }

    uint16_t pins = mcp23017_pin_state[0] | (mcp23017_pin_state[1] << 8);

    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        uint16_t pin_state = pins & (secondary_row_pins[row_index]);
        state |= pin_state ? 0 : (MATRIX_COL_SHIFTER << row_index);
    }

    return state;
}

static bool read_rows_on_col(matrix_col_t current_matrix[], uint8_t current_col) {
    matrix_col_t last_col_value = current_matrix[current_col];

    select_col(current_col);
    select_secondary_col(current_col);

    current_matrix[current_col] = read_rows() | (read_secondary_rows() << 6);

    unselect_col(current_col);

    return (last_col_value != current_matrix[current_col]);
}

void matrix_init_custom(void) { init_pins(); }

bool matrix_scan_custom(matrix_col_t current_matrix[]) {
    bool changed = false;

    for (uint8_t current_col = 0; current_col < SPLIT_MATRIX_COLS; current_col++) {
        changed |= read_rows_on_col(current_matrix, current_col);
    }

    return changed;
}
