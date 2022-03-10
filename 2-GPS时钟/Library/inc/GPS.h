#ifndef _GPS_H_
#define _GPS_H_

#include <reg52.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "oled.h"

#define false 0
#define true 1
#define   uchar unsigned char
#define   uint unsigned int
//定义数组长度
#define GPS_Buffer_Length 80
#define UTCTime_Length 11
#define latitude_Length 11
#define N_S_Length 2
#define longitude_Length 12
#define E_W_Length 2 



typedef struct SaveData 
{
	char GPS_Buffer[GPS_Buffer_Length];
	char isGetData;		//是否获取到GPS数据
	char isParseData;	//是否解析完成
	char UTCTime[UTCTime_Length];		//UTC时间
	char latitude[latitude_Length];		//纬度
	char N_S[N_S_Length];		//N/S
	char longitude[longitude_Length];		//经度
	char E_W[E_W_Length];		//E/W
	char isUsefull;		//定位信息是否有效
} xdata _SaveData;

#define gpsRxBufferLength  76
extern char idata gpsRxBuffer[gpsRxBufferLength];
extern unsigned char RX_Count;
extern _SaveData Save_Data;

void GPS_Handle(void);
void Uart_Init();
void clrStruct();


#endif
