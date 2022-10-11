/*
 * ADC.c
 *
 * Created: 8/30/2022 5:21:39 PM
 *  Author: effic
 */ 



#include "ADC.h"




void ADC_init(void){
	
	//enable ADC module 
	SET_BIT(ADC_CSRA, ADC_EN);
	
	//set the prescalar selection Fosc/64 ( ps2 ps1 ps0 =  1 1 0 )
	CLR_BIT(ADC_CSRA,ADC_PS0);
	SET_BIT(ADC_CSRA,ADC_PS1);
	SET_BIT(ADC_CSRA,ADC_PS2);
	
	//select vref 
	SET_BIT(ADC_MUXR,REFS0);
	CLR_BIT(ADC_MUXR,REFS1);
	
	//adjust result data to right (ADLAR = 0)
	CLR_BIT(ADC_MUXR,ADLAR);
	
}

uint16 ADC_READ(uint8 channel){
	ADC_MUXR = (ADC_MUXR & 0xF0) |(0x0F & channel);
	SET_BIT(ADC_CSRA,ADC_SC);
	while(READ_BIT(ADC_CSRA,ADC_IF) == 0);

	return ADC_DR;
}