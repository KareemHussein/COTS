/************************************************************************
 *                                                                      *
 *************************  Date    : 19/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : ADC             *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef ADC_interface_K_
#define ADC_interface_K_

#define ADC_u8_CHANNEL_0        0
#define ADC_u8_CHANNEL_1        1
#define ADC_u8_CHANNEL_2        2
#define ADC_u8_CHANNEL_3        3
#define ADC_u8_CHANNEL_4        4
#define ADC_u8_CHANNEL_5        5
#define ADC_u8_CHANNEL_6        6
#define ADC_u8_CHANNEL_7        7

                 
				        /*************** APIS PROTOTYPES ***************/
						
void ADC_voidInit(void);
u8 ADC_u8GetDigitalValueSynchronous(u8 Copy_u8ChannelNum, u16 *Copy_pu16DigitalValue);
u8 ADC_u8GetDigitalValueAsynchronous(u8 Copy_u8ChannelNum, void(*Copy_pfNotification)(u16));

#endif /*ADC_interface_K_*/
