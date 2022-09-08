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

#define IODIRA 0x00 // Input / Output config bit for port A / B: see page 12 of the MCP datasheet
#define IODIRB 0x01
#define GPPUA 0x0C // internal pull up registers addresses
#define GPPUB 0x0D
#define GPIOA 0x12 // General purpose data port A / B addresses
#define GPIOB 0x13

typedef int16_t mcp23017_status_t;

void              mcp23017_init(void);
bool              mcp23017_reset_required(void);
mcp23017_status_t mcp23017_writeReg(uint8_t regaddr, const uint8_t* data, uint16_t length);
mcp23017_status_t mcp23017_readReg(uint8_t regaddr, uint8_t* data, uint16_t length);
