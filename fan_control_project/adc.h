/*
  * Module: ADC
 * File Name: adc.h
 *  Created on: Oct 4, 2022
 *      Author: philopater ghobrial
 */

#ifndef ADC_H_
#define ADC_H_


# include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	div_2,div_02,div_4,div_8,div_16,div_32,div_64,div_128
}ADC_prescaler;

typedef enum
{
	AREF,AVCC,internal_voltage=3
}ADC_referencevoltage_ref_volt;

typedef struct
{
	ADC_referencevoltage_ref_volt volt;
	ADC_prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */

void ADC_init(const ADC_ConfigType (* Config_Ptr));
/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */

uint16 ADC_readChannel(uint8 ch_num);


#endif /* ADC_H_ */
