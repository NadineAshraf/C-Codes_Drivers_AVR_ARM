/*************************************************************/
/*************************************************************/
/**************   Author : Nadine Ashraf Adeeb   *************/ 
/**************             Layer:HAL            *************/ 
/**************             SWC: LED             *************/ 
/**************            Version:v1.0          *************/ 
/**************    Date: 7 September,2022        *************/
/*************************************************************/
/*************************************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "LED_Interface.h"
#include "LED_Private.h" 
#include "LED_Config.h"
                 /* Pre-Build Configuration*/
void LED_u8StateON(void)
{
	#if LED_CONNECTION_TYPE == SOURCE
	DIO_u8SetPinValue(LED_u8PORT, LED_u8PIN, LED_HIGH);
	#elif LED_CONNECTION_TYPE == SINK
    DIO_u8SetPinValue(LED_u8PORT, LED_u8PIN, LED_LOW);
	#else
		#error "Wrong Connection"
	#endif

}

void LED_u8StateOFF(void)
{
	#if LED_CONNECTION_TYPE == SOURCE
	DIO_u8SetPinValue(LED_u8PORT, LED_u8PIN, LED_LOW);
	#elif LED_CONNECTION_TYPE == SINK
    DIO_u8SetPinValue(LED_u8PORT, LED_u8PIN, LED_HIGH);
	#else
		#error "Wrong Connection"
	#endif

}
              /* Post-Buid Configuration*/
u8 LED_u8ConnectionON(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8ConnectionType)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8ConnectionType == SOURCE)
	{
		DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin, LED_HIGH);
	}
	else if(Copy_u8ConnectionType == SINK)
	{
		DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin, LED_LOW);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
u8 LED_u8ConnectionOFF(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8ConnectionType)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_u8ConnectionType == SOURCE)
	{
		DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin, LED_LOW);
	}
	else if(Copy_u8ConnectionType == SINK)
	{
		DIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin, LED_HIGH);
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}
