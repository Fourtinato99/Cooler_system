/*
 * STD_MACROS.h
 *
 * Created: 8/16/2022 11:38:55 PM
 *  Author: effic
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define F_CPU 8000000LL

#include <avr/io.h>
#include <util/delay.h>
#include "UTILITIES.h"

#define SET_BIT(REG , BIT)(REG |= (1<<BIT))
#define CLR_BIT(REG , BIT)(REG &= ~(1<<BIT))
#define TOG_BIT(REG , BIT)(REG ^= (1<<BIT))
#define READ_BIT(REG,BIT)(REG>>BIT & 1)








#endif /* STD_MACROS_H_ */