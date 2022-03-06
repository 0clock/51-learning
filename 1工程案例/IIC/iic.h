#ifndef _IIC_H_
#define _IIC_H_

#include "reg52.h"
#include "delay.h"

#define   uchar unsigned char
#define   uint unsigned int

sbit SCL = P1^1 ;	
sbit SDA  = P1^0 ; 

void iic_start();
void iic_stop();
void iic_ack();
void iic_send_byte(uchar bat);
unsigned char iic_rev();
 

#endif
