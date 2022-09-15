/*
 * main.c
 *
 *  Created on: Apr 2, 2022
 *      Author: Nadine Ashraf Adeeb
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include "TIMER_Interface.h"
#include "GIE_Interface.h"
#include <util/delay.h>
void PWM(void);
void LED(void);
void main(void)
{
	u8 Local_u8Counter;
	DIO_u8SetPinDirection(DIO_u8PORTD , DIO_u8PIN0 ,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD , DIO_u8PIN1 ,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD , DIO_u8PIN2 ,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB , DIO_u8PIN3 ,DIO_u8PIN_OUTPUT); // must be on OC0 pin
	TIMER0_voidInitPWMMode( NON_INVERTING_MODE ,PRESCALER_8  );
	//TIMER0_u8SetCallBack(&PWM);
	//GIE_voidEnable();
	while(1)
	{
		for(Local_u8Counter=0 ; Local_u8Counter<255 ; Local_u8Counter++)
		{
			TIMER0_voidSetCompareMatchValue(Local_u8Counter);
			_delay_ms(10);
		}

	}
}
void LED(void)
{
	static u16 Local_u16Counter=0;
	static u8 Local_u8LedState=0;
	Local_u16Counter++;
	if(Local_u16Counter == 4000)
	{
		TOG_BIT(Local_u8LedState , 0);
		DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN0,Local_u8LedState);
	Local_u16Counter=0;
	}
}

void PWM(void)
{
	static u8 Local_u8Counter = 0;
	Local_u8Counter++;
	if(Local_u8Counter == 5)
	{
		DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_LOW);

	}
	else if(Local_u8Counter ==10)
	{
		DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_LOW);
	}
	else if(Local_u8Counter ==15)
		{
			DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_LOW);
		}
	else if(Local_u8Counter == 20)
			{
				DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN0, DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN1, DIO_u8PIN_HIGH);
				DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_HIGH);
				Local_u8Counter = 0;
			}
}
