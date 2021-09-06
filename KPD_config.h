/************************************************************************
 *                                                                      *
 *************************  Date    : 12/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : KPD             *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef KPD_config_K_
#define KPD_config_K_

#define KPD_u8_TYPE


                     /* MACROS FOR KPD ROWS PORTS & PINS CONFIGURATION */
					 
#define KPD_u8_ROWS_NUM                      4

// Output High			 
#define KPD_u8_ROWS_PORT                     KPD_u8_PORTB
#define KPD_u8_ROW0_PIN                      KPD_u8_PIN4
#define KPD_u8_ROW1_PIN                      KPD_u8_PIN5
#define KPD_u8_ROW2_PIN                      KPD_u8_PIN6
#define KPD_u8_ROW3_PIN                      KPD_u8_PIN7

#define KPD_u8_ROWS_PINS                     {KPD_u8_ROW0_PIN, KPD_u8_ROW1_PIN, KPD_u8_ROW2_PIN, KPD_u8_ROW3_PIN}



                     /* MACROS FOR KPD COLUMNS PORTS & PINS CONFIGURATION */
	
#define KPD_u8_COLS_NUM                      4

// Input	
#define KPD_u8_COLS_PORT                     KPD_u8_PORTD
#define KPD_u8_COL0_PIN                      KPD_u8_PIN2
#define KPD_u8_COL1_PIN                      KPD_u8_PIN3
#define KPD_u8_COL2_PIN                      KPD_u8_PIN4
#define KPD_u8_COL3_PIN                      KPD_u8_PIN5

#define KPD_u8_COLS_PINS                     {KPD_u8_COL0_PIN, KPD_u8_COL1_PIN, KPD_u8_COL2_PIN, KPD_u8_COL3_PIN}


#define KPD_KEYS                            {{'1','2','3','+'},  \
		                                     {'4','5','6','-'},  \
		                                     {'7','8','9','*'},  \
		                                     {'%','0','/','='}}
								   
					
#endif /*KPD_config_K_*/