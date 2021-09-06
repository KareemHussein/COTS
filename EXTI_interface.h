/************************************************************************
 *                                                                      *
 *************************  Date    : 17/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : EXTI            *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef EXTI_interface_K_
#define EXTI_interface_K_

/* Enum For Interrupt Source */
typedef enum {
	EXTI_u8_INT0, // PORT_D PIN_2
	EXTI_u8_INT1, // PORT_D PIN_3
	EXTI_u8_INT2  // PORT_B PIN_2
}EXTI_source;

/* Enum For Interrupt Trigger Edge */
typedef enum {
	LOW_LEVEL,
	ANY_LOGICAL_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}EXTI_trigger;


                 
				        /*************** APIS PROTOTYPES ***************/
						
u8 EXTI_u8Enable(EXTI_source Copy_u8InterruptSource, EXTI_trigger Copy_u8InterruptTriggerEdge);
u8 EXTI_u8Disable(EXTI_source Copy_u8InterruptSource);
u8 EXTI_u8SetCallBack(EXTI_source Copy_u8InterruptSource, void (*Copy_PfCallBack)(void));

#endif /*EXTI_interface_K_*/