/*
 * KEYPAD_program.c
 *
 *  Created on: Feb 6, 2021
 *      Author: Ahmed Ashraf
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "KEYPAD_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"

#include"GPIO_interface.h"




u8 HKeyPad_u8GetKey(void)
{
	u8 Local_u8row,Local_u8col,Local_u8key = NO_KEY ;

	MGPIO_voidSetPinValue(KEYPAD_PORT, FIRST_OUTPUT  , HIGH);
	MGPIO_voidSetPinValue(KEYPAD_PORT, FIRST_OUTPUT+1, HIGH);
	MGPIO_voidSetPinValue(KEYPAD_PORT, FIRST_OUTPUT+2, HIGH);
	MGPIO_voidSetPinValue(KEYPAD_PORT, FIRST_OUTPUT+3, HIGH);


	for (Local_u8row = 0 ; Local_u8row <4 ; Local_u8row++)
	{
		MGPIO_voidSetPinValue(KEYPAD_PORT, FIRST_OUTPUT+Local_u8row , LOW);

		for (Local_u8col = 0 ; Local_u8col < 4 ; Local_u8col ++)
		{
			if(!MGPIO_u8GetPinValue(KEYPAD_PORT, FIRST_INPUT+Local_u8col))
			{
			Local_u8key = Keys[Local_u8row][Local_u8col];
			while(!MGPIO_u8GetPinValue(KEYPAD_PORT, FIRST_INPUT+Local_u8col));
			//_delay_ms(300);
			}
		}
		MGPIO_voidSetPinValue(KEYPAD_PORT, FIRST_OUTPUT+Local_u8row, HIGH);
	}
	return Local_u8key;
}
