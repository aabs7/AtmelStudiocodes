/*
 * timer.h
 *
 * Created: 9/29/2017 3:30:59 PM
 *  Author: abheesh
 */ 


//This header file has functions which initializes and provides PWM for 4 MECHANUM motors in open loop//



#ifndef PWM_H_
#define PWM_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define FREQUENCY 4000
#define ICR_VALUE ((F_CPU/(8*FREQUENCY))-1)

#include <avr/io.h>
#include "headers.h"

///////defining PWM pins for motor/////////////////
#define _DD_M1 B,5
#define _DD_M2 B,6
#define _DD_M3 B,7
#define _DD_M4 E,3
//////////////////////////////////////////////////


void _pwm_base_init(void)
{
	/////////set PWM pins for output mode/////////
	OUTPUT(_DD_M1) ; //set PORTB PIN5 as output
	OUTPUT(_DD_M2) ; 
	OUTPUT(_DD_M3) ;
	OUTPUT(_DD_M4) ;
	//////////////////////////////////////////////
	ICR1 = ICR_VALUE;	//frequency set to 4Khz
	ICR3 = ICR_VALUE;	//frequency set to 4khz
	//////////////////////////////////////////////
	TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(1<<COM1C1)|(1<<WGM11);
	TCCR3A = (1<<COM3A1) | (1<< WGM31);
	TCCR1B = (1<<WGM12) | (1<<WGM13) | (1<<CS11);
	TCCR3B = (1<<WGM32) | (1<<WGM33) | (1<<CS31);
	/////////////////////////////////////////////
}
void _pwm_base_dc(int dutycycle)
{
	OCR1A = dutycycle;
	OCR1B = dutycycle;
	OCR1C = dutycycle;
	OCR3A = dutycycle;
}

#endif /* PWM_H_ */