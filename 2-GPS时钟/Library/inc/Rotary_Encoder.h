#ifndef _ROTARY_ENCODER_H_
#define _ROTARY_ENCODER_H_

#include "reg52.h"

sbit ROTARY_ENCODER_CLK=P2^2;     //　K1、K2、K3分别接旋转编码器的CLK、DT、SW
sbit ROTARY_ENCODER_DT=P2^1;
sbit ROTARY_ENCODER_SW=P2^0;


#endif
