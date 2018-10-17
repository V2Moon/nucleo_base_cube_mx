#include "stm32f1xx_hal.h"
#include "accelero.h"
#include "MyGPIO.h"

//Id�e 1 : scruter avec le timer pour les IT r�guli�res
//Dans le handler on regarde 1 chanel (on peut connaitre
//L'angle limite en ne mesurant qu'un seul axe)

//Id�e 2 : configurer l'ADC avec une IT qui se d�clenche
//A l'angle limite !! (plus besoin du timer et des valeurs)

//Le PIN pour acc�l�ro - X
GPIO_Struct_TypeDef *AcceleroGPIOX;
AcceleroGPIOX[1] = GPIOC;//, IN_PIN, INPUT_FLOATING};
AcceleroGPIOX[2] = 10;

GPIO_Struct_TypeDef *AcceleroGPIOY;
AcceleroGPIOY[1] = GPIOC;//, IN_PIN, INPUT_FLOATING};
AcceleroGPIOY[2] = 11;

//Activer horloge locale des 2 ADC
void init_Accelero ()
{
	GPIO_Init(AcceleroGPIO);

}

void config_ADC_IN10 () // IN 11 � faire aussi + config le DMA
{
	//ON -> Clk on
	ADC_CHANNEL_10 |= ADC_CR2_ADON;

	
}


//Param�trer le capteur
void set_g_select ()
{
//Choisir la pr�cision du capteur
//Pas sleep mode (2=1, 1=0)
	
}


//Return l'angle de roulis
int get_angle ()
{
	//X=PC0 (ADC_IN10)
	//Y=PC1 (ADC_IN11)
	return atan(X/Y);
}


//Configuration d'une IT (faire avec une structure ?)
void initNVIC (void)
{

}
//initNVIC + initP�riph + handler
//IT = changement des valeurs de l'angle roulis (cf DMA)
//Handler = regarde si >45