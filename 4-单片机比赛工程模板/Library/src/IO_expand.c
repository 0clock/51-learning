#include "IO_expand.h"
//**************************************************************************************************
//向74HC595写一字节数据
//**************************************************************************************************
void wbyte_595(uchar temp)               
 {
     uchar i;                      //定义循环变量
     ST_CP=0;                      //置为低电平
     for(i=0;i<8;i++)              //循环8次，写入1字节
      {
       SH_CP=0;                    //时钟置为低电平
       if((temp & 0x80)!=0)  DS=1; //如果最高位为1，发送数据1
         else DS=0;                //如果最高位为0，发送数据0
       SH_CP=1;                    //数据在SHcp的上升沿输入到移位寄存器中
       temp<<=1;                   //左移1位，准备写入下1位数据
      }
    ST_CP=1;                       //上升沿时移位寄存器的数据进入数据存储寄存器
    delay(10);                     //延时
 }


//**************************************************************************************************
//138 低电平位置 0-7  大于7关闭
//**************************************************************************************************
void wbyte_138(uchar temp) 
{
	if(temp>7){
		HC138_EN=0;
		return ;
	}

	HC138_EN=1;
	HC138_A = temp;		 //最低位
	HC138_B = temp>>1;
	HC138_C = temp>>2;	 //最高位

}

