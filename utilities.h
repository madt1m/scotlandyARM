#ifndef __UTILITIES_H
#define __UTILITIES_H

#include <stdint.h>
#include "type.h"

/***********************************************************
This is the provided encoding for our playMusic function. We modeled
the A4 chromatic scale, with the following mappings: 
A4			0
Bb4			1 
B4			2
C5			3
Db5			4
D5			5
Eb5			6
E5			7
F5			8
Gb5			9
G5			10
Ab5			11
A5			12
Bb5			13
B5			14
C6			15
Db6			16
D6			17
Eb6			18
E6			19
F6			20
Gb6			21
G6			22
Ab6			23
PAUSE		24
A song will have to be written as a string structured as follows:
"<NOTE_CODE><DURATION_IN_MS><NOTE_CODE><DURATION_IN_MS>..."
To change used notes, or change encoding, modify the musical_notes array.
**************************************************************/
#define MUSICAL_NOTES_NUMBER	25 
#define MAIN_MENU = {"-Praise the Empire",
				"-Request TIE Bombers",
				"-What Sith are you?"}

#define QUESTION_1 = {"-Trough a Mask",
					  "-Using a meat chunk"}
#define QUESTION_2 = {"-Darth Vader",
					  "-Darth Fener"}
#define QUESTION_3 = {"-Wookie",
					  "-Droid"}


#define DEVICE_VERSION = {"iSith Device vIII"}
#define CHOICE_CUSTOM_TEXT = {"GRAB AN OPTION:"}
#define CREDITS = {"Powered by Force."}
#define BAR_LINE = {"(=0=)(-0-)(-0-)(=0=)"}


const char* vader_ascii[] ={  "| _______||_______ |",
							  "|/ ----- \\/ ----- \\|",
							  "  (     )  (     )  ",
							  "\\  ----- () -----  /",
							  " \\      /||\\      / ",
							  "  \\    /||||\\    /  ",
							  "   \\  /||||||\\  /   ",
							  "    \\o========o/    ",
							  "..__|`-._  _.-'|__..",
							  "    |    `'    |     "};

const char* tie_ascii[] = {" /  _  \\ ",
						   "|-=(_)=-|",
						   " \\     / "};


void SysTick_Handler(void);
char convertInputToChar(uint8_t);
void delay(int);
void tone(unsigned int duration, unsigned int frequency);
void speaker_init(void);
void playMusic(char* s);
unsigned char menuHandler(unsigned char** text, unsigned char* CHOICE_CUSTOM_TEXT, unsigned int NUM_ENTRIES);
void welcome(void);


#endif
