/*
 * USART_interface.h
 *
 *  Created on: Feb 15, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void   MUSART1_voidInit(void);
void   MUSART1_voidTransmit(u8 arr[]);
u8     MUSART1_u8Receive(void);

#endif /* USART_INTERFACE_H_ */
