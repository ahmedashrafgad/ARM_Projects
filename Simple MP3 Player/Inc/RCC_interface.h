/*
 * RCC_interface.h
 *
 *  Created on: Feb 2, 2021
 *      Author: Ahmed Ashraf
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


typedef enum
{
	 RCC_AHB ,
	 RCC_APB1,
	 RCC_APB2
}BUSID_type;



void MRCC_voidInit(void);
void MRCC_voidEnablePeripheralClock (BUSID_type Copy_enumBusID,u8 Copy_u8PeripheralID);
void MRCC_voidDisablePeripheralClock(BUSID_type Copy_enumBusID,u8 Copy_u8PeripheralID);
void MRCC_voidSetADCScaller(u8 Copy_enumADCScaller);

/*  =============== RCC_AHB CHOICES =============== */
#define RCC_DMA1       0
#define RCC_DMA2       1
#define RCC_SRAM       2
#define RCC_FLITF      4
#define RCC_CRCEN      6
#define	RCC_USBOTG     12
#define	RCC_ETHMAC     14
#define RCC_ETHMACTX   15
#define RCC_ETHMACRX   16

/*  =============== RCC_APB2 CHOICES =============== */
#define	 RCC_ALTFUN    0
#define	 RCC_GPIOA     2
#define	 RCC_GPIOB     3
#define	 RCC_GPIOC     4
#define	 RCC_GPIOD     5
#define	 RCC_GPIOE     6
#define	 RCC_ADC1      9
#define	 RCC_ADC2      10
#define	 RCC_TIMER1    11
#define	 RCC_SPI1      12
#define	 RCC_USART1    14

/*  =============== RCC_APB1 CHOICES =============== */
#define	 RCC_TIMER2    0
#define	 RCC_TIMER3    1
#define	 RCC_TIMER4    2
#define	 RCC_TIMER5    3
#define	 RCC_TIMER6    4
#define	 RCC_TIMER7    5
#define	 RCC_WWGOG     11 		//Window watch dog timer
#define	 RCC_SPI2      14
#define	 RCC_SPI3      15
#define	 RCC_USART2    17
#define	 RCC_USART3    18
#define	 RCC_UART4     19
#define	 RCC_UART5     20
#define	 RCC_I2C1      21
#define	 RCC_I2C2      22
#define	 RCC_CAN1      25
#define	 RCC_CAN2      26
#define	 RCC_BKPEN     27 		//  Backup interface clock enable
#define	 RCC_PWREN     28 		//Power interface clock enable
#define	 RCC_DACEN     29    	// DAC interface clock enable






#endif /* RCC_INTERFACE_H_ */
