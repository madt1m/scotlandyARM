/*
* Test file for scotlandyARM project.
* All the equipment will be tested here
* - Joystick, Display, Ethernet
* No weapon provided.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "joystick.h"
#include "system_LPC17xx.h"
#include "timer.h"
#include "lpc17xx.h"

#define extern

#include "type.h"
#include "EMAC.h"         // Keil: *.c -> *.h    // ethernet packet driver
#include "tcpip.h"        // Keil: *.c -> *.h    // easyWEB TCP/IP stack

unsigned int pagecounter = 100;
unsigned int adcValue    =   0;
extern uint32_t SystemFrequency;

extern void TCPClockHandler(void);
char prova[] = "prova";

volatile DWORD TimeTick  = 0;

void SysTick_Handler (void) {
  TimeTick++;
  if (TimeTick >= 20) {
    TimeTick = 0;
    LPC_GPIO2->FIOPIN ^= 1 << 0;
    TCPClockHandler();  
  }  
}

void Channel(void);

int main(){

 

	uint8_t val;
  uint8_t test_array[8];
	char password[8];
	int i = 0; 
  uint8_t PASSWORD_SENT = 0x0;

  SystemInit();                                      /* setup core clocks */
  SysTick_Config(SystemFrequency/100);               /* Generate interrupt every 10 ms */

	joystickInit();
	enable_timer(0);

	while(1) {
		val = joystick_get_input();
		delayMs(0, 5000);
		//test_array[i] = val;
    password[i] = convertInputToChar(val);
		i++;
	}

  LPC_GPIO0->FIODIR   |= 1 << 21;					// ÉèÖÃLEDÓÐÐ§
  LPC_GPIO0->FIOPIN	  |= 1 << 21;

  LPC_GPIO2->FIODIR   |= 1 << 0;                    /* P2.0 defined as Output (LED) */

  LPC_PINCON->PINSEL3 |=  (3ul<<30);                   /* P1.31 is AD0.5 */
  LPC_SC->PCONP       |=  (1<<12);                   /* Enable power to ADC block */
  LPC_ADC->ADCR        =  (1<< 5) |                  /* select AD0.5 pin */
                          (4<< 8) |                  /* ADC clock is 25MHz/5 */
                          (1<<21);                   /* enable ADC */ 
  TCPLowLevelInit();

   *(unsigned char *)RemoteIP = 192;               // inserisco l'ip del nostro server remoto
  *((unsigned char *)RemoteIP + 1) = 168;          
  *((unsigned char *)RemoteIP + 2) = 1;        
  *((unsigned char *)RemoteIP + 3) = 7;
	TCPLocalPort = 12345;
	TCPRemotePort = 12007;
  TCPActiveOpen();

  while(1){
  	DoNetworkStuff();
    Channel();
  }
}


void Channel() {
  if (SocketStatus & SOCK_CONNECTED)             // check if somebody has connected to our TCP
  {
    if (SocketStatus & SOCK_DATA_AVAILABLE && !PASSWORD_SENT) {     // check if remote TCP sent data
      TCPReleaseRxBuffer(); 
    }
    else{

    }
      if (SocketStatus & SOCK_TX_BUF_RELEASED)     // check if buffer is free for TX
      {
        memcpy(TCP_TX_BUF, password, sizeof(password)-1);
        TCPTransmitTxBuffer();
        PASSWORD_SENT = 0x1; 
      }
    }
  }
}

}

