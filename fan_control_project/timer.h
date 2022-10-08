/*
 * timer.h
 *
 *  Created on: Oct 6, 2022
 *      Author: felob
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define Timer_Initial_Value  0




/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/* function description:
 * initialize timer to work in PWM mode and give commands to DC motor
 */
void PWM_Timer0_Start(uint8 duty_cycle);



#endif /* TIMER_H_ */
