/************************************************************************
 *                                                                      *
 *************************  Date    : 07/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : DIO             *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef DIO_private_K_
#define DIO_private_K_


                   /***************** DIO REGISTERS *****************/
				   
/* DATA DIRCTION REGISTERS */

#define DIO_u8_DDRA_REG    (*(volatile u8*)0x3A)
#define DIO_u8_DDRB_REG    (*(volatile u8*)0x37)
#define DIO_u8_DDRC_REG    (*(volatile u8*)0x34)
#define DIO_u8_DDRD_REG    (*(volatile u8*)0x31)


/* PORT REGISTERS */

#define DIO_u8_PORTA_REG   (*(volatile u8*)0x3B)
#define DIO_u8_PORTB_REG   (*(volatile u8*)0x38)
#define DIO_u8_PORTC_REG   (*(volatile u8*)0x35)
#define DIO_u8_PORTD_REG   (*(volatile u8*)0x32)


/* PIN REGISTERS */

#define DIO_u8_PINA_REG    (*(volatile u8*)0x39)
#define DIO_u8_PINB_REG    (*(volatile u8*)0x36)
#define DIO_u8_PINC_REG    (*(volatile u8*)0x33)
#define DIO_u8_PIND_REG    (*(volatile u8*)0x30)	

/* Macros For Pins Initial Directions */

#define DIO_u8_INITIAL_INPUT      0
#define DIO_u8_INITIAL_OUTPUT     1

/* Macros For Pins Initial Values */

#define DIO_u8_INITIAL_INPUT_FLOATING      0
#define DIO_u8_INITIAL_INPUT_PULLUP        1
#define DIO_u8_INITIAL_OUTPUT_LOW          0	
#define DIO_u8_INITIAL_OUTPUT_HIGH	   1   
   
/* Macros For Concatenation Functions */

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)        CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)   0b##b7##b6##b5##b4##b3##b2##b1##b0

   
#endif /*DIO_private_K_*/