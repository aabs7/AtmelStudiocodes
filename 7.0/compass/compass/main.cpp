/*
 * compass.cpp
 *
 * Created: 11/24/2017 12:58:51 AM
 * Author : abheesh
 */ 

#define F_CPU 16000000ul // Clock Speed

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "compass.h"
#include "uart.h"


int main(void)
{
	sei();
	uart0_init(UART_BAUD_SELECT(9600,F_CPU));
    init_HMC5883L();
	uart0_puts("Initializing compass ...\r\n");
	_delay_ms(300);
	uart0_puts("... \r\n");
	_delay_ms(300);
	uart0_puts("...\r\n");
    while (1) 
    {
		
		read_Compass();
		
		uart0_puts("RAW X: ");uart0_putint(raw_x);
		uart0_puts("\tRAW Y: ");uart0_putint(raw_y);
		uart0_puts("\tangle = ");uart0_putint(calculateAngle());
		uart0_puts("\r\n");
		
		
    }
}

