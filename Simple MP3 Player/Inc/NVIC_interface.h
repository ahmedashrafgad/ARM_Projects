/*
 * NVIC_interface.h
 *
 *  Created on: Feb 7, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/* =====================   Interrupt numbers  =====================*/

typedef enum{
	INTERRUPT_WWDG             ,
	INTERRUPT_PVD              ,
	INTERRUPT_TAMPER           ,
	INTERRUPT_RTC              ,
	INTERRUPT_FLASH            ,
	INTERRUPT_RCC              ,
	INTERRUPT_EXTI0            ,
	INTERRUPT_EXTI1            ,
	INTERRUPT_EXTI2            ,
	INTERRUPT_EXTI3            ,
	INTERRUPT_EXTI4            ,
	INTERRUPT_DMA1_Channel1    ,
	INTERRUPT_DMA1_Channel2    ,
	INTERRUPT_DMA1_Channel3    ,
	INTERRUPT_DMA1_Channel4    ,
	INTERRUPT_DMA1_Channel5    ,
	INTERRUPT_DMA1_Channel6    ,
	INTERRUPT_DMA1_Channel7    ,
	INTERRUPT_ADC1_2           ,
	INTERRUPT_USB_HP_CAN_TX    ,
	INTERRUPT_USB_LP_CAN_RX0   ,
	INTERRUPT_CAN1_RX1         ,
	INTERRUPT_CAN1_SCE         ,
	INTERRUPT_EXTI9_5          ,
	INTERRUPT_TIM1_BRK         ,
	INTERRUPT_TIM1_UP          ,
	INTERRUPT_TIM1_TRG_COM     ,
	INTERRUPT_TIM1_CC          ,
	INTERRUPT_TIM2             ,
	INTERRUPT_TIM3             ,
	INTERRUPT_TIM4             ,
	INTERRUPT_I2C1_EV          ,
	INTERRUPT_I2C1_ER          ,
	INTERRUPT_I2C2_EV          ,
	INTERRUPT_I2C2_ER          ,
	INTERRUPT_SPI1             ,
	INTERRUPT_SPI2             ,
	INTERRUPT_USART1           ,
	INTERRUPT_USART2           ,
	INTERRUPT_USART3           ,
	INTERRUPT_EXTI15_10        ,
	INTERRUPT_RTCAlarm         ,
	INTERRUPT_USBWakeup        ,
	INTERRUPT_TIM8_BRK         ,
	INTERRUPT_TIM8_UP          ,
	INTERRUPT_TIM8_TRG_COM     ,
	INTERRUPT_TIM8_CC          ,
	INTERRUPT_ADC3             ,
	INTERRUPT_FSMC             ,
	INTERRUPT_SDIO             ,
	INTERRUPT_TIM5             ,
	INTERRUPT_SPI3             ,
	INTERRUPT_UART4            ,
	INTERRUPT_UART5            ,
	INTERRUPT_TIM6             ,
	INTERRUPT_TIM7             ,
	INTERRUPT_DMA2_Channel1    ,
	INTERRUPT_DMA2_Channel2    ,
	INTERRUPT_DMA2_Channel3    ,
	INTERRUPT_DMA2_Channel4_5

}INTERRUPTNUM_Type;

/* =====================  Core Peripherals Interrupt numbers  =====================*/
typedef enum{
	INTERRUPT_MemManage   =  0 ,
	INTERRUPT_BusFault    =  1 ,
	INTERRUPT_UsageFault  =  2 ,
	INTERRUPT_SVCall      =  7 ,
	INTERRUPT_PendSV      =  10,
	INTERRUPT_SysTick     =  11
}CORE_INTERRUPTNUM_Type;

/* =====================   NVIC_GROUP_4_SUB_4 Priorites  =====================*/
 typedef enum {
	 Group0_Sub0  = 0b0000,     // 0b0000
     Group0_Sub1  ,             // 0b0001
     Group0_Sub2  ,             // 0b0010
     Group0_Sub3  ,             // 0b0011
     Group1_Sub0  ,             // 0b0100
     Group1_Sub1  ,             // 0b0101
     Group1_Sub2  ,             // 0b0110
     Group1_Sub3  ,             // 0b0111
     Group2_Sub0  ,             // 0b1000
     Group2_Sub1  ,             // 0b1001
     Group2_Sub2  ,             // 0b1010
     Group2_Sub3  ,             // 0b1011
     Group3_Sub0  ,             // 0b1100
     Group3_Sub1  ,             // 0b1101
     Group3_Sub2  ,             // 0b1110
     Group3_Sub3                // 0b1111
  }Priorioty4Group4Sub_Type;




void MNVIC_voidInit             (void);
void MNVIC_voidEnableInterrupt  (INTERRUPTNUM_Type Copy_enumInterruptNum);
void MNVIC_voidDisableInterrupt (INTERRUPTNUM_Type Copy_enumInterruptNum);
void MNVIC_voidSetPendingFlag   (INTERRUPTNUM_Type Copy_enumInterruptNum);
void MNVIC_voidClearPendingFlag (INTERRUPTNUM_Type Copy_enumInterruptNum);
u8   MNVIC_u8GetActiveFlag      (INTERRUPTNUM_Type Copy_enumInterruptNum);
void MNVIC_voidSetPriority      (INTERRUPTNUM_Type Copy_enumInterruptNum, Priorioty4Group4Sub_Type Copy_enumPriority);
void MNVIC_voidSetPriorityCorePeripherals(CORE_INTERRUPTNUM_Type Copy_enumCorePerInterruptNum, Priorioty4Group4Sub_Type Copy_enumPriority);



/* =====================   Priority grouping  =====================
 void MNVIC_voidSetPriorityCorePeripherals(CORE_INTERRUPTNUM_Type Copy_StructCorePerInterruptNum, Priorioty4Group4Sub_Type Copy_StructPriority) *  Case ----->  MNVIC_GROUP_8_SUB_2    ----->   0bXXXY
 *  Case ----->  MNVIC_GROUP_4_SUB_4    ----->   0bXXYY
 *  Case ----->  MNVIC_GROUP_2_SUB_8    ----->   0bXYYY
 *  Case ----->  MNVIC_GROUP_0_SUB_16   ----->   0bYYYY
 */



#endif /* NVIC_INTERFACE_H_ */
