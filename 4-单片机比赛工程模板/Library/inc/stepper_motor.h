/**************************************************************************************
*		              步进电机实验												  *
实现现象：下载程序后，按照光盘内操作视频接线，步进电机旋转
注意事项：无																				  
***************************************************************************************/

#ifndef _STEPPER_MOTOR_H_
#define _STEPPER_MOTOR_H_

#include "STC12C5A60S2.H"      //包含头文件

  #ifndef uchar
	#define uchar unsigned char
  #endif

  #ifndef uint
	#define uint  unsigned int
  #endif

sbit MOTOA = P1^0;
sbit MOTOB = P1^1;
sbit MOTOC = P1^2;
sbit MOTOD = P1^3; 	


extern void stepper_motor(uchar Dir);


#endif
