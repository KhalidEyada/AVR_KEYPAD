/*
 * Keypad.h
 *
 * Created: 10/14/2016 8:11:55 AM
 *  Author: Khaled Eyada
 */ 
#include "avr/io.h"
#include "types.h"
#include "DIO.h"
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "types.h"
extern void Keypad_VoidInit(void);
extern u8 Keypad_u8ScanButton(void);




#endif /* KEYPAD_H_ */