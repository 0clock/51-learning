/*********************************************************************************************************
** 文件功能 ：AT24C02 驱动程序
** 文件说明 ：AT24C02的的三位地址线全部接地，故其地址为0xa0
** 工程作者 ：Blue Sky Teams——ZZL
** 工程版本 ：V1.0
*********************************************************************************************************/
#ifndef _AT24C02_H_
#define _AT24C02_H_

  #ifndef uchar
	#define uchar unsigned char
  #endif

  #ifndef uint
	#define uint  unsigned int
  #endif

#include"intrins.h"
#include "STC12C5A60S2.H" 


sbit AT24C02_SDA=P2^7;//双向数据端口
sbit AT24C02_SCL=P2^6;//串行时钟
/*********************************************************************************************************
** 函数功能 ：IIC起始信号
** 函数说明 ：SCL线为高电平期间，SDA线由高电平向低电平的变化表示起始信号
** 入口参数 ：无
** 出口参数 ：无 
*********************************************************************************************************/
extern void AT24C02_Start();


/*********************************************************************************************************
** 函数功能 ：IIC终止信号
** 函数说明 ：SCL线为高电平期间，SDA线由低电平向高电平的变化表示终止信号。
** 入口参数 ：无
** 出口参数 ：无 
*********************************************************************************************************/
extern void AT24C02_Stop();


/*********************************************************************************************************
** 函数功能 ：IIC应答信号
** 函数说明 ：等待应答即SDA为低，若等待一定时间还没应答，默认为接受完了
** 入口参数 ：无
** 出口参数 ：无 
*********************************************************************************************************/
extern void AT24C02_Ack();

/*********************************************************************************************************
** 函数功能 ：发送一个字节
** 入口参数 ：dat：待发送的字节
** 出口参数 ：无
*********************************************************************************************************/
extern void AT24C02_Write_Byte(dat);

/*********************************************************************************************************
** 函数功能 ：接收一个字节
** 入口参数 ：无
** 出口参数 ：dat：接收到的字节
*********************************************************************************************************/
extern uchar AT24C02_Read_Byte();

/*********************************************************************************************************
** 函数功能 ：AT24C02的初始化函数
** 函数说明 ：AT24C02初始化时SCL、SDA均为高电平
** 入口参数 ：无
** 出口参数 ：无 
*********************************************************************************************************/
extern void AT24C02_Init();

/*********************************************************************************************************
** 函数功能 ：随机地址存储字节
** 函数说明 ：随机写入一个地址，将字节存在那个地址上
** 入口参数 ：dat：待存储的字节
**            add：存储字节的地址
** 出口参数 ：无 
*********************************************************************************************************/
extern void AT24C02_Write_Add(uchar dat,uchar add);

/*********************************************************************************************************
** 函数功能 ：随机地址读取字节
** 函数说明 ：写入一个地址，读取这个地址上的字节
** 入口参数 ： add：待读取字节的地址        
** 出口参数 ：无 
*********************************************************************************************************/
extern uchar AT24C02_Read_Add(uchar add);

/*********************************************************************************************************
** 函数功能 ：随机地址读取一页
** 函数说明 ：页写方式，地址必须满足页方式，才能被全部写进EEPROM；
**            如地址要为0x00,0x08，0x10这样写入的8个字节才能全部写进去，否则如写0x01则写入数据最后一个将无法写进！
** 入口参数 ：add：待存储字符串的地址
**            dat：待存储的字符串       
** 出口参数 ：无 
*********************************************************************************************************/
extern void AT24C02_Write_Page(uchar *dat,uchar add);

/************************** (C) COPYRIGHT 2011 Blue Sky Teams *****END OF FILE*****************************/   

#endif

/*
void main()
{
	uchar temp;
	LCD_1602_Init();
	AT24C02_Init();		 //I2C总线初始化
	Write_Add('A',0x03);//向AT24C02内部地址为0x03处写入一个字节的数据
	Delay_Ms(100);
	temp = Read_Add(0x03); //从AT24C02内部地址为0x03处读出刚写入的数据
	Write_1602_String("The data is:",0x80);
	Write_1602_Data(temp); 
	while(1)
	{
				
	}		
}
*/
