/*
 * ultrasonic.c
 *
 *  Created on: 18 Apr 2023
 *      Author: ACER
 */

#include"ultrasonic.h"
#include"../../MCAL/DIO/gpio_a.h"
#include"../../MCAL/ICU/icu.h"
#include<avr/delay.h>
#include<avr/io.h>

uint16 a=0,b=0,distance,tick=0,check=0;

void ULTRASONIC_init(void)
{
	ICU_configType config;
	config.clock=F_CPU_8;
	config.edge=RISING_EDGE;
	ICU_init(&config);

	ICU_callBack(ULTRASONIC_edgeProcessing);

	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, PIN_OUTPUT);
}

void ULTRASONIC_trigger(void)
{
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_HIGH);
	_delay_us(20);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_LOW);
}

uint16 ULTRASONIC_readDistance(void)
{
	ULTRASONIC_trigger();

	while(tick!=2){}


	distance=ICR1/58;
	check=0;
	tick=0;


	return distance;

}

void ULTRASONIC_edgeProcessing(void)
{
	tick++;
	if(tick==1)
	{
		ICU_clearTimerValue();
		ICU_setuptEdgeDetectionType(FALLING_EDGE);
	}
	else if(tick==2)
	{
		ICU_setuptEdgeDetectionType(RISING_EDGE);
	//	tick=0;
		check=1;
	}
}
