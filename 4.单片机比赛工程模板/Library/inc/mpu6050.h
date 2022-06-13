//
// Created by Jay on 2022/6/11.
//

#ifndef __MPU6050_H
#define __MPU6050_H

#include <STC12C5A60S2.H>
#include <math.h>    //Keil library
#include <stdio.h>   //Keil library
#include"intrins.h"
#include "delay.h"


#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

//****************************************
// 定义51单片机端口
//****************************************
#define DataPort P0		//LCD1602数据端口
sbit    SCL=P1^0;			//IIC时钟引脚定义
sbit    SDA=P1^1;			//IIC数据引脚定义
//****************************************
// 定义MPU6050内部地址
//****************************************
#define	SMPLRT_DIV		0x19	//陀螺仪采样率，典型值：0x07(125Hz)
#define	CONFIG			0x1A	//低通滤波频率，典型值：0x06(5Hz)
#define	GYRO_CONFIG		0x1B	//陀螺仪自检及测量范围，典型值：0x18(不自检，2000deg/s)
#define	ACCEL_CONFIG	0x1C	//加速计自检、测量范围及高通滤波频率，典型值：0x01(不自检，2G，5Hz)
#define	ACCEL_XOUT_H	0x3B
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42
#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48
#define	PWR_MGMT_1		0x6B	//电源管理，典型值：0x00(正常启用)
#define	WHO_AM_I			0x75	//IIC地址寄存器(默认数值0x68，只读)
#define	SlaveAddress	0xD0	//IIC写入时的地址字节数据，+1为读取
//****************************************
//定义类型及变量
//****************************************

//int	Temperature,Temp_h,Temp_l;	//温度及高低位数据
//****************************************
//函数声明
//****************************************
void  delay(unsigned int k);										//延时
void  lcd_printf(uchar *s,int temp_data);

//MPU6050操作函数
void  InitMPU6050();													//初始化MPU6050
void  I2C_Start();
void  I2C_Stop();
void  I2C_SendACK(bit ack);
bit   I2C_RecvACK();
void  I2C_SendByte(uchar dat);
uchar I2C_RecvByte();
void  I2C_ReadPage();
void  I2C_WritePage();

uchar Single_ReadI2C(uchar REG_Address);				 //读取I2C数据
void  Single_WriteI2C(uchar REG_Address,uchar REG_data);	//向I2C写入数据

int GetData(uchar REG_Address);
#endif //__MPU6050_H
