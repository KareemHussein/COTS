/************************************************************************
 *                                                                      *
 *************************  Date    : 07/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : DIO             *******************
 *                                                                      *
 ************************************************************************/


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_MATH.h"

/* MCAL */
#include "DIO_private.h"
#include "DIO_interface.h"
#include "DIO_config.h"

volatile u8 *DIO_APu8DataDirctionRegisters[4]={&DIO_u8_DDRA_REG, &DIO_u8_DDRB_REG, &DIO_u8_DDRC_REG, &DIO_u8_DDRD_REG};
volatile u8 *DIO_APu8PortRegisters[4]={&DIO_u8_PORTA_REG, &DIO_u8_PORTB_REG, &DIO_u8_PORTC_REG, &DIO_u8_PORTD_REG};
volatile u8 *DIO_APu8PinRegisters[4]={&DIO_u8_PINA_REG, &DIO_u8_PINB_REG, &DIO_u8_PINC_REG, &DIO_u8_PIND_REG};



void DIO_voidInit(void)
{
	/*Set Initial Directions FOR Pins */
	DIO_u8_DDRA_REG = CONC(DIO_u8_PA7_INITIAL_DIRECTION,DIO_u8_PA6_INITIAL_DIRECTION,DIO_u8_PA5_INITIAL_DIRECTION,DIO_u8_PA4_INITIAL_DIRECTION,
	                       DIO_u8_PA3_INITIAL_DIRECTION,DIO_u8_PA2_INITIAL_DIRECTION,DIO_u8_PA1_INITIAL_DIRECTION,DIO_u8_PA0_INITIAL_DIRECTION);
						   
	DIO_u8_DDRB_REG = CONC(DIO_u8_PB7_INITIAL_DIRECTION,DIO_u8_PB6_INITIAL_DIRECTION,DIO_u8_PB5_INITIAL_DIRECTION,DIO_u8_PB4_INITIAL_DIRECTION,
	                       DIO_u8_PB3_INITIAL_DIRECTION,DIO_u8_PB2_INITIAL_DIRECTION,DIO_u8_PB1_INITIAL_DIRECTION,DIO_u8_PB0_INITIAL_DIRECTION);
		 				   
    DIO_u8_DDRC_REG = CONC(DIO_u8_PC7_INITIAL_DIRECTION,DIO_u8_PC6_INITIAL_DIRECTION,DIO_u8_PC5_INITIAL_DIRECTION,DIO_u8_PC4_INITIAL_DIRECTION,
	                       DIO_u8_PC3_INITIAL_DIRECTION,DIO_u8_PC2_INITIAL_DIRECTION,DIO_u8_PC1_INITIAL_DIRECTION,DIO_u8_PC0_INITIAL_DIRECTION);
		 				   
    DIO_u8_DDRD_REG = CONC(DIO_u8_PD7_INITIAL_DIRECTION,DIO_u8_PD6_INITIAL_DIRECTION,DIO_u8_PD5_INITIAL_DIRECTION,DIO_u8_PD4_INITIAL_DIRECTION,
	                       DIO_u8_PD3_INITIAL_DIRECTION,DIO_u8_PD2_INITIAL_DIRECTION,DIO_u8_PD1_INITIAL_DIRECTION,DIO_u8_PD0_INITIAL_DIRECTION);
					
					
    /*Set Initial Values FOR Pins */
	DIO_u8_PORTA_REG = CONC(DIO_u8_PA7_INITIAL_VALUE,DIO_u8_PA6_INITIAL_VALUE,DIO_u8_PA5_INITIAL_VALUE,DIO_u8_PA4_INITIAL_VALUE,
	                        DIO_u8_PA3_INITIAL_VALUE,DIO_u8_PA2_INITIAL_VALUE,DIO_u8_PA1_INITIAL_VALUE,DIO_u8_PA0_INITIAL_VALUE);
							
	DIO_u8_PORTB_REG = CONC(DIO_u8_PB7_INITIAL_VALUE,DIO_u8_PB6_INITIAL_VALUE,DIO_u8_PB5_INITIAL_VALUE,DIO_u8_PB4_INITIAL_VALUE,
	                        DIO_u8_PB3_INITIAL_VALUE,DIO_u8_PB2_INITIAL_VALUE,DIO_u8_PB1_INITIAL_VALUE,DIO_u8_PB0_INITIAL_VALUE);
							
	DIO_u8_PORTC_REG = CONC(DIO_u8_PC7_INITIAL_VALUE,DIO_u8_PC6_INITIAL_VALUE,DIO_u8_PC5_INITIAL_VALUE,DIO_u8_PC4_INITIAL_VALUE,
	                        DIO_u8_PC3_INITIAL_VALUE,DIO_u8_PC2_INITIAL_VALUE,DIO_u8_PC1_INITIAL_VALUE,DIO_u8_PC0_INITIAL_VALUE);
							
	DIO_u8_PORTD_REG = CONC(DIO_u8_PD7_INITIAL_VALUE,DIO_u8_PD6_INITIAL_VALUE,DIO_u8_PD5_INITIAL_VALUE,DIO_u8_PD4_INITIAL_VALUE,
	                        DIO_u8_PD3_INITIAL_VALUE,DIO_u8_PD2_INITIAL_VALUE,DIO_u8_PD1_INITIAL_VALUE,DIO_u8_PD0_INITIAL_VALUE);
	
}


/* PIN APIS */

u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirection)
{
	u8 Local_u8ErorState = PASS;
	if ((Copy_u8PortId <= DIO_u8_MAX_PORTS)&&(Copy_u8PinId<=DIO_u8_MAX_PINS)&&((Copy_u8PinDirection == DIO_u8_PIN_OUTPUT)||(Copy_u8PinDirection == DIO_u8_PIN_INPUT)))
	{
		WRITE_BIT(*DIO_APu8DataDirctionRegisters[Copy_u8PortId],Copy_u8PinId,Copy_u8PinDirection);
	}
	else
	{
		Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;
}


u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue)
{
	u8 Local_u8ErorState = PASS;
	if ((Copy_u8PortId <= DIO_u8_MAX_PORTS)&&(Copy_u8PinId<=DIO_u8_MAX_PINS)&&((Copy_u8PinValue == DIO_u8_PIN_HIGH)||(Copy_u8PinValue == DIO_u8_PIN_LOW)))
	{
		WRITE_BIT(*DIO_APu8PortRegisters[Copy_u8PortId],Copy_u8PinId,Copy_u8PinValue);
	}
	else
	{
		Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;
}


u8 DIO_u8TogglePinValue(u8 Copy_u8PortId, u8 Copy_u8PinId)
{
	u8 Local_u8ErorState = PASS;
	if ((Copy_u8PortId <= DIO_u8_MAX_PORTS)&&(Copy_u8PinId<=DIO_u8_MAX_PINS))
	{
		TOGGLE_BIT(*DIO_APu8PortRegisters[Copy_u8PortId],Copy_u8PinId);
	}
	else
	{
		Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;
}


u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_Pu8PinValue)
{
	u8 Local_u8ErorState = PASS;
	u8 Local_u8ReturnedPinValue;
	if ((Copy_u8PortId <= DIO_u8_MAX_PORTS)&&(Copy_u8PinId<=DIO_u8_MAX_PINS)&&(Copy_Pu8PinValue != NULL_PTR))
	{
		Local_u8ReturnedPinValue = READ_BIT(*DIO_APu8PinRegisters[Copy_u8PortId],Copy_u8PinId);
		if (0 == Local_u8ReturnedPinValue)
		{
			*Copy_Pu8PinValue = DIO_u8_PIN_LOW;
		}
		else
		{
			*Copy_Pu8PinValue = DIO_u8_PIN_HIGH;
		}
	}
	else
	{
		Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;
}


u8 DIO_u8SetInputPinResistanceType(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinResistanceType)
{
	u8 Local_u8ErorState = PASS;
	if ((Copy_u8PortId <= DIO_u8_MAX_PORTS)&&(Copy_u8PinId<=DIO_u8_MAX_PINS)&&((Copy_u8PinResistanceType == DIO_u8_PIN_PULLUP)||(Copy_u8PinResistanceType == DIO_u8_PIN_PULLDOWN)))
	{
		WRITE_BIT(*DIO_APu8PortRegisters[Copy_u8PortId],Copy_u8PinId,Copy_u8PinResistanceType);
	}
	else
	{
		Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;
} 



/* PORT APIS */

u8 DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection)
{
	u8 Local_u8ErorState = PASS;
	if ((Copy_u8PortId <= DIO_u8_MAX_PORTS)&&((Copy_u8PortDirection == DIO_u8_PORT_OUTPUT)||(Copy_u8PortDirection == DIO_u8_PORT_INPUT)))
	{
		WRITE_REG(*DIO_APu8DataDirctionRegisters[Copy_u8PortId],Copy_u8PortDirection);
	}
	else
	{
		Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;
}


u8 DIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue)
{
	u8 Local_u8ErorState = PASS;
	if (Copy_u8PortId <= DIO_u8_MAX_PORTS)
	{
		WRITE_REG(*DIO_APu8PortRegisters[Copy_u8PortId],Copy_u8PortValue);
	}
	else
	{
		Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;
}


u8 DIO_u8GetPortValue(u8 Copy_u8PortId, u8 *Copy_Pu8PortValue)
{
	u8 Local_u8ErorState = PASS;
	if ((Copy_u8PortId <= DIO_u8_MAX_PORTS)&&(Copy_Pu8PortValue != NULL_PTR))
	{
		*Copy_Pu8PortValue = READ_REG(*DIO_APu8PinRegisters[Copy_u8PortId]);
	}
	else
	{
		Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;
}


u8 DIO_u8SetInputPortResistanceType(u8 Copy_u8PortId, u8 Copy_u8PortResistanceType)
{
	u8 Local_u8ErorState = PASS;
	if ((Copy_u8PortId <= DIO_u8_MAX_PORTS)&&((Copy_u8PortResistanceType == DIO_u8_PORT_PULLUP)||(Copy_u8PortResistanceType == DIO_u8_PORT_PULLDOWN)))
	{
		WRITE_REG(*DIO_APu8PortRegisters[Copy_u8PortId],Copy_u8PortResistanceType);
	}
	else
	{
		Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;
}
