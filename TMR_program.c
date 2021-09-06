/************************************************************************
 *                                                                      *
 *************************  Date    : 21/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : TMR             *******************
 *                                                                      *
 ************************************************************************/
 
 
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_MATH.h"

/* MCAL */
#include "TMR_private.h"
#include "TMR_interface.h"
#include "TMR_config.h"


// GLobal Pointers To Function 
static void(*TMR_pfTimer0OvfCallBack)(void) = NULL_PTR;
static void(*TMR_pfTimer0CtcCallBack)(void) = NULL_PTR;


void TMR_voidTimer0Init(void)
{
	/* TIMER0 INIT */
	
#if TMR_u8_TMR0_MODE == TMR_u8_TMR0_NORMAL_MODE
	// Select Mode = Normal Mode
	CLEAR_BIT(TMR_u8_TMR0_TCCR0_REG, TMR_u8_TMR0_WGM00_BIT);
	CLEAR_BIT(TMR_u8_TMR0_TCCR0_REG, TMR_u8_TMR0_WGM01_BIT);
	
	// Init Timer With Preload Value
    TMR_u8_TMR0_TCNT0_REG = TMR_u8_TMR0_PRELOAD_VALUE;	
	
	// Enable OVF Interrupt
    SET_BIT(TMR_u8_TIMSK_REG, TMR_u8_TMR0_TOIE0_BIT);

#elif TMR_u8_TMR0_MODE == TMR_u8_TMR0_CTC_MODE	
	// Select Mode = CTC Mode
	CLEAR_BIT(TMR_u8_TMR0_TCCR0_REG, TMR_u8_TMR0_WGM00_BIT);
	SET_BIT(TMR_u8_TMR0_TCCR0_REG, TMR_u8_TMR0_WGM01_BIT);
		
	// Enable CTC Interrupt
	SET_BIT(TMR_u8_TIMSK_REG, TMR_u8_TMR0_OCIE0_BIT);
#endif

    // Select Prescaler Value = 8
	CLEAR_BIT(TMR_u8_TMR0_TCCR0_REG, TMR_u8_TMR0_CS00_BIT);
	SET_BIT(TMR_u8_TMR0_TCCR0_REG, TMR_u8_TMR0_CS01_BIT);
	CLEAR_BIT(TMR_u8_TMR0_TCCR0_REG, TMR_u8_TMR0_CS02_BIT);
}


void TMR_voidTimer1Init(void)
{
	// Select Mode = 
	CLEAR_BIT(TMR_u8_TMR1_TCCR1A_REG, 0);
	SET_BIT(TMR_u8_TMR1_TCCR1A_REG, 1);
	SET_BIT(TMR_u8_TMR1_TCCR1B_REG, 3);
	SET_BIT(TMR_u8_TMR1_TCCR1B_REG, 4);
	
	// IC1  20ms
	TMR_u16_TMR1_ICR1_REG = 19999;

	// NON INV
	CLEAR_BIT(TMR_u8_TMR1_TCCR1A_REG, 6);
	SET_BIT(TMR_u8_TMR1_TCCR1A_REG, 7);
	
	// Select Prescaler Value = 8
	CLEAR_BIT(TMR_u8_TMR1_TCCR1B_REG, 0);
	SET_BIT(TMR_u8_TMR1_TCCR1B_REG, 1);
	CLEAR_BIT(TMR_u8_TMR1_TCCR1B_REG, 2);
}


void TMR_voidTimer0Stop(void)
{
	CLEAR_BIT(TMR_u8_TMR0_TCCR0_REG, TMR_u8_TMR0_CS00_BIT);
	CLEAR_BIT(TMR_u8_TMR0_TCCR0_REG, TMR_u8_TMR0_CS01_BIT);
	CLEAR_BIT(TMR_u8_TMR0_TCCR0_REG, TMR_u8_TMR0_CS02_BIT);
}


void TMR_voidTimer1SetCompareMatchValue(u16 Copy_u16OCR1A_Value)
{
	TMR_u16_TMR1_OCR1A_REG = Copy_u16OCR1A_Value;
}


u8   TMR_u8Timer0OVF_SetCallBack(void(*Copy_PfCallBack)(void))
{
	u8 Local_u8ErrorState = PASS;
	if (Copy_PfCallBack != NULL_PTR)
	{
		TMR_pfTimer0OvfCallBack = Copy_PfCallBack;
	}
	else
	{
		Local_u8ErrorState = FAIL;
	}
	return Local_u8ErrorState;
}


u8   TMR_u8Timer0CTC_SetCallBack(void(*Copy_PfCallBack)(void))
{
	u8 Local_u8ErrorState = PASS;
	if (Copy_PfCallBack != NULL_PTR)
	{
		TMR_pfTimer0CtcCallBack = Copy_PfCallBack;
	}
	else
	{
		Local_u8ErrorState = FAIL;
	}
	return Local_u8ErrorState;
}


// ISR Function protoType for TMR0 OVF 
void __vector_11(void) __attribute__ ((signal)); 
void __vector_11(void)
{
	static u16 Local_u16Counter = 0;
	Local_u16Counter++;
	
	if (Local_u16Counter == TMR_u16_TMR0_OVERFLOW_COUNTER)
	{
		// Set Preload Value
        TMR_u8_TMR0_TCNT0_REG = TMR_u8_TMR0_PRELOAD_VALUE;
		
		// Clear Counter
		Local_u16Counter = 0;
		
		// Call Call Back Function
		if(TMR_pfTimer0OvfCallBack != NULL_PTR)
		{
			TMR_pfTimer0OvfCallBack();
		}
		
	}
}


// ISR Function protoType for TMR0 CTC  
void __vector_10(void) __attribute__ ((signal)); 
void __vector_10(void)
{
	static u16 Local_u16Counter = 0;
	Local_u16Counter++;
	
	if (Local_u16Counter == TMR_u16_TMR0_CPMPAREMATCH_COUNTER)
	{
		// Clear Counter
		Local_u16Counter = 0;
		
		// Call Call Back Function
		if(TMR_pfTimer0CtcCallBack != NULL_PTR)
		{
			TMR_pfTimer0CtcCallBack();
		}
		
	}
}