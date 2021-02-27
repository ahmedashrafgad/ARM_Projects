/*
 * ADC_private.h
 *
 *  Created on: Feb 12, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

typedef struct
{
	volatile u32 SR     ;
	volatile u32 CR1    ;
	volatile u32 CR2    ;
	volatile u32 SMPR1  ;
	volatile u32 SMPR2  ;
	volatile u32 JOFR1  ;
	volatile u32 JOFR2  ;
	volatile u32 JOFR3  ;
	volatile u32 JOFR4  ;
	volatile u32 HTR    ;
	volatile u32 LTR    ;
	volatile u32 SQR1   ;
	volatile u32 SQR2   ;
	volatile u32 SQR3   ;
	volatile u32 JSQR   ;
	volatile u32 JDR1   ;
	volatile u32 JDR2   ;
	volatile u32 JDR3   ;
	volatile u32 JDR4   ;
	volatile u32 DR     ;
}ADC_type;

#define 	ADC   ((ADC_type*)0x40012400)

 #define SAMPLE_TIME_1_5C 		0b000
 #define SAMPLE_TIME_7_5C		0b001
 #define SAMPLE_TIME_13_5C		0b010
 #define SAMPLE_TIME_28_5C		0b011
 #define SAMPLE_TIME_41_5C		0b100
 #define SAMPLE_TIME_55_5C		0b101
 #define SAMPLE_TIME_71_5C		0b110
 #define SAMPLE_TIME_239_5C		0b111


#endif /* ADC_PRIVATE_H_ */
