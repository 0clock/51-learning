/*
	用0.96寸OLED显示屏显了GPS模块得到的时间
	使用了一个按键用来切换OLED显示屏的不同界面
	用一块TFT彩屏显示了一张图片
	编写时间：2022-3-10
*/

#include "main.h"

void main(){
	OLED_Init();
	OLED_Clear();
	OLED_DrawBMP(0,0,128,8,(unsigned char *)Apple_Logo);//开机动画-苹果logo
	Lcd_Init(); 
	LCD_Clear(BLACK);
	LCD_ShowPicture(0,0,160,80,(unsigned char *)gImage_NASA);
	Init_BMP280();
	bmp280Convert();
	Uart_Init();
	Delay10ms();
	while(1){
		GUI_MainFuction();
	}
}