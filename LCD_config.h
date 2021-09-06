/************************************************************************
 *                                                                      *
 *************************  Date    : 12/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : LCD             *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef LCD_config_K_
#define LCD_config_K_

                     /* MACROS FOR LCD CONTROL PORTS & PINS CONFIGURATION */
					 
/* Macros For Rs configuration */					 
#define LCD_u8_RS_PORT           LCD_u8_PORTA
#define LCD_u8_RS_PIN            LCD_u8_PIN1 

/* Macros For Rw configuration */
#define LCD_u8_RW_PORT           LCD_u8_PORTA
#define LCD_u8_RW_PIN            LCD_u8_PIN7

/* Macros For En configuration */
#define LCD_u8_EN_PORT           LCD_u8_PORTA
#define LCD_u8_EN_PIN            LCD_u8_PIN2



                     /* MACROS FOR LCD DATA PORT & PINS CONFIGURATION */

	 
/* Options FOR LCD Mode:
1- LCD_u8_8_BIT_MODE
2- LCD_u8_4_BIT_MODE */

#define LCD_u8_MODE              LCD_u8_4_BIT_MODE
#define LCD_u8_DATA_PORT         LCD_u8_PORTA
			
			
/* 4 Bit Mode Pins Configurtion */

#define LCD_u8_D4_PIN            LCD_u8_PIN3
#define LCD_u8_D4_PORT           LCD_u8_PORTA

#define LCD_u8_D5_PIN            LCD_u8_PIN4
#define LCD_u8_D5_PORT           LCD_u8_PORTA

#define LCD_u8_D6_PIN            LCD_u8_PIN5
#define LCD_u8_D6_PORT           LCD_u8_PORTA

#define LCD_u8_D7_PIN            LCD_u8_PIN6
#define LCD_u8_D7_PORT           LCD_u8_PORTA

				  
#endif /*LCD_config_K_*/