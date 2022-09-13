/*************************************************************/
/*************************************************************/
/**************   Author : Nadine Ashraf Adeeb   *************/ 
/**************             Layer:HAL            *************/ 
/**************             SWC: LED             *************/ 
/**************            Version:v1.0          *************/ 
/**************    Date: 7 September,2022        *************/
/*************************************************************/
/*************************************************************/ 
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
		
#define SOURCE    1
#define SINK      0

void LED_u8StateON(void);
void LED_u8StateOFF(void);

u8 LED_u8ConnectionON(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8ConnectionType);
u8 LED_u8ConnectionOFF(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8ConnectionType);
#endif	
