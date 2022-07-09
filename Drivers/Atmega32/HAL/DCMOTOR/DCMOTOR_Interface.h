/************************************************************/
/* Author : Nadine Ashraf Adeeb                             */
/* Description: File that holds all configuration for       */
/*                  DC MOTOR                                */
/*                Layer : HAL                               */
/* Version :v1.0                                            */
/* Date : 26 Sep ,2021                                      */
/************************************************************/
#ifndef DCMOTOR_INTERFACE_H
#define DCMOTOR_INTERFACE_H

void DCMOTOR_voidInit(void);

void DCMOTOR_voidStopMotor(void);
void DCMOTOR_voidCounterClockWise(void);
void DCMOTOR_voidClockWise(void);

#endif
