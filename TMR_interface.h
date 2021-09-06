/************************************************************************
 *                                                                      *
 *************************  Date    : 21/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : TMR             *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef TMR_interface_K_
#define TMR_interface_K_


                         /*************** APIS PROTOTYPES ***************/
						 
void TMR_voidTimer0Init(void);
void TMR_voidTimer1Init(void);

void TMR_voidTimer1SetCompareMatchValue(u16 Copy_u16OCR1A_Value);

void TMR_voidTimer0Stop(void);
u8 TMR_u8Timer0OVF_SetCallBack(void(*Copy_PfCallBack)(void));
u8 TMR_u8Timer0CTC_SetCallBack(void(*Copy_PfCallBack)(void));

#endif /*TMR_interface_K_*/