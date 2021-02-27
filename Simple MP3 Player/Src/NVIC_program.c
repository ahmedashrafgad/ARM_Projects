/*
 * NVIC_program.c
 *
 *  Created on: Feb 7, 2021
 *      Author: Ahmed Ashraf
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidInit(void)
{
	#ifndef 	SCB_AIRCR
	/* Number of groups and sub groups*/
    #define SCB_AIRCR  *((u32*)(0xE000ED00 + 0x0C))//Register in system Contol block peripheral
	#endif
	SCB_AIRCR = NVIC_GROUP_SUB_DISTRIBUTION;
}



void MNVIC_voidEnableInterrupt(INTERRUPTNUM_Type Copy_enumInterruptNum)
{
	if (Copy_enumInterruptNum <= 31 )
	{
		NVIC_ISER0 = (1 << Copy_enumInterruptNum) ;
		/* I  can use SET_BIT(NVIC_ISER0,Copy_IntNumber)
		but the register when i write ZERO has no effect so no problem to shift direct */

	}
	else if (Copy_enumInterruptNum <= 59)
	{
		/* when i want to write on the first bit on the second register it will give mn 32
		   so i need to make it back to number of bit in the second reg so -32 */
		Copy_enumInterruptNum -= 32 ;
		NVIC_ISER1 = (1 << Copy_enumInterruptNum) ;
		//SET_BIT(NVIC_ISER1,Copy_IntNumber)
	}
	else
	{
		//return error
	}
}

void MNVIC_voidDisableInterrupt(INTERRUPTNUM_Type Copy_enumInterruptNum)
{
	if (Copy_enumInterruptNum <= 31 )
	{
		NVIC_ICER0 = (1 << Copy_enumInterruptNum) ;
		/* I  can use SET_BIT(NVIC_ISER0,Copy_IntNumber)
		but the register when i write ZERO has no effect so no problem to shift direct */

	}
	else if (Copy_enumInterruptNum <= 59)
	{
		/* when i want to write on the first bit on the second register it will give mn 32
		   so i need to make it back to number of bit in the second reg so -32 */
		Copy_enumInterruptNum -= 32 ;
		NVIC_ICER1 = (1 << Copy_enumInterruptNum) ;
		//SET_BIT(NVIC_ISER1,Copy_IntNumber)
	}
	else
	{
		//return error
	}
}
void MNVIC_voidSetPendingFlag(INTERRUPTNUM_Type Copy_enumInterruptNum)
{
	if (Copy_enumInterruptNum <= 31 )
	{
		NVIC_ISPR0 = (1 << Copy_enumInterruptNum) ;
		/* I  can use SET_BIT(NVIC_ISER0,Copy_IntNumber)
		but the register when i write ZERO has no effect so no problem to shift direct */

	}
	else if (Copy_enumInterruptNum <= 59)
	{
		/* when i want to write on the first bit on the second register it will give mn 32
		   so i need to make it back to number of bit in the second reg so -32 */
		Copy_enumInterruptNum -= 32 ;
		NVIC_ISPR1 = (1 << Copy_enumInterruptNum) ;
		//SET_BIT(NVIC_ISER1,Copy_IntNumber)
	}
	else
	{
		//return error
	}

}

void MNVIC_voidClearPendingFlag(INTERRUPTNUM_Type Copy_enumInterruptNum)
{
	if (Copy_enumInterruptNum <= 31 )
	{
		NVIC_ICPR0 = (1 << Copy_enumInterruptNum) ;
		/* I  can use SET_BIT(NVIC_ISER0,Copy_IntNumber)
		but the register when i write ZERO has no effect so no problem to shift direct */

	}
	else if (Copy_enumInterruptNum <= 59)
	{
		/* when i want to write on the first bit on the second register it will give mn 32
		   so i need to make it back to number of bit in the second reg so -32 */
		Copy_enumInterruptNum -= 32 ;
		NVIC_ICPR1 = (1 << Copy_enumInterruptNum) ;
		//SET_BIT(NVIC_ISER1,Copy_IntNumber)
	}
	else
	{
		//return error
	}

}

u8 MNVIC_u8GetActiveFlag(INTERRUPTNUM_Type Copy_enumInterruptNum)
{
	u8 Local_u8Result=0xFF;

	if (Copy_enumInterruptNum <= 31 )
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_enumInterruptNum);
	}
	else if (Copy_enumInterruptNum <= 59)
	{
		/* when i want to write on the first bit on the second register it will give mn 32
		   so i need to make it back to number of bit in the second reg so -32 */
		Copy_enumInterruptNum -= 32 ;
		Local_u8Result    = GET_BIT(NVIC_IABR1,Copy_enumInterruptNum);
	}
	else
	{
		//return error
	}
	return Local_u8Result ;

}

void MNVIC_voidSetPriority(INTERRUPTNUM_Type Copy_enumInterruptNum, Priorioty4Group4Sub_Type Copy_enumPriority)
{
	if (Copy_enumInterruptNum < 60)
	{
		/********** Bits From 4 : 7 *****************/
		NVIC_IPR[Copy_enumInterruptNum] = (Copy_enumPriority<<4);
	}

	else
	{
		/* Report Error */
	}
}

void MNVIC_voidSetPriorityCorePeripherals(CORE_INTERRUPTNUM_Type Copy_enumCorePerInterruptNum, Priorioty4Group4Sub_Type Copy_enumPriority)
{
		/********** Bits From 4 : 7 *****************/
		SCB_SHPR[Copy_enumCorePerInterruptNum] = (Copy_enumPriority<<4);
}


