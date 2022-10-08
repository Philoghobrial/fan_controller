/*
 * name: fan_temp_controlled project
 *
 *  Created on: Oct 5, 2022
 *      Author: philopater ghobrial
 */
#include "adc.h"
#include "motor.h"
#include "lcd.h"
#include "sens.h"
#include <avr/io.h> /* To use the SREG register */
int main(void){
	ADC_ConfigType adc_config={internal_voltage,div_8};
	ADC_init(&adc_config);
	DcMotor_init();
	LCD_init();
	uint8 temp_value;
	while(1){
		temp_value=LM35_getTemperature();
		LCD_clearScreen();
		while(temp_value<30){
			DcMotor_Rotate(stop,0);
			LCD_displayStringRowColumn(0,3,"FAN IS OFF");
			LCD_moveCursor(1,3);
			LCD_displayString("Temp = ");
			temp_value=LM35_getTemperature();
			if(temp_value<10){
				LCD_display_Character(' ');
			}
			LCD_intgerToString(temp_value);
			LCD_moveCursor(1,12);
			LCD_display_Character('C');


		}
		while((temp_value<60)&&(temp_value>=30)){
			DcMotor_Rotate(anticlockwise,25);
			LCD_displayStringRowColumn(0,3,"FAN IS ON ");
			LCD_moveCursor(1,3);
			LCD_displayString("Temp = ");
			temp_value=LM35_getTemperature();
			LCD_intgerToString(temp_value);
			LCD_moveCursor(1,12);
			LCD_display_Character('C');

		}
		while((temp_value<90)&&(temp_value>=60)){
			DcMotor_Rotate(anticlockwise,50);
			LCD_displayStringRowColumn(0,3,"FAN IS ON ");
			LCD_moveCursor(1,3);
			LCD_displayString("Temp = ");
			temp_value=LM35_getTemperature();
			LCD_intgerToString(temp_value);
			LCD_moveCursor(1,12);
			LCD_display_Character('C');

		}
		while((temp_value<120)&&(temp_value>=90)){
			DcMotor_Rotate(anticlockwise,75);
			LCD_displayStringRowColumn(0,3,"FAN IS ON ");
			LCD_moveCursor(1,3);
			LCD_displayString("Temp = ");
			temp_value=LM35_getTemperature();
			if(temp_value<100){
				LCD_displayStringRowColumn(1,10," ");
			}
			LCD_intgerToString(temp_value);
			LCD_moveCursor(1,13);
			LCD_display_Character('C');

		}
		while(temp_value>=120){
			DcMotor_Rotate(anticlockwise,100);
			LCD_displayStringRowColumn(0,3,"FAN IS ON ");
			LCD_moveCursor(1,3);
			LCD_displayString("Temp = ");
			temp_value=LM35_getTemperature();
			LCD_intgerToString(temp_value);
			LCD_moveCursor(1,13);
			LCD_display_Character('C');
		}
	}
}


