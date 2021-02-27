/*
 * USART_program.c
 *
 *  Created on: Feb 16, 2021
 *      Author: Ahmed Ashraf
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"


void   MUSART1_voidInit(void)
{
	/*9600    BRR = 0x341 */
	 USART1 -> BRR = 0x341;
	/*11520    BRR = 0x341 */

	/*
		1- Enable RX
		2- Enable TX
		3- Enable USART
	*/
	SET_BIT(USART1 -> CR1, 2);
	SET_BIT(USART1 -> CR1, 3);
	SET_BIT(USART1 -> CR1, 13);

	/* Clear status Register */
	USART1 -> SR = 0 ;
}
void   MUSART1_voidTransmit(u8 arr[])
{
	u8 i = 0 ;
	while (arr[i] != '0')
	{
		USART1 -> DR = arr[i];
		/* while (MUSART1 -> SR , 6) == 0)*/
		/* wait untill transmission is complete */
		while (((USART1 -> SR )& 0x40) == 0);
		i++;
	}
}

u8 MUSART1_u8Receive(void)
{
	while (((USART1 -> SR )& 1 <<  5 ) == 0);
	return (0xFF & (USART1 -> DR));
}
