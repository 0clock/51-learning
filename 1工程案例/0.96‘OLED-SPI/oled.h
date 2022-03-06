//////////////////////////////////////////////////////////////////////////////////	 

//  功能描述   : OLED 4接口演示例程(51系列)
//              说明: 
//              ----------------------------------------------------------------
//              GND    电源地
//              VCC  接5V或3.3v电源
//              D0   P1^0（SCL）
//              D1   P1^1（SDA）
//              RES  接P12
//              DC   接P13
//              CS   接P14               
//******************************************************************************/

#ifndef __OLED_H
#define __OLED_H			  	

#include "reg52.h" 
//#include "sys.h"
//#include "stdlib.h"	  
#define   uchar unsigned char
#define   uint unsigned int
#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据
#define OLED_MODE 0

sbit OLED_CS=P3^3; //片选
sbit OLED_RST =P3^5;//复位
sbit OLED_DC =P3^4;//数据/命令控制
sbit OLED_SCL=P3^7;//时钟 D0（SCLK?
sbit OLED_SDIN=P3^6;//D1（MOSI） 数据


#define OLED_CS_Clr()  OLED_CS=0
#define OLED_CS_Set()  OLED_CS=1

#define OLED_RST_Clr() OLED_RST=0
#define OLED_RST_Set() OLED_RST=1

#define OLED_DC_Clr() OLED_DC=0
#define OLED_DC_Set() OLED_DC=1

#define OLED_SCLK_Clr() OLED_SCL=0
#define OLED_SCLK_Set() OLED_SCL=1

#define OLED_SDIN_Clr() OLED_SDIN=0
#define OLED_SDIN_Set() OLED_SDIN=1;





//OLED模式设置
//0:4线串行模式
//1:并行8080模式

#define SIZE 12
#define XLevelL		0x02
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  
//-----------------OLED端口定义----------------  					   

void delay_ms(unsigned int ms);


 		     

//OLED控制用函数
void OLED_WR_Byte(uchar dat,uchar cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);

//清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!	 
void OLED_Clear(void);
void OLED_DrawPoint(uchar x,uchar y,uchar t);
void OLED_Fill(uchar x1,uchar y1,uchar x2,uchar y2,uchar dot);


void OLED_ShowChar(uchar x,uchar y,uchar chr);

//显示2个数字
void OLED_ShowNum(uchar x,uchar y,uint num,uchar len,uchar size2);

//显示一个字符号串
void OLED_ShowString(uchar x,uchar y, uchar *p);	 

void OLED_Set_Pos(unsigned char x, unsigned char y);

//显示汉字
void OLED_ShowCHinese(uchar x,uchar y,uchar no);

//功能描述：显示显示BMP图片128×64起始点坐标(x,y),x的范围0～127，y为页的范围0～7//
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
#endif  
	 



