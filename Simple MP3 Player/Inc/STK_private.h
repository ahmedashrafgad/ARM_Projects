/*
 * STK_private.h
 *
 *  Created on: Feb 10, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_


typedef struct
{
	volatile u32 CTRL  ;
	volatile u32 LOAD  ;
	volatile u32 VAL   ;
	volatile u32 CALIB   ;
}STK_Type;

#define     STK    ((STK_Type*)0xE000E010)


#define     STK_SRC_AHB_8         	 1
#define     STK_SRC_AHB          	 3

#define     STK_SINGLE_INTERVAL      1
#define     STK_PERIODIC_INTERVAL    3



#endif /* STK_PRIVATE_H_ */
