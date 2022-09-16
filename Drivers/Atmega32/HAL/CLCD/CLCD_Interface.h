/*************************************************************/
/*************************************************************/
/**************   Author : Nadine Ashraf Adeeb   *************/ 
/**************             Layer:HAL            *************/ 
/**************             SWC:CLCD             *************/ 
/**************            Version:v1.0          *************/ 
/**************    Date: 7 September,2022        *************/
/*************************************************************/
/*************************************************************/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidInit(void);
void CLCD_voidSendCommand(u8 Copy_u8Command);
void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidSendString(const char* Copy_pcString);
void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);
void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);
void CLCD_voidWriteNumber(s32 Copy_s32Number);
#endif
