/*
 * interrupts.h
 *
 *  Created on: May 9, 2022
 *      Author: The Bayoumi
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include <avr/interrupt.h>

#include <avr/io.h>

#include <util/delay.h>

void INT0_INIT_RESET();

void INT1_INIT_PAUSE();

void INT2_INIT_RESUME();


#endif /* INTERRUPTS_H_ */
