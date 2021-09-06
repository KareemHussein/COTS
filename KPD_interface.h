/************************************************************************
 *                                                                      *
 *************************  Date    : 13/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : KPD             *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef KPD_interface_K_
#define KPD_interface_K_


                        /*************** MACROS FOR KPD PORTS & PINS ***************/ 
						
/* Macros For KPD Pin Id */
#define KPD_u8_PIN0                0
#define KPD_u8_PIN1                1
#define KPD_u8_PIN2                2
#define KPD_u8_PIN3                3
#define KPD_u8_PIN4                4
#define KPD_u8_PIN5                5
#define KPD_u8_PIN6                6
#define KPD_u8_PIN7                7

 
/* Macros For KPD Port Id */
#define KPD_u8_PORTA               0
#define KPD_u8_PORTB               1
#define KPD_u8_PORTC               2
#define KPD_u8_PORTD               3
			

#define KPD_u8_NOT_PRESSED         0xff			
	
	
u8 KPD_u8GetValue(u8 * Copy_Pu8ReturnedValue);				   
					   
#endif /*KPD_interface_K_*/
