#include <avr/io.h>
#include <util/delay.h>
#include "ride.h"



void forward()
{
	direction_PORT |= (1<<Rfore) | (1<<Lfore);									
	direction_PORT &= ~(1<<Rrear) & ~(1<<Lrear);			//values to ride forward
	direction_PORT |= (1<<Lenable) | (1<<Penable);
	stop_run();
}


void stop_run() 
{
	_delay_ms(350);
	direction_PORT &= ~(1<<Lenable) & ~(1<<Penable);
	
}

void stop_turn() 
{
	_delay_ms(100);
	direction_PORT &= ~(1<<Lenable) & ~(1<<Penable);
	
}

void left()
{
	direction_PORT |= (1<<Rrear) | (1<<Lfore);
	direction_PORT &= ~(1<<Rfore) & ~(1<<Lrear);			//values to ride forward
	direction_PORT |= (1<<Lenable) | (1<<Penable);
	stop_turn();
}

void right()
{
	direction_PORT |= (1<<Rfore) | (1<<Lrear);
	direction_PORT &= ~(1<<Rrear) & ~(1<<Lfore);			//values to ride forward
	direction_PORT |= (1<<Lenable) | (1<<Penable);
	stop_turn();
}

void reverse()
{
	direction_PORT |= (1<<Rrear) | (1<<Lrear);
	direction_PORT &= ~(1<<Rfore) & ~(1<<Lfore);			//values to ride forward
	direction_PORT |= (1<<Lenable) | (1<<Penable);
	stop_run();
}