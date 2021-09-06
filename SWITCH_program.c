/************************************************************************
 *                                                                      *
 *************************  Date    : 15/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : SWITCH          *******************
 *                                                                      *
 ************************************************************************/

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "SWITCH_interface.h"


u8 SWITCH_GetState(SWITCH_t *Copy_PstrSwitch, SWITCH_State *Copy_PEnuSwitch)
{
	u8 Local_u8ErorState = PASS;
	u8 Local_u8SwitchState;

	if ((Copy_PstrSwitch != NULL_PTR) && (Copy_PEnuSwitch != NULL_PTR ))
	{
		(void)DIO_u8GetPinValue((Copy_PstrSwitch->SWITCH_u8_PORT),(Copy_PstrSwitch->SWITCH_u8_PIN), &Local_u8SwitchState);

		if ((Copy_PstrSwitch->SWITCH_u8_ConnectionType) == SWITCH_u8_ACTIVE_LOW)
		{
			if (0 == Local_u8SwitchState)
			{
				*Copy_PEnuSwitch = SWITCH_PRESSED;
			}
			else if (1 == Local_u8SwitchState)
			{
				*Copy_PEnuSwitch = SWITCH_NOT_PRESSED;
			}
		}

		else if ((Copy_PstrSwitch->SWITCH_u8_ConnectionType) == SWITCH_u8_ACTIVE_HIGH)
		{
			if (1 == Local_u8SwitchState)
			{
				*Copy_PEnuSwitch = SWITCH_PRESSED;
			}
			else if (0 == Local_u8SwitchState)
			{
				*Copy_PEnuSwitch = SWITCH_NOT_PRESSED;
			}
		}
	}
	else
	{
		Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;
}
