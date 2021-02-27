/*
 * STK_program.c
 *
 *  Created on: Feb 10, 2021
 *      Author: Ahmed Ashraf
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


/* Define Callback Global Variable */
static void(*STK_CallBack)(void)= NULL;

/* Define Variable for interval mode */
static u8 STK_u8IntervalMode;

void MSTK_voidInit(void)
{
#if STK_CLK_SRC == STK_SRC_AHB_8
    /* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
	STK -> CTRL = 0x00000000;
#else
    /* Disable STK - Disable STK Interrupt - Set clock source AHB */
	STK -> CTRL = 0x00000004;

#endif
}

void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )
{
	/* ===== To make function work with Milli-Seconds ===== */
	Copy_u32Ticks*=1000;
	/* Range check  on ticks not more than 24 bits */
	if (Copy_u32Ticks <= 16777216)
	{
		/* Load ticks to load register */
		STK -> LOAD = Copy_u32Ticks;

		/* Start Timer */
		SET_BIT(STK->CTRL, 0);

		/* Wait till flag is raised */
		while( (GET_BIT(STK->CTRL,16)) == 0)
		{
			asm("NOP");
		}

		/* Stop Timer */
		CLR_BIT(STK->CTRL, 0);
		STK -> LOAD = 0;
		STK -> VAL  = 0;
	}
}

void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* ===== To make function work with Milli-Seconds ===== */
		Copy_u32Ticks*=1000;
	/* Range check  on ticks not more than 24 bits */
	if (Copy_u32Ticks <= 16777216)
	{
		/* Load ticks to load register */
		STK -> LOAD = Copy_u32Ticks;

		/* Start Timer */
		SET_BIT(STK->CTRL, 0);

		/* Save CallBack */
		STK_CallBack = Copy_ptr;

		/* Set Mode to Single */
		STK_u8IntervalMode = STK_SINGLE_INTERVAL;

		/* Enable STK Interrupt */
		SET_BIT(STK->CTRL, 1);
	}
}
void MSTK_voidSetIntervalSingleMicro  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Range check  on ticks not more than 24 bits */
	if (Copy_u32Ticks <= 16777216)
	{
		/* Load ticks to load register */
		STK -> LOAD = Copy_u32Ticks;

		/* Start Timer */
		SET_BIT(STK->CTRL, 0);

		/* Save CallBack */
		STK_CallBack = Copy_ptr;

		/* Set Mode to Single */
		STK_u8IntervalMode = STK_SINGLE_INTERVAL;

		/* Enable STK Interrupt */
		SET_BIT(STK->CTRL, 1);
	}
}

void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* ===== To make function work with Milli-Seconds ===== */
		Copy_u32Ticks*=1000;
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks;

	/* Start Timer */
	SET_BIT(STK->CTRL, 0);

	/* Save CallBack */
	STK_CallBack = Copy_ptr;

	/* Set Mode to Single */
	STK_u8IntervalMode = STK_PERIODIC_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, 1);
}

void MSTK_voidSetIntervalPeriodicMicro( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	STK -> LOAD = Copy_u32Ticks;

	/* Start Timer */
	SET_BIT(STK->CTRL, 0);

	/* Save CallBack */
	STK_CallBack = Copy_ptr;

	/* Set Mode to Single */
	STK_u8IntervalMode = STK_PERIODIC_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(STK->CTRL, 1);
}

void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(STK->CTRL, 1);

	/* Stop Timer */
	CLR_BIT(STK->CTRL, 0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
}

u32  MSTK_u32GetCounts(void)
{
	u32 Local_u32Counts;

	Local_u32Counts = (STK -> LOAD) - (STK -> VAL) ;
	/* ===== To make function return in Milli-Seconds ===== */
	Local_u32Counts *=1000;
	return Local_u32Counts;
}

u32  MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime;

	Local_u32RemainTime = STK -> VAL ;
	/* ===== To make function return in Milli-Seconds ===== */
	Local_u32RemainTime*=1000;
	return Local_u32RemainTime;
}

void SysTick_Handler(void)
{
	u8 Local_u8Temporary;
		/*     **** if Single ****       */
	if (STK_u8IntervalMode == STK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(STK->CTRL, 1);

		/* Stop Timer */
		CLR_BIT(STK->CTRL, 0);
		STK -> LOAD = 0;
		STK -> VAL  = 0;
	}
	/* Do whatever you want when interrupt is fired*/
	/* Callback notification */
	STK_CallBack();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STK->CTRL,16);
}
/* clearing the flag by sw
 * 1- Flag = 1;
 * 2- Flag = 0 ;
 * 3- read  flag ==> flag = 0 ;
 * 4- write flag ==> flag = 0 ;
 */

