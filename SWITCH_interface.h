/************************************************************************
 *                                                                      *
 *************************  Date    : 15/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : SWITCH          *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef SWITCH_INTERFACE_K_
#define SWITCH_INTERFACE_K_


typedef struct
{
	u8 SWITCH_u8_PORT;
	u8 SWITCH_u8_PIN;
	u8 SWITCH_u8_ConnectionType;
}SWITCH_t;

/* enum For Switch state */
typedef enum
{
	SWITCH_PRESSED,
	SWITCH_NOT_PRESSED
}SWITCH_State;

/* Macros For Switch Connection Type */
#define SWITCH_u8_ACTIVE_HIGH     1
#define SWITCH_u8_ACTIVE_LOW      0


                        /*************** MACROS FOR SWITCH PIN ***************/


/* Macros For Switch Pin Id */
#define SWITCH_u8_PIN0           0                  
#define SWITCH_u8_PIN1           1                  
#define SWITCH_u8_PIN2           2                  
#define SWITCH_u8_PIN3           3                  
#define SWITCH_u8_PIN4           4                  
#define SWITCH_u8_PIN5           5                  
#define SWITCH_u8_PIN6           6                  
#define SWITCH_u8_PIN7           7                  
                                                    
                                                    
                       /*************** MACROS FOR SWITCH PORT ***************/
					   
/* Macros For Switch Port Id */
#define SWITCH_u8_PORTA               0
#define SWITCH_u8_PORTB               1
#define SWITCH_u8_PORTC               2
#define SWITCH_u8_PORTD               3


                       /*************** APIS PROTO TYPES ***************/

					   
u8 SWITCH_GetState(SWITCH_t *Copy_PstrSwitch, SWITCH_State *Copy_PEnuSwitch);

#endif /*SWITCH_INTERFACE_K*/
