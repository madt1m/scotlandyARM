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
#include "lpc17xx.h"
#include "GLCD.h"
#include "timer.h"
#include "type.h"
#include "EMAC.h"         // Keil: *.c -> *.h    // ethernet packet driver

#define extern

#include "tcpip.h"        // Keil: *.c -> *.h    // easyWEB TCP/IP stack
#include "channel.h"
#include "speaker.h"

volatile DWORD TimeTick = 0;
unsigned char* WRONG_PASSWORD  = {"I hope you had fun with the sound simulator! Have a great day"};
unsigned char* HAPPY_LINE = 	{":) XD :D =) :X xD :/ ;)"};
unsigned char OK_CODE[] = "200";
unsigned char* stringa = "Welcome onboard your SOUND SIMULATOR! Please use joystick and enjoy making music.";

unsigned char * TEXT_TRY = "Cantami, o Diva, del pelide Achille l'ira funesta che\
 infiniti addusse lutti agli Achei, molte anzi tempo all'Orco\
 generose travolse alme d'eroi,\
 e di cani e d'augelli orrido pasto\
 lor salme abbandono' (cosi' di Giove\
 l'alto consiglio s'adempia), da quando\
 primamente disgiunse aspra contesa\
 il re de' prodi Atride e il divo Achille";
unsigned char* MAIN_MENU[] = {"-Praise the Empire", 
"-Request TIE Bombers", 
"-What Sith are you?"};

unsigned char* QUESTION_1[] = {"-Trough a Mask","-Using a meat chunk"};
unsigned char* QUESTION_2[] = {"-Darth Vader","-Darth Fener"};
unsigned char* QUESTION_3[] = {"-Droid","-Wookie"};
unsigned char* DEVICE_VERSION = "iSith Device vIII";
unsigned char* CREDITS = "Powered by Force.";
unsigned char* BAR_LINE = "(=0=)(-0-)(-0-)(=0=)";

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


unsigned char* vader_ascii[] ={  "| _______||_______ |",
							  "|/ ----- \\/ ----- \\|",
							  "  (     )  (     )  ",
							  "\\  ----- () -----  /",
							  " \\      /||\\      / ",
							  "  \\    /||||\\    /  ",
							  "   \\  /||||||\\  /   ",
							  "    \\o========o/    ",
							  "..__|`-._  _.-'|__..",
							  "    |    `'    |     "};

unsigned char* tie_ascii[] = {" /  _  \\ ",
						   "|-=(_)=-|",
						   " \\     / "};

unsigned char* binary_strings[] = {"0110110 1 011 10 10 10",
																		"0101 01 0010 101 000101010",
																	 "010110 01 10 10 1011 01  1",
																	 "010111 1 1 01 1100110  1001",
	                                 "0101 010 0 10 10 11 1010 1 ",
																	 "1 101 001 10001 101 0 1010 ",
																	 " 1 11 11 00 101 01 01 01 01 0",
																	 "1 01010 111 01 001 1 1 01 01 0"};
unsigned char code;
unsigned char menu_choice[3];
unsigned char WAIT_FOR_BUFFER = 0x0;

	
int main(){
	char val; 
	int i = 0; 

  SystemInit();                                      /* setup core clocks */
  SysTick_Config(SystemFrequency/100);               /* Generate interrupt every 10 ms */

	ChannelStatus = CHANNEL_INIT;
	joystick_init();
	speaker_init();
	GLCD_Init();
	GLCD_Clear(White);
	GLCD_SetBackColor(White);
	GLCD_SetTextColor(DarkGreen);
	TCPRemotePort = init_port();
	GLCD_DisplayText(0, 0, stringa, White);
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
				case 's':
					tone(300, 650);
				default:
					break;
			}
			password[i] = val;
			i++;
		}
	}
	

  //LPC_GPIO0->FIODIR   |= 1 << 21;					// ÉèÖÃLEDÓÐÐ§
  //LPC_GPIO0->FIOPIN	  |= 1 << 21;

  TCPLowLevelInit();

   *(unsigned char *)RemoteIP = 192;               // inserisco l'ip del nostro server remoto
  *((unsigned char *)RemoteIP + 1) = 168;          
  *((unsigned char *)RemoteIP + 2) = 1;        
  *((unsigned char *)RemoteIP + 3) = 4;
	TCPLocalPort = 12345;
  TCPActiveOpen();
	//connection_open(192,168,1,8, 12345, 12345);
  while(1){
  	DoNetworkStuff();
    Channel();
  }
}


void Channel(){
		unsigned char code_to_send[1];
		int j;
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
				 	
				 	if(!strcmp(response, OK_CODE)) {
				 		
				 		delayMs(0,5000);
				 		playMusic(imperial_march_2);
				 		ChannelStatus = CHANNEL_CONNECTED;
				 		delayMs(0,2000);

				 		GLCD_Clear(Black);
    				delayMs(0, 2000);
						GLCD_SetBackColor(Black);
						GLCD_SetTextColor(Red);
						welcome();
				 	}
				 	else { 
				 		GLCD_DisplayText(2,0,WRONG_PASSWORD, White);
						delayMs(0,2000);
				 		j=0;
				 		while(1){
				 			GLCD_DisplayText(j, (j*3)%20 ,HAPPY_LINE, White);
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
    			if(code != 0) {
						code_to_send[0] = code;
	    			if (SocketStatus & SOCK_TX_BUF_RELEASED) { 
						TCPTxDataCount = sizeof(code_to_send);
				        memcpy(TCP_TX_BUF, code_to_send, sizeof(code_to_send));
				        TCPTransmitTxBuffer();
				    }
				}
				else{
					praiseTheEmpire();
					break;
				}
				ChannelStatus = CODE_SENT;
				break;

			case CODE_SENT:

				switch(code){
					case 1:
						if (SocketStatus & SOCK_DATA_AVAILABLE) {   // check if remote TCP sent data
				    		memcpy(response, TCP_RX_BUF, TCPRxDataCount);   // ARMBROs: fill our buffer with incoming data
							TCPReleaseRxBuffer();

							GLCD_DisplayText(0,0,response, Black);
							delayMs(0,2000);

							GLCD_DisplayString(7,0,tie_ascii[0]);
							GLCD_DisplayString(8,0,tie_ascii[1]);
							GLCD_DisplayString(9,0,tie_ascii[2]);
							delayMs(0,2000);

							GLCD_DisplayString(7,10,tie_ascii[0]);
							GLCD_DisplayString(8,10,tie_ascii[1]);
							GLCD_DisplayString(9,10,tie_ascii[2]);
							delayMs(0,2000);

							joystick_get_input();
							memset(response,0x0,sizeof(response));
							ChannelStatus = CHANNEL_CONNECTED;
						}
						break;
					case 2:
						if(!WAIT_FOR_BUFFER){
							menu_choice[0] = menuHandler(QUESTION_1, "You prefer breathing:", 2);
							menu_choice[1] = menuHandler(QUESTION_2, "Your favourite darth:", 2);
							menu_choice[2] = menuHandler(QUESTION_3, "Best pet ever:", 2);
						}
						WAIT_FOR_BUFFER = 0x01;
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
					
					GLCD_Clear(Black);
					GLCD_DisplayString(0,0,BAR_LINE);
					GLCD_DisplayString(1,0,DEVICE_VERSION);
					GLCD_DisplayText(3,0,response, Black);
					GLCD_DisplayString(8,0,CREDITS);
					GLCD_DisplayString(9,0,BAR_LINE);
					delayMs(0,2000);
					joystick_get_input();
					memset(response, 0x0, sizeof(response));
				ChannelStatus = CHANNEL_CONNECTED;
				WAIT_FOR_BUFFER = 0x0;
				}
				break;
		}
	}
}

void SysTick_Handler (void) {
  TimeTick++;
  if (TimeTick >= 20) {
    TimeTick = 0;
    LPC_GPIO2->FIOPIN ^= 1 << 0;
    TCPClockHandler();  
  }  
}


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


unsigned char menuHandler(unsigned char** text, unsigned char* CHOICE_CUSTOM_TEXT, unsigned int NUM_ENTRIES){
	unsigned char current = 0;
	int j;
	unsigned char val = 0X0;

	GLCD_Clear(Black);
	GLCD_DisplayString(0,0,BAR_LINE);
	GLCD_DisplayString(1,0,DEVICE_VERSION);
	GLCD_DisplayString(2,0,CHOICE_CUSTOM_TEXT);
	GLCD_DisplayString(8,0,CREDITS);
	GLCD_DisplayString(9,0,BAR_LINE);

//	GLCD_DisplayString(4,0,MENU);
	while(val != JOYSTICK_SELECT) {

		for(j=0; j < NUM_ENTRIES; j++){
			if(current == j){
				GLCD_SetBackColor(LightGrey);
			}
			else{
				GLCD_SetBackColor(Black);
			}
			GLCD_DisplayString(j+4,0,text[j]);
		}

		val = joystick_get_input();
		switch(val){
			case JOYSTICK_UP:
				if(current > 0){
					current--;
				}
				break;
			case JOYSTICK_DOWN:
				if(current < NUM_ENTRIES-1){
					current++;
				}
				break;
			default:
				break;
		}
	}
	GLCD_SetBackColor(Black);
	return current;
}

void welcome() {
	int j;
	unsigned int count = 0;
	TIME_ELAPSED = 0x0;
	

	init_timer(1, 4000*(25000000/1000));
	enable_timer(1);
	srand(8);   // should only be called once
	j=0;

	while(!TIME_ELAPSED){
		GLCD_DisplayString(j,0,binary_strings[rand()%8]);
		j++;
		if(j == 10)
			j=0;
		count++;		
	}
	reset_timer(1);
	disable_timer(1);
	GLCD_Clear(Black);
	delayMs(0, 2000);
	return;
}

void praiseTheEmpire(){
	unsigned int musical_notes[MUSICAL_NOTES_NUMBER] = {440,466,494,523,554,587,622,659,698,740,785,831,
																							880, 932, 988, 1046, 1108, 1174, 1244, 1318, 1397, 1480, 1568, 1661, 1};
	GLCD_Clear(Black);
	
	GLCD_DisplayString(0,0,vader_ascii[0]);
	tone(500, musical_notes[10]);
	tone(100, musical_notes[24]);

	GLCD_DisplayString(1,0,vader_ascii[1]);
	tone(500, musical_notes[10]);
	tone(100, musical_notes[24]);
	
	GLCD_DisplayString(2,0,vader_ascii[2]);
	tone(500, musical_notes[10]);
	tone(100, musical_notes[24]);
	
	GLCD_DisplayString(3,0,vader_ascii[3]);
	tone(300, musical_notes[6]);
	tone(100, musical_notes[24]);
	
	GLCD_DisplayString(4,0,vader_ascii[4]);
	tone(100, musical_notes[13]);
	tone(50, musical_notes[24]);
	
	GLCD_DisplayString(5,0,vader_ascii[5]);
	tone(500, musical_notes[10]);
	tone(50, musical_notes[24]);
	
	GLCD_DisplayString(6,0,vader_ascii[6]);
	tone(300, musical_notes[6]);
	tone(100, musical_notes[24]);
	
	GLCD_DisplayString(7,0,vader_ascii[7]);
	tone(100, musical_notes[13]);
	tone(50, musical_notes[24]);

	GLCD_DisplayString(8,0,vader_ascii[8]);
	tone(800, musical_notes[10]);
	tone(100, musical_notes[24]);

	GLCD_DisplayString(9,0,vader_ascii[9]);
	playMusic(imperial_march_2);
	delayMs(0, 5000);
	return;
}

int init_port(){
	char val = convertInputToChar(joystick_get_input());
	if(val == 'u'){
		return 12007;
	}
	else{
		return 13007;
	}
}
	

