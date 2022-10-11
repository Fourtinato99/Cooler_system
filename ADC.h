/*
 * ADC.h
 *
 * Created: 8/30/2022 5:21:55 PM
 *  Author: effic
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "STD_MACROS.h"

//define register

//define control and status  register a bits
#define ADC_EN   7
#define ADC_SC   6
#define ADC_ATE  5
#define ADC_IF   4
#define ADC_IE   3
#define ADC_PS2  2
#define ADC_PS1  1
#define ADC_PS0  0

//define multiplexer selection register bits
#define REFS1 7
#define REFS0 6
#define ADLAR 5

#define MUX3  3
#define MUX2  2
#define MUX1  1
#define MUX0  0



#define ADC_DR   *((volatile uint16*) 0x78)
#define ADC_CSRA *((volatile uint8*)  0x7A)
#define ADC_CSRB *((volatile uint8*)  0x7B)
#define ADC_MUXR *((volatile uint8*)  0x7c)




void ADC_init(void);

uint16 ADC_READ(uint8 channel);


#endif /* ADC_H_ */