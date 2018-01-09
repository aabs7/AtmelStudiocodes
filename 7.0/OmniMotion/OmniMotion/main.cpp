/*
 * OmniMotion.cpp
 *
 * Created: 10/23/2017 8:22:19 AM
 * Author : abheesh
 */ 


#include <avr/io.h>
#include "Motor.h"
#include "uart.h"
#include "drive.h"
#include "pid.h"
#include <avr/interrupt.h>
#include <math.h>

#define F_CPU 16000000UL


encoder e1,e2,e3,e4;
Motor m1(1) , m2(2) , m3(3) , m4(4);

char rcvdata = ' ';


int main(void)
{
	
	sei();
	uart0_init(UART_BAUD_SELECT(9600,F_CPU));
    while (1) 
    {
		uart0_puts("Abehesh don \r\n");
		rcvdata = uart0_getc();
		if (rcvdata == 'x')
			mov(0);
		else if( rcvdata == 'y')
			mov(90);
		else if(rcvdata == 'e')
			mov(45);
		else if (rcvdata == 'q')
			mov(60);
		else if(rcvdata == 's')
		{
			ma.SETPOINT = 0;
			mb.SETPOINT = 0;
			mc.SETPOINT = 0;
			md.SETPOINT = 0;
		}
		//mov(60);
		setTuningsM1();
		setTuningsM2();
		setTuningsM3();
		setTuningsM4();
		
		
    }
}

ISR(INT0_vect)
{
	e1.count_encoder++;
}
ISR(INT2_vect)
{
	e2.count_encoder++;
}
ISR(INT1_vect)
{
	e3.count_encoder++;
}
ISR(INT3_vect)
{
	e4.count_encoder++;
}
ISR(TIMER0_OVF_vect)
{
	e1.speed = e1.count_encoder;
	e2.speed = e2.count_encoder;
	e3.speed = e3.count_encoder;
	e4.speed = e4.count_encoder;
	e1.count_encoder = 0;
	e2.count_encoder = 0;
	e3.count_encoder = 0;
	e4.count_encoder = 0;
	
}