/*
* As soon as board boots, a logo is printed on display.
* At this point, the board is waiting for an input from joystick.
* When the joystick button is pressed, the input phase ends, the password
* variable is printed and it gets encapsulated into an IP packet.
* The packet is sent via Ethernet to a server which checks the password and
* returns to the board the outcome, together with some custom messages. (Autodestruction REMEMBAH)
*/
/*
#include "lpc17xx.h"
#include "joystick.h"
#include "display.h"
//#include "channel.h"
#include "utilities.h"
#define PASSWORD_LENGTH 8;
#define MAX_READ 1024;

int main(){
	
	while(1){
		uint8_t joystick_input = 0b00000000; 
		uint8_t button_pressed = 0b00010000;  // This stands for the end of input phase
		int count = 0;  					  // Avoids password with length more than PASSWORD_LENGTH
		channel conn_channel;
		char buffer[MAX_READ];
		char password[PASSWORD_LENGTH];
		debug("Insert Password\n");
		while((joystick_input != button_pressed) && (count < PASSWORD_LENGTH)){
			joystick_input = getInput();
			password[count] = getCharCode(joystick_input);
			count++;
		}
		debug("Password Inserted\n");
		printLine(password);
		conn_channel = openConnection();
		if(conn_channel.code != SUCCESS){
			printLine("[!!!] Channel connection has failed with code: ");
			printLine(conn_channel.code);
			printLine("\n");
			//reset();
		}
		int bytes = writeTo(connection, password);
		if(!bytes){
			printLine("[!!!] Failure while writing to connection.");
			//reset();
		}
		bytes = readFrom(connection, buffer);
		if(!bytes){
			printLine("[!!!] Failure while reading from connection.");
			//reset();
		}
		printLine(buffer);		
	}
}
*/