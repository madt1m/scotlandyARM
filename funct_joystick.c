/**
* filename: funct_joystick.c
* last_modified: 12/01/2018
* <-------->
* Contains high level functions controlling Joystick peripheral
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lpc17xx.h"
#include "timer.h"


uint8_t joystick_get_input() {

		uint8_t old_value = 0x80;
		uint8_t value = old_value;
		
		while(1) {
			value = (LPC_GPIO1->FIOPIN >> 25) & 0x1F;
			if(value != old_value && old_value != 0x80) {
				delayMs(0, 50);
				return value;
			}
			if(old_value == 0x80){
				old_value = value;
			}
		}
}
