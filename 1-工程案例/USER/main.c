#include "config.h"

void main()
{
	OLED_Init();
	OLED_Clear();
	OLED_DrawBMP(0,0,128,8,(unsigned char *)Apple_Logo);
	Lcd_Init(); 
	LCD_Clear(BLACK);
	LCD_ShowPicture(0,0,160,80,(unsigned char *)gImage_NASA);
	Init_BMP280();
	bmp280Convert();
	Uart_Init();
	Delay10ms();
	while(1)
	{
		GUI_MainFuction();
		//LCD_ShowPicture(0,0,160,80,(unsigned char *)gImage_WXJB);
	}
}

