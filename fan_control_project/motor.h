/*
 * motor.h
 * module: dc motor
 *  Created on: Oct 5, 2022
 *      Author: philopater ghobrial
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define output_Pin_1
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	stop,clockwise,anticlockwise
}DcMotor_state;



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * function description
 * initialize motor to work correctly
 */
void DcMotor_init(void);

/*
 * function description
 * choose the rotation direction and speed of rotation according to upcoming inputs
 */

void DcMotor_Rotate(DcMotor_state state,uint8 speed);

#endif /* MOTOR_H_ */
