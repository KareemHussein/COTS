/************************************************************************
 *                                                                      *
 *************************  Date    : 04/1/2021       *******************
 *************************  Name    : Kareem Hussein  *******************
 *************************  Version : 1.0             *******************
 *************************  SWC     : STD TYPES       *******************
 *                                                                      *
 ************************************************************************/

#ifndef STD_TYPES_K_
#define STD_TYPES_K_

#define HIGH 1
#define LOW  0


                     /***************** DEFINE DATA TYPES *****************/

typedef unsigned char        u8;
typedef signed char          s8;

typedef unsigned short int   u16;
typedef signed short int     s16;

typedef unsigned long int    u32;
typedef signed long int      s32;

typedef unsigned long long   u64;
typedef signed long long     s64;

typedef float                f32;
typedef double               f64;
typedef long double          f128;




                     /******************** BOOLEAN VLUES  ********************/

#define FALSE                0
#define TRUE                 1           


#define FAIL                 0
#define PASS                 1

#define NULL                 0
#define NULL_PTR             ((void*)0)

#endif /*STD_TYPES_K_*/
