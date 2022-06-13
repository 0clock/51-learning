



#ifndef _IO_EXPAND_H_
#define _IO_EXPAND_H_

#include "STC12C5A60S2.H"      //包含头文件

  #ifndef uchar
	#define uchar unsigned char
  #endif

  #ifndef uint
	#define uint  unsigned int
  #endif


//74HC595 引脚定义
sbit SH_CP=P1^5;  //时钟        
sbit ST_CP=P1^6;  //上升沿更新数据       
sbit DS=P1^7;	  //数据

//74HC138 引脚定义
sbit HC138_A=P1^0;       
sbit HC138_B=P1^1;        
sbit HC138_C=P1^2; 
sbit HC138_EN=P1^3;


extern void delay(uint time); 

//**************************************************************************************************
//向74HC595写一字节数据
//**************************************************************************************************
extern void wbyte_595(uchar temp);

//**************************************************************************************************
//向74HC138写位选数据 0—7  大于7关闭
//**************************************************************************************************
extern void wbyte_138(uchar temp);

#endif