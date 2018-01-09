/*
 * pid.h
 *
 * Created: 10/22/2017 5:38:07 PM
 *  Author: abheesh
 */ 


#ifndef PID_H_
#define PID_H_

#include "Motor.h"
#include "encoder.h"
#include "uart.h"



extern Motor m1,m2,m3,m4;
extern encoder e1,e2,e3,e4;

double kp = 1  , ki , kd = 5 ;

struct pid
{
	int input , output;
	int error;
	double Iterm;
	int previnput;
	int MOTOR_OCR_VALUE = 10 ;
	int SETPOINT;
	
	inline void incrKP(void){kp += 0.05;}
	inline void incrKD(void){kd += 0.05;}
	inline void incrKI(void){ki += 0.05;}
	inline void dcrKP(void){kp -= 0.05;}
	inline void dcrKI(void){ki -= 0.05;}
	inline void dcrKD(void){kd -= 0.05;}
	inline void reset(void){kp = 0;ki=0;kd=0;}
	inline float getkp(void){return kp;}
	inline float getkd(void){return kd;}
	inline float getki(void){return ki;}
	void setpid(int KP, int KI, int KD)
	{
		kp = KP;
		ki = KI;
		kd = KD;
	}

};

pid ma,mb,mc,md;



void setTuningsM1(void)
{
	ma.input = e1.speed;
	if (ma.SETPOINT > 0)
		ma.error = ma.SETPOINT - ma.input;
	else if (ma.SETPOINT < 0)
		ma.error = ma.SETPOINT + ma.input;
	ma.Iterm += ki * ma.error;
	
	ma.output = kp * ma.error + ma.Iterm - kd * (ma.input - ma.previnput) ;
	
	ma.previnput = ma.input;
	ma.MOTOR_OCR_VALUE = ma.MOTOR_OCR_VALUE + ma.output;
	
	if (ma.MOTOR_OCR_VALUE > ICR_TOP)
		ma.MOTOR_OCR_VALUE = ICR_TOP;

	m1.SetOcrValue(ma.MOTOR_OCR_VALUE);
}

void setTuningsM2(void)
{
	mb.input = e2.speed;
	if (mb.SETPOINT > 0)
		mb.error = mb.SETPOINT - mb.input;
	else if (mb.SETPOINT < 0)
		mb.error = mb.SETPOINT + mb.input;
	mb.Iterm += ki * mb.error;
	
	mb.output = kp * mb.error + mb.Iterm - kd * (mb.input - mb.previnput) ;
	
	mb.previnput = mb.input;
	mb.MOTOR_OCR_VALUE = mb.MOTOR_OCR_VALUE + mb.output;
	
	if (mb.MOTOR_OCR_VALUE > ICR_TOP)
	mb.MOTOR_OCR_VALUE = ICR_TOP;
	
	m2.SetOcrValue(mb.MOTOR_OCR_VALUE);
}

void setTuningsM3(void)
{
	mc.input = e3.speed;
	if (mc.SETPOINT > 0)
		mc.error = mc.SETPOINT - mc.input;
	else if (mc.SETPOINT < 0)
	mc.error = mc.SETPOINT + mc.input;	
	mc.Iterm += ki * mc.error;
	
	mc.output = kp * mc.error + mc.Iterm - kd * (mc.input - mc.previnput) ;
	
	mc.previnput = mc.input;
	mc.MOTOR_OCR_VALUE = mc.MOTOR_OCR_VALUE + mc.output;
	
	if (mc.MOTOR_OCR_VALUE > ICR_TOP)
	mc.MOTOR_OCR_VALUE = ICR_TOP;
	m3.SetOcrValue(mc.MOTOR_OCR_VALUE);

}
void setTuningsM4(void)
{
	
	md.input = e4.speed;
	if (md.SETPOINT > 0)
		md.error = md.SETPOINT - md.input;
	else if (ma.SETPOINT < 0)
		md.error = md.SETPOINT + md.input;
	md.Iterm += ki * md.error;
	
	md.output = kp * md.error + md.Iterm - kd * (md.input - md.previnput) ;
	
	md.previnput = md.input;
	md.MOTOR_OCR_VALUE = md.MOTOR_OCR_VALUE + md.output;

	if (md.MOTOR_OCR_VALUE > ICR_TOP)
		md.MOTOR_OCR_VALUE = ICR_TOP;
	
	m4.SetOcrValue(md.MOTOR_OCR_VALUE);
}
inline void incrkp(){
	kp += 0.05;}
inline void dcrkp(){
	kp -= 0.05;
}
inline void incrki(){
	ki += 0.005;
}
inline void dcrki(){
	ki -= 0.005;
}
inline void incrkd(){
	kd += 0.05;
}
inline void dcrkd(){
	kd -= 0.05;
}
#endif /* PID_H_ */