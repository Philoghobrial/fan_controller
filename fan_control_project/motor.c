/*
 * motor.c
 *
 *  Created on: Oct 5, 2022
 *      Author: philopater ghobrial
 */
#include "common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h>
#include "motor.h"
#include "gpio.h"
extern void PWM_Timer0_Start(uint8 duty_cycle);
/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void DcMotor_init(void){
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);

}
void DcMotor_Rotate(DcMotor_state state,uint8 speed){
	PORTB = ((PORTB&0xFC)| state);
	uint8 duty_cycle = (uint8)(((uint32)speed*255)/(100));
	if(speed==0){
			duty_cycle=-1;
		}
    PWM_Timer0_Start(duty_cycle);
}
