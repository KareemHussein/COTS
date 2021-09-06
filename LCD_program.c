/************************************************************************
 *                                                                      *
 *************************  Date    : 12/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : LCD             *******************
 *                                                                      *
 ************************************************************************/

#include <util/delay.h>
#define F_CPU   8000000UL

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_private.h"
#include "LCD_interface.h"
#include "LCD_config.h"

void LCD_voidInit(void)
{
	_delay_ms(35);
	
#if LCD_u8_MODE == LCD_u8_8_BIT_MODE
	LCD_voidSendCmnd(0b00111000); // Function Set command 2*16 LCD
	
#elif LCD_u8_MODE == LCD_u8_4_BIT_MODE
    (void)DIO_u8SetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, LCD_u8_PIN_LOW); // set Rs pin = 0 (write command)
	(void)DIO_u8SetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, LCD_u8_PIN_LOW); // set Rw pin = 0 (write)
	
	Private_voidWriteHalfPort(0b0010);
	/* Enable Pulse *//* H => L */
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_HIGH);
	_delay_ms(1);
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_LOW);
	
	LCD_voidSendCmnd(0b00101000);
#endif

	_delay_us(45);
	LCD_voidSendCmnd(0b00001111); // Display on off Control (DisplayOn, Cursor on, Blink on)
	_delay_us(45);
	LCD_voidSendCmnd(0b00000001); // Clear Display
	_delay_ms(2);
	LCD_voidSendCmnd(0b00000110); // Set Entry Mode
}


void LCD_voidSendCmnd(u8 Copy_u8Cmnd)
{
	(void)DIO_u8SetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, LCD_u8_PIN_LOW); // set Rs pin = 0 (write command)

	(void)DIO_u8SetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, LCD_u8_PIN_LOW); // set Rw pin = 0 (write)
	
#if LCD_u8_MODE == LCD_u8_8_BIT_MODE
	(void)DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Cmnd); // Write Command on Data Pins

	/* Enable Pulse *//* H => L */
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_HIGH);
	_delay_ms(1);
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_LOW);
	
#elif LCD_u8_MODE == LCD_u8_4_BIT_MODE
    Private_voidWriteHalfPort(Copy_u8Cmnd>>4); // Write The Most 4 bits Of Command on Data Pins
	
	/* Enable Pulse *//* H => L */
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_HIGH);
	_delay_ms(1);
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_LOW);
	
	Private_voidWriteHalfPort(Copy_u8Cmnd); // Write The Least 4 bits Of Command on Data Pins
	
	/* Enable Pulse *//* H => L */
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_HIGH);
	_delay_ms(1);
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_LOW);
#endif
}


void LCD_voidSendChar(u8 Copy_u8Char)
{
	(void)DIO_u8SetPinValue(LCD_u8_RS_PORT, LCD_u8_RS_PIN, LCD_u8_PIN_HIGH); // set Rs pin = 1 (write data)

	(void)DIO_u8SetPinValue(LCD_u8_RW_PORT, LCD_u8_RW_PIN, LCD_u8_PIN_LOW); // set Rw pin = 0 (write)

#if LCD_u8_MODE == LCD_u8_8_BIT_MODE	
	(void)DIO_u8SetPortValue(LCD_u8_DATA_PORT, Copy_u8Char); // Write Command on Data Pins

	/* Enable Pulse *//* H => L */
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_HIGH);
	_delay_ms(1);
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_LOW);
	
#elif LCD_u8_MODE == LCD_u8_4_BIT_MODE
     Private_voidWriteHalfPort(Copy_u8Char>>4); // Write The Most 4 bits Of Command on Data Pins
	
	/* Enable Pulse *//* H => L */
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_HIGH);
	_delay_ms(1);
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_LOW);
	
	Private_voidWriteHalfPort(Copy_u8Char); // Write The Least 4 bits Of Command on Data Pins
	
	/* Enable Pulse *//* H => L */
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_HIGH);
	_delay_ms(1);
	(void)DIO_u8SetPinValue(LCD_u8_EN_PORT, LCD_u8_EN_PIN, LCD_u8_PIN_LOW);
#endif
}


void LCD_voidWriteString(const u8 *Copy_Pu8String)
{
	u8 Local_u8StringLengh = 0;
	while (Copy_Pu8String[Local_u8StringLengh] != '\0')
	{
		LCD_voidSendChar(Copy_Pu8String[Local_u8StringLengh]);
		++ Local_u8StringLengh;
	}
}


void LCD_voidWriteNumber(u32 Copy_u32Number)
{
	u32 Local_u32Reversed = 1;
	if (Copy_u32Number == 0)
	{
		LCD_voidSendChar('0');
	}
	else
	{
		// Reverse Number
		while (Copy_u32Number != 0)
		{
			Local_u32Reversed = Local_u32Reversed*10 + (Copy_u32Number%10);
			Copy_u32Number /= 10;
		}
		
		do 
		{
			LCD_voidSendChar((Local_u32Reversed%10)+'0');
			Local_u32Reversed /= 10;
		}while (Local_u32Reversed != 1);
	} 
}


void LCD_voidGoToSpecificPosition(u8 Copy_u8LineNumber, u8 Copy_u8Position)
{
	if(Copy_u8LineNumber == LCD_u8_LINE_ONE)
	{
		if(Copy_u8Position <= 15)
		{
			LCD_voidSendCmnd(0x80 + Copy_u8Position);
		}
	}

	else if (Copy_u8LineNumber == LCD_u8_LINE_TWO)
	{
		if(Copy_u8Position <= 15)
		{
			LCD_voidSendCmnd(0xc0 + Copy_u8Position);
		}
	}
}


void LCD_voidClear(void)
{
	LCD_voidSendCmnd(0b00000001); // Clear Display
	_delay_ms(2);
}


void LCD_voidWriteSpecialChar(u8 *Copy_Pu8pattern, u8 Copy_u8CharPosition, u8 Copy_u8LineNumber, u8 Copy_u8Position)
{
	/*LCD_voidSendCmnd(Copy_u8CharPosition); // set AC to CGRAM
	
	LCD_voidSendChar(Copy_Pu8pattern);
	
	LCD_voidGoToSpecificPosition(Copy_u8LineNumber, Copy_u8Position)); // set AC to DDRAM
	
	LCD_voidSendChar(Copy_u8CharPosition);*/
}


void LCD_voidShift(u8 Copy_u8ShiftingDirection)
{
	if (Copy_u8ShiftingDirection == LCD_u8_SHIFT_LEFT)
	{
		LCD_voidSendCmnd(0b00011000);
		_delay_ms(10);
	}
	else if (Copy_u8ShiftingDirection == LCD_u8_SHIFT_RIGHT)
	{
		LCD_voidSendCmnd(0b00011100);
		_delay_ms(10);
	}
}

static void Private_voidWriteHalfPort(u8 Copy_u8Value)
{
	u8 Local_u8BitValues;
	Local_u8BitValues = READ_BIT(Copy_u8Value, 0);
	if (0 == Local_u8BitValues)
	{
		DIO_u8SetPinValue(LCD_u8_D4_PORT, LCD_u8_D4_PIN, LCD_u8_PIN_LOW);
	}
	else 
	{
		DIO_u8SetPinValue(LCD_u8_D4_PORT, LCD_u8_D4_PIN, LCD_u8_PIN_HIGH);
	}
	
	Local_u8BitValues = READ_BIT(Copy_u8Value, 1);
	if (0 == Local_u8BitValues)
	{
		DIO_u8SetPinValue(LCD_u8_D5_PORT, LCD_u8_D5_PIN, LCD_u8_PIN_LOW);
	}
	else 
	{
		DIO_u8SetPinValue(LCD_u8_D5_PORT, LCD_u8_D5_PIN, LCD_u8_PIN_HIGH);
	}
	
	Local_u8BitValues = READ_BIT(Copy_u8Value, 2);
	if (0 == Local_u8BitValues)
	{
		DIO_u8SetPinValue(LCD_u8_D6_PORT, LCD_u8_D6_PIN, LCD_u8_PIN_LOW);
	}
	else 
	{
		DIO_u8SetPinValue(LCD_u8_D6_PORT, LCD_u8_D6_PIN, LCD_u8_PIN_HIGH);
	}
	
	Local_u8BitValues = READ_BIT(Copy_u8Value, 3);
	if (0 == Local_u8BitValues)
	{
		DIO_u8SetPinValue(LCD_u8_D7_PORT, LCD_u8_D7_PIN, LCD_u8_PIN_LOW);
	}
	else 
	{
		DIO_u8SetPinValue(LCD_u8_D7_PORT, LCD_u8_D7_PIN, LCD_u8_PIN_HIGH);
	}
}