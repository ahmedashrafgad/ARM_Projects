/*
 * STK_interface.h
 *
 *  Created on: Feb 10, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

/* Apply Clock choice from configuration file
   Disable SysTick interrupt
   Disable Systick                          */
void MSTK_voidInit(void);
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks );
void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidSetIntervalSingleMicro  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidSetIntervalPeriodicMicro( u32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void MSTK_voidStopInterval(void);
/* Elapsed time means how much time the timer counted (load register - value register) */
u32  MSTK_u32GetCounts(void);
/* Remaning time means time left for the timer to finish counting (read value register)*/
u32  MSTK_u32GetRemainingTime(void);
void MSTK_voidEnableSTK(void);
void MSTK_voidEnableSTKINTRRUPT(void);


#endif /* STK_INTERFACE_H_ */
