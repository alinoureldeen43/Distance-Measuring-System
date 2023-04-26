/*
 * icu.h
 *
 *  Created on: Apr 5, 2023
 *      Author: Ahmed Hassan
 */

#ifndef ICU_H_
#define ICU_H_

#include"../../LIBRARIES/std_types.h"

#define ICU_PORT_ID		PORTD_ID
#define ICU_PIN_ID		PIN6_ID

typedef enum{
	FALLING_EDGE,RISING_EDGE
}ICU_edgeType;

typedef enum{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_clock;

typedef struct{
	ICU_edgeType edge;
	ICU_clock clock;
}ICU_configType;


void ICU_init(const ICU_configType *Config_Ptr);
void ICU_setuptEdgeDetectionType(const ICU_edgeType edgetype);
void ICU_callBack(void(*ICU_ptr2fun));
uint16 ICU_getInputCaptureValue(void);
void ICU_clearTimerValue(void);
void ICU_deInit(void);

#endif /* ICU_H_ */
