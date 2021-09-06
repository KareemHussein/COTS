/************************************************************************
 *                                                                      *
 ************************** Created: 10/1/2021 **************************
 ************************ Author: Kareem Hussein ************************
 ***************************** Version: 1.0 *****************************
 *************************** Brief: LED_module **************************
 *********** Description: macros definitions and fun prototype **********
 *                                                                      *
 ************************************************************************/
 
#ifndef LED_INTERFACE_K_
#define LED_INTERFACE_K_


typedef struct
{
	u8 LED_u8_PORT;
	u8 LED_u8_PIN;
	u8 LED_u8_ConnectionType;
}LED_t;

/* Macros For Led Connection Type */
#define LED_u8_ACTIVE_HIGH     1
#define LED_u8_ACTIVE_LOW      0



                        /*************** MACROS FOR LED PIN ***************/
						
/* Macros For Led state */
#define LED_u8_OFF            0
#define LED_u8_ON             1

/* Macros For Led Pin Id */
#define LED_u8_PIN0           0
#define LED_u8_PIN1           1
#define LED_u8_PIN2           2
#define LED_u8_PIN3           3
#define LED_u8_PIN4           4
#define LED_u8_PIN5           5
#define LED_u8_PIN6           6
#define LED_u8_PIN7           7


                       /*************** MACROS FOR LED PORT ***************/
					   
/* Macros For Led Port Id */
#define LED_u8_PORTA               0
#define LED_u8_PORTB               1
#define LED_u8_PORTC               2
#define LED_u8_PORTD               3


                       /*************** APIS PROTO TYPES ***************/
					   
u8 LED_u8On(LED_t *Copy_PstrLED);
u8 LED_u8Off(LED_t *Copy_PstrLED);
u8 LED_u8Toggle(LED_t *Copy_PstrLED);

#endif /*LED_INTERFACE_K*/
