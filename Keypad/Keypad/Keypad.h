/*
 * Keypad.c
 *
 * Created: 7/30/2023 9:43:45 AM
 * Author : khaled Eyada
 */ 
#include "avr/io.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"

#ifndef KEYPAD_H_
#define KEYPAD_H_

#define BOUNCING_DELAY 20


void KPD_voidInit(void);
u8 KPD_u8GetPressedKey(void);
 


#endif /* KEYPAD_H_ */