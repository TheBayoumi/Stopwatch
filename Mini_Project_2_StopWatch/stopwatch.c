/*
 * stop.c
 *
 *  Created on: May 8, 2022
 *      Author: The Bayoumi
 *
 */

#include "seven_segment_decoder.h"

#include "interrupts.h"

#include "timer.h"

unsigned char sec = 0;

unsigned char min = 0;

unsigned char hour = 0;


ISR(TIMER1_COMPA_vect)
{
	sec++;
	if(sec==60)
	{
		sec = 0;
		min++;
	}
	if(min==60)
		{
			min = 0;
			sec = 0;
			hour++;
		}
	if(hour==24)
				{
					hour= 0;
					min = 0;
					sec = 0;
				}

}

ISR(INT0_vect)
{
	sec   =0;
	min   =0;
	hour  =0;
}

ISR(INT1_vect)
{
	TCCR1B &= ~(1<<WGM12);
	TCCR1B &= ~(1<<CS12);
	TCCR1B &= ~(1<<CS10);
}

ISR(INT2_vect)
{
	TCCR1B |= (1<<WGM12) | (1<<CS12) | (1<<CS10);
}

int main (void)
{
	Seven_Segment_INIT();
	Decoder_INIT();
	Timer1_CTC_INIT();
	INT0_INIT_RESET();
	INT1_INIT_PAUSE();
	INT2_INIT_RESUME();
	while(1)
	{
		Display_funct();
	}
}
