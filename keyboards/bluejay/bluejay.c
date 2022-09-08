/*
 * Copyright 2022 Jonathan Ferron
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
#include "bluejay.h"
#include "i2c_master.h"
#include "mcp23017.h"

void matrix_init_kb(void) {
    // keyboard start-up code
    // runs once when the firmware starts up
    i2c_init();

    // may need to manually set SDA and SCL internal pull-up here on the ATMega side: this is in case the master side is being used when not connected 
    // to the right hand side (since pull-up resistors are on the right hand side)
    // could be something like this:
    // digitalWrite(SDA, 1); or setPinInputHigh(C4);
    // digitalWrite(SCL, 1); or setPinInputHigh(C5);
    setPinInputHigh(C4);
    setPinInputHigh(C5);

    matrix_init_user();
}

void matrix_scan_kb(void) {
    // looping keyboard code
    // runs every cycle (a lot)
    if (mcp23017_reset_required()) {
        mcp23017_init();        
    }

    matrix_scan_user();    
}