//
// Created by Jay on 2022/6/11.
//
#ifndef __DHT11_H
#define __DHT11_H
#include"intrins.h"
#include "STC12C5A60S2.H"
#include "delay.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

uchar dat_r[4];          //用于存放从DHT11读取到的数值
sbit DATA=P3^3;   //定义数据线,DHT11的2脚，2脚要上拉5.1K电阻

#endif //__DHT11_H
