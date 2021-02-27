/*
 * EXTI_program.c
 *
 *  Created on: Feb 8, 2021
 *      Author: Ahmed Ashraf
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#ifndef		NULL
#define 	NULL		(void *)0
#endif

static void (*EXTI0_pfCallBack)(void) = NULL;
static void (*EXTI1_pfCallBack)(void) = NULL;
static void (*EXTI2_pfCallBack)(void) = NULL;
static void (*EXTI3_pfCallBack)(void) = NULL;


void MEXTI_voidInit(void)
{
	/*		Select all Edge Modes for All Lines		*/
#if			EXTI0 == EXTI_FALLING_EDGE
			SET_BIT(EXTI -> FTSR , 0);
#elif		EXTI0 == EXTI_RAISING_EDGE
			SET_BIT(EXTI -> RTSR , 0);
#elif		EXTI0 == EXTI_INTONCHANGE
			SET_BIT(EXTI -> RTSR , 0);
			SET_BIT(EXTI -> FTSR , 0);
#else
#error		"Wrong Choice of edge mode for line0 !"
#endif

#if			EXTI1 == EXTI_FALLING_EDGE
			SET_BIT(EXTI -> FTSR , 1);
#elif		EXTI1 == EXTI_RAISING_EDGE
			SET_BIT(EXTI -> RTSR , 1);
#elif		EXTI1 == EXTI_INTONCHANGE
			SET_BIT(EXTI -> RTSR , 1);
			SET_BIT(EXTI -> FTSR , 1);
#else
#error		"Wrong Choice of edge mode for line1 !"
#endif

#if			EXTI2 == EXTI_FALLING_EDGE
			SET_BIT(EXTI -> FTSR , 2);
#elif		EXTI2 == EXTI_RAISING_EDGE
			SET_BIT(EXTI -> RTSR , 2);
#elif		EXTI2 == EXTI_INTONCHANGE
			SET_BIT(EXTI -> RTSR , 2);
			SET_BIT(EXTI -> FTSR , 2);
#else
#error		"Wrong Choice of edge mode for line2 !"
#endif

#if			EXTI3 == EXTI_FALLING_EDGE
			SET_BIT(EXTI -> FTSR , 3);
#elif		EXTI3 == EXTI_RAISING_EDGE
			SET_BIT(EXTI -> RTSR , 3);
#elif		EXTI3 == EXTI_INTONCHANGE
			SET_BIT(EXTI -> RTSR , 3);
			SET_BIT(EXTI -> FTSR , 3);
#else
#error		"Wrong Choice of edge mode for line3 !"
#endif
	/*		Disable all EXTI lines		 			*/
			EXTI -> IMR = 0;
	/*		Clear All Pending BITs					*/
			EXTI -> PR 	= 0xFFFFFFFF;
}

void MEXTI_voidEnableLine(EXTILINE_type Copy_enumEXTI_Line)
{
	SET_BIT(EXTI -> IMR , Copy_enumEXTI_Line);
}
void MEXTI_voidSetSignalLatch(EXTILINE_type Copy_enumEXTI_Line, EXTIEGDE_type Copy_enumEdgeMode)
{
	if(Copy_enumEXTI_Line < 16)
	{
		CLR_BIT(EXTI -> FTSR , Copy_enumEXTI_Line );
		CLR_BIT(EXTI -> RTSR , Copy_enumEXTI_Line );
		switch(Copy_enumEdgeMode)
		{
			case EXTI_RAISING_EDGE 	: 	SET_BIT(EXTI -> RTSR , Copy_enumEXTI_Line ); 	break;
			case EXTI_FALLING_EDGE	:	SET_BIT(EXTI -> FTSR , Copy_enumEXTI_Line ); 	break;
			case EXTI_INTONCHANGE 	: 	SET_BIT(EXTI -> RTSR , Copy_enumEXTI_Line );
										SET_BIT(EXTI -> FTSR , Copy_enumEXTI_Line );	break;
		}
	}
}
void MEXTI_voidDisableLine(EXTILINE_type Copy_enumEXTI_Line )
{
	CLR_BIT(EXTI -> IMR , Copy_enumEXTI_Line);
}

void MEXTI_voidSetSoftwareTrigger(EXTILINE_type Copy_enumEXTI_Line )
{
	/*		   Task			*/
	SET_BIT(EXTI -> SWIER , Copy_enumEXTI_Line);

}
/*********============ Setting CallBack for External interrupts ============*********/
/*============ 	EXTI0 Callback fun ============*/
void MEXTI0_voidSetCallBack(void (*pf) (void)) // address ahmed Function
{
	if(pf != NULL)
	{
		/*EXTI0_pfCallBack = pf = address ahmed Function*/
		EXTI0_pfCallBack = pf ;
	}
}
/*============ 	EXTI1 Callback fun ============*/
void MEXTI1_voidSetCallBack(void (*pf) (void)) // address ahmed Function
{
	if(pf != NULL)
	{
		/*EXTI1_pfCallBack = pf = address ahmed Function*/
		EXTI1_pfCallBack = pf ;
	}
}
/*============ 	EXTI2 Callback fun ============*/
void MEXTI2_voidSetCallBack(void (*pf) (void)) // address ahmed Function
{
	if(pf != NULL)
	{
		/*EXTI2_pfCallBack = pf = address ahmed Function*/
		EXTI2_pfCallBack = pf ;
	}
}
/*============ 	EXTI3 Callback fun ============*/
void MEXTI3_voidSetCallBack(void (*pf) (void)) // address ahmed Function
{
	if(pf != NULL)
	{
		/*EXTI3_pfCallBack = pf = address ahmed Function*/
		EXTI3_pfCallBack = pf ;
	}
}
/*********============ 	External Interrupt ============*********/
/*============ 	EXTI0 Interrupt ============*/
void EXTI0_IRQHandler(void)
{
	EXTI0_pfCallBack();
	/*	Clear pending Bit		*/
		SET_BIT(EXTI -> PR , 0);

}
/*============ 	EXTI1 Interrupt ============*/
void EXTI1_IRQHandler(void)
{
	EXTI1_pfCallBack();
	/*	Clear pending Bit		*/
		SET_BIT(EXTI -> PR , 1);
}
/*============ 	EXTI2 Interrupt ============*/
void EXTI2_IRQHandler(void)
{
	EXTI2_pfCallBack();
	/*	Clear pending Bit		*/
		SET_BIT(EXTI -> PR , 2);
}
/*============ 	EXTI3 Interrupt ============*/
void EXTI3_IRQHandler(void)
{
	EXTI3_pfCallBack(); //ahmed();
	/*	Clear pending Bit		*/
		SET_BIT(EXTI -> PR , 3);
}

void EXTI9_5_IRQHandler(void)
{
	if (GET_BIT(EXTI -> PR ,5)==1)
	{
		//code  callback
		SET_BIT(EXTI-> PR , 5); // clear flag after excuting
	}
	/*
	 *
	 *
	 */
	if (GET_BIT(EXTI -> PR ,9)==1)
		{
			//code  callback
			SET_BIT(EXTI-> PR , 9); // clear flag after excuting
		}

}

