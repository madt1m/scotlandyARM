#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "speaker.h"
#include "timer.h"

/********************************************************
The idea is to send 1 and 0s to the speaker to make it 
pitch at the given frequency, for the given duration.
We will use two timer for the purpose.
NOTE: duration has to be provided in ms, frequency in Hz
********************************************************/

unsigned char TIME_ELAPSED = 0x0;

void tone(unsigned int duration, unsigned int frequency){
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


