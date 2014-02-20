/*
  LED bar library V1.0
  2010 Copyright (c) Seeed Technology Inc.  All right reserved.

  Original Author: LG
  
  Modify: Loovee, 2014-2-26

  User can choose which Io to be used.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef __LED_BAR_H__
#define __LED_BAR_H__

#define CMDMODE     0x0000                          // Work on 8-bit mode
#define ON          0x00ff                          // 8-bit 1 data
#define SHUT        0x0000                          // 8-bit 0 data


void led_bar_init(int pin_clk, int pin_dta);
void led_bar_index_bit(unsigned int index_bits);
void led_bar_set_level(int level);
void led_bar_set_single_led(int num, int st);



#endif
