/************************************************************************
 *                                                                      *
 *************************  Date    : 04/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : PORT MATH       *******************
 *                                                                      *
 ************************************************************************/
 
#ifndef PORT_MATH_K_
#define PORT_MATH_K_


#define SET_REG(REG)                           REG=0xff
#define CLEAR_REG(REG)                         REG=0x00
#define TOGGLE_REG(REG)                        REG^=0xff
#define READ_REG(REG)                          (REG)
#define WRITE_REG(REG,DATA)                    ((REG)=(DATA))


#endif /*PORT_MATH_K_*/
