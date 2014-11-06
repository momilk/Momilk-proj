/*
 * CPPFile1.cpp
 *
 * Created: 11/6/2014 11:12:50 AM
 *  Author: ofir
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "ButtonInt.h"

void ButtonIntFunc(){
	cli();
	EIMSK |=(1<<INT6);
	EICRB |=(0<<ISC60) | (1<<ISC61);
	sei();
}

