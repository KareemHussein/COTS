/************************************************************************
 *                                                                      *
 ************************** Created: 10/1/2021 **************************
 ************************ Author: Kareem Hussein ************************
 ***************************** Version: 1.0 *****************************
 *************************** Brief: SSD_module **************************
 *********** Description: macros definitions and fun prototype **********
 *                                                                      *
 ************************************************************************/
 
#ifndef SSD_INTERFACE_K_
#define SSD_INTERFACE_K_


                         /*************** MACROS FOR SSD PORT ***************/

/* Macros For SSD Port Id */
#define SSD_u8_PORTA               0
#define SSD_u8_PORTB               1
#define SSD_u8_PORTC               2
#define SSD_u8_PORTD               3

/* Macros For SSD Pin Id */
#define SSD_u8_PIN0           0
#define SSD_u8_PIN1           1
#define SSD_u8_PIN2           2
#define SSD_u8_PIN3           3
#define SSD_u8_PIN4           4
#define SSD_u8_PIN5           5
#define SSD_u8_PIN6           6
#define SSD_u8_PIN7           7

                         /*************** APIS PROTO TYPES ***************/
						 
void SSD_voidOn(void);
void SSD_voidOff(void);
void SSD_voidStNumber(u8 Copy_u8DesirdNumber);

#endif /*SSD_INTERFACE_K_*/
