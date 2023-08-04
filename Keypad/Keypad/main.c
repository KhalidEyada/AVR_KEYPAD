/*
 * main.c
 *
 * Created: 7/30/2023 9:43:45 AM
 * Author : khaled Eyada
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include "DIO_Interface.h"
#include "Keypad.h"
#include "lcd.h"
#include <util/delay.h>
#include <stdlib.h>



int main(void)
{
    /* Replace with your application code */
	KPD_voidInit();/*initiate the keyboard*/
	LCD_init();  /*initiate the LCD*/
	LCD_moveCursor(0,1); /*Move LCD cursor to row 0 column 1*/
	LCD_displayString("PLEASE ENTER NUMS"); /*dis[laying a string on the LCD*/
	LCD_moveCursor(2,6); /*Move LCD cursor to row 2 column 6*/
    while (1) 
    {
	  u8 key = KPD_u8GetPressedKey(); /*reading the pressed key*/
		if (key!=0)
		{
			LCD_displayCharacter(key); /*displaying the read character*/
		}
    }
}

