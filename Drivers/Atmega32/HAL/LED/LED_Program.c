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
#include "LED_Register.h"
#include "LED_Private.h" 
#include "LED_Config.h"

void LED_u8StateON(u8 Copy_u8LEDConnection)
{
	#if LED_CONNECTION_TYPE == SOURCE
	DIO_u8SetPinValue(LED_u8PORT, LED_u8PIN, LED_HIGH);
	#elif LED_CONNECTION_TYPE == SINK
        DIO_u8SetPinValue(LED_u8PORT, LED_u8PIN, LED_LOW);
	#else
		#error "Wrong Connection"
	#endif

}

void LED_u8StateOFF(u8 Copy_u8LEDConnection)
{
	#if LED_CONNECTION_TYPE == SOURCE
	DIO_u8SetPinValue(LED_u8PORT, LED_u8PIN, LED_LOW);
	#elif LED_CONNECTION_TYPE == SINK
        DIO_u8SetPinValue(LED_u8PORT, LED_u8PIN, LED_HIGH);
	#else
		#error "Wrong Connection"
	#endif

}
