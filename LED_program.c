/************************************************************************
 *                                                                      *
 ************************** Created: 10/1/2021 **************************
 ************************ Author: Kareem Hussein ************************
 ***************************** Version: 1.0 *****************************
 *************************** Brief: LED_module **************************
 ************** Description: LED definitions implementation *************
 *                                                                      *
 ************************************************************************/

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LED_interface.h"

u8 LED_u8On(LED_t *Copy_PstrLED)
{
	u8 Local_u8ErorState = PASS;
	if (Copy_PstrLED != NULL_PTR)
	{
		if (Copy_PstrLED->LED_u8_ConnectionType == LED_u8_ACTIVE_HIGH)
		{
			(void)DIO_u8SetPinValue((Copy_PstrLED->LED_u8_PORT), (Copy_PstrLED->LED_u8_PIN), LED_u8_ON);
		}
		else if (Copy_PstrLED->LED_u8_ConnectionType == LED_u8_ACTIVE_LOW)
		{
			(void)DIO_u8SetPinValue((Copy_PstrLED->LED_u8_PORT), (Copy_PstrLED->LED_u8_PIN), LED_u8_OFF);
		}
	}
	else
	{
		Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;
}


u8 LED_u8Off(LED_t *Copy_PstrLED)
{
	u8 Local_u8ErorState = PASS;
	if (Copy_PstrLED != NULL_PTR)
	{
		if (Copy_PstrLED->LED_u8_ConnectionType == LED_u8_ACTIVE_HIGH)
		{
			(void)DIO_u8SetPinValue((Copy_PstrLED->LED_u8_PORT), (Copy_PstrLED->LED_u8_PIN), LED_u8_OFF);
		}
		else if (Copy_PstrLED->LED_u8_ConnectionType == LED_u8_ACTIVE_LOW)
		{
			(void)DIO_u8SetPinValue((Copy_PstrLED->LED_u8_PORT), (Copy_PstrLED->LED_u8_PIN), LED_u8_ON);
		}
	}
	else
	{
		Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;
}


u8 LED_u8Toggle(LED_t *Copy_PstrLED)
{
	u8 Local_u8ErorState = PASS;
	if (Copy_PstrLED != NULL_PTR)
	{
		(void)DIO_u8TogglePinValue((Copy_PstrLED->LED_u8_PORT), (Copy_PstrLED->LED_u8_PIN));
	}
	else
	{
		Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;
}
