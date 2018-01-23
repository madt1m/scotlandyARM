#ifndef __CHANNEL_H
#define __CHANNEL_H

#include "type.h"

extern volatile DWORD TimeTick;

#define CHANNEL_DATA_AVAILABLE      0x01
#define PASSWORD_LEN				9
extern unsigned char* WRONG_PASSWORD;
extern unsigned char* HAPPY_LINE;

unsigned char ChannelStatus;
#define CHANNEL_INIT				0x00
#define PASSWORD_SENT 				0x01
#define WAIT_FOR_PROFILE			0x02
#define CHANNEL_CONNECTED 			0x04
#define CODE_SENT 					0x08

extern unsigned char OK_CODE[];
extern unsigned char* stringa;

extern unsigned char * TEXT_TRY;

extern unsigned char* MAIN_MENU[];

extern unsigned char* QUESTION_1[];
extern unsigned char* QUESTION_2[];
extern unsigned char* QUESTION_3[];


extern unsigned char* DEVICE_VERSION;
extern unsigned char* CREDITS;
extern unsigned char* BAR_LINE;

extern char* imperial_march;

extern char* imperial_march_2;


extern unsigned char* vader_ascii[];

extern unsigned char* tie_ascii[];

extern unsigned int SystemFrequency;
extern void TCPClockHandler(void);
char password[PASSWORD_LEN];
extern unsigned char response[MAX_TCP_RX_DATA_SIZE];
extern void Channel(void);

							 
extern void SysTick_Handler(void);
extern char convertInputToChar(uint8_t);

extern void welcome(void);
extern unsigned char menuHandler(unsigned char** txt, unsigned char* custom, unsigned int NUM_ENTRIES);
extern void praiseTheEmpire(void);
							 
#endif
