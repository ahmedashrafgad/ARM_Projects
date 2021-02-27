/*
 * GPIO_interface.h
 *
 *  Created on: Feb 3, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

typedef enum
{
	LOW  = 0,
	HIGH = 1,
}GPIOPINVALUE_type;

typedef enum
{
	PORT_LOW  =  ( (u32)0x00000000 ) ,
	PORT_HIGH =  ( (u32)0xFFFFFFFF ) ,
}GPIOPORTVALUE_type;
typedef enum
{
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC
}GPIOPORT_type;

typedef enum
{
	 /*Note Input Options : Analog
	 					   Floating
	 					   PullUp
	 					   PullDown
	 					   Pull up and pull down has the same mode in bits*/
	INPUT_ANLOG            =  0b0000    ,
	INPUT_FLOATING         =  0b0100    ,
	INPUT_PULLUP_PULLDOWN  =  0b1000    ,

	 /*Note Output Options : PP = Push Pull
	                         OD = Open Drain
	 				         AF = Alternative Function */
	 /*OutPut Modes for 10 MHZ */
	OUTPUT_10MHZ_PP        =  0b0001    ,
	OUTPUT_10MHZ_OD        =  0b0101    ,
	OUTPUT_10MHZ_AF_PP     =  0b1001    ,
	OUTPUT_10MHZ_AF_OD     =  0b1101    ,

	 /*Output Modes for 2 MHZ */
	 OUTPUT_2MHZ_PP        =  0b0010    ,
	 OUTPUT_2MHZ_OD        =  0b0110    ,
	 OUTPUT_2MHZ_AF_PP     =  0b1010    ,
	 OUTPUT_2MHZ_AF_OD     =  0b1110    ,

	 /*Output Modes for 50 MHZ */
	 OUTPUT_50MHZ_PP       =  0b0011    ,
	 OUTPUT_50MHZ_OD       =  0b0111    ,
	 OUTPUT_50MHZ_AF_PP    =  0b1011    ,
	 OUTPUT_50MHZ_AF_OD    =  0b1111

}GPIOPINMODE_type;


typedef enum
{
	 /*----------------------------------------- PORT MODES -----------------------------------------*/

	INPUT_PORT_ANLOG             =  ( (u32)0x00000000 )  ,        // 0b00000000000000000000000000000000
	INPUT_PORT_FLOATING          =  ( (u32)0x44444444 )  ,        // 0b01000100010001000100010001000100
	INPUT_PORT_PULLUP_PULLDOWN   =  ( (u32)0x88888888 )  ,        // 0b10001000100010001000100010001000
	 //For Speed 10
	OUTPUT_PORT_10MHZ_PP         =  ( (u32)0x11111111 )  ,        // 0b00010001000100010001000100010001
	OUTPUT_PORT_10MHZ_OD         =  ( (u32)0x55555555 )  ,        // 0b01010101010101010101010101010101
	OUTPUT_PORT_10MHZ_AFPP       =  ( (u32)0x99999999 )  ,        // 0b10011001100110011001100110011001
	OUTPUT_PORT_10MHZ_AFOD       =  ( (u32)0xDDDDDDDD )  ,        // 0b11011101110111011101110111011101

	 //For Speed 2
	OUTPUT_PORT_2MHZ_PP          =  ( (u32)0x22222222 )  ,         // 0b00100010001000100010001000100010
	OUTPUT_PORT_2MHZ_OD          =  ( (u32)0x66666666 )  ,         // 0b01100110011001100110011001100110
	OUTPUT_PORT_2MHZ_AFPP        =  ( (u32)0xAAAAAAAA )  ,         // 0b10101010101010101010101010101010
	OUTPUT_PORT_2MHZ_AFOD        =  ( (u32)0xEEEEEEEE )  ,         // 0b11101110111011101110111011101110

	 //For Speed 2
	OUTPUT_PORT_50MHZ_PP         =  ( (u32)0x33333333 )  ,         // 0b00110011001100110011001100110011
	OUTPUT_PORT_50MHZ_OD         =  ( (u32)0x77777777 )  ,         // 0b01110111011101110111011101110111
	OUTPUT_PORT_50MHZ_AFPP       =  ( (u32)0xBBBBBBBB )  ,         // 0b10111011101110111011101110111011
	 //OUTPUT_PORT_50MHZ_AFOD       =  ( (u32)0xFFFFFFFF )‬           // 0b11111111111111111111111111111111

}GPIOPORTMODE_type;

typedef enum
{
	PIN0    ,
	PIN1    ,
	PIN2    ,
	PIN3    ,
	PIN4    ,
	PIN5    ,
	PIN6    ,
	PIN7    ,
	PIN8    ,
	PIN9    ,
	PIN10   ,
	PIN11   ,
	PIN12   ,
	PIN13   ,
	PIN14   ,
	PIN15
}GPIOPIN_type;


 /*function to take port , pin and the mode to set its dirction and type*/
  void MGPIO_voidSetPinDirection   (GPIOPORT_type Copy_enumPortID , GPIOPIN_type Copy_enumPinID , GPIOPINMODE_type Copy_enumPinMode);
  /*function to take the value of the pin as it has many speeds and types of output and inputs */
  /* if Pin is output (High or Low) */
  void MGPIO_voidSetPinValue	   (GPIOPORT_type Copy_enumPortID , GPIOPIN_type Copy_enumPinID ,GPIOPINVALUE_type Copy_enumPinValue);
  /*function to get the value of the input (input by 0 or input by 1 ) */
  /* IF Pin is input (return High or Low) */
  u8 MGPIO_u8GetPinValue		   (GPIOPORT_type Copy_enumPortID , GPIOPIN_type Copy_enumPinID );

  void MGPIO_voidTogglePin         (GPIOPORT_type Copy_enumPortID , GPIOPIN_type Copy_enumPinID );
  // set port direction
  void MGPIO_voidSetPortDirection  (GPIOPORT_type Copy_enumPortID , GPIOPORTMODE_type Copy_enumPortMode  ) ;
  // set port value
  void MGPIO_voidSetPortValue      (GPIOPORT_type Copy_enumPortID , GPIOPORTVALUE_type Copy_enumPortValue );
  // Get port value
  u32 MGPIO_voidGetPortValue	   (GPIOPORT_type Copy_enumPortID );




#endif /* GPIO_INTERFACE_H_ */
