/*
 * seven_segment_decoder.h
 *
 *  Created on: May 9, 2022
 *      Author: The Bayoumi
 */

#ifndef SEVEN_SEGMENT_DECODER_H_
#define SEVEN_SEGMENT_DECODER_H_

#include <avr/io.h>

#include <util/delay.h>

void Decoder_INIT (void);

void Seven_Segment_INIT (void);

void Display_funct (void);

#endif /* SEVEN_SEGMENT_DECODER_H_ */
