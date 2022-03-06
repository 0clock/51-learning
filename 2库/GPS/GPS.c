#include "GPS.h"

char idata gpsRxBuffer[gpsRxBufferLength];
unsigned char RX_Count = 0;
unsigned dayplus=0;
_SaveData Save_Data;

void Uart_Init()					  			   
{
	SCON = 0X50;  //UART方式1；8位UART
	REN  = 1;     //允许串行口接收数据
	PCON = 0x00;  //SMOD=0;波特率不加倍
	TMOD = 0x20;  //T1方式2，用于产生波特率
	TH1  = 0xFD;  //装初值
	TL1  = 0xFD;
	TR1  = 1;     //启动定时器1
	EA   = 1;     //打开全局中断控制
	ES   = 1;     //打开串行口中断	
	clrStruct();
}


void RECEIVE_DATA(void) interrupt 4 using 3	  		
{ 
	unsigned char temp = 0;
	char i = 0;
	ES=0;
	temp = SBUF;
	RI = 0;
	if(temp == '$')
	{
		RX_Count = 0;	
	}
		
	if(RX_Count <= 5)
	{
	   gpsRxBuffer[RX_Count++] = temp;
	}
	else if(gpsRxBuffer[0] == '$' && gpsRxBuffer[4] == 'M' && gpsRxBuffer[5] == 'C')			//确定是否收到"GPRMC/GNRMC"这一帧数据
	{
		gpsRxBuffer[RX_Count++] = temp;
		if(temp == '\n')									   
		{
			memset(Save_Data.GPS_Buffer, 0, GPS_Buffer_Length);      //清空
			memcpy(Save_Data.GPS_Buffer, gpsRxBuffer, RX_Count); 	//保存数据
			Save_Data.isGetData = true;
			RX_Count = 0;
			memset(gpsRxBuffer, 0, gpsRxBufferLength);      //清空				
		}
		
		if(RX_Count >= 75)
		{
			RX_Count = 75;
			gpsRxBuffer[RX_Count] = '\0';//添加结束符
		}			
	}
	ES=1; 
}

void clrStruct()
{
	Save_Data.isGetData = false;
	Save_Data.isParseData = false;
	Save_Data.isUsefull = false;
	memset(Save_Data.GPS_Buffer, 0, GPS_Buffer_Length);      //清空
	memset(Save_Data.UTCTime, 0, UTCTime_Length);
	memset(Save_Data.latitude, 0, latitude_Length);
	memset(Save_Data.N_S, 0, N_S_Length);
	memset(Save_Data.longitude, 0, longitude_Length);
	memset(Save_Data.E_W, 0, E_W_Length);
	
}

void GPS_Handle(void)
{
	char *subString;
	char *subStringNext;
	char i = 0;
	if (Save_Data.isGetData)
	{
		Save_Data.isGetData = false;		
		for (i = 0 ; i <= 6 ; i++)
		{
			if (i == 0)
			{
				if ((subString = strstr(Save_Data.GPS_Buffer, ",")) == NULL)
						;
			}
			else
			{
				subString++;
				if ((subStringNext = strstr(subString, ",")) != NULL)
				{
					char usefullBuffer[2]; 
					switch(i)
					{
						case 1:memcpy(Save_Data.UTCTime, subString, subStringNext - subString);break;	//获取UTC时间
						case 2:memcpy(usefullBuffer, subString, subStringNext - subString);;break;	//获取UTC时间
						case 3:memcpy(Save_Data.latitude, subString, subStringNext - subString);break;	//获取纬度信息
						case 4:memcpy(Save_Data.N_S, subString, subStringNext - subString);break;	//获取N/S
						case 5:memcpy(Save_Data.longitude, subString, subStringNext - subString);break;	//获取经度信息
						case 6:memcpy(Save_Data.E_W, subString, subStringNext - subString);break;	//获取E/W

						default:break;
					}
					subString = subStringNext;
					Save_Data.isParseData = true;
					if(usefullBuffer[0] == 'A')
						Save_Data.isUsefull = true;
					else if(usefullBuffer[0] == 'V')
						Save_Data.isUsefull = false;

				}
			}
		}
	}
}

