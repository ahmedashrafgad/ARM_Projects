/*
 * EXTI_interface.h
 *
 *  Created on: Feb 8, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum {
	 EXTI_LINE0		,
	 EXTI_LINE1    	,
	 EXTI_LINE2     ,
	 EXTI_LINE3     ,
	 EXTI_LINE4     ,
	 EXTI_LINE5     ,
	 EXTI_LINE6     ,
	 EXTI_LINE7     ,
	 EXTI_LINE8     ,
	 EXTI_LINE9     ,
	 EXTI_LINE10    ,
	 EXTI_LINE11    ,
	 EXTI_LINE12    ,
	 EXTI_LINE13    ,
	 EXTI_LINE14    ,
	 EXTI_LINE15
}EXTILINE_type;

typedef enum
{
 	EXTI_FALLING_EDGE			,
 	EXTI_RAISING_EDGE			,
 	EXTI_INTONCHANGE
}EXTIEGDE_type;

void MEXTI_voidInit(void);
void MEXTI_voidEnableLine			(EXTILINE_type Copy_enumEXTI_Line);
void MEXTI_voidSetSignalLatch		(EXTILINE_type Copy_enumEXTI_Line, EXTIEGDE_type Copy_enumEdgeMode);
void MEXTI_voidDisableLine			(EXTILINE_type Copy_enumEXTI_Line );
void MEXTI_voidSetSoftwareTrigger	(EXTILINE_type Copy_enumEXTI_Line );
void MEXTI0_voidSetCallBack			(void (*pf) (void) );
void MEXTI1_voidSetCallBack			(void (*pf) (void) );
void MEXTI2_voidSetCallBack			(void (*pf) (void) );
void MEXTI3_voidSetCallBack			(void (*pf) (void) );

#endif /* EXTI_INTERFACE_H_ */
