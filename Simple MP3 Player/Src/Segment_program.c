/*
 * Segment_program.h
 *
 *  Created on: Feb 5, 2021
 *      Author: Ahmed Ashraf
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Segment_interface.h"
#include "Segment_config.h"
#include "Segment_private.h"


#include "GPIO_interface.h"


void HSegment_voidDisplayNum(u8 Copy_u8UsedSegments,u8 Copy_u8Number)
{
	u8 Local_u8Units = 0 ;
	u8 Local_u8Tenth = 0 ;
	if(Copy_u8UsedSegments == 1 )
	{
		MGPIO_voidSetPortValue( GPIO_PORTA , SegmentUnit[Copy_u8Number] );
		  MGPIO_voidSetPinValue(GPIO_PORTA,PIN7 ,HIGH);
		  MGPIO_voidSetPinValue(GPIO_PORTA,PIN8 ,HIGH);
	      MGPIO_voidSetPinValue(GPIO_PORTA,PIN9 ,HIGH);
	      MGPIO_voidSetPinValue(GPIO_PORTA,PIN10,HIGH);
	      MGPIO_voidSetPinValue(GPIO_PORTA,PIN11,HIGH);
		  MGPIO_voidSetPinValue(GPIO_PORTA,PIN12,HIGH);
		  MGPIO_voidSetPinValue(GPIO_PORTA,PIN15,LOW);

	}
	else if (Copy_u8UsedSegments == 2 )
	{
		if (Copy_u8Number < 10)
		{
			MGPIO_voidSetPortValue( GPIO_PORTA , SegmentUnit[Copy_u8Number] );
			//zero 1111110
			MGPIO_voidSetPinValue(GPIO_PORTA,PIN7 ,HIGH);
		    MGPIO_voidSetPinValue(GPIO_PORTA,PIN8 ,HIGH);
			MGPIO_voidSetPinValue(GPIO_PORTA,PIN9 ,HIGH);
			MGPIO_voidSetPinValue(GPIO_PORTA,PIN10,HIGH);
			MGPIO_voidSetPinValue(GPIO_PORTA,PIN11,HIGH);
		    MGPIO_voidSetPinValue(GPIO_PORTA,PIN12,HIGH);
			MGPIO_voidSetPinValue(GPIO_PORTA,PIN15,LOW);
		}
		else if (Copy_u8Number < 100)
		{
			Local_u8Tenth = Copy_u8Number / 10 ;
			Local_u8Units = Copy_u8Number % 10 ;

			MGPIO_voidSetPortValue( GPIO_PORTA , SegmentUnit[Local_u8Units] );
			switch(Local_u8Tenth)
			{
			//one    0110000
			case 1 : MGPIO_voidSetPinValue(GPIO_PORTA,PIN7 ,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN8 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN9 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN10,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN11,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN12,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN15,LOW);
					 break;

			//two    1101101
			case 2 : MGPIO_voidSetPinValue(GPIO_PORTA,PIN7 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN8 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN9 ,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN10,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN11,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN12,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN15,HIGH);
					 break;

			//three 1111001
			case 3 : MGPIO_voidSetPinValue(GPIO_PORTA,PIN7 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN8 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN9 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN10,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN11,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN12,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN15, HIGH);

					 break;

			//four	 0110011
			case 4 : MGPIO_voidSetPinValue(GPIO_PORTA,PIN7 ,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN8 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN9 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN10,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN11,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN12,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN15, HIGH);

					 break;

			//five	 1011011
			case 5 : MGPIO_voidSetPinValue(GPIO_PORTA,PIN7 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN8 ,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN9 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN10,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN11,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN12,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN15, HIGH);

					 break;

			//six    0011111
			case 6 : MGPIO_voidSetPinValue(GPIO_PORTA,PIN7 ,LOW);
				     MGPIO_voidSetPinValue(GPIO_PORTA,PIN8 ,LOW);
				     MGPIO_voidSetPinValue(GPIO_PORTA,PIN9 ,HIGH);
				     MGPIO_voidSetPinValue(GPIO_PORTA,PIN10,HIGH);
				     MGPIO_voidSetPinValue(GPIO_PORTA,PIN11,HIGH);
				     MGPIO_voidSetPinValue(GPIO_PORTA,PIN12,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN15, HIGH);

				     break;

			//seven  1110000
			case 7 : MGPIO_voidSetPinValue(GPIO_PORTA,PIN7 ,HIGH);
				   	 MGPIO_voidSetPinValue(GPIO_PORTA,PIN8 ,HIGH);
				   	 MGPIO_voidSetPinValue(GPIO_PORTA,PIN9 ,HIGH);
				   	 MGPIO_voidSetPinValue(GPIO_PORTA,PIN10,LOW);
				   	 MGPIO_voidSetPinValue(GPIO_PORTA,PIN11,LOW);
				   	 MGPIO_voidSetPinValue(GPIO_PORTA,PIN12,LOW);
				   	 MGPIO_voidSetPinValue(GPIO_PORTA,PIN15,LOW);
				   	break;

			//eight  1111111
			case 8 : MGPIO_voidSetPinValue(GPIO_PORTA,PIN7 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN8 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN9 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN10,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN11,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN12,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN15, HIGH);

					 break;

			//ten	 1110011
			case 9 : MGPIO_voidSetPinValue(GPIO_PORTA,PIN7 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN8 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN9 ,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN10,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN11,LOW);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN12,HIGH);
					 MGPIO_voidSetPinValue(GPIO_PORTA,PIN15, HIGH);
					 break;
			}
		}		
	}
}
