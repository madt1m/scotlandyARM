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
#include "bmp_logo.h"
#include "timer.h"

#define extern
#define CHANNEL_DATA_AVAILABLE      0x01
#define PASSWORD_LEN				9
#define WRONG_PASSWORD  = {"I hope you had fun with the sound simulator! Have a great day"}
#define HAPPY_LINE = 	{":) XD :D =) :X xD :/ ;)"}


unsigned char ChannelStatus;
#define CHANNEL_INIT				0x00
#define PASSWORD_SENT 				0x01
#define WAIT_FOR_PROFILE			0x02
#define CHANNEL_CONNECTED 			0x04
#define CODE_SENT 					0x08




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


char* imperial_march = 
"10 500 24 100\
 10 500 24 100\
 10 500 24 100\
 6 300 24 100\
 13 100 24 50\
 10 500 24 50\
 6 300 24 100\
 13 100 24 50\
 10 800 24 50";

 char* imperial_march_2 = 
 "17 500 24 100\
  17 500 24 100\
  17 500 24 100\
  18 300 24 100\
  13 100 24 50\
  9 500 24 50\
  6 300 24 100\
  13 100 24 50\
  10 800 24 50";

unsigned int pagecounter = 100;
unsigned int adcValue    =   0;
extern unsigned int SystemFrequency;
extern void TCPClockHandler(void);
char prova[] = "prova";
char password[PASSWORD_LEN];
unsigned char* stringa = "Lord Vader personal device. Good morning, supreme lord. Please identify yourself, if you mind, your greatness.";
unsigned char response[MAX_TCP_RX_DATA_SIZE];
void Channel(void);

int main(){
	char val; 
	unsigned char code;
	unsigned char menu_choice[3];
	int i = 0; 
	int j;

  SystemInit();                                      /* setup core clocks */
  SysTick_Config(SystemFrequency/100);               /* Generate interrupt every 10 ms */

	ChannelStatus = CHANNEL_INIT;
	joystick_init();
	speaker_init();
	GLCD_Init();
	GLCD_Clear(White);
	GLCD_SetBackColor(White);
	GLCD_SetTextColor(DarkGreen);
	//GLCD_DisplayText(0, 0, stringa);
	//GLCD_DisplayText(0,0,TEXT_TRY);
	//playMusic(imperial_march);
	while(i < PASSWORD_LEN) {
		val = convertInputToChar(joystick_get_input());
		if(val != 'q'){
			switch(val){
				case 'l':
					tone(300, 785);
					break;
				case 'd':
					tone(300, 622);
					break;
				case 'u':
					tone(300, 932);
					break;
				case 'r':
					tone(300, 800);
					break;
				default:
					break;
			}
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


void Channel(){

	if (SocketStatus & SOCK_CONNECTED){
		switch (ChannelStatus) {
			case CHANNEL_INIT:

				if (SocketStatus & SOCK_TX_BUF_RELEASED) {    // check if buffer is free for TX
					TCPTxDataCount = sizeof(password);
			        memcpy(TCP_TX_BUF, password, sizeof(password)); // send the password on the wire
			        TCPTransmitTxBuffer();
			        ChannelStatus = PASSWORD_SENT;       
    			}
    			break;

    		case PASSWORD_SENT:

    			if (SocketStatus & SOCK_DATA_AVAILABLE) {   // check if remote TCP sent data
				    memcpy(response, TCP_RX_BUF, TCPRxDataCount);   // ARMBROs: fill our buffer with incoming data
					TCPReleaseRxBuffer();                           // Release the buffer, and signal that new data is available   
				 	
				 	if(!strcmp(response, "200")) {
				 		
				 		delayMs(0,5000);
				 		playMusic(imperial_march_2);
				 		ChannelStatus = CHANNEL_CONNECTED;
				 		delayMs(0,2000);

				 		GLCD_Clear(Black);
    					delayMs(0, 2000)
						GLCD_SetBackColor(Black);
						GLCD_SetTextColor(Red);
						welcome();
				 	}
				 	else { 
				 		GLCD_DisplayText(4,0,WRONG_PASSWORD);
				 		j=0;
				 		while(1){
				 			GLCD_DisplayText(j, (j*3)%20 ,HAPPY_LINE);
				 			j++;
				 			if(j == 9)
				 				j=0;
				 		}
				 	}
				 	memset(response, 0x0, sizeof(response));
    			}
    			break;
    		case CHANNEL_CONNECTED:
    			code = menuHandler(MAIN_MENU, "GRAB AN OPTION:", 3);
    			if(code =! 1) {
	    			if (SocketStatus & SOCK_TX_BUF_RELEASED) {    // check if buffer is free for TX
						TCPTxDataCount = sizeof(code);
				        memcpy(TCP_TX_BUF, code, sizeof(code)); // send the password on the wire
				        TCPTransmitTxBuffer();
				    }
				}
				else{
					praiseTheEmpire();
				}

				ChannelStatus = CODE_SENT;
				break;

			case CODE_SENT:

				switch(code){
					case 2:
						if (SocketStatus & SOCK_DATA_AVAILABLE) {   // check if remote TCP sent data
				    		memcpy(response, TCP_RX_BUF, TCPRxDataCount);   // ARMBROs: fill our buffer with incoming data
							TCPReleaseRxBuffer();

							GLCD_DisplayText(1,0,response);
							delayMs(0,2000);

							GLCD_DisplayString(3,0,tie_ascii[0]);
							GLCD_DisplayString(4,0,tie_ascii[1]);
							GLCD_DisplayString(5,0,tie_ascii[2]);
							delayMs(0,2000);

							GLCD_DisplayString(3,10,tie_ascii[0]);
							GLCD_DisplayString(4,10,tie_ascii[1]);
							GLCD_DisplayString(5,10,tie_ascii[2]);
							delayMs(0,2000);

							GLCD_DisplayString(7,0,tie_ascii[0]);
							GLCD_DisplayString(8,0,tie_ascii[1]);
							GLCD_DisplayString(9,0,tie_ascii[2]);
							delayMs(0,2000);

							GLCD_DisplayString(7,10,tie_ascii[0]);
							GLCD_DisplayString(8,10,tie_ascii[1]);
							GLCD_DisplayString(9,10,tie_ascii[2]);
							delayMs(0,2000);

							joystick_get_input()
							memset(response,0x0,sizeof(response));
							ChannelStatus = CHANNEL_CONNECTED;
						}
						break;
					case 3:
						menu_choice[0] = menuHandler(MENU1, "You prefer breathing:", 2);
						menu_choice[1] = menuHandler(MENU2, "Your favourite darth:", 2);
						menu_choice[2] = menuHandler(MENU3, "Best pet ever:", 2);
						if (SocketStatus & SOCK_TX_BUF_RELEASED) {    // check if buffer is free for TX
							TCPTxDataCount = sizeof(menu_choice);
					        memcpy(TCP_TX_BUF, menu_choice, sizeof(menu_choice)); // send the password on the wire
					        TCPTransmitTxBuffer();
					        ChannelStatus = WAIT_FOR_PROFILE;
				    	}
						break;

				}
				break;

			case WAIT_FOR_PROFILE:
				if (SocketStatus & SOCK_DATA_AVAILABLE) {   // check if remote TCP sent data
				    memcpy(response, TCP_RX_BUF, TCPRxDataCount);   // ARMBROs: fill our buffer with incoming data
					TCPReleaseRxBuffer();
				}

				GLCD_Clear(Black);
				GLCD_DisplayString(0,0,BAR_LINE);
				GLCD_DisplayString(1,0,VERSION);
				GLCD_DisplayString(4,0,response);
				GLCD_DisplayString(8,0,CREDITS);
				GLCD_DisplayString(9,0,BAR_LINE);
				joystick_get_input();
				memset(response, 0x0, sizeof(response));
				ChannelStatus = CHANNEL_CONNECTED;
				break;
		}
	}
}


void Channel() {
  if (SocketStatus & SOCK_CONNECTED)             // check if somebody has connected to our TCP
  {
    
    

    if (ChannelStatus & CHANNEL_DATA_AVAILABLE){
      GLCD_DisplayText(0,0,response);
      ChannelStatus &= ~CHANNEL_DATA_AVAILABLE;
    }
  }
}

