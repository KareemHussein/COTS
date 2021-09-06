/************************************************************************
 *                                                                      *
 ************************** Created: 10/1/2021 **************************
 ************************ Author: Kareem Hussein ************************
 ***************************** Version: 1.0 *****************************
 ******************** Brief: SSD_configuration_module *******************
 ********************** Description: configure SSD **********************
 *                                                                      *
 ************************************************************************/
 
#ifndef SSD_CONFIG_K_
#define SSD_CONFIG_K_

/* Macros For Common configuration */
#define SSD_u8_COM_PORT       SSD_u8_PORTC
#define SSD_u8_COM_PIN        SSD_u8_PIN0

                    /* MACROS FOR SSD PORT & PINS CONFIGURATION */

	 
/* Options FOR SSD Type:
1- SSD_u8_COM_CATHODE
2- SSD_u8_COM_ANNODE */

#define SSD_u8_TYPE           SSD_u8_COM_CATHODE
#define SSD_u8_PORT           SSD_u8_PORTB





#endif /*SSD_CONFIG_K_*/
