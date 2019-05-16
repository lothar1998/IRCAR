#include <avr/io.h>
#include <util/delay.h> 
#include "ride.h"
#include "IR_Receiver.h"
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>


struct IR_Packet received_packet;

int main(void)
{
	direction_DDR |= (1<<Rfore) | (1<<Lfore) | (1<<Rrear | (1<<Lrear));			//setting 2, 4, 5, 7 bytes on portD as an output
    
	power = 255;
	
	init_receiver();
	
	sei();
	
	PWM();
	
	
	
	while (1) 
    {
		cli();
		uint8_t check_result = check_new_packet(&received_packet);
		sei();
	
		if (check_result)
		{
			char buff[10];
			if (received_packet.repeat > 0)
			{
				
					
			} else
			{
	
					if(received_packet.command==65)
						left();
					if(received_packet.command==66)
						right();
					if(received_packet.command==6)
						forward();
					if(received_packet.command==5)
						reverse();

				
			}
		}
	
		_delay_ms(50);
	
    }
}

