/************************************************************************
 *                                                                      *
 *************************  Date    : 19/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : ADC             *******************
 *                                                                      *
 ************************************************************************/


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_MATH.h"

/* MCAL */
#include "ADC_private.h"
#include "ADC_interface.h"
#include "ADC_config.h"


// Busy Flag
static u8 ADC_u8BusyFlag = 0;

// GLobal Pointer
static void(*ADC_pfNotification)(u16) = NULL_PTR;


void ADC_voidInit(void)
{
	// Select Vref = AVCC
	SET_BIT(ADC_u8_ADMUX_REG, ADC_u8_REFS0_BIT);
	CLEAR_BIT(ADC_u8_ADMUX_REG, ADC_u8_REFS1_BIT);

	CLEAR_BIT(ADC_u8_ADMUX_REG, ADC_u8_ADLAR_BIT); // Select Right Adjustment

	
	// Single Conversation Mode
	CLEAR_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADATE_BIT);

	// Prescaler 128 For 16MHZ
	CLEAR_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADPS0_BIT);
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADPS1_BIT);
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADPS2_BIT);

	// ADC Enable
	SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADEN_BIT);
}


u8 ADC_u8GetDigitalValueSynchronous(u8 Copy_u8ChannelNum, u16 *Copy_pu16DigitalValue)
{
	u8 Local_u8ErrorState = PASS;
	u32 Local_u32TimeOutCounter = 0;
	
	if ((Copy_u8ChannelNum < 32) && (Copy_pu16DigitalValue != NULL_PTR))
	{
		//Clear ADMUX Channel Bits
		ADC_u8_ADMUX_REG &= 0b11100000;

		// Select Channel Number
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNum;

		// Start Conversition
		SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADSC_BIT);

		// Wait For The Flag Of ADC
		while ((READ_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADIF_BIT) == 0) && (Local_u32TimeOutCounter < ADC_u32_TIME_OUT_VALUE))
		{
			Local_u32TimeOutCounter++;
		}

		if (READ_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADIF_BIT) != 0) // Flag = 1
		{
			// Clear Flag 
		    SET_BIT(ADC_u8_ADCSRA_REG, ADC_u8_ADIF_BIT);

		   // Read Digital Value
		   *Copy_pu16DigitalValue = ADC_u16_ADC_REG;
		}
		else
	    {
		 Local_u8ErrorState = FAIL;
	    }
	} 

	else
	{
		Local_u8ErrorState = FAIL;
	}
	return Local_u8ErrorState;	
}


u8 ADC_u8GetDigitalValueAsynchronous(u8 Copy_u8ChannelNum, void(*Copy_pfNotification)(u16))
{
	u8 Local_u8ErrorState = PASS;
	if((Copy_u8ChannelNum < 32) && (Copy_pfNotification != NULL_PTR) && (ADC_u8BusyFlag == 0))
	{
		// Set Busy Flag 
		ADC_u8BusyFlag = 1;
		
		// Update Global Pointer
		ADC_pfNotification = Copy_pfNotification;
		
		// Clear ADMUX Channel Bits
		ADC_u8_ADMUX_REG &= 0b11100000;
		
		// Select Channel Number
		ADC_u8_ADMUX_REG |= Copy_u8ChannelNum;
		
		// Enable Interrupt Of ADC
		SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIE_BIT);
		
		// Start Conversion
		SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADSC_BIT);
	}
	else
	{
		Local_u8ErrorState = FAIL;
	}
	return Local_u8ErrorState;
}


// ISR Function protoType for ADC 
void __vector_16(void) __attribute__ ((signal)); 
void __vector_16(void)
{
	if (ADC_pfNotification != NULL_PTR)
	{
		// Disable Interrupt
		CLEAR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIE_BIT);
		
		// Call Notification Function
		ADC_pfNotification(ADC_u16_ADC_REG);
		
		// Clear Busy Flag
		ADC_u8BusyFlag = 0;
	}
}