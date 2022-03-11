#ifndef _DIGITRON_H_
#define _DIGITRON_H_

#ifndef uchar
	#define uchar unsigned char
#endif

#ifndef uint
	#define uint  unsigned int
#endif

#include "delay.h"


#define SMG_GPIO P0

//定义了74HC245的三个引脚
sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;


void DigDisplay(uchar Location,uchar Number);

#endif