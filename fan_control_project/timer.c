/*
 * timer.c
 *
 *  Created on: Oct 6, 2022
 *      Author: philopater ghobrial
 */
#include "timer.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h>
#include "gpio.h"
void PWM_Timer0_Start(uint8 duty_cycle){

	TCNT0 = Timer_Initial_Value; // Set Timer Initial Value to 0
	OCR0  = duty_cycle; // Set Compare Value
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
	// Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	CLEAR_BIT(TCCR0,FOC0);
	SET_BIT(TCCR0,COM01);
	CLEAR_BIT(TCCR0,COM00);
	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);

}
