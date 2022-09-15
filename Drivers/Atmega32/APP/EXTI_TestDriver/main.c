/*
 * main.c
 *
 *  Created on: Sep 11, 2022
 *      Author: Nadine Ashraf Adeeb
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"

#include "EXTI_Interface.h"
#include "GIE_Interface.h"
void INT0_ISR(void);

void main (void)
{

	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0, PULLUP);

	EXTI_voidINT0SetCallBack(&INT0_ISR);
	//EXTI_voidINT0Init();
	EXTI_voidINT0State(ENABLE);
	EXTI_u8INT0SetSenseControl(FALLING_EDGE);
	GIE_voidEnable();
	while(1)
	{

	}
}
void INT0_ISR(void)
{
	//DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN2 , DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTD, DIO_u8PIN0 , DIO_u8PIN_HIGH);
}
