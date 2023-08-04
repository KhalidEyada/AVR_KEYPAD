/*
 * Keypad.c
 *
 * Created: 10/14/2016 8:12:11 AM
 *  Author: Khaled Eyada
 */ 
#include "avr/io.h"
#include "types.h"
#include "DIO.h"
#include "Keypad.h"
extern void Keypad_VoidInit(void)
{
	DIO_VoidInit();
}
extern u8 Keypad_u8ScanButton(void)
{
	
	
	DIO_VoidWritePortVal(2,0xf7);
		if(DIO_U8ReadPinVal(2,4)==0)
		return 1;
		if(DIO_U8ReadPinVal(2,5)==0)
		return 2;
		if(DIO_U8ReadPinVal(2,6)==0)
		return 3;
		
		DIO_VoidWritePortVal(2,0xfb);
		if(DIO_U8ReadPinVal(2,4)==0)
		return 4;
		if(DIO_U8ReadPinVal(2,5)==0)
		return 5;
		if(DIO_U8ReadPinVal(2,6)==0)
		return 6;
		
	DIO_VoidWritePortVal(2,0xfd);
		if(DIO_U8ReadPinVal(2,4)==0)
		return 7;
		if(DIO_U8ReadPinVal(2,5)==0)
		return 8;
		if(DIO_U8ReadPinVal(2,6)==0)
		return 9;
	
		DIO_VoidWritePortVal(2,0xfe);
			if(DIO_U8ReadPinVal(2,5)==0)
			return 0;
			
			return 10;

	}

