/*
 * Keypad.c
 *
 * Created: 7/30/2023 9:43:45 AM
 * Author : khaled Eyada
 */ 
#define F_CPU 8000000UL
#include "Keypad.h"
#include <util/delay.h>
#include "KEYPAD_Private.h"

/*********************************************************************************/
/* Function: KPD_voidInit			                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns No thing                                				    **/
/* Desc:This Function initialize KEYPAD								       	    **/
/*********************************************************************************/
void KPD_voidInit(void)
{
	DIO_voidSetPortDirection(DIO_u8_PORTC,0xFF);/*setting port C's pins as output */
	DIO_voidSetPortDirection(DIO_u8_PORTD,0x00);/*setting port d's pins as input */
}

/*********************************************************************************/
/* Function: KPD_u8GetPressedKey	                        				    **/
/* I/P Parameters: Nothing									          		    **/
/* Returns:it returns u8	                                				    **/
/* Desc:This Function used to get the value of the pressed key		       	    **/
/*********************************************************************************/
u8 KPD_u8GetPressedKey(void)
{
		u8 val = 0;
		_delay_ms(BOUNCING_DELAY);/*delay to solve the problem of bouncing*/
		
		/*I'm using if instead of two for loops te reduce time*/
		
		DIO_voidSetPortValue(DIO_u8_PORTC,0xDF);/*setting pin 5 to logical low while the other pins to high*/
		
		/*go through each column pin to see which one pressed*/
		if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN7)==KEYPAD_u8_FLAG_DOWN)
		val= '1';
		else if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN6)==KEYPAD_u8_FLAG_DOWN)
		val= '2';
		else if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN5)==KEYPAD_u8_FLAG_DOWN)
		val= '3';
		else if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN3)==KEYPAD_u8_FLAG_DOWN)
		val= '+';
		
		DIO_voidSetPortValue(DIO_u8_PORTC,0xEF);/*setting pin 4 to logical low while the other pins to high*/
		
		/*go through each column pin to see which one pressed*/
		if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN7)==KEYPAD_u8_FLAG_DOWN)
		val= '4';
		else if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN6)==KEYPAD_u8_FLAG_DOWN)
		val= '5';
		else if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN5)==KEYPAD_u8_FLAG_DOWN)
		val= '6';
		else if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN3)==KEYPAD_u8_FLAG_DOWN)
		val= '-';
		
		DIO_voidSetPortValue(DIO_u8_PORTC,0xF7);/*setting pin 3 to logical low while the other pins to high*/
		
		/*go through each column pin to see which one pressed*/
		if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN7)==KEYPAD_u8_FLAG_DOWN)
		val= '7';
		else if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN6)==KEYPAD_u8_FLAG_DOWN)
		val= '8';
		else if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN5)==KEYPAD_u8_FLAG_DOWN)
		val= '9';
		else if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN3)==KEYPAD_u8_FLAG_DOWN)
		val= '*';
	
		DIO_voidSetPortValue(DIO_u8_PORTC,0xFB);/*setting pin 2 to logical low while the other pins to high*/
		
		/*go through each column pin to see which one pressed*/
		if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN7)==KEYPAD_u8_FLAG_DOWN)
		val= '.';
		else if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN6)==KEYPAD_u8_FLAG_DOWN)
		val= '0';
		else if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN5)==KEYPAD_u8_FLAG_DOWN)
		val= '=';
		else if(DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN3)==KEYPAD_u8_FLAG_DOWN)
		val= '/';
		
		/*do while loop to make function wait until the user releases the pin*/
		u8 temp=ALL_COLUMNS_HIGH;
		do 
		{	
			DIO_voidSetPortValue(DIO_u8_PORTC,0x00);
			temp = (DIO_voidGetPortValue(DIO_u8_PORTD))&(ALL_COLUMNS_HIGH);
		}while(temp != (ALL_COLUMNS_HIGH));
		
		return val;
	}

