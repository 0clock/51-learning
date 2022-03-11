#ifndef _DS1302_H_
#define _DS1302_H_

#include "REG52.h"

/* 用单次读操作从某一寄存器读取一个字节，reg-寄存器地址，返回值-读到的字节 */
unsigned char DS1302SingleRead(unsigned char reg);

/* DS1302初始化，如发生掉电则重新设置初始时间 */
void InitDS1302();

/* 获取实时时间，即读取DS1302当前时间并转换为时间结构体格式 */
void GetRealTime(struct sTime *time);

/* 设定实时时间，时间结构体格式的设定时间转换为数组并写入DS1302 */
void SetRealTime(struct sTime *time);


#endif
