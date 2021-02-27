/*
 * DMA_private.h
 *
 *  Created on: Feb 14, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

typedef struct
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 RESERVED;
}DMA1_channel;

typedef struct
{
	volatile u32 ISR;
	volatile u32 IFCR;
	DMA1_channel Channel[7];
}DMA1_Type;

#define			DMA1			((volatile DMA1_Type *) 0x40020000)



#endif /* DMA_PRIVATE_H_ */
