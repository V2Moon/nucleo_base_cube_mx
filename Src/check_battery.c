#include <stdio.h>
#include "stm32f10x.h"
#include "stm32f1xx_hal.h"
//#include "check_battery.h"

/*=================================================================================
Autor : NIRINA Carrel
Software : Keil uVision 5
Processor : STM32F103RB
===================================================================================*/

/*=================================================================================
Programs necessary for monitoring the battery of the project Voilier. When 
the level of the battery is low, a message is send with RF sender.
===================================================================================*/


/*=================================================================================
Initialize the GPIOC 2 in Analog input
===================================================================================*/
void init_PC2(void){
	//set GPIOC 2
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
	//Init GPIOC 2
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
}

/*=================================================================================
Initialize the ADC1 channel 12
===================================================================================*/
void init_ADC1(void){
	//init ADC
	ADC_InitTypeDef ADC_InitStruct;
	ADC_InitStruct.ContinuousConvMode = ENABLE;
	ADC_InitStruct.NbrOfConversion = 1;
	//init Channel 12
	ADC_ChannelConfTypeDef ADC_InitChannel;
	ADC_InitChannel.Channel = ADC_CHANNEL_12;
	ADC_InitChannel.Rank = ADC_REGULAR_RANK_1;
	//init Handle ADC
	ADC_HandleTypeDef ADC_InitHandle;
	ADC_InitHandle.Instance = ADC1;
	ADC_InitHandle.Init = ADC_InitStruct;
	//CALL HAL FUNCTION FOR INIT
	HAL_ADC_Init(&ADC_InitHandle);
	HAL_ADC_ConfigChannel(&ADC_InitHandle,&ADC_InitChannel);
}
