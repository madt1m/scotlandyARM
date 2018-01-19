#include <stdint.h>
#include <stdio.h>
#include "utilities.h"
#include "joystick.h"


char convertInputToChar(uint8_t val){
	switch(val) {
		case(JOYSTICK_UP):
			return 'u';
		case(JOYSTICK_DOWN):
			return 'd';
		case(JOYSTICK_LEFT):
			return 'l';
		case(JOYSTICK_RIGHT):
			return 'r';
		case(JOYSTICK_SELECT):	//Pressing the button will end the input phase
			return 's';
		default:
			return 'q';
	}
}

void delay(int c){
	int i = 0;
	for(i = 0; i < c*275;){
		i++;
	}
}

