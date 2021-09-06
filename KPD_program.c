/************************************************************************
 *                                                                      *
 *************************  Date    : 13/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : KPD             *******************
 *                                                                      *
 ************************************************************************/


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPD_private.h"
#include "KPD_interface.h"
#include "KPD_config.h"


u8 KPD_u8GetValue(u8 * Copy_Pu8ReturnedValue)
{
	u8 Local_u8ErrorState = PASS;
	u8 Local_u8PinValue,Local_u8PinFlag = 0 ;
	
	static u8 Local_Au8RowsPins[KPD_u8_ROWS_NUM] = KPD_u8_ROWS_PINS;
	static u8 Local_Au8ColoumnsPins[KPD_u8_COLS_NUM] = KPD_u8_COLS_PINS;
	static u8 Local_Au8KPD_Chars[KPD_u8_ROWS_NUM][KPD_u8_COLS_NUM] = KPD_KEYS;

	if(Copy_Pu8ReturnedValue != NULL_PTR)
	{
		*Copy_Pu8ReturnedValue = KPD_u8_NOT_PRESSED;

		for (u8 Local_u8RowsCounter = 0; Local_u8RowsCounter < KPD_u8_ROWS_NUM; ++Local_u8RowsCounter)
		{
			// Activate Each Row
			DIO_u8SetPinValue(KPD_u8_ROWS_PORT, Local_Au8RowsPins[Local_u8RowsCounter], DIO_u8_PIN_LOW);

			// Loop TO Check Coloumns Value
			for (u8 Local_u8ColsCounter = 0; Local_u8ColsCounter < KPD_u8_COLS_NUM; ++Local_u8ColsCounter)
			{
				// Check If Coloumn In Low State
				DIO_u8GetPinValue(KPD_u8_COLS_PORT, Local_Au8ColoumnsPins[Local_u8ColsCounter], &Local_u8PinValue);
				if (Local_u8PinValue == DIO_u8_PIN_LOW)
				{
					*Copy_Pu8ReturnedValue = Local_Au8KPD_Chars[Local_u8RowsCounter][Local_u8ColsCounter];
					while(Local_u8PinValue == DIO_u8_PIN_LOW)
					{
						DIO_u8GetPinValue(KPD_u8_COLS_PORT, Local_Au8ColoumnsPins[Local_u8ColsCounter], &Local_u8PinValue);
					}
					Local_u8PinFlag = 1;
					break;
				}
			}
			// Deactivate Current Row
			DIO_u8SetPinValue(KPD_u8_ROWS_PORT, Local_Au8RowsPins[Local_u8RowsCounter], DIO_u8_PIN_HIGH);
			if (Local_u8PinFlag == 1)
			{
				break;
			}
		}		
	}
	else
	{
		Local_u8ErrorState = FAIL;
	}
	return Local_u8ErrorState;
}
