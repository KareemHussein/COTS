/************************************************************************
 *                                                                      *
 ************************** Created: 10/1/2021 **************************
 ************************ Author: Kareem Hussein ************************
 ***************************** Version: 1.0 *****************************
 *************************** Brief: SSD_module **************************
 ************** Description: SSD definitions implementation *************
 *                                                                      *
 ************************************************************************/
 
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_MATH.h"

/* MCAL */
#include "DIO_INTERFACE.h"

/* HAL */
#include "SSD_private.h"
#include "SSD_interface.h"
#include "SSD_config.h"


static const u8 SSD_Au8Numbers[10]={SSD_u8_ZERO,SSD_u8_ONE,SSD_u8_TWO,SSD_u8_THREE,SSD_u8_FOUR,
                                    SSD_u8_FIVE,SSD_u8_SEX,SSD_u8_SEVEN,SSD_u8_EIGHT,SSD_u8_NINE};


void SSD_voidOn()
{
#if SSD_u8_TYPE == SSD_u8_COM_CATHODE
	(void)DIO_u8SetPinValue(SSD_u8_COM_PORT, SSD_u8_COM_PIN, DIO_u8_PIN_LOW);

#elif SSD_u8_TYPE == SSD_u8_COM_ANNODE	
	(void)DIO_u8SetPinValue(SSD_u8_COM_PORT, SSD_u8_COM_PIN, DIO_u8_PIN_HIGH);
#endif	
}


void SSD_voidOff()
{
#if SSD_u8_TYPE == SSD_u8_COM_CATHODE
	(void)DIO_u8SetPinValue(SSD_u8_COM_PORT, SSD_u8_COM_PIN, DIO_u8_PIN_HIGH);

#elif SSD_u8_TYPE == SSD_u8_COM_ANNODE	
	(void)DIO_u8SetPinValue(SSD_u8_COM_PORT, SSD_u8_COM_PIN, DIO_u8_PIN_LOW);
#endif	
}


void SSD_voidStNumber(u8 Copy_u8DesirdNumber)
{
#if SSD_u8_TYPE == SSD_u8_COM_CATHODE	
(void)DIO_u8SetPortValue(SSD_u8_PORT,SSD_Au8Numbers[Copy_u8DesirdNumber]);
#elif SSD_u8_TYPE == SSD_u8_COM_ANNODE
(void)DIO_u8SetPortValue(SSD_u8_PORT,~SSD_Au8Numbers[Copy_u8DesirdNumber]);
#endif
}
