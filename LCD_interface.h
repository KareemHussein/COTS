/************************************************************************
 *                                                                      *
 *************************  Date    : 12/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : LCD             *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef LCD_interface_K_
#define LCD_interface_K_


                        /*************** MACROS FOR LCD PIN ***************/ 
						
/* Macros For LCD Pin state */
#define LCD_u8_PIN_LOW        0
#define LCD_u8_PIN_HIGH       1

/* Macros For LCD Pin Id */
#define LCD_u8_PIN0           0
#define LCD_u8_PIN1           1
#define LCD_u8_PIN2           2
#define LCD_u8_PIN3           3
#define LCD_u8_PIN4           4
#define LCD_u8_PIN5           5
#define LCD_u8_PIN6           6
#define LCD_u8_PIN7           7

  
/* Macros For LCD Port Id */
#define LCD_u8_PORTA               0
#define LCD_u8_PORTB               1
#define LCD_u8_PORTC               2
#define LCD_u8_PORTD               3

/* Macros For LCD Line Id */
#define LCD_u8_LINE_ONE            0
#define LCD_u8_LINE_TWO            1

/* Macros For LCD Shifting Direction */
#define LCD_u8_SHIFT_LEFT          0
#define LCD_u8_SHIFT_RIGHT         1


void LCD_voidInit(void);
void LCD_voidSendCmnd(u8 Copy_u8Cmnd);
void LCD_voidSendChar(u8 Copy_u8Char);
void LCD_voidWriteString(const u8 *Copy_Pu8String);
void LCD_voidWriteNumber(u32 Copy_u32Number);
void LCD_voidGoToSpecificPosition(u8 Copy_u8LineNumber, u8 Copy_u8Position);
void LCD_voidClear(void);	
void LCD_voidWriteSpecialChar(u8 *Copy_Pu8pattern, u8 Copy_u8CharPosition, u8 Copy_u8LineNumber, u8 Copy_u8Position);
void LCD_voidShift(u8 Copy_u8ShifttingDirection);					   
					   
#endif /*LCD_interface_K_*/
