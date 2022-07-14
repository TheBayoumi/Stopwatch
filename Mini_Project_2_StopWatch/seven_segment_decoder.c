/*
 * seven_segment_decoder.c
 *
 *  Created on: May 9, 2022
 *      Author: The Bayoumi
 */
#include "seven_segment_decoder.h"

void Decoder_INIT (void)
{
	DDRA = 0x3f;
	PORTA |= 0xff;
}

void Seven_Segment_INIT (void)
{
	DDRC = 0x0f;
	PORTC &= ~0x00;
}

void Display_funct (void)
{
	extern unsigned char sec;
	extern unsigned char min;
	extern unsigned char hour;
	PORTA = (1<<0);
	PORTC = sec % 10;
	_delay_ms(1);
	PORTA = (1<<1);
	PORTC = sec / 10;
	_delay_ms(1);
	PORTA = (1<<2);
	PORTC = min % 10 ;
	_delay_ms(1);
	PORTA = (1<<3);
	PORTC = min / 10;
	_delay_ms(1);
	PORTA = (1<<4);
	PORTC = hour % 10;
	_delay_ms(1);
	PORTA = (1<<5);
	PORTC = hour / 10;
	_delay_ms(1);
}
