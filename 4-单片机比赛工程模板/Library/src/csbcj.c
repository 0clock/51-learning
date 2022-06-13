#include<reg52.h>
sbit Trig = P2^0;
sbit Echo = P2^1;
void Delay10us()
{
     TMOD |= 0x1;
     TH0 = 0xFF;
     TL0 = 0xF6;
     TR0 = 1;
     while(!TF0);
     TF0 = 0;
}
void Rstart()  
{
     Trig=0;
     Trig=1;
     Delay10us();
     Trig=0;
}
int gettime()
{
     unsigned int time = 0;
     time = TH0*256+TL0;// TH0<<8 | TL0;
     return time;
}
float Getdis(unsigned int time)  
{
     float distance;
     distance = (float)time * 0.017;
     TH0=0;
     TL0=0;
     return distance;
}
void star()
{
     TH0 = 0;
     TL0 = 0;
     TR0 = 1;
}
void end()
{
     TR0 = 0;
}
void GetOnce()  
{
     Rstart();
     while(!Echo);
     star();
     while(Echo);
     end();
}
void delay()
{
     int i;
     int j;
     for(i=0;i<100;i++)
      for(j = 0;j<2000;j++);
}
