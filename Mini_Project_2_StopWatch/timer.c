/*
 * Timer.c
 *
 *  Created on: May 9, 2022
 *      Author: The Bayoumi
 */
#include "timer.h"

#include "interrupts.h"

void Timer1_CTC_INIT(void)
{
	TCNT1 = 0;
	OCR1A   = 1000;
	SREG   |= (1<<7);
	TCCR1A |= (1<<FOC1A) | (1<<FOC1B);
	TCCR1B |= (1<<WGM12) | (1<<CS12) | (1<<CS10);
	TIMSK  |= (1<<OCIE1A);

}
