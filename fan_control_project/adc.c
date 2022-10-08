/*
 * ADC.c
 * module: ADC
 *  Created on: Oct 4, 2022
 *      Author: philopater ghobrial
 */
# include "common_macros.h"   /* To use the macros like SET_BIT */
# include "adc.h"
# include <avr/io.h>   /* To use the ADC Registers */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void ADC_init(const ADC_ConfigType (* Config_Ptr)){
	// ADMUX Register Bits Description:
	 SET_BIT(ADMUX,REFS0);    // REFS1:0 = 01 to choose AVCC = 5v as reference voltage
	 CLEAR_BIT(ADMUX,REFS1);
	 ADMUX= (ADMUX&0x3F)|((Config_Ptr->volt)<<6);
	 // ADLAR   = 0 right adjusted
	CLEAR_BIT(ADMUX,MUX4);  // MUX4:0  = 00000 to choose channel 0 as initialization
		 // ADATE   = 0 Disable Auto Trigger
	SET_BIT(ADCSRA,ADEN);  // ADEN    = 1 Enable ADC
	CLEAR_BIT(ADCSRA,ADIE);   // ADIE    = 0 Disable ADC Interrupt
	ADCSRA = (ADCSRA & 0xF80) | (Config_Ptr->prescaler);
	// according to user input user chooses the prescaler
	 // ADC must operate in range 50-200Khz

}
uint16 ADC_readChannel(uint8 ch_num){
	ADMUX=((ADMUX&0xE0)|(ch_num & 0x07)); //clear first 5 bits and add chaneel to them
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));/* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF);// Clear ADIF Flag by write '1' to it
	return ADC; /* Read the digital value from the data register */

}

