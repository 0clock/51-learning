
/***************************************************************************************************    
工程名称：	smg_scan
功能描述：	控制数码管8位动态扫描显示01234567 
硬件连接：  用8位杜邦线将J8与J12连接，2位杜邦线分别将J11_0与J15_DS1、J11_1与J15_DS2连接。
维护记录：  2011-8-22
***************************************************************************************************/
#ifndef _DIGITAL_TUBE_H_
#define _DIGITAL_TUBE_H_
#include "STC12C5A60S2.H" 


#ifndef uchar
	#define uchar unsigned char
#endif
#ifndef uint
	#define uint  unsigned int
#endif


#define SMG P1
sbit LE1=P2^0;           //位选573锁存器使能
sbit LE2=P2^1;           //段选573锁存器使能
extern uchar wei;
extern void Delay(uint time);
extern void scan(void); //显示1-8
#endif
