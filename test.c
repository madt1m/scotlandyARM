/*
* Test file for scotlandyARM project.
* All the equipment will be tested here
* - Joystick, Display, Ethernet
* No weapon provided.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "joystick.h"


int main(){

	uint8_t val;
	uint8_t password[10];
	int i = 0;
	joystickInit();
	while(1) {
		val = joystickRead();
		password[i] = val;
		i++;
	}
}