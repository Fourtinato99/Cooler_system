/*
 * cooler_system.c
 *
 * Created: 9/3/2022 10:45:41 PM
 * Author : effic
 */ 

#include "STD_MACROS.h"
#include "MAX7221.h"
#include "TIMER0.h"
#include "LCD.h"
#include "ADC.h"


int main(void)
{
	
	
	//////////////////////////////////////////////////////////////////////////
	//define a variable 
	float temp_degree = 0;  //to store temperature 
	uint8 duty0 = 0;            //to store duty cycle of motor 0
	
	//////////////////////////////////////////////////////////////////////////
	
	//LED and BUZZER
	//////////////////////////////////////////////////////////////////////////
	SET_BIT(DDRB,0);  //led 
	SET_BIT(DDRB,1);  //buzzer
	
	
	//initiating LCD (6 pins)  PORTD (0,1,2,3,4,7)
	//initiating pin direction in LCD header
	//////////////////////////////////////////////////////////////////////////
	LCD_init_4();
	LCD_y_x(1,3);
	//////////////////////////////////////////////////////////////////////////
	
	
	//initiating ADC and the pin that read from it (PORTC0 ) (1 pin)
	//////////////////////////////////////////////////////////////////////////
	CLR_BIT(DDRC,0); 
	ADC_init();
	//////////////////////////////////////////////////////////////////////////
	
	
	//initiating 7-segment driver using (max7221 IC that communicate with SPI PROTOCOL)
	//using SPI pins (4 pins)
	//////////////////////////////////////////////////////////////////////////
    MAX7221_init();
	MAX7221_write_temp(15.24);
	//////////////////////////////////////////////////////////////////////////
	
	
	//we control motor speed using timer0 in phase correct mode pin (OC0A and OC0B)
	// note OC0A pin rotate motor in opposite direction of OCB 
	// and we use pin(PORTC4 and PORTC5 ) to enable or disable the two motors
	//////////////////////////////////////////////////////////////////////////
	//set enable motor pins
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,5);
	//timer as fast PWM
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	
	//initiating the time without running it
	
	//////////////////////////////////////////////////////////////////////////
	

	
	LCD_y_x(1,1);
	LCD_write_string("Temp:");
	
    while (1) 
    {
		//first reading the current temperature
		temp_degree = (ADC_READ(0)/1023.0)*50;
		
		//display temperature on LCD and seven segment
		LCD_y_x(1,1);
		LCD_write_string("Temp:");
		LCD_write_float(temp_degree,2);
		MAX7221_write_temp(temp_degree);
		
		LCD_y_x(2,1);
		
		if(temp_degree >=35)
		{
			//turn on led and buzzer
			SET_BIT(PORTB,0);
			SET_BIT(PORTB,1);
			
			//calculate the duty cycle    0=35' max= 50'
			// duty cycle = ratio * 100 = (current degree -35 / 50 )*100
			duty0 = ((temp_degree-35)/15.0 )*100;
			
			//turn on the two motors in one direction at the same speed
			SET_BIT(PORTC,4);
			SET_BIT(PORTC,5);
			
			TIMER0_init_fastPWM(1, ((duty0*255)/100.0)  ,0,0,0);
			
			
			LCD_write_string("duty cycle:");
			LCD_write_num(duty0);
			LCD_write_string("%       ");
			
			
			
		}
		else
		{
			//turn on led and buzzer
			CLR_BIT(PORTB,0);
			CLR_BIT(PORTB,1);
			
			LCD_write_string("motor is off    ");
			CLR_BIT(PORTC,4);
			CLR_BIT(PORTC,5);
			TIMER0_init_fastPWM(0,0,0,0,0);
			
		}
		
	


    }
}

