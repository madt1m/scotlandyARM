
#include "lpc17xx.h"


void joystickInit() {
/*
  LPC_GPIO1->FIODIR   &= ~((1<<25)|(1<<26)|
                           (1<<27)|(1<<28)|. 
                           (1<<29)           );  P1.25..29    is input  (Joystick)
* Fast GPIO Port Direction Control Register --> Set pin direction (Input/Output)
* Fast Port Pin Value Register --> The current state of the pins can be read from the register Writing in this register will set those pins.
*/
  LPC_GPIO1->FIODIR = 0x00000000;  // li metto in input (0 input, 1 output)    
}
