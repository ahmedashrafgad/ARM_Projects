/*
 * ADC_program.c
 *
 *  Created on: Feb 12, 2021
 *      Author: Ahmed Ashraf
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

 #include "ADC_interface.h"
 #include "ADC_private.h"
 #include "ADC_config.h"

#include"RCC_interface.h"
#include"STK_interface.h"


/* Define Callback Global Variable */
static void (*ADC_pfCallBack)(void) = NULL;

void MADC_voidInit(ADCSCALLER_type Copy_enumADCScaller,u8 Copy_u8NumOfChannels)
{
	MRCC_voidSetADCScaller(Copy_enumADCScaller);
	//enable end of conversion interrupt
	SET_BIT(ADC->CR1 , 5);
	// Set number of used channels in SQR1
	Copy_u8NumOfChannels --;
	ADC->SQR1 = (Copy_u8NumOfChannels << 20);
	// we wont change the defult sequance so it will move from 0 To 17 in the same normal order

	//start ADC on
	SET_BIT(ADC->CR2,0);
	SET_BIT(ADC->CR2,3);
	//Continous Mode on
	SET_BIT(ADC->CR2,1);
	MSTK_voidSetBusyWait(1);
	//Enable Calibration
	SET_BIT(ADC->CR2,2);
	//Wait Until Calibration done
	while(GET_BIT(ADC->CR2,2)==1);
}

void MADC_voidEnableChannel(ADCChannel_type Copy_enumChannel,u8 Copy_u8Sequance)
{
	ADC-> CR1 = Copy_enumChannel;
	if (Copy_enumChannel<10)
	{
		//Set Sample Time for the Channel
		ADC->SMPR2 = SAMPLE_TIME << (Copy_enumChannel*3);
	}
	else if (Copy_enumChannel >= 10 && Copy_enumChannel<18)
	{
		Copy_enumChannel -= 10;
		//Set Sample Time for the Channel
		ADC->SMPR1 = SAMPLE_TIME << (Copy_enumChannel*3);
	}
	//select the Sequance of reading the channel
	if (Copy_enumChannel <= 6)
	{
		ADC->SQR3 = Copy_enumChannel << (Copy_u8Sequance *5);
	}
	else if (Copy_enumChannel <= 12)
	{
		Copy_u8Sequance-= 7;
		ADC->SQR2 = Copy_enumChannel << (Copy_u8Sequance *5);
	}
	else if (Copy_enumChannel <= 16)
	{
		Copy_u8Sequance-= 13;
		ADC->SQR1 = Copy_enumChannel << (Copy_u8Sequance *5);
	}
}

u8 MADC_voidRead(void)
{
	u8 Local_u8Value=0;
	while (GET_BIT(ADC->SR , 1)==0);
	//MSTK_voidSetBusyWait(2);
	 ADC->DR = Local_u8Value ;
	return Local_u8Value;
}
/*
void MADC_voidSetCallBack(void (*pf) (void)) // address ahmed Function
{
	if(pf != NULL)
	{
		//ADC_pfCallBack = pf = address ahmed Function
		ADC_pfCallBack = pf ;
	}
}
*/

