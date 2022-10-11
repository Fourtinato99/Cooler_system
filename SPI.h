/*
 * SPI.h
 *
 * Created: 8/29/2022 2:12:46 PM
 *  Author: effic
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "STD_MACROS.h"


#define SPICR *((volatile uint8*) 0x4C )
#define SPISR *((volatile uint8*) 0x4D )
#define SPIDR *((volatile uint8*) 0x4E )


#define SS   2
#define MOSI 3
#define MISO 4
#define SCK  5

#define SS_LATCH(x)( x > 0 ? SET_BIT(PORTB,SS) :CLR_BIT(PORTB,SS) )
// initiating pins of spi PB2->ss PB3->MOSI  PB4->MISO   PB5->SCK


//master 
/*
		SS   ->output
		MOSI ->output
		MISO ->input
		SCK  -> output

*/
#define SPI_INIT_PINS_MASTER DDRB = (DDRB | (1<<MOSI) | (1<<SCK)| (1<<SS) ) & ~(1<<MISO)




//slave
/*
		SS   ->input
		MOSI ->output
		MISO ->input
		SCK  -> input

*/
#define SPI_INIT_PINS_SLAVE  DDRB = (DDRB | (1<<MISO) ) & ~(1<<MOSI| (1<<SCK)| (1<<SS))




//read interrupt flag
#define SPI_READ_INTF READ_BIT(SPISR,7)


void SPI_master_init(void);
void SPI_slave_init(void);
uint8 SPI_s_r(uint8 data);

#endif /* SPI_H_ */