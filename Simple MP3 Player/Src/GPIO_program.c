/*
 * GPIO_program.c
 *
 *  Created on: Feb 3, 2021
 *      Author: Ahmed Ashraf
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void MGPIO_voidSetPinDirection(GPIOPORT_type Copy_enumPortID , GPIOPIN_type Copy_enumPinID , GPIOPINMODE_type Copy_enumPinMode)
{
	/*            range check                    */
	if ((Copy_enumPortID <3) && (Copy_enumPinID <16) )
	{
		switch(Copy_enumPortID)
		{
		case GPIO_PORTA :
			/********** Low Port ***********/
			if (Copy_enumPinID < 8 )
			{
				/* i want to reset the the pin to zero case so ill make with the same idea of CLR_BIT
							   but with 4 bits togther so ill write 0b1111 then make not(~) to make it 0b0000 then
							   make AND (&) with the pin from ( Copy_u8Pin * 4 ) then put it in the register GPIOA_CRL*/

			GPIOA_CRL &= ~( ( 0b1111 )    << ( Copy_enumPinID * 4 ));
	    	/* i want to set the mode of the pin so ill use the same idea of SET_BIT but with 4 bits */
	    	GPIOA_CRL |=   ( Copy_enumPinMode ) << ( Copy_enumPinID * 4 );
			}
			/********** High Port **********/
			/* more than 15 means that we will write on register GPIO_CRH  (the High pins of the port)*/
			/* we will use the same idea we used in the lower pins in the HIGh pins */
			else if (Copy_enumPinID < 16)
			{
				Copy_enumPinID = Copy_enumPinID - 8;
				GPIOA_CRH &= ~ ( ( 0b1111 )    << ( Copy_enumPinID * 4 ) );
				GPIOA_CRH |=   ( Copy_enumPinMode ) << ( Copy_enumPinID * 4 );

			}
			break;

		case GPIO_PORTB :
			if (Copy_enumPinID < 8 )
						{
			/* i want to reset the the pin to zero case so ill make with the same idea of CLR_BIT
	     	   but with 4 bits togther so ill write 0b1111 then make not(~) to make it 0b0000 then
	     	   make AND (&) with the pin from ( Copy_u8Pin * 4 ) then put it in the register GPIOA_CRL*/

	     	GPIOB_CRL &= ~( ( 0b1111 )    << ( Copy_enumPinID * 4 ));
         	/* i want to set the mode of the pin so ill use the same idea of SET_BIT but with 4 bits */
         	GPIOB_CRL |=   ( Copy_enumPinMode ) << ( Copy_enumPinID * 4 );
	     	}
	     	/********** High Port **********/
	     	/* more than 15 means that we will write on register GPIO_CRH  (the High pins of the port)*/
	     	/* we will use the same idea we used in the lower pins in the HIGh pins */
	     	else if (Copy_enumPinID < 16)
	     	{
	     		Copy_enumPinID = Copy_enumPinID - 8;
	     		GPIOB_CRH &= ~ ( ( 0b1111 )    << ( Copy_enumPinID * 4 ) );
	     		GPIOB_CRH |=   ( Copy_enumPinMode ) << ( Copy_enumPinID * 4 );

	     	}
	     	break;

		case GPIO_PORTC :
			if (Copy_enumPinID < 8 )
						{
							/* i want to reset the the pin to zero case so ill make with the same idea of CLR_BIT
										   but with 4 bits togther so ill write 0b1111 then make not(~) to make it 0b0000 then
										   make AND (&) with the pin from ( Copy_u8Pin * 4 ) then put it in the register GPIOA_CRL*/

						GPIOC_CRL &= ~( ( 0b1111 )    << ( Copy_enumPinID * 4 ));
				    	/* i want to set the mode of the pin so ill use the same idea of SET_BIT but with 4 bits */
				    	GPIOC_CRL |=   ( Copy_enumPinMode ) << ( Copy_enumPinID * 4 );
						}
						/********** High Port **********/
						/* more than 15 means that we will write on register GPIO_CRH  (the High pins of the port)*/
						/* we will use the same idea we used in the lower pins in the HIGh pins */
						else if (Copy_enumPinID < 16)
						{
							Copy_enumPinID = Copy_enumPinID - 8;
							GPIOC_CRH &= ~ ( ( 0b1111 )    << ( Copy_enumPinID * 4 ) );
							GPIOC_CRH |=   ( Copy_enumPinMode ) << ( Copy_enumPinID * 4 );

						}
						break;

		}
	}
	else
	{
		/*return error*/
	}
}
 /* if Pin is output (High or Low) */
 void MGPIO_voidSetPinValue(GPIOPORT_type Copy_enumPortID , GPIOPIN_type Copy_enumPinID ,GPIOPINVALUE_type Copy_enumPinValue)
 {
		/*            range check                    */
		if ((Copy_enumPortID <3) && (Copy_enumPinID <16) )
		{
			switch(Copy_enumPortID)
		{
			case GPIO_PORTA:
				switch(Copy_enumPinValue)
				{
					case HIGH:	SET_BIT(GPIOA_ODR , Copy_enumPinID);	break;
					case LOW :	CLR_BIT(GPIOA_ODR , Copy_enumPinID);	break;
					default:;	/*		Return ERROR		*/
				}
				break;
			case GPIO_PORTB:
				switch(Copy_enumPinValue)
				{
					case HIGH:	SET_BIT(GPIOB_ODR , Copy_enumPinID);	break;
					case LOW :	CLR_BIT(GPIOB_ODR , Copy_enumPinID);	break;
					default:;	/*		Return ERROR		*/
				}
				break;
			case GPIO_PORTC:
				switch(Copy_enumPinValue)
				{
					case HIGH:	SET_BIT(GPIOC_ODR , Copy_enumPinID);	break;
					case LOW :	CLR_BIT(GPIOC_ODR , Copy_enumPinID);	break;
					default:;	/*		Return ERROR		*/
				}
				break;
	}
	}else{/*	Return ERROR	*/}
}
 /* IF Pin is input (return High or Low) */
 u8 MGPIO_u8GetPinValue		   (GPIOPORT_type Copy_enumPortID , GPIOPIN_type Copy_enumPinID )
 {
	 u8 Local_u8Value = 0 ;
	 /*            range check                    */
	 if ((Copy_enumPortID <3) && (Copy_enumPinID <16) )
	 {
	 switch(Copy_enumPortID)
	 	{
	 	case GPIO_PORTA:Local_u8Value = GET_BIT( GPIOA_IDR , Copy_enumPinID );break;
	 	case GPIO_PORTB:Local_u8Value = GET_BIT( GPIOB_IDR , Copy_enumPinID );break;
	 	case GPIO_PORTC:Local_u8Value = GET_BIT( GPIOC_IDR , Copy_enumPinID );break;
	 	}
	 }
	 else { /*return error*/}
	 return Local_u8Value;
 }

 void MGPIO_voidTogglePin(GPIOPORT_type Copy_enumPortID , GPIOPIN_type Copy_enumPinID )
 {
 		switch(Copy_enumPortID)
 	{
 		case GPIO_PORTA :
 		TOG_BIT(GPIOA_ODR, Copy_enumPinID);
 		break;
 		case GPIO_PORTB :
 		TOG_BIT(GPIOB_ODR, Copy_enumPinID);
 		break;
 		case GPIO_PORTC :
 		TOG_BIT(GPIOC_ODR, Copy_enumPinID);
 		break;
 	}
 }

 void MGPIO_voidSetPortDirection  ( GPIOPORT_type Copy_enumPortID  , GPIOPORTMODE_type Copy_enumPortMode  )
 {
	 switch(Copy_enumPortID){
	 	case GPIO_PORTA:
	 		GPIOA_CRL = Copy_enumPortMode ;
	 		GPIOA_CRH = Copy_enumPortMode ;
	 		break;

	 	case GPIO_PORTB:
	 		GPIOB_CRL = Copy_enumPortMode ;
	 		GPIOB_CRH = Copy_enumPortMode ;
	 		break;
	 	case GPIO_PORTC:
	 		GPIOC_CRL = Copy_enumPortMode ;
	 		GPIOC_CRH = Copy_enumPortMode ;
	 		break;


	 	default :break;
	 	}

 }

 void MGPIO_voidSetPortValue   ( GPIOPORT_type Copy_enumPortID  , GPIOPORTVALUE_type Copy_enumPortValue )
 {
 	switch (Copy_enumPortID)
 	{
 		case GPIO_PORTA : GPIOA_ODR =  Copy_enumPortValue ; break ;
 		case GPIO_PORTB : GPIOB_ODR =  Copy_enumPortValue ; break ;
 		case GPIO_PORTC : GPIOC_ODR =  Copy_enumPortValue ; break ;

 	}

 }


 u32 MGPIO_voidGetPortValue(GPIOPORT_type Copy_enumPortID )
 {
	u32 Local_u32Value = 0;
	 switch(Copy_enumPortID)
	  	{
	  		case GPIO_PORTA :
	  		GPIOA_IDR = Local_u32Value;
	  		break;
	  		case GPIO_PORTB :
	  		GPIOB_IDR = Local_u32Value;
	  		break;
	  		case GPIO_PORTC :
	  		GPIOC_IDR = Local_u32Value;
	  		break;
	  	}
	 return Local_u32Value;
}

