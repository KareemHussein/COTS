/************************************************************************
 *                                                                      *
 *************************  Date    : 19/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : ADC             *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef ADC_private_K_
#define ADC_private_K_ 
 
 
 
                        /* ADC REGISTERS */
						
// ADC Multiplexer Selection Register
#define ADC_u8_ADMUX_REG             (*(volatile u8*)0x27)
#define ADC_u8_MUX0_BIT              0
#define ADC_u8_MUX1_BIT              1
#define ADC_u8_MUX2_BIT              2
#define ADC_u8_MUX3_BIT              3
#define ADC_u8_MUX4_BIT              4
#define ADC_u8_ADLAR_BIT             5
#define ADC_u8_REFS0_BIT             6
#define ADC_u8_REFS1_BIT             7

// ADC Control and Status Register A 
#define ADC_u8_ADCSRA_REG           (*(volatile u8*)0x26)
#define ADC_u8_ADPS0_BIT            0
#define ADC_u8_ADPS1_BIT            1
#define ADC_u8_ADPS2_BIT            2
#define ADC_u8_ADIE_BIT             3
#define ADC_u8_ADIF_BIT             4
#define ADC_u8_ADATE_BIT            5
#define ADC_u8_ADSC_BIT             6
#define ADC_u8_ADEN_BIT             7

// The ADC Data Register – ADCL and ADCH
#define ADC_u8_ADCH_REG           (*(volatile u8*)0x25)
#define ADC_u8_ADCL_REG           (*(volatile u8*)0x24)
#define ADC_u16_ADC_REG           (*(volatile u16*)0x24)

// Special FunctionIO Register – SFIOR
#define ADC_u8_SFIOR_REG          (*(volatile u8*)0x50)
#define ADC_u8_ADTS0_BIT          5
#define ADC_u8_ADTS1_BIT          6
#define ADC_u8_ADTS2_BIT          7
                    
#endif /*ADC_private_K_*/
	
