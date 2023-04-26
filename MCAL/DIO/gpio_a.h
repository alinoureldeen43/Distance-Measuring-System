/*
 * gpio_a.h
 *
 *  Created on: Apr 1, 2023
 *      Author: Ahmed Hassan
 */


#ifndef MCAL_GPIO_GPIO_A_H_
#define MCAL_GPIO_GPIO_A_H_

#include "../../LIBRARIES/std_types.h"

#define NUM_OF_PORTS	4
#define NUM_OF_PINS		8

#define PORTA_ID		0
#define PORTB_ID		1
#define PORTC_ID		2
#define PORTD_ID		3

#define PIN0_ID			0
#define PIN1_ID			1
#define PIN2_ID			2
#define PIN3_ID			3
#define PIN4_ID			4
#define PIN5_ID			5
#define PIN6_ID			6
#define PIN7_ID			7

typedef enum{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_portDirection;

typedef enum{
	PIN_INPUT,PIN_OUTPUT
}GPIO_pinDirection;

/*

							FUNCTIONS PROTOTYPES

*/

// THIS FUNCTION TAKES 3 INPUT (PORT,PIN,DIRECTION) AND SET THE DIRECTION OF THE PIN
void GPIO_setupPinDirection(uint8 port_num,uint8 pin_num,GPIO_pinDirection direction);

//THIS FUNCTION TAKES 3 INPUT (PORT,PIN,VALUE) AND SET THE LOGIC VALUE OF THE PIN
void GPIO_writePin(uint8 port_num,uint8 pin_num,uint8 value);

//
uint8 GPIO_readPin(uint8 port_num,uint8 pin_num);

//
void GPIO_setupPortDirection(uint8 port_num,GPIO_portDirection direction);

//
void GPIO_writePort(uint8 port_num, uint8 value);

//
uint8 GPIO_readPort(uint8 port_num);

#endif /* MCAL_GPIO_GPIO_A_H_ */
