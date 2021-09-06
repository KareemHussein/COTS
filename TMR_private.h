/************************************************************************
 *                                                                      *
 *************************  Date    : 21/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : TMR             *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef TMR_private_K_
#define TMR_private_K_ 


                       /* MACROS FOR TIMERS CONFIGURATIONS */

/* TIMER0 */
#define TMR_u8_TMR0_NORMAL_MODE       0
#define TMR_u8_TMR0_CTC_MODE          1


                       /* TIMERS REGISTERS */
	
// Timer/Counter Interrupt Flag Register (TIFR)
#define TMR_u8_TIFR_REG          (*(volatile u8*)0x58)	

// Timer Counter Interrupt Mask Register (TIMSK)
#define TMR_u8_TIMSK_REG         (*(volatile u8*)0x59)
#define TMR_u8_TMR0_TOIE0_BIT         0
#define TMR_u8_TMR0_OCIE0_BIT         1
#define TMR_u8_TMR1_TOIE1_BIT         2
#define TMR_u8_TMR1_OCIE1B_BIT        3
#define TMR_u8_TMR1_OCIE1A_BIT        4
#define TMR_u8_TMR1_TICIE1_BIT        5
#define TMR_u8_TMR2_TOIE2_BIT         6
#define TMR_u8_TMR2_OCIE2_BIT         7
                         

/* TIMER0 */
					   
// Timer Counter Control Register (TCCR0)
#define TMR_u8_TMR0_TCCR0_REG          (*(volatile u8*)0x53)
#define TMR_u8_TMR0_CS00_BIT           0
#define TMR_u8_TMR0_CS01_BIT           1
#define TMR_u8_TMR0_CS02_BIT           2
#define TMR_u8_TMR0_WGM01_BIT          3
#define TMR_u8_TMR0_COM00_BIT          4
#define TMR_u8_TMR0_COM01_BIT          5
#define TMR_u8_TMR0_WGM00_BIT          6
#define TMR_u8_TMR0_FOC0_BIT           7



// Timer Prescaler Types
#define TMR_u8_TMR0_PRESCALER_0           0b
#define TMR_u8_TMR0_PRESCALER_1
#define TMR_u8_TMR0_PRESCALER_8
#define TMR_u8_TMR0_PRESCALER_64
#define TMR_u8_TMR0_PRESCALER_256
#define TMR_u8_TMR0_PRESCALER_1024
#define TMR_u8_TMR0_
#define TMR_u8_TMR0_


#define TMR_u8_TMR0_TCNT0_REG         (*(volatile u8*)0x52)
#define TMR_u8_TMR0_OCR0_REG          (*(volatile u8*)0x5c)


/* TIMER1 */
#define TMR_u8_TMR1_TCCR1A_REG          (*(volatile u8*)0x4F)
#define TMR_u8_TMR1_TCCR1B_REG          (*(volatile u8*)0x4A)

#define TMR_u8_TMR1_TCNT1H_REG          (*(volatile u8*)0x4D)
#define TMR_u8_TMR1_TCNT1L_REG          (*(volatile u8*)0x4C)
#define TMR_u16_TMR1_TCNT1_REG          (*(volatile u16*)0x53)

#define TMR_u8_TMR1_OCR1AH_REG          (*(volatile u8*)0x4B)
#define TMR_u8_TMR1_OCR1AL_REG          (*(volatile u8*)0x4A)
#define TMR_u16_TMR1_OCR1A_REG          (*(volatile u16*)0x4A)

#define TMR_u8_TMR1_ICR1H_REG          (*(volatile u8*)0x47)
#define TMR_u8_TMR1_ICR1L_REG          (*(volatile u8*)0x46)
#define TMR_u16_TMR1_ICR1_REG          (*(volatile u16*)0x46)


#endif /*TMR_private_K_*/