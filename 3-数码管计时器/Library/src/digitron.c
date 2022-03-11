#include "digitron.h"


uchar code smgduan[16]= {0x3f, 0x06, 0x5b, 0x4f,
											0x66, 0x6d, 0x7d, 0x07,
											0x7f, 0x6f, 0x77, 0x7c,
											0x39, 0x5e, 0x79, 0x71}; //0~F数码
											
void DigDisplay(uchar Location,uchar Number){ //数码管显示函数
	
			switch(Location)
			{
			case 7:
					LSC = 0;LSB = 0;LSA = 0;break; //显示第1个数码管
			case 6:
					LSC = 0;LSB = 0;LSA = 1;break; //显示第2个数码管
			case 5:
					LSC = 0;LSB = 1;LSA = 0;break; //显示第3个数码管
			case 4:
					LSC = 0;LSB = 1;LSA = 1;break; //显示第4个数码管
			case 3:
					LSC = 1;LSB = 0;LSA = 0;break; //显示第5个数码管
			case 2:
					LSC = 1;LSB = 0;LSA = 1;break; //显示第6个数码管
			case 1:
					LSC = 1;LSB = 1;LSA = 0;break; //显示第7个数码管
			case 0:
				LSC = 1;LSB = 1;LSA = 1;break; //显示第8个数码管
			}
			SMG_GPIO= smgduan[Number];//显示1~8的数值
			Delay50us();					 //延时，造成视觉暂留现象
			SMG_GPIO = 0x00; 			//数码管消隐
}	




