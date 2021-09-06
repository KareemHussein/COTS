/************************************************************************
 *                                                                      *
 *************************  Date    : 17/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : EXTI            *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef EXTI_private_K_
#define EXTI_private_K_ 
 
 
                        /* EXTERNAL INTERRUPT REGISTERS */
						
// General Interrupt Control Register
#define EXTI_u8_GICR_REG    (*(volatile u8*)0x5B)
#define EXTI_u8_INT0_BIT    6
#define EXTI_u8_INT1_BIT    7
#define EXTI_u8_INT2_BIT    5						

// MCU Control Register
#define EXTI_u8_MCUCR_REG   (*(volatile u8*)0x55)
#define EXTI_u8_ISC00_BIT   0
#define EXTI_u8_ISC01_BIT   1
#define EXTI_u8_ISC10_BIT   2
#define EXTI_u8_ISC11_BIT   3

// MCU Control and Status Register
#define EXTI_u8_MCUCSR_REG  (*(volatile u8*)0x54)
#define EXTI_u8_ISC2_PIN    6

// General Interrupt Flag Register
#define EXTI_u8_GIFR_REG    (*(volatile u8*)0x5A)
#define EXTI_u8_INTF0_BIT   6
#define EXTI_u8_INTF1_BIT   7
#define EXTI_u8_INTF2_BIT   5

#endif /*EXTI_private_K_*/
