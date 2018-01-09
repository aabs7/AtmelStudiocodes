/*
 * angle control with encoder.cpp
 *
 * Created: 10/26/2017 10:06:59 PM
 * Author : abheesh
 */ 


#define INPUT2(port,pin)	DDR ## port &= ~_BV(pin)
#define OUTPUT2(port,pin)	DDR ## port |= _BV(pin)
#define CLEAR2(port,pin)	PORT ## port &= ~_BV(pin)
#define SET2(port,pin)		PORT ## port |= _BV(pin)

#define INPUT(x)	INPUT2(x)
#define OUTPUT(x)	OUTPUT2(x)
#define CLEAR(x)	CLEAR2(x)
#define SET(x)		SET2(x)



#define DD_F1 K,6
#define DD_B1 K,7

#define DD_PWM1			L,5
#define PWM_TCCRA1		TCCR5A
#define PWM_TCCRB1		TCCR5B
#define PWM_ICR1			ICR5
#define PWM_OCR1			OCR5C

#define PWM_1COM0		COM5C0
#define PWM_1COM1		COM5C1

#define PWM_1WGM0		WGM50
#define PWM_1WGM1		WGM51
#define PWM_1WGM2		WGM52
#define PWM_1WGM3		WGM53
#define PWM_1CS0			CS50
#define PWM_1CS1			CS51
#define PWM_1CS2			CS52
#define ICR_TOP   249

#define F_CPU 16000000UL

#include <avr/io.h>
#include "encoder.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include "uart.h"

void initpwm();
void dutycycle(int);

encoder e;

int angletime;
int setAngle = 90 ;
int error;
int currentAngle = 0;
int previousAngle;
int motorocr;

char rcvdata;


int main(void)
{
	
	uart0_init(UART_BAUD_SELECT(38400,F_CPU));
	sei();
	initpwm();
	
    while (1) 
    {
		//rcvdata = uart0_getc();
		//if(rcvdata == 'i')
			//uart0_puts("abheesh is don \r\n");
		dutycycle(10);

		//uart0_puts("Abheeshdon\r\n");
		uart0_putint(e.get_angle());
		uart0_puts("\t\t");
		uart0_putint(e.count_encoder);
		uart0_puts("\r\n");
		//currentAngle = e.get_angle();
		//error = setAngle - currentAngle;
		//if(e.count_encoder > 50)
		//{
			//PWM_OCR1 = 0;
			//_delay_ms(2000);
		//}
	
		_delay_ms(10);
		//rcvdata = 0;
		
    }
}
void initpwm()
{
	OUTPUT(DD_F1);
	OUTPUT(DD_B1);

	OUTPUT(DD_PWM1);

	PWM_TCCRA1	|=  ( 1 << PWM_1COM1 ) | ( 1 << PWM_1WGM1 );														//
	PWM_TCCRB1	|=  ( 1 << PWM_1WGM2 ) | ( 1 << PWM_1WGM3 ) | ( 1 << PWM_1CS1);									//PRESCALAR 8
	PWM_ICR1		 =         ICR_TOP;

}
void setforward()
{
	SET		(DD_F1);
	CLEAR	(DD_B1);

}
void dutycycle(int x)
{
	PWM_OCR1 = int((ICR_TOP/100)*x);
	setforward();
}
//ISR(INT0_vect)
//{
	//e.count_encoder++;
	//if(e.count_encoder > 200)
		//{
			//e.count_encoder = 0;
			//angletime++;
		//}
//}

