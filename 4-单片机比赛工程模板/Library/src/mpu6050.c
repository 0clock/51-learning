//
// Created by Jay on 2022/6/11.
//

#include "mpu6050.h"
void  SeriPushSend(uchar send_data)
{
    SBUF=send_data;
    while(!TI);TI=0;
}
//****************************************
//延时
//****************************************
/*void delay(unsigned int k)
{
    unsigned int i,j;
    for(i=0;i<k;i++)
    {
        for(j=0;j<121;j++);
    }
}*/

//**************************************
//延时5微秒(STC90C52RC@12M)
//不同的工作环境,需要调整此函数
//当改用1T的MCU时,请调整此延时函数
//**************************************

//**************************************
//I2C起始信号
//**************************************
void I2C_Start()
{
    SDA = 1;                    //拉高数据线
    SCL = 1;                    //拉高时钟线
    Delay_Us(5);                 //延时
    SDA = 0;                    //产生下降沿
    Delay_Us(5);                //延时
    SCL = 0;                    //拉低时钟线
}
//**************************************
//I2C停止信号
//**************************************
void I2C_Stop()
{
    SDA = 0;                    //拉低数据线
    SCL = 1;                    //拉高时钟线
    Delay_Us(5);                 //延时
    SDA = 1;                    //产生上升沿
    Delay_Us(5);                 //延时
}
//**************************************
//I2C发送应答信号
//入口参数:ack (0:ACK 1:NAK)
//**************************************
void I2C_SendACK(bit ack)
{
    SDA = ack;                  //写应答信号
    SCL = 1;                    //拉高时钟线
    Delay_Us(5);                 //延时
    SCL = 0;                    //拉低时钟线
    Delay_Us(5);                  //延时
}
//**************************************
//I2C接收应答信号
//**************************************
bit I2C_RecvACK()
{
    SCL = 1;                    //拉高时钟线
    Delay_Us(5);                  //延时
    CY = SDA;                   //读应答信号
    SCL = 0;                    //拉低时钟线
    Delay_Us(5);                  //延时
    return CY;
}
//**************************************
//向I2C总线发送一个字节数据
//**************************************
void I2C_SendByte(uchar dat)
{
    uchar i;
    for (i=0; i<8; i++)         //8位计数器
    {
        dat <<= 1;              //移出数据的最高位
        SDA = CY;               //送数据口
        SCL = 1;                //拉高时钟线
        Delay_Us(5);              //延时
        SCL = 0;                //拉低时钟线
        Delay_Us(5);             //延时
    }
    I2C_RecvACK();
}
//**************************************
//从I2C总线接收一个字节数据
//**************************************
uchar I2C_RecvByte()
{
    uchar i;
    uchar dat = 0;
    SDA = 1;                    //使能内部上拉,准备读取数据,
    for (i=0; i<8; i++)         //8位计数器
    {
        dat <<= 1;
        SCL = 1;                //拉高时钟线
        Delay_Us(5);              //延时
        dat |= SDA;             //读数据
        SCL = 0;                //拉低时钟线
        Delay_Us(5);              //延时
    }
    return dat;
}
//**************************************
//向I2C设备写入一个字节数据
//**************************************
void Single_WriteI2C(uchar REG_Address,uchar REG_data)
{
    I2C_Start();                  //起始信号
    I2C_SendByte(SlaveAddress);   //发送设备地址+写信号
    I2C_SendByte(REG_Address);    //内部寄存器地址，
    I2C_SendByte(REG_data);       //内部寄存器数据，
    I2C_Stop();                   //发送停止信号
}
//**************************************
//从I2C设备读取一个字节数据
//**************************************
uchar Single_ReadI2C(uchar REG_Address)
{
    uchar REG_data;
    I2C_Start();                   //起始信号
    I2C_SendByte(SlaveAddress);    //发送设备地址+写信号
    I2C_SendByte(REG_Address);     //发送存储单元地址，从0开始
    I2C_Start();                   //起始信号
    I2C_SendByte(SlaveAddress+1);  //发送设备地址+读信号
    REG_data=I2C_RecvByte();       //读出寄存器数据
    I2C_SendACK(1);                //接收应答信号
    I2C_Stop();                    //停止信号
    return REG_data;
}
//**************************************
//初始化MPU6050
//**************************************
void InitMPU6050()
{
    Single_WriteI2C(PWR_MGMT_1, 0x00);	//解除休眠状态
    Single_WriteI2C(SMPLRT_DIV, 0x07);
    Single_WriteI2C(CONFIG, 0x06);
    Single_WriteI2C(GYRO_CONFIG, 0x18);
    Single_WriteI2C(ACCEL_CONFIG, 0x01);
}
//**************************************
//合成数据
//**************************************
int GetData(uchar REG_Address)
{
    uchar H,L;
    H=Single_ReadI2C(REG_Address);
    L=Single_ReadI2C(REG_Address+1);
    return (H<<8)+L;   //合成数据
}


/*void init_uart()
{
    TMOD=0x21;
    TH1=0xfd;
    TL1=0xfd;

    SCON=0x50;
    PS=1;      //串口中断设为高优先级别
    TR0=1;	   //启动定时器
    TR1=1;
    ET0=1;     //打开定时器0中断
    ES=1;
    EA=1;
}*/

//*********************************************************
//主程序
//*********************************************************
/*
void main()
{
    delay(500);		//上电延时
//	InitLcd();		//液晶初始化
    init_uart();
    InitMPU6050();	//初始化MPU6050
    delay(150);
    while(1)
    {

        Display10BitData(GetData(ACCEL_XOUT_H),2,0);	//显示X轴加速度
        Display10BitData(GetData(ACCEL_YOUT_H),7,0);	//显示Y轴加速度
        Display10BitData(GetData(ACCEL_ZOUT_H),12,0);	//显示Z轴加速度
        Display10BitData(GetData(GYRO_XOUT_H),2,1);	//显示X轴角速度
        Display10BitData(GetData(GYRO_YOUT_H),7,1);	//显示Y轴角速度
        Display10BitData(GetData(GYRO_ZOUT_H),12,1);	//显示Z轴角速度

        SeriPushSend(0x0d);
        SeriPushSend(0x0a);//换行，回车
        delay(100);
    }
}*/
