#include"delay.h"

 /*********************************************************************************************************
** 函数功能 ：延时函数
** 函数说明 ：利用软件延时，占用CPU，经调试最小单位大约为1us
** 入口参数 ：time:需要延时的时间，单位us
** 出口参数 ：无
*********************************************************************************************************/							   
void Delay_Us(uchar n)
{
    while (n--)
    {
        _nop_();
        _nop_();
    }
}
/*********************************************************************************************************
** 函数功能 ：延时函数
** 函数说明 ：利用软件延时，占用CPU，经调试最小单位大约为1ms
** 入口参数 ：time:需要延时的时间，单位ms
** 出口参数 ：无
*********************************************************************************************************/
void Delay_Ms(uint time)
{
	uint i,j;
	for(i = 0;i < time;i ++)
		for(j = 0;j < 930;j ++);
}


 /*********************************************************************************************************
函数功能 ：延时函数

不知道多久
***********************************************************************************/
void Delay(uint time)             //int型数据为16位,所以最大值为65535            
{
 	uint  i,j;                  //定义变量i,j,用于循环语句 
 	for(i=0;i<time;i++)         //for循环,循环50*time次
    	for(j=0;j<50;j++);       //for循环,循环50次
}
