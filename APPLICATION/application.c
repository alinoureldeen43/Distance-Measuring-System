/*
 * application.c
 *
 *  Created on: 18 Apr 2023
 *      Author: Ali Hassan
 */

#include"../MCAL/DIO/gpio_a.h"
#include"../MCAL/ICU/icu.h"

#include"../HAL/LCD/lcd.h"
#include"../HAL/ULTRASONIC/ultrasonic.h"

#include<avr/delay.h>

int main()
{
	uint16 distance=0;

	LCD_init();
	LCD_displayStringRowColumn(0,5,"Welcome");
	_delay_ms(1000);
	LCD_clearScrean();
	LCD_displayString("Distance=    cm");//11

	ULTRASONIC_init();

	while(1)
	{
		distance=ULTRASONIC_readDistance();
		LCD_moveCursor(0,10);
		if(distance<100)
		{
			LCD_integrToString(distance);
		}
		else
		{
			LCD_integrToString(distance);
			LCD_displayCharacters(' ');
		}
	}
}
