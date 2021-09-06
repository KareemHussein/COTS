/************************************************************************
 *                                                                      *
 *************************  Date    : 18/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : GI              *******************
 *                                                                      *
 ************************************************************************/


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_MATH.h"

/* MCAL */
#include "GI_private.h"
#include "GI_interface.h"


void GI_voidEnable(void)
{
	SET_BIT(GI_u8_SREG_REG, GI_u8_I_PIN);
}


void GI_voidDisable(void)
{
	CLEAR_BIT(GI_u8_SREG_REG, GI_u8_I_PIN);
}
