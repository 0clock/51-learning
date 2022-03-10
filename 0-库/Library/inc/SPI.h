#ifndef _SPI_H_
#define _SPI_H_

//#include	<intrinsics.h> 
#include "reg52.h"
#include "oled.h"
#define  u8 unsigned char 
#define  u16 unsigned short
#define  u32 unsigned int 

#define USE_HORIZONTAL  2  //设置横屏或者竖屏显示 0或1为竖屏 2或3为横屏

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 80
#define LCD_H 160

#else
#define LCD_W 160
#define LCD_H 80
#endif

//----------------------------------------------------------------------------------
//LCD 时钟D0
sbit LCD_SCLK_PIN_NUM=P1^7;
#define LCD_SCLk_Set   LCD_SCLK_PIN_NUM=1;//时钟线
#define LCD_SCLK_Clr   LCD_SCLK_PIN_NUM=0;

//----------------------------------------------------------------------------------
//LCD 数据D1
sbit LCD_SDIN_PIN_NUM=P1^6;
#define LCD_SDA_Set   LCD_SDIN_PIN_NUM=1;//数据线
#define LCD_SDA_Clr   LCD_SDIN_PIN_NUM=0;

//----------------------------------------------------------------------------------
//LCD 复位/RES
sbit LCD_RST_PIN_NUM=P1^5;
#define LCD_RES_Set    LCD_RST_PIN_NUM=1;//复位
#define LCD_RES_Clr    LCD_RST_PIN_NUM=0;

//----------------------------------------------------------------------------------
//LCD 数据/命令DC
sbit LCD_DC_PIN_NUM=P1^4;
#define LCD_DC_Set     LCD_DC_PIN_NUM=1;//数据/命令
#define LCD_DC_Clr     LCD_DC_PIN_NUM=0;

//----------------------------------------------------------------------------------
//LCD 片选CS
sbit LCD_CE_PIN_NUM=P1^3;
#define LCD_CS_Set     LCD_CE_PIN_NUM=1;//片选
#define LCD_CS_Clr     LCD_CE_PIN_NUM=0;

//----------------------------------------------------------------------------------
//LCD 背光BLK
sbit LCD_BLK_PIN_NUM=P1^2;
#define LCD_BLK_Set    LCD_BLK_PIN_NUM=1;//背光
#define LCD_BLK_Clr    LCD_BLK_PIN_NUM=0;	


extern  u16 BACK_COLOR;   //背景色		   


//LCD控制用函数

void LCD_Writ_Bus(u8 dat);
void LCD_WR_DATA8(u8 dat);
void LCD_WR_DATA(u16 dat);
void LCD_WR_REG(u8 dat);
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);
void Lcd_Init(void); 
void LCD_Clear(u16 Color);
void LCD_ShowChinese(u16 x,u16 y,u8 index,u8 size,u16 color);
void LCD_DrawPoint(u16 x,u16 y,u16 color);
void LCD_DrawPoint_big(u16 x,u16 y,u16 colory);
void LCD_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 color);
void LCD_DrawLine(u16 x1,u16 y1,u16 x2,u16 y2,u16 color);
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);
void Draw_Circle(u16 x0,u16 y0,u8 r,u16 color);
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 mode,u16 color);
void LCD_ShowString(u16 x,u16 y,const u8 *p,u16 color);
u32 mypow(u8 m,u8 n);
void LCD_ShowNum(u16 x,u16 y,u16 num,u8 len,u16 color);
void LCD_ShowNum1(u16 x,u16 y,float num,u8 len,u16 color);
void LCD_ShowPicture(u16 x,u16 y,u16 sizex,u16 sizey,const u8 pic[]);



//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE           	 0x001F  
#define BRED             0XF81F
#define GRED 			       0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40 //棕色
#define BRRED 			     0XFC07 //棕红色
#define GRAY  			     0X8430 //灰色
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色 
 
#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 			     0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)
#endif  
