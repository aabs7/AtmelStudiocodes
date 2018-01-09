/*
 * MVM.cpp
 *
 * Created: 9/29/2017 1:48:46 PM
 * Author : abheesh
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "pwm.h"
#include "drive.h"


int main(void)
{
    _pwm_base_init();
   	
    while (1)
    {
	   _pwm_base_dc(500);
	   MOV0F();
	   _delay_ms(500);
	   MOV0B();
	   _delay_ms(500);
	   MOV90F();
	   _delay_ms(500);
	   MOV90B();
	   _delay_ms(500);
	   
    }
}

