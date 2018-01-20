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
#include "utilities.h"
#include "system_LPC17xx.h"
#include "lpc17xx.h"
#include "GLCD.h"

#define extern
#define CHANNEL_DATA_AVAILABLE      0x01

#include "type.h"
#include "EMAC.h"         // Keil: *.c -> *.h    // ethernet packet driver
#include "tcpip.h"        // Keil: *.c -> *.h    // easyWEB TCP/IP stack

#define TEXT_TRY "Cantami, o Diva, del pelide Achille l'ira funesta che\
 infiniti addusse lutti agli Achei, molte anzi tempo all'Orco\
 generose travolse alme d'eroi,\
 e di cani e d'augelli orrido pasto\
 lor salme abbandono' (cosi' di Giove\
 l'alto consiglio s'adempia), da quando\
 primamente disgiunse aspra contesa\
 il re de' prodi Atride e il divo Achille"

unsigned int pagecounter = 100;
unsigned int adcValue    =   0;
extern uint32_t SystemFrequency;
unsigned char ChannelStatus = 0;
extern void TCPClockHandler(void);
char prova[] = "prova";
uint8_t PASSWORD_SENT = 0x0;
char password[8];
unsigned char* stringa = "ARMA. Startup...";
unsigned char response[MAX_TCP_RX_DATA_SIZE];

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
	char val;
	int i = 0; 

  SystemInit();                                      /* setup core clocks */
  SysTick_Config(SystemFrequency/100);               /* Generate interrupt every 10 ms */

	joystick_init();
	GLCD_Init();
	GLCD_Clear(Black);
	GLCD_SetBackColor(Black);
	GLCD_SetTextColor(Green);
	GLCD_DisplayString(0, 0, stringa);
	//GLCD_DisplayText(0,0,TEXT_TRY);
	
	while(i < 8) {
		val = convertInputToChar(joystick_get_input());
		if(val != 'q'){
			password[i] = val;
			i++;
		}
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
  *((unsigned char *)RemoteIP + 3) = 8;
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
    if (SocketStatus & SOCK_DATA_AVAILABLE) {   // check if remote TCP sent data
      memcpy(response, TCP_RX_BUF, TCPRxDataCount);   // ARMBROs: fill our buffer with incoming data
			TCPReleaseRxBuffer();                           // Release the buffer, and signal that new data is available   
      ChannelStatus |= CHANNEL_DATA_AVAILABLE; 
    }
    if (SocketStatus & SOCK_TX_BUF_RELEASED)     // check if buffer is free for TX
    {
			TCPTxDataCount = sizeof(password);
      memcpy(TCP_TX_BUF, password, sizeof(password)); // send the password on the wire
      TCPTransmitTxBuffer();
      PASSWORD_SENT = 0x1;       
    }

    if (ChannelStatus & CHANNEL_DATA_AVAILABLE){
      GLCD_DisplayString(response);
      ChannelStatus &= ~CHANNEL_DATA_AVAILABLE;
    }
  }
}

