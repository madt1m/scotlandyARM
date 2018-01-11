#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "lpc17xx.h"
#include "timer.h"

uint8_t joystickRead() {

		uint8_t old_value = 0x80;
		uint8_t value = old_value;
		uint8_t toreturn;
		
		while(1) {
			value = (LPC_GPIO1->FIOPIN >> 25) & 0x1F;
			if(value != old_value && old_value != 0x80) {
				delayMs(0, 5000);
				return value;
			}
			if(old_value == 0x80){
				old_value = value;
			}
		}
}
