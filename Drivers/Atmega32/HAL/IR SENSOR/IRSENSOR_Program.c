#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "IRSENSOR_Interface.h"
#include "IRSENSOR_Register.h"
#include "IRSENSOR_Private.h" 
#include "IRSENSOR_Config.h"


u8 IRSENSOR_u8GetState(u8 Copy_u8IRState)
{
	u8 Local_u8ErrorState = OK;

	DIO_u8GetPinValue(IR_LED_u8PORT,IR_u8PIN, &Copy_u8IRState);

		if(Copy_u8IRState == IRSENSOR_HIGH)
		{
			DIO_u8SetPinValue(IR_LED_u8PORT, LED_u8PIN, DIO_u8PIN_LOW);
		}
		else if(Copy_u8IRState == IRSENSOR_LOW)
		{
			DIO_u8SetPinValue(IR_LED_u8PORT, LED_u8PIN, DIO_u8PIN_HIGH);
		}
		else
		{
			Local_u8ErrorState = NOK;
		}
        return Local_u8ErrorState;

}
