/************************************************************/
/* Author : Nadine Ashraf Adeeb                             */
/* Description: File that holds all configuration for       */
/*                  BIT MATH                                */
/*                Layer : LIB                               */
/* Version :v1.0                                            */
/* Date : 3 Sep ,2021                                       */
/************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BIT)  (REG|=(1<<BIT))
#define CLR_BIT(REG,BIT)  (REG&=~(1<<BIT))
#define TOG_BIT(REG,BIT)  (REG^=(1<<BIT))
#define GET_BIT(REG,BIT)  ((REG>>BIT)&0x01)

#endif
