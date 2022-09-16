/*************************************************************/
/*************************************************************/
/**************   Author : Nadine Ashraf Adeeb   *************/ 
/**************             Layer:HAL            *************/ 
/**************             SWC:CLCD             *************/ 
/**************            Version:v1.0          *************/ 
/**************    Date: 7 September,2022        *************/
/*************************************************************/
/*************************************************************/
/******                Added Functions                  ******/ 
/******  void CLCD_voidWriteNumber(s32 Copy_s32Number)  ******/
/******            Date: 16 September,2022              ******/
/*************************************************************/
/*************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Interface.h"
#include <util/delay.h>

#include "CLCD_Interface.h"
#include "CLCD_Private.h" 
#include "CLCD_Config.h"

void CLCD_voidInit(void)
{
	/* Wait for more than 30 ms*/
	_delay_ms(40);
	/* Function set command: 2 lines. 5*8 Font size*/
	CLCD_voidSendCommand(0b00111000);
	/* Display on off control: display enable, disable cursor, no blink cursor */
	CLCD_voidSendCommand(0b00001100);
	/* Clear Display*/
	CLCD_voidSendCommand(0b00000001);
	
}
void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	
	/* Set RS pin to LOW for Command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN , DIO_u8PIN_LOW);
	/* Set RW pin to LOW for Write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
	/* Set Command to Data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Command);
	/* Send Enable Pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
	
	
}
void CLCD_voidSendData(u8 Copy_u8Data)
{
	/* Set RS pin to HIGH for Data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN , DIO_u8PIN_HIGH);
	/* Set RW pin to LOW for Write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
	/* Set Command to Data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Data);
	/* Send Enable Pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
	
}
void CLCD_voidSendString(const char* Copy_pcString)
{
	u8 Local_u8Counter = 0;
	while(Copy_pcString[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}

}
void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8Address;
	if(Copy_u8XPos == 0)
	{
		/* Location is at first line */
		Local_u8Address = Copy_u8YPos;
	}
	else if(Copy_u8XPos == 1)
	{
		/* Location is at second line */
		Local_u8Address = Copy_u8YPos +0x40;
	}
	/* Set bit number 7 for Set DDRAM Address command the send the command*/
	CLCD_voidSendCommand(Local_u8Address + 128);
}

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress = 0,Local_u8Iterator;
	/*Calculate the CGRAM Address whose each block is 8 bytes*/
	Local_u8CGRAMAddress = Copy_u8PatternNumber*8;
	/*Send CG RAM address command to LCD, With setting bit 6, clearing bit 7*/
	CLCD_voidSendCommand(Local_u8CGRAMAddress+64);
	/* Write the pattern into CGRAM*/
	for(Local_u8Iterator = 0 ; Local_u8Iterator<8; Local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]);
	}
	/* Go back to the DDRAM to display the pattern */
	CLCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos);
	/*Display the pattern written in the CGRAM*/
	CLCD_voidSendData(Copy_u8PatternNumber);
}
void CLCD_voidWriteNumber(s32 Copy_s32Number)
{
	s32 Copy_s32CopyNumber = Copy_s32Number;
	u8 Local_u8Counter = 0;
	if(Copy_s32Number == 0)
	{
		CLCD_voidSendData('0');
	}
	if(Copy_s32Number < 0)
	{
		CLCD_voidSendData('-');
		Copy_s32CopyNumber*= -1;
		Copy_s32Number*= -1;
	}
	/* Counting number of digits for the integer*/
	while(Copy_s32CopyNumber != 0)
	{
		Copy_s32CopyNumber = Copy_s32CopyNumber / 10;
		Local_u8Counter++;
	}
	/* Separating number digits then organizing them into a char array */
	u8 Local_u8NumberDigits[Local_u8Counter];
	for(s32 Local_s32Digit = Local_u8Counter -1; Local_s32Digit >= 0; Local_s32Digit--)
	{
		Local_u8NumberDigits[Local_s32Digit] = (Copy_s32Number % 10) + '0';
		Copy_s32Number = Copy_s32Number / 10;
	}
	/* Writing the number on the LCD Display */
	for(s32 Local_s32Digit = 0; Local_s32Digit < Local_u8Counter; Local_s32Digit++)
		{
		    CLCD_voidSendData(Local_u8NumberDigits[Local_s32Digit]);
		}
}
