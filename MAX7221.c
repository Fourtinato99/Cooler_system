/*
 * MAX7221.c
 *
 * Created: 9/3/2022 11:51:16 PM
 *  Author: effic
 */ 

#include "MAX7221.h"


void MAX7221_init(void)
{
	SPI_master_init();
	
	//setting decode mode
	MAX7221_send_C(0x09 ,0x0F);
	
	//setting the intensity
	MAX7221_send_C(0x0A ,0x0F);
	
	
	//setting scan limit register =  how many digits are displayed 
	// 0,1,2,3 will display
	MAX7221_send_C(0x0B ,0x03);
	
	
	// turn on the IC chip as normal operation
	MAX7221_send_C(0x0C ,0x01);
	
	
	
	
	MAX7221_send_C(0x01 ,2);


	
	
}

void MAX7221_send_C(uint8 cmd ,uint8 data)
{
	SS_LATCH(0);
	SPI_s_r(cmd);
	SPI_s_r(data);
	SS_LATCH(1);
}

void MAX7221_write_temp(float data)
{
	data *=  100;
	MAX7221_send_C(4,((uint64) data)%10);
	
	data/=10;
	MAX7221_send_C(3, ((uint64) data)%10 );
	
	data/=10;
	MAX7221_send_C(2,  0x80 | ((uint64) data)%10 );
	
	 data/=10;
	 MAX7221_send_C(1, ((uint64) data)%10 );
	
	
	
}