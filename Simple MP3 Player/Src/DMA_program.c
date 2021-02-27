/*
 * DMA_program.c
 *
 *  Created on: Feb 14, 2021
 *      Author: Ahmed Ashraf
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

void DMA1_voidChannelInit(void)
{
	/*
	 * 	Memory to Memory
	 * 	Periority	Very High
	 * 	Element Size (Source and destination = u32)
	 * 	MINC , PINC Incrementing
	 * 	No Circular Mode
	 * 	Data Direction : Peripheral to Memory
	 * 	Enable Transfer Complete Interrupt
	 * 	Channel Disable
	 *
	 * */

	DMA1 -> Channel[0].CCR = 0x00007AC2;
}
void DMA1_voidChannelStart(u32 * Copy_Pu32SourceAdd ,u32 * Copy_Pu32DestinationAdd ,u16 Copy_u16BlockSize)
{
	/*		Make sure that Channel is Disabled	 	*/
	CLR_BIT(DMA1 -> Channel[0].CCR , 0);
	/*		Load The Block Size						*/
	DMA1 -> Channel[0].CNDTR = Copy_u16BlockSize;
	/*		Load Source Add And Destination Add		*/
	DMA1 -> Channel[0].CPAR =	Copy_Pu32SourceAdd;
	DMA1 -> Channel[0].CMAR =	Copy_Pu32DestinationAdd;
	/*		Enable Channel							*/
	SET_BIT(DMA1 -> Channel[0].CCR , 0);
}

