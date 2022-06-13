
#ifndef  _MAIN_H_
#define  _MAIN_H_


#include "STC12C5A60S2.H" 	//头文件
#include"intrins.h"


#include "int_it.h"		    // 外部中断

#include "time.h"			//定时中断

#include "usart.h"			//串口

#include "ADC.h"   			//片内ADC

#include "PWM.h"			//PWM输出


#include "HX711.h"         //压力传感器

#include "4_4_key.h" 		//矩阵按键

#include "Digital_tube.h"   // 数码管

#include "AT24C02.h"	    //片外EEPROM

#include "DS18B20.h"   		// 温度传感器

#include "ds1302.h"   		//时钟模块

#include "IO_expand.h" 		//74HC595/138

#include "LCD1602.h"		//LCD1602

#include "parallel_12864.h" // 并行LCD12864

#include "PCF8591.h"		// 片外AD/DA模块

#include "stepper_motor.h"  // 4步进电机

#include "delay.h"

#include "buzz.h"

#include "key.h"

#include "as608.h"

#include "mpu6050.h"






#endif
