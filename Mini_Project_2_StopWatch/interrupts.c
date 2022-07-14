/*
 * interrupts.c
 *
 *  Created on: May 9, 2022
 *      Author: The Bayoumi
 */
#include "interrupts.h"

void INT0_INIT_RESET(void)
{
	DDRD  &= (~(1<<PD2));
	PORTD =  (1<<PD2);
	GICR  |= (1<<INT0);
	MCUCR |= (1<<ISC01);
	SREG  |= (1<<7);
}

void INT1_INIT_PAUSE(void)
{
	DDRD  &= (~(1<<PD3));
	PORTD |= (1<<PD3);
	GICR  |= (1<<INT1);
	MCUCR |= (1<<ISC11) | (1<<ISC10);
	SREG  |= (1<<7);
}

void INT2_INIT_RESUME(void)
{
	DDRB  &= (~(1<<PB2));
	PORTB |= (1<<PB2);
	GICR  |= (1<<INT2);
	MCUCR &= ~(1<<ISC2);
	SREG  |= (1<<7);
}
