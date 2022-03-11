#include "OLED_GUI.h"
	
unsigned int MenuFirst_Flag=1;
unsigned int MenuFirst_Top_Flag=1;
unsigned int OLED_Clean=0;
unsigned int hour=0;
unsigned int TrueMenu_Flag=1;

void GUI_NumDisplay(uint x,uint y,uint num)
{
	switch(num)
	{
		case 0 : OLED_DrawBMP(x,y,x+14,y+3,(unsigned char *)Num_0); break;
		case 1 : OLED_DrawBMP(x,y,x+14,y+3,(unsigned char *)Num_1); break;
		case 2 : OLED_DrawBMP(x,y,x+14,y+3,(unsigned char *)Num_2); break;
		case 3 : OLED_DrawBMP(x,y,x+14,y+3,(unsigned char *)Num_3); break;
		case 4 : OLED_DrawBMP(x,y,x+14,y+3,(unsigned char *)Num_4); break;
		case 5 : OLED_DrawBMP(x,y,x+14,y+3,(unsigned char *)Num_5); break;
		case 6 : OLED_DrawBMP(x,y,x+14,y+3,(unsigned char *)Num_6); break;
		case 7 : OLED_DrawBMP(x,y,x+14,y+3,(unsigned char *)Num_7); break;
		case 8 : OLED_DrawBMP(x,y,x+14,y+3,(unsigned char *)Num_8); break;
		case 9 : OLED_DrawBMP(x,y,x+14,y+3,(unsigned char *)Num_9); break;
		default: OLED_DrawBMP(x,y,x+14,y+3,(unsigned char *)Num_0); break;
	}
}

void GUI_Print()
{
	if(gpsRxBuffer[1]=='B')
	{
	OLED_ShowChar(0,0,gpsRxBuffer[0]);
	OLED_ShowChar(10,0,gpsRxBuffer[1]);
	OLED_ShowChar(20,0,gpsRxBuffer[2]);
	OLED_ShowChar(30,0,gpsRxBuffer[3]);
	OLED_ShowChar(40,0,gpsRxBuffer[4]);
	OLED_ShowChar(50,0,gpsRxBuffer[5]);
	OLED_ShowChar(60,0,gpsRxBuffer[6]);
	OLED_ShowChar(70,0,gpsRxBuffer[7]);
	OLED_ShowChar(80,0,gpsRxBuffer[8]);
	}
	if((gpsRxBuffer[1]=='B')&&(gpsRxBuffer[5]=='V'))
	{
	OLED_ShowChar(0,2,gpsRxBuffer[0]);
	OLED_ShowChar(10,2,gpsRxBuffer[1]);
	OLED_ShowChar(20,2,gpsRxBuffer[2]);
	OLED_ShowChar(30,2,gpsRxBuffer[3]);
	OLED_ShowChar(40,2,gpsRxBuffer[4]);
	OLED_ShowChar(50,2,gpsRxBuffer[5]);
	OLED_ShowChar(60,2,gpsRxBuffer[6]);
	OLED_ShowChar(70,2,gpsRxBuffer[7]);
	OLED_ShowChar(80,2,gpsRxBuffer[8]);
	OLED_ShowChar(90,2,gpsRxBuffer[9]);
	OLED_ShowChar(100,2,gpsRxBuffer[10]);
	OLED_ShowChar(110,2,gpsRxBuffer[11]);
	OLED_ShowChar(120,2,gpsRxBuffer[12]);
	}
	if((gpsRxBuffer[2]=='N')&&(gpsRxBuffer[5]=='C'))
	{
	OLED_ShowChar(0,4,gpsRxBuffer[0]);
	OLED_ShowChar(10,4,gpsRxBuffer[1]);
	OLED_ShowChar(20,4,gpsRxBuffer[2]);
	OLED_ShowChar(30,4,gpsRxBuffer[3]);
	OLED_ShowChar(40,4,gpsRxBuffer[4]);
	OLED_ShowChar(50,4,gpsRxBuffer[5]);
	OLED_ShowChar(60,4,gpsRxBuffer[7]);
	OLED_ShowChar(70,4,gpsRxBuffer[8]);
	OLED_ShowChar(80,4,gpsRxBuffer[9]);
	OLED_ShowChar(90,4,gpsRxBuffer[10]);
	OLED_ShowChar(100,4,gpsRxBuffer[11]);
	OLED_ShowChar(110,4,gpsRxBuffer[12]);
	}else
	{
		OLED_ShowString(0,6, "error :(");	 
	}
}
void GUI_DisBMP280(void)
{
	bmp280Convert();
	OLED_ShowString(0,-1, "BMP280:");
	OLED_ShowString(0,0, "Tem:");	
	//OLED_ShowChar(40,0,temperature);
	OLED_ShowNum(36,0,temperature/100,2,16);
	OLED_ShowString(52,0, ".");
	OLED_ShowNum(58,0,temperature%100,2,16);
	OLED_ShowString(78,0, "C");
	OLED_ShowString(0,1, "Hum:");
	OLED_ShowNum(40,1,humidity,4,16);
	OLED_ShowString(78,1, "%");
	OLED_ShowString(0,2, "AP:");
	OLED_ShowNum(40,2,pressure,10,16);
	//OLED_ShowString(78,2, "pa");
	OLED_ShowString(0,3, "Hi:");
	OLED_ShowNum(40,3,height,10,16);
	//OLED_ShowString(78,3, "m");
}

void GUI_DisGPS(void)
{
	GPS_Handle();
	OLED_ShowString(0,0,"UTC:");
	OLED_ShowString(30,0,Save_Data.UTCTime);
	OLED_ShowString(0,1,"Lati&Longi:");
	OLED_ShowString(30,2,Save_Data.latitude);
	OLED_ShowString(100,2,Save_Data.N_S);
	OLED_ShowString(30,3,Save_Data.longitude);
		OLED_ShowString(100,3,Save_Data.E_W);
	
	Delay200ms();
	//GUI_Print();
}

void GUI_TimeDisplay()
{
	uint x=7;
	GPS_Handle();
	if(!OLED_Clean)
		{
			OLED_Clear();
		}
	hour=(Save_Data.UTCTime[0]-'0')*10+(Save_Data.UTCTime[1]-'0')+8;
	if(hour>=24)
  	{
	  	hour %= 24;
		}
	GUI_NumDisplay(x,2,hour/10);
	GUI_NumDisplay(x+16,2,hour%10);//x+16
	OLED_DrawBMP(x+33,3,x+35,5,(unsigned char *)Pixel_Dot);//x+33
	GUI_NumDisplay(x+39,2,Save_Data.UTCTime[2]-'0');//x+38
	GUI_NumDisplay(x+55,2,Save_Data.UTCTime[3]-'0');//x+54
	OLED_DrawBMP(x+73,3,x+75,5,(unsigned char *)Pixel_Dot);//x+71
	GUI_NumDisplay(x+79,2,Save_Data.UTCTime[4]-'0');//x+76
	GUI_NumDisplay(x+95,2,Save_Data.UTCTime[5]-'0');//x+92
	
	
}

void GUI_MenuFirst(void)  //首页一共四页
{
	if(MenuFirst_Flag!=TrueMenu_Flag)  //全局刷新
	{
  	OLED_Clear();
	}
		
	if(MenuFirst_Flag==2)
	{
		OLED_DrawBMP(0,0,128,8,(unsigned char *)BWeLyHqW);
		OLED_Clean=0;
	} else if(MenuFirst_Flag==1) {
		//OLED_DrawBMP(0,0,128,8,(unsigned char *)Time_Logo);
		GUI_TimeDisplay();
		OLED_Clean=1;
	} else if(MenuFirst_Flag==3) {
		GUI_DisBMP280();
		OLED_Clean=1;
	} else if(MenuFirst_Flag==4) {
		GUI_DisGPS();
		OLED_Clean=1;
	}
	TrueMenu_Flag=MenuFirst_Flag;
}


void GUI_MainFuction(void)  //开机后显示主界面
{
		FirstMenukey();
		if(MenuFirst_Top_Flag==1)
		{
			GUI_MenuFirst();  //首页
		}/*else if(MenuFirst_Top_Flag==2)
		{
			GUI_MenuSecond();
		}*/
}