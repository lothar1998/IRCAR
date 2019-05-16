#include <avr/io.h>
#include <util/delay.h>
#include "ride.h"



void forward()
{
	direction_PORT |= (1<<Rfore) | (1<<Lfore);									
	direction_PORT &= ~(1<<Rrear) & ~(1<<Lrear);			//values to ride forward
	PWM_L_value = power;
	PWM_R_value = power;									//powering wheels
	
	stop_run();
}

void PWM()
{
	DDRB |= (PWM_L|PWM_P);						//setting PB1 and PB2 as outputs
	
	TCCR1A |= (1<<WGM10);						//choosing fast PWM 8bit
	TCCR1B |= (1<<WGM12);
	
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1);		//Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at BOTTOM
	
	TCCR1B |= (1<<CS10)|(1<<CS11);				//prescaler = 64,  fpwm = 976,5Hz
	
	PWM_L_value = 0;
	PWM_R_value = 0;
}

void stop_run() 
{
	_delay_ms(400);		//time for riding 
	PWM_L_value = 0;
	PWM_R_value = 0;
}

void stop_turn() 
{
	_delay_ms(150);		//time for turning
	PWM_L_value = 0;
	PWM_R_value = 0;
	
}
