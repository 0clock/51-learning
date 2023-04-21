
/***************************************************************************************************    
库名称：	key
作者： Jun
日期：  2023-4-21
***************************************************************************************************/
#include "key.h"      //包含头文件
uchar KeyValue = 16;



//**************************************************************************************************
//矩阵键盘扫描函数
//**************************************************************************************************
void KeyDown(void){
	char a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f){ //读取按键是否按下     
		Delay_Ms(10);//延时10ms进行消抖
		if(GPIO_KEY!=0x0f){//再次检测键盘是否按下
			//测试列
			GPIO_KEY=0X0F;
			switch(GPIO_KEY){
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
			}
			//测试行
			GPIO_KEY=0XF0;
			switch(GPIO_KEY){
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
			while((a<50)&&(GPIO_KEY!=0xf0)){	 //检测按键松手检测
				Delay_Ms(10);
				a++;
			}
		}
	}
} 
/**
  * @brief  获取独立按键键码
  * @param  无
  * @retval 按下按键的键码，范围：0~4，无按键按下时返回值为0
  */
unsigned char KeyScan(){
	unsigned char KeyNumber=0;
	if(key1==0){Delay_Ms(20);while(key1==0);Delay_Ms(20);KeyNumber=1;}
	if(key2==0){Delay_Ms(20);while(key2==0);Delay_Ms(20);KeyNumber=2;}
	if(key3==0){Delay_Ms(20);while(key3==0);Delay_Ms(20);KeyNumber=3;}
	if(key4==0){Delay_Ms(20);while(key4==0);Delay_Ms(20);KeyNumber=4;}
	return KeyNumber;
}
                         

