/************************************************************************
 *                                                                      *
 *************************  Date    : 07/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : DIO             *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef DIO_interface_K_
#define DIO_interface_K_


                        /*************** MACROS FOR PIN ***************/
					   
/* Macros For Pin Direction */
#define DIO_u8_PIN_INPUT      0
#define DIO_u8_PIN_OUTPUT     1

/* Macros For Pin state */
#define DIO_u8_PIN_LOW        0
#define DIO_u8_PIN_HIGH       1

/* Macros For Pin Id */
#define DIO_u8_PIN0           0
#define DIO_u8_PIN1           1
#define DIO_u8_PIN2           2
#define DIO_u8_PIN3           3
#define DIO_u8_PIN4           4
#define DIO_u8_PIN5           5
#define DIO_u8_PIN6           6
#define DIO_u8_PIN7           7

/* Macros For Maximum Number Of Pins */
#define DIO_u8_MAX_PINS       7

/* Macros For Input Pin Resistance Type */
#define DIO_u8_PIN_PULLDOWN   0
#define DIO_u8_PIN_PULLUP     1


                        /*************** MACROS FOR PORT ***************/

/* Macros For Port Direction */
#define DIO_u8_PORT_INPUT          0x00
#define DIO_u8_PORT_OUTPUT         0xff

/* Macros For Port state */
#define DIO_u8_PORT_LOW            0x00
#define DIO_u8_PORT_HIGH           0xff

/* Macros For Port Id */
#define DIO_u8_PORTA               0
#define DIO_u8_PORTB               1
#define DIO_u8_PORTC               2
#define DIO_u8_PORTD               3

/* Macros For Maximum Number Of Ports */
#define DIO_u8_MAX_PORTS           3

/* Macros For Input PORT Resistance Type */
#define DIO_u8_PORT_PULLDOWN       0x00
#define DIO_u8_PORT_PULLUP         0xff



                       /*************** APIS PROTO TYPES ***************/

void DIO_voidInit(void);

/* Pin Apis */					   
u8 DIO_u8SetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDirection);

u8 DIO_u8SetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);

u8 DIO_u8TogglePinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);

u8 DIO_u8GetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 *Copy_Pu8PinValue);

u8 DIO_u8SetInputPinResistanceType(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinResistanceType);

/* Port Apis */
u8 DIO_u8SetPortDirection(u8 Copy_u8PortId, u8 Copy_u8PortDirection);     

u8 DIO_u8SetPortValue(u8 Copy_u8PortId, u8 Copy_u8PortValue);

u8 DIO_u8GetPortValue(u8 Copy_u8PortId, u8 *Copy_Pu8PortValue);

u8 DIO_u8SetInputPortResistanceType(u8 Copy_u8PortId, u8 Copy_u8PortResistanceType);
					   
					   
#endif /*DIO_interface_K*/