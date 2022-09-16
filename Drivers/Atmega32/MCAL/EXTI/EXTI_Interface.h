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


void EXTI_voidINT0Init(void);
void EXTI_voidINT1Init(void);
void EXTI_voidINT2Init(void);

u8 EXTI_u8INT0SetSenseControl(u8 Copy_u8Sense);
u8 EXTI_u8INT1SetSenseControl(u8 Copy_u8Sense);
u8 EXTI_u8INT2SetSenseControl(u8 Copy_u8Sense);

#define ENABLE  1
#define DISABLE 2

void EXTI_voidINT0State(u8 Copy_u8Int0State);
void EXTI_voidINT1State(u8 Copy_u8Int0State);
void EXTI_voidINT2State(u8 Copy_u8Int0State);

#define INT0    0
#define INT1    1
#define INT2    2
void EXTI_voidINTSetCallBack(void (*Copy_pvNotificationFunction)(void), u8 Copy_u8INTNumber);


#endif

#endif
