#include "iic.h"


void iic_start()   
{
  SDA=1;
  SCL=1;
  Delay5us();
  SDA=0;
  Delay5us();
  SCL=0;
}

void iic_stop()  
{
  SDA=0;
  SCL=1;
  Delay5us();
  SDA=1;
  Delay5us();
  SCL=0;
}

void iic_ack()   
{
  uchar i=0;
  SCL=1;
  Delay5us();
  while((SDA==1) && (i<255))
			i++;
	SCL=0;
	Delay5us();
}

void iic_send_byte(uchar bat)  
{
  uchar i,temp;
  temp=bat;
  for(i=0;i<=7;i++)
  {
    temp=temp<<1;
    SCL=0;
    SDA=CY;
    Delay5us();
    SCL=1;
    Delay5us();
  }
  SCL=0;
  Delay5us();
  SDA=1;
  Delay5us();
}

unsigned char iic_rev()  
{
  uchar temp,i;
  SCL=0;
  Delay5us();
  SDA=1;
  for(i=0;i<=7;i++)
  {
   SCL=1;
   Delay5us();
   temp=(temp<<1)|SDA;
   SCL=0;
   Delay5us();
  }
  Delay5us();
  return temp;
}
