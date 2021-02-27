/*
 * USART_private.h
 *
 *  Created on: Feb 15, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

typedef struct
{
	volatile u32    SR;
	volatile u32    DR;
	volatile u32    BRR;
	volatile u32    CR1;
	volatile u32    CR2;
	volatile u32    CR3;
	volatile u32    GRPR;

}MUSART_Type;

#define USART1  ((volatile MUSART_Type*) 0x40013800)

#endif /* USART_PRIVATE_H_ */
