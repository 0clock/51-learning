#ifndef __DELAY_H__
#define __DELAY_H__

#include<STC12C5A60S2.h>
#include"intrins.h"

#ifndef uchar
	#define uchar unsigned char
#endif

#ifndef uint
	#define uint  unsigned int
#endif
	
void Delay_Us(uchar n);
void Delay_Ms(uint time);

#endif
