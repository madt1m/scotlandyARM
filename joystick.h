/*
* filename: joystick.h
* last_modified: 12/01/2018
* <------->
* Prototypes of functions controlling joystick peripheral
*/

#include <stdint.h>

//Codes for joystick positions
#define JOYSTICK_RIGHT				0xF
#define JOYSTICK_LEFT				0x1D
#define JOYSTICK_DOWN				0x17
#define JOYSTICK_UP					0x1B
#define JOYSTICK_SELECT				0x1E


// Get value
uint8_t joystickRead(void);

// Configures Joystick pins
void joystick_init(void);

// Gets a single, debounced input from the Joystick
uint8_t joystick_get_input(void);

// Reads Joystick state
uint8_t joystick_state(void);



