#include "lpc17xx.h"


void speaker_init(){
  LPC_PINCON->PINSEL1 |= (0 << 21);
  LPC_GPIO0->FIODIR  = 0x04000000;  	// set direction of port 20 to output
}
