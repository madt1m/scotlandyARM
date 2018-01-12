/*
* filename: joystick.h
* last_modified: 12/01/2018
* <------->
* Prototypes of functions controlling joystick peripheral
*/

#include <stdint.h>

// Configures Joystick pins
void joystick_init(void);

// Gets a single, debounced input from the Joystick
uint8_t joystick_get_input(void);

// Reads Joystick state
uint8_t joystick_state(void);


