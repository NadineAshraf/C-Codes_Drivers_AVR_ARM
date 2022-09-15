/*************************************************************/
/*************************************************************/
/**************   Author : Nadine Ashraf Adeeb   *************/ 
/**************            Layer:MCAL            *************/ 
/**************             SWC: EXTI            *************/ 
/**************            Version:v1.0          *************/ 
/**************    Date: 11 September,2022       *************/
/*************************************************************/
/*************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#define  LOW_LEVEL     1
#define  ON_CHANGE     2
#define  FALLING_EDGE  3
#define  RISING_EDGE   4

#define INT0 6
#define INT1 7
#define INT2 5
void EXTI_voidINT0Init(void);
void EXTI_voidINT1Init(void);
void EXTI_voidINT2Init(void);

u8 EXTI_u8INT0SetSenseControl(u8 Copy_u8Sense);
u8 EXTI_u8INT1SetSenseControl(u8 Copy_u8Sense);
u8 EXTI_u8INT2SetSenseControl(u8 Copy_u8Sense);

u8 EXTI_u8EnableInterrupt(u8 Copy_InterruptNumber);
u8 EXTI_u8DisableInterrupt(u8 Copy_InterruptNumber);
#define ENABLE  1
#define DISABLE 2

void EXTI_voidINT0State(u8 Copy_u8Int0State);
void EXTI_voidINT1State(u8 Copy_u8Int0State);
void EXTI_voidINT2State(u8 Copy_u8Int0State);

void EXTI_voidINT0SetCallBack(void (*Copy_pv0NotificationFunction)(void));
void EXTI_voidINT1SetCallBack(void (*Copy_pv1NotificationFunction)(void));
void EXTI_voidINT2SetCallBack(void (*Copy_pv2NotificationFunction)(void));

#endif
