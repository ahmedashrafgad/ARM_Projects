/*
 * NVIC_private.h
 *
 *  Created on: Feb 7, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


#define   NVIC_BASE_ADDRESS 0xE000E100
/*enable external interrupts
  each bit of the register eqavilant to an interrupt
  ISER2 is not used because i have only 59 peripheral */
#define   NVIC_ISER0      *((volatile u32*) (NVIC_BASE_ADDRESS +0x000))
#define   NVIC_ISER1      *((volatile u32*) (NVIC_BASE_ADDRESS +0x004))
#define   NVIC_ISER2 	  *((volatile u32*) (NVIC_BASE_ADDRESS +0x008))
/*clear external interrupts*/
#define   NVIC_ICER0 	  *((volatile u32*) (NVIC_BASE_ADDRESS +0x080))
#define   NVIC_ICER1 	  *((volatile u32*) (NVIC_BASE_ADDRESS +0x084))
#define   NVIC_ICER2	  *((volatile u32*) (NVIC_BASE_ADDRESS +0x088))
/*set pending flag*/
#define   NVIC_ISPR0	  *((volatile u32*) (NVIC_BASE_ADDRESS +0x100))
#define   NVIC_ISPR1	  *((volatile u32*) (NVIC_BASE_ADDRESS +0x104))
#define   NVIC_ISPR2	  *((volatile u32*) (NVIC_BASE_ADDRESS +0x108))
/*clear pending falg*/
#define   NVIC_ICPR0	  *((volatile u32*) (NVIC_BASE_ADDRESS +0x180))
#define   NVIC_ICPR1 	  *((volatile u32*) (NVIC_BASE_ADDRESS +0x184))
#define   NVIC_ICPR2	  *((volatile u32*) (NVIC_BASE_ADDRESS +0x188))
/*return the active flag (read only reg)
 "0" means not actived
 "1" means actived */
#define   NVIC_IABR0 	  *((volatile u32*) (NVIC_BASE_ADDRESS +0x200))
#define   NVIC_IABR1	  *((volatile u32*) (NVIC_BASE_ADDRESS +0x204))
#define   NVIC_IABR2 	  *((volatile u32*) (NVIC_BASE_ADDRESS +0x208))

/* to access a Part of u32 reg -- we can divide it into 4 parts u8 */
#define   NVIC_IPR    	   ((volatile u8*)  (NVIC_BASE_ADDRESS +0x300))

#define   NVIC_GROUP_16_SUB_0      (0x05FA0300)
#define   NVIC_GROUP_8_SUB_2       (0x05FA0400)
#define   NVIC_GROUP_4_SUB_4       (0x05FA0500)
#define   NVIC_GROUP_2_SUB_8       (0x05FA0600)
#define   NVIC_GROUP_0_SUB_16      (0x05FA0700)

/* This base address of system control block to make the priority of Core Peripherals */
#define   SCB_BASE_ADD        (0xE000ED00)
#define   SCB_SHPR            ((volatile u8 *)(SCB_BASE_ADD+0x18))

/*
 SCB_SHPR[0];      memory management fault -4
 SCB_SHPR[1];      bus fault - 5
 SCB_SHPR[2];      usage fault -6
 SCB_SHPR[7];      SVCall    -11
 SCB_SHPR[10];     PendSV    - 14
 SCB_SHPR[11];     PendSV    - 15
*/

#endif /* NVIC_PRIVATE_H_ */
