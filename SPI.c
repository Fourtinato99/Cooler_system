/*
 * SPI.c
 *
 * Created: 8/29/2022 2:13:04 PM
 *  Author: effic
 */ 

#include "SPI.h"

void SPI_master_init(void){
	
	//initiating pins
	SPI_INIT_PINS_MASTER;
	SPICR = (1<<6)|(1<<4)|(1<<0);
}

uint8 SPI_s_r(uint8 data){
	SPIDR = data;
	while( SPI_READ_INTF == 0);
	return SPIDR;
	
}
void SPI_slave_init(void)

{
		//initiating pins
		SPI_INIT_PINS_SLAVE;
		
	
	
}
