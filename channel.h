#ifndef __CHANNEL_H
#define __CHANNEL_H

#define extern
#define CHANNEL_DATA_AVAILABLE      0x01
#define PASSWORD_LEN				9
unsigned char* WRONG_PASSWORD  = {"I hope you had fun with the sound simulator! Have a great day"};
unsigned char* HAPPY_LINE = 	{":) XD :D =) :X xD :/ ;)"};

unsigned char ChannelStatus;
#define CHANNEL_INIT				0x00
#define PASSWORD_SENT 				0x01
#define WAIT_FOR_PROFILE			0x02
#define CHANNEL_CONNECTED 			0x04
#define CODE_SENT 					0x08

unsigned char OK_CODE[] = "200";
unsigned char* stringa = "Lord Vader personal device. Good morning, supreme lord. Please identify yourself, if you mind, your greatness.";

unsigned char * TEXT_TRY = "Cantami, o Diva, del pelide Achille l'ira funesta che\
 infiniti addusse lutti agli Achei, molte anzi tempo all'Orco\
 generose travolse alme d'eroi,\
 e di cani e d'augelli orrido pasto\
 lor salme abbandono' (cosi' di Giove\
 l'alto consiglio s'adempia), da quando\
 primamente disgiunse aspra contesa\
 il re de' prodi Atride e il divo Achille";

unsigned char** MAIN_MENU = {"-Praise the Empire","-Request TIE Bombers","-What Sith are you?"};

unsigned char** QUESTION_1  {"-Trough a Mask","-Using a meat chunk"};
unsigned char** QUESTION_2 = {"-Darth Vader","-Darth Fener"};
unsigned char** QUESTION_3 = {"-Wookie","-Droid"};


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

extern unsigned int SystemFrequency;
extern void TCPClockHandler(void);
char password[PASSWORD_LEN];
unsigned char response[MAX_TCP_RX_DATA_SIZE];
void Channel(void);

							 
void SysTick_Handler(void);
char convertInputToChar(uint8_t);

void welcome(void);
unsigned char menuHandler(char** txt, char* custom, unsigned int NUM_ENTRIES);
							 
#endif
