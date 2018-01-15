/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: LED Flasher for MCB1700
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2004-2014 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include "LPC17xx.h"                    /* LPC17xx Definitions                */
#include "Board_LED.h"
#include "Board_ADC.h"

char text[10];

/* Import external variables from IRQ.c file                                  */
extern volatile unsigned char clock_1s;

/* variable to trace in LogicAnalyzer (should not read to often)              */
volatile unsigned short AD_dbg;

uint16_t AD_last;                       /* Last converted value               */

/*----------------------------------------------------------------------------
  Main function
 *----------------------------------------------------------------------------*/
int main (void) {
  int32_t  res;
  uint32_t AD_avg   = 0;
  uint16_t AD_value = 0;
  uint16_t AD_print = 0;

  LED_Initialize();                     /* LED Initialization                 */
  ADC_Initialize();                     /* ADC Initialization                 */

  SystemCoreClockUpdate();
  SysTick_Config(SystemCoreClock/100);  /* Generate interrupt each 10 ms      */

  while (1) {                           /* Loop forever                       */    
    
    /* AD converter input                                                     */
    res = ADC_GetValue();
    if (res != -1) {                    /* If conversion has finished         */
      AD_last = res;

      AD_avg += AD_last << 8;           /* Add AD value to averaging          */
      AD_avg ++;
      if ((AD_avg & 0xFF) == 0x10) {    /* average over 16 values             */
        AD_value = (AD_avg >> 8) >> 4;  /* average devided by 16              */
        AD_avg = 0;
      }
    }

    if (AD_value != AD_print) {
      AD_print = AD_value;              /* Get unscaled value for printout    */
      AD_dbg   = AD_value;

      sprintf(text, "0x%04X", AD_value);/* format text for print out          */
    }

    /* Print message with AD value every second                               */
    if (clock_1s) {
      clock_1s = 0;

      printf("AD value: %s\r\n", text);
    }
  }
}
