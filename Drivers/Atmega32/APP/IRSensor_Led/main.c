/*
 * main.c
 *
 *  Created on: Sep 7, 2022
 *      Author: Nadine Ashraf Adeeb
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "IRSENSOR_Interface.h"


void main(void)
{
	while(1)
	{
		DIO_u8SetPinDirection(DIO_u8PORTC, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
		IRSENSOR_u8GetState(IRSENSOR_HIGH);
	}
}
