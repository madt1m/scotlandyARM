#define extern
#define CHANNEL_DATA_AVAILABLE      0x01

#define TEXT_TRY "Cantami, o Diva, del pelide Achille l'ira funesta che\
 infiniti addusse lutti agli Achei, molte anzi tempo all'Orco\
 generose travolse alme d'eroi,\
 e di cani e d'augelli orrido pasto\
 lor salme abbandono' (cosi' di Giove\
 l'alto consiglio s'adempia), da quando\
 primamente disgiunse aspra contesa\
 il re de' prodi Atride e il divo Achille"

#define TEST_MENU "[STATUS:ACTIVE]\
 -Request Support\
 -Mission Briefing\
 -Send New Equip"

#define BOOT_TEXT "Startup...\
 Initializing boot procedure.\
 Insert code to continue."

unsigned char CHANNEL_STATUS;
#define PASSWORD_SENT 		0X00000001
#define CODE_SENT			0X00000010

unsigned char response[MAX_TCP_RX_DATA_SIZE];