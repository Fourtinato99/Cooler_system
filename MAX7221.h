/*
 * MAX7221.h
 *
 * Created: 9/3/2022 11:50:58 PM
 *  Author: effic
 */ 


#ifndef MAX7221_H_
#define MAX7221_H_

#include "STD_MACROS.h"
#include "SPI.h"

void MAX7221_init(void);
void MAX7221_send_C(uint8 cmd ,uint8 data);
void MAX7221_write_temp(float data);



#endif /* MAX7221_H_ */