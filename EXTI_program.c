/************************************************************************
 *                                                                      *
 *************************  Date    : 17/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : EXTI            *******************
 *                                                                      *
 ************************************************************************/


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_MATH.h"

/* MCAL */
#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_config.h"


// Global Pointers To Functions
static void (*EXTI_AptrToFunction[3])(void) = {NULL_PTR, NULL_PTR, NULL_PTR};

u8 EXTI_u8Enable(EXTI_source Copy_u8InterruptSource, EXTI_trigger Copy_u8InterruptTriggerEdge)
{
	u8 Local_u8ErorState = PASS;
	switch(Copy_u8InterruptSource)
	{
	case EXTI_u8_INT0 :
	{
		if (Copy_u8InterruptTriggerEdge == LOW_LEVEL)
		{
			CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC00_BIT);
			CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC01_BIT);
		}
		else if (Copy_u8InterruptTriggerEdge == ANY_LOGICAL_CHANGE)
		{
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC00_BIT);
			CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC01_BIT);
		}
		else if (Copy_u8InterruptTriggerEdge == FALLING_EDGE)
		{
			CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC00_BIT);
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC01_BIT);
		}
		else if (Copy_u8InterruptTriggerEdge == RISING_EDGE)
		{
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC00_BIT);
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC01_BIT);
		}
		else
		{
			Local_u8ErorState = FAIL;
		}


		SET_BIT(EXTI_u8_GICR_REG,EXTI_u8_INT0_BIT);
	}break;

	case EXTI_u8_INT1 :
	{
		if (Copy_u8InterruptTriggerEdge == LOW_LEVEL)
		{
			CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC10_BIT);
			CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC11_BIT);
		}
		else if (Copy_u8InterruptTriggerEdge == ANY_LOGICAL_CHANGE)
		{
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC10_BIT);
			CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC11_BIT);
		}
		else if (Copy_u8InterruptTriggerEdge == FALLING_EDGE)
		{
			CLEAR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC10_BIT);
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC11_BIT);
		}
		else if (Copy_u8InterruptTriggerEdge == RISING_EDGE)
		{
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC10_BIT);
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_ISC11_BIT);
		}
		else
		{
			Local_u8ErorState = FAIL;
		}

		SET_BIT(EXTI_u8_GICR_REG,EXTI_u8_INT1_BIT);
	}break;

	case EXTI_u8_INT2 :
	{
		if (Copy_u8InterruptTriggerEdge == FALLING_EDGE)
		{
			CLEAR_BIT(EXTI_u8_MCUCSR_REG,EXTI_u8_ISC2_BIT);
		}
		else if (Copy_u8InterruptTriggerEdge == RISING_EDGE)
		{
			SET_BIT(EXTI_u8_MCUCSR_REG,EXTI_u8_ISC2_BIT);
		}
		else
		{
			Local_u8ErorState = FAIL;
		}

		SET_BIT(EXTI_u8_GICR_REG,EXTI_u8_INT2_BIT);
	}break;

	default :
	{
		Local_u8ErorState = FAIL;
	}break;
	}
	return Local_u8ErorState;
}


u8 EXTI_u8Disable(EXTI_source Copy_u8InterruptSource)
{
	u8 Local_u8ErorState = PASS;
	switch(Copy_u8InterruptSource)
	{
	case EXTI_u8_INT0 :
	{
		CLEAR_BIT(EXTI_u8_GICR_REG,EXTI_u8_INT0_BIT);
	}break;

	case EXTI_u8_INT1 :
	{
		CLEAR_BIT(EXTI_u8_GICR_REG,EXTI_u8_INT1_BIT);
	}break;

	case EXTI_u8_INT2 :
	{
		CLEAR_BIT(EXTI_u8_GICR_REG,EXTI_u8_INT2_BIT);
	}break;

	default :
	{
		Local_u8ErorState = FAIL;
	}break;
	}
	return Local_u8ErorState;
}


u8 EXTI_u8SetCallBack(EXTI_source Copy_u8InterruptSource, void (*Copy_PfCallBack)(void))
{
	u8 Local_u8ErorState = PASS;
	if ((Copy_u8InterruptSource <= EXTI_u8_INT2) && (Copy_PfCallBack != NULL_PTR))
	{
		EXTI_AptrToFunction[Copy_u8InterruptSource] = Copy_PfCallBack;
	}
	else
	{
			Local_u8ErorState = FAIL;
	}
	return Local_u8ErorState;	
}


// ISR Function protoType for EXTI0
void __vector_1(void) __attribute__ ((signal)); 
void __vector_1(void)
{
	if (EXTI_AptrToFunction[EXTI_u8_INT0] != NULL_PTR)
	{
		EXTI_AptrToFunction[EXTI_u8_INT0]();
	}
}


// ISR Function protoType for EXTI1
void __vector_2(void) __attribute__ ((signal)); 
void __vector_2(void)
{
	if (EXTI_AptrToFunction[EXTI_u8_INT1] != NULL_PTR)
	{                                  
		EXTI_AptrToFunction[EXTI_u8_INT1]();
	}
}


// ISR Function protoType for EXTI2
void __vector_3(void) __attribute__ ((signal)); 
void __vector_3(void)
{
	if (EXTI_AptrToFunction[EXTI_u8_INT2] != NULL_PTR)
	{                                  
		EXTI_AptrToFunction[EXTI_u8_INT2]();
	}
}