#ifndef __HX711_H__
#define __HX711_H__


#include "STC12C5A60S2.H"      //包含头文件
#include <intrins.h>

  #ifndef uchar
	#define uchar unsigned char
  #endif

  #ifndef uint
	#define uint  unsigned int
  #endif

//IO设置
sbit HX711_DOUT=P1^4; 
sbit HX711_SCK =P1^3; 



//函数或者变量声明

extern uint GapValue ; //重量系数

extern void Delay__hx711_us(void);
extern int HX711_Read(void);

#endif