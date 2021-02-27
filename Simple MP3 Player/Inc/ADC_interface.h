/*
 * ADC_interface.h
 *
 *  Created on: Feb 12, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum
{
	ADC_Channel0  = 00000 ,
	ADC_Channel1   ,
	ADC_Channel2   ,
	ADC_Channel3   ,
	ADC_Channel4   ,
	ADC_Channel5   ,
	ADC_Channel6   ,
	ADC_Channel7   ,
	ADC_Channel8   ,
	ADC_Channel9   ,
	ADC_Channel10  ,
	ADC_Channel11  ,
	ADC_Channel12  ,
	ADC_Channel13  ,
	ADC_Channel14  ,
	ADC_Channel15  ,
	ADC_Channel16  ,
	ADC_Channel17  ,
}ADCChannel_type;

typedef enum
{
	ADC_SCALLER_DIV2,
	ADC_SCALLER_DIV4,
	ADC_SCALLER_DIV6,
	ADC_SCALLER_DIV8
}ADCSCALLER_type;

void MADC_voidInit(ADCSCALLER_type Copy_enumADCScaller,u8 Copy_u8NumOfChannels);
void MADC_voidEnableChannel(ADCChannel_type Copy_enumChannel,u8 Copy_u8Sequance);
u8 MADC_voidRead(void);

#endif /* ADC_INTERFACE_H_ */
