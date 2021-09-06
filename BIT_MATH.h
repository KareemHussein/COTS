/************************************************************************
 *                                                                      *
 *************************  Date    : 04/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : BIT MATH        *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef BIT_MATH_K_
#define BIT_MATH_K_


#define SET_BIT(REG,BIT_INDEX)              REG|=(1<<BIT_INDEX)
#define CLEAR_BIT(REG,BIT_INDEX)            REG=(REG&(~(1<<BIT_INDEX)))
#define TOGGLE_BIT(REG,BIT_INDEX)           REG^=(1<<BIT_INDEX)
#define READ_BIT(REG,BIT_INDEX)             ((REG>>BIT_INDEX)&0x01)
#define WRITE_BIT(REG,BIT_INDEX,DATA)       REG=(REG&(~(1<<BIT_INDEX)))|(DATA<<BIT_INDEX)


#endif /*BIT_MATH_K_*/
