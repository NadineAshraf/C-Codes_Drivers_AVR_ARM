/*
 * main.c
 *
 *  Created on: Sep 15, 2022
 *      Author: Nadine Ashraf Adeeb
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "TIMER_Interface.h"
#include "GIE_Interface.h"
#include <util/delay.h>

void main(void)
{
	u8 Local_u8Counter;
	DIO_u8SetPinDirection(DIO_u8PORTD , DIO_u8PIN5 ,DIO_u8PIN_OUTPUT);
	TIMER1_voidInitFastPWM(NON_INVERTING_MODE, FASTPWM_MODE14, PRESCALER_8);
	TIMER1_voidSetICR(19999);
	while(1)
	{
		/*for(Local_u8Counter= 750 ; Local_u8Counter<2500 ; Local_u8Counter++)
				{
			TIMER1_voidSetChannelACompareMatch(Local_u8Counter);
					_delay_ms(10);
				}*/
		TIMER1_voidSetChannelACompareMatch(499);
	}
}
