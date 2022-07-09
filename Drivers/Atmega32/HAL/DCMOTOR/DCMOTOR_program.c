/************************************************************/
/* Author : Nadine Ashraf Adeeb                             */
/* Description: File that holds all configuration for       */
/*                  DC MOTOR                                */
/*                Layer : HAL                               */
/* Version :v1.0                                            */
/* Date : 26 Sep ,2021                                      */
/************************************************************/
#include "STD_TYPES.h" 
#include "BIT_MATH.h" 
#include "DIO_Interface.h"

#include "DCMOTOR_Interface.h"
#include "DCMOTOR_Private.h"
#include "DCMOTOR_Config.h"                                                                                                          

void DCMOTOR_voidInit(void)
{
     DIO_voidSetPinDirection( Transistor_Port, Transistor_B1_B2,OUTPUT);
     DIO_voidSetPinDirection( Transistor_Port, Transistor_B0_B3,OUTPUT);
}

void DCMOTOR_voidClockWise(void)
{         
     DIO_voidSetPinValue (Transistor_Port,Transistor_B1_B2 , LOW);
     DIO_voidSetPinValue (Transistor_Port,Transistor_B0_B3 , HIGH);
}
void DCMOTOR_voidStopMotor(void)
{
     DIO_voidSetPinValue (Transistor_Port,Transistor_B0_B3 , LOW);
     DIO_voidSetPinValue (Transistor_Port,Transistor_B1_B2, LOW);
}
void DCMOTOR_voidCounterClockWise(void)
{
     DIO_voidSetPinValue (Transistor_Port,Transistor_B0_B3 , LOW);
     DIO_voidSetPinValue (Transistor_Port,Transistor_B1_B2 , HIGH);
}
