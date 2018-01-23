#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"
#include "joystick.h"
#include "lpc17xx.h"
#include "system_LPC17xx.h"
#include "tcpip.h"
#include "timer.h"
#include "GLCD.h"

//#define BAR_STRING 					"*==================*"
unsigned char TIME_ELAPSED = 0x0;
volatile DWORD TimeTick = 0;

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

void delay(int c){
	int i = 0;
	for(i = 0; i < c*275;){
		i++;
	}
}

/********************************************************
The idea is to send 1 and 0s to the speaker to make it 
pitch at the given frequency, for the given duration.
We will use two timer for the purpose.
NOTE: duration has to be provided in ms, frequency in Hz
********************************************************/

void tone(unsigned int duration, unsigned int frequency){
	extern uint32_t SystemFrequency;
	TIME_ELAPSED = 0x0;
	// Outer timer to handle duration
	init_timer(1, duration*(25000000/1000));
	init_timer(0, (25000000)/(2*frequency));
	
	enable_timer(0);
	enable_timer(1);
	while(!TIME_ELAPSED){
	}
	reset_timer(1);
	reset_timer(0);
	disable_timer(1);
	disable_timer(0);
}

void speaker_init(){
	LPC_PINCON->PINSEL1 |= (0 << 21);
  LPC_GPIO0->FIODIR  = 0x04000000;  	// set direction of port 20 to output
}

void playMusic(char* s){

	unsigned int musical_notes[MUSICAL_NOTES_NUMBER] = {440,466,494,523,554,587,622,659,698,740,785,831,
												880, 932, 988, 1046, 1108, 1174, 1244, 1318, 1397, 1480, 1568, 1661, 1};
	// notes will be encoded with up to 2 characters, delay with up to 4
	char note[3];
	char duration[5];
	unsigned char counter = 2;
	memset(note,0,sizeof(note));
	memset(duration,0,sizeof(duration));
	while(*s){
		while(counter){
			while(*s != ' ' && *s){
				if(counter == 2){
					note[strlen(note)] = *s;
				}
				else if(counter ==	1){
					duration[strlen(duration)] = *s;
				}
				s++;
			}
			if(*s)
				s++;
		counter--;
		}		
		tone(atoi(duration), musical_notes[atoi(note)]);
		counter = 2;
		memset(note, 0, sizeof(note));
		memset(duration, 0, sizeof(duration));
	}
}

unsigned char menuHandler(char** text, char* CHOICE_CUSTOM_TEXT, unsigned int NUM_ENTRIES){
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
					current++;
				}
				break;
			case JOYSTICK_DOWN:
				if(current < NUM_ENTRIES){
					current--;
				}
				break;
			default:
				break;
		}
	}
	return current;
}

void welcome() {
	char line[20];
	char *p = line;
	int i, j, r;
	TIME_ELAPSED = 0x0;

	init_timer(1, 4000*(25000000/1000));
	enable_timer(1);
	srand(8);   // should only be called once
	j=0;
	
	while(!TIME_ELAPSED){
		for (i = 0; i < sizeof(line); i++) {
			r = rand()%2;
			sprintf(p, "%d", r);
			p++;
		}
		GLCD_DisplayString(j,0,line);
		j++;
		if(j == 9)
			j=0;
	}
	reset_timer(1);
	disable_timer(1);
	GLCD_Clear(Black);
	delayMs(0, 2000);
	return;
}

void praiseTheEmpire() {
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





	



	
	
