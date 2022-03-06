#ifndef _BME280_H_
#define _BME280_H_

#include "reg52.h"
#include "delay.h"
#include  "stdint.h"
#include  <math.h>     
#include "iic.h"

extern long  temperature;
extern long  pressure;
extern long  height;
extern long  humidity;

void Init_BMP280();//初始化BMP180
long bmp280Convert(void);//數據轉換


#endif
