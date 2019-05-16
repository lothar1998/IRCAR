#ifndef IRCAR_RIDE_H
#define IRCAR_RIDE_H



#include <avr/io.h>
#include <util/delay.h>

#define direction_DDR DDRD	
#define direction_PORT PORTD
#define Rfore 3
#define Rrear 4			//right engine direction ports
#define Lfore 5
#define Lrear 7			//left engine direction ports


#define PWM_L (1<<PB1)
#define PWM_P (1<<PB2)	//engines speed control output

#define PWM_L_value OCR1A
#define PWM_R_value OCR1B	//engines speed control PWM value

int power;			//power of the engines



void forward();
void left();
void right();
void reverse();
void stop_run();
void PWM();
void stop_turn();




#endif