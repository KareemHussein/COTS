/************************************************************************
 *                                                                      *
 *************************  Date    : 21/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : TMR             *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef TMR_config_K_
#define TMR_config_K_

                      
					  
					  /* MACROS FOR TIMERS CONFIGURATIONS */
 
/* TIMER0 CONFIGURATION */ 

/* Options FOR TIMER0 Mode:
1- TMR_u8_TMR0_NORMAL_MODE
2- TMR_u8_TMR0_CTC_MODE */

#define TMR_u8_TMR0_MODE           TMR_u8_TMR0_CTC_MODE

// Timer0 OVF Configuration	
#define TMR_u8_TMR0_PRELOAD_VALUE                  192
#define TMR_u16_TMR0_OVERFLOW_COUNTER              3907

// Timer0 CTC Configuration	
#define TMR_u16_TMR0_CPMPAREMATCH_COUNTER          10000        

#endif /*TMR_config_K_*/