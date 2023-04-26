/*
 * icu.c
 *
 *  Created on: Apr 5, 2023
 *      Author: Ahmed Hassan
 */

#include"icu.h"
#include"../../LIBRARIES/common_macros.h"
#include<avr/interrupt.h>
#include<avr/io.h>
#include"../../MCAL/DIO/gpio_a.h"

static volatile void(*callBack)(void)=NULL_PTR;

ISR(TIMER1_CAPT_vect)
{
	if(callBack != NULL_PTR)
	{
		(*callBack)();
	}
}

void ICU_init(const ICU_configType *Config_Ptr)
{
	GPIO_setupPinDirection(ICU_PORT_ID,ICU_PIN_ID,PIN_OUTPUT);

	TCCR1A = (1<<FOC1A) | (1<<FOC1B);
	TCCR1B = (TCCR1B&0xF8) | (Config_Ptr->clock);
	TCCR1B = (TCCR1B&0xBF)|(Config_Ptr->edge<<6);
	TCNT1 = 0;
	ICR1=0;
	TIMSK = (TIMSK&0xDF) | (1<<TICIE1);
}
void ICU_setuptEdgeDetectionType(const ICU_edgeType edgetype)
{
	TCCR1B = (TCCR1B&0xBF)|(edgetype<<6);
}
void ICU_callBack(void(*ICU_ptr2fun))
{
	callBack=ICU_ptr2fun;
}
uint16 ICU_getInputCaptureValue(void)
{
	return ICR1;
}
void ICU_clearTimerValue(void)
{
	TCNT1= 0;
}
void ICU_deInit(void)
{
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1= 0;
	TIMSK &= ~(1<<TICIE1);
}
