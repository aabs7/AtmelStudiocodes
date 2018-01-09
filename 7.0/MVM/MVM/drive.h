/*
 * drive.h
 *
 * Created: 9/29/2017 8:05:00 PM
 *  Author: abheesh
 */ 

//This header file includes only forward and side movement of MECHANUM wheels//

#ifndef DRIVE_H_
#define DRIVE_H_

#define _DD_IN1_M1		F,0
#define _DD_IN2_M1		F,1
#define _DD_IN1_M2		F,2
#define _DD_IN2_M2		F,3
#define _DD_IN1_M3		F,4
#define _DD_IN2_M3		F,5
#define _DD_IN1_M4		F,6
#define _DD_IN2_M4		F,7


#include "headers.h"


/////////To move MECHANUM 0 degree front//////
/*move all the motor in forward direction*/

void MOV0F(void)
{
	DDRF = 0xff;
	SET(_DD_IN1_M1);
	SET(_DD_IN1_M2);
	SET(_DD_IN1_M3);
	SET(_DD_IN1_M4);
	CLEAR(_DD_IN2_M1);
	CLEAR(_DD_IN2_M2);
	CLEAR(_DD_IN2_M3);
	CLEAR(_DD_IN2_M4);
}

//////////To move MECHANUM 0 degree back///////
/*move all the motor in backward direction*/

void MOV0B(void)
{
	DDRF = 0xff;
	CLEAR(_DD_IN1_M1);
	CLEAR(_DD_IN1_M2);
	CLEAR(_DD_IN1_M3);
	CLEAR(_DD_IN1_M4);
	SET(_DD_IN2_M1);
	SET(_DD_IN2_M2);
	SET(_DD_IN2_M3);
	SET(_DD_IN2_M4);
}

/////////To move MECHANUM 90 degree front/////
/*move 2front motor in forward, and two back motor in backward*/
/*for left 90 degree movement*/

void MOV90F(void)
{
	DDRF = 0xff;
	SET(_DD_IN1_M1);
	CLEAR(_DD_IN1_M2);
	CLEAR(_DD_IN1_M3);
	SET(_DD_IN1_M4);
	CLEAR(_DD_IN2_M1);
	SET(_DD_IN2_M2);
	SET(_DD_IN2_M3);
	CLEAR(_DD_IN2_M4);
}

//////////To move MECHANUM 90 degree back//////
/*move 2 back motor in forward, and two front motor in back*/
/*for right 90 degree movement*/

void MOV90B(void)
{
	DDRF = 0xff;
	CLEAR(_DD_IN1_M1);
	SET(_DD_IN1_M2);
	SET(_DD_IN1_M3);
	CLEAR(_DD_IN1_M4);
	SET(_DD_IN2_M1);
	CLEAR(_DD_IN2_M2);
	CLEAR(_DD_IN2_M3);
	SET(_DD_IN2_M4);
}
	
#endif /* DRIVE_H_ */