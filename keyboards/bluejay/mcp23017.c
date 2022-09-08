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
#include "i2c_master.h"
#include "mcp23017.h"

#define MCP23017_ADDR 0b0100000

#define MCP23017_TIMEOUT 100

static i2c_status_t mcp23017_status = I2C_STATUS_ERROR;

void mcp23017_init(void) {
    mcp23017_status = I2C_STATUS_SUCCESS;

    // port a from a7 to a0: rowl, row2, unused, unused, colB, colA, row3, row4: RRUUCCRR
    // port b from b7 to b0: row5, unused, unused, unused, colF, colE, colD, colC: RUUUCCCC

    // Set pin direction - A7..A0, B7..B0
    // 0 : output for column pins
    // 1 : input for row pins or for unused pins
    uint8_t iodir[] = {0b11110011, 0b11110000};
    mcp23017_writeReg(IODIRA, iodir, 2);

    // Set pull-up - A7..A0, B7..B0
    // 0 : pull-up off for column pins, or by default for unused pins
    // l : pull-up on for row pins
    uint8_t gppu[] = {0b11000011, 0b10000000};
    mcp23017_writeReg(GPPUA, gppu, 2);
}

bool mcp23017_reset_required(void) { return mcp23017_status != I2C_STATUS_SUCCESS; }

i2c_status_t mcp23017_writeReg(uint8_t regaddr, const uint8_t* data, uint16_t length) {
    if (mcp23017_status) {
        return mcp23017_status;
    }

    mcp23017_status = i2c_writeReg((MCP23017_ADDR << 1), regaddr, data, length, MCP23017_TIMEOUT);
    return mcp23017_status;
}

i2c_status_t mcp23017_readReg(uint8_t regaddr, uint8_t* data, uint16_t length) {
    if (mcp23017_status) {
        return mcp23017_status;
    }

    mcp23017_status = i2c_readReg((MCP23017_ADDR << 1), regaddr, data, length, MCP23017_TIMEOUT);
    return mcp23017_status;
}
