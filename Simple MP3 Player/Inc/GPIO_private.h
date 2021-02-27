/*
 * GPIO_private.h
 *
 *  Created on: Feb 3, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_



#define GPIOA_BASE_ADDRESS        0x40010800            // define the boundary address of GPIO port A
#define GPIOB_BASE_ADDRESS        0x40010C00            // define the boundary address of GPIO port B
#define GPIOC_BASE_ADDRESS        0x40011000            // define the boundary address of GPIO port C

/************************** PORT A ********************************/
#define GPIOA_CRL				*((u32*)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH				*((u32*)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR				*((u32*)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR				*((u32*)(GPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_BSRR				*((u32*)(GPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR				*((u32*)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_LCKR				*((u32*)(GPIOA_BASE_ADDRESS + 0x18))

/************************** PORT B ********************************/
#define GPIOB_CRL				*((u32*)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH				*((u32*)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR				*((u32*)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR				*((u32*)(GPIOB_BASE_ADDRESS + 0x0C))
#define GPIOB_BSRR				*((u32*)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR				*((u32*)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_LCKR				*((u32*)(GPIOB_BASE_ADDRESS + 0x18))

/************************** PORT C ********************************/
#define GPIOC_CRL				*((u32*)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH				*((u32*)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR				*((u32*)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR				*((u32*)(GPIOC_BASE_ADDRESS + 0x0C))
#define GPIOC_BSRR				*((u32*)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR				*((u32*)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_LCKR				*((u32*)(GPIOC_BASE_ADDRESS + 0x18))

#endif /* GPIO_PRIVATE_H_ */
