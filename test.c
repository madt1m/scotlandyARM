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
#include "timer.h"

int main(){

	uint8_t val;
	uint8_t password[10];
	int i = 0;
	joystickInit();
	enable_timer(0);
	while(1) {
		val = joystickRead();
		delayMs(0, 5000);
		password[i] = val;
		i++;
	}
}