/*
 * ultrasonic.h
 *
 *  Created on: 18 Apr 2023
 *      Author: ACER
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include"../../LIBRARIES/std_types.h"

#define ULTRASONIC_TRIGGER_PORT_ID	PORTB_ID
#define ULTRASONIC_TRIGGER_PIN_ID	PIN5_ID



void ULTRASONIC_init(void);
void ULTRASONIC_trigger(void);
uint16 ULTRASONIC_readDistance(void);
void ULTRASONIC_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
