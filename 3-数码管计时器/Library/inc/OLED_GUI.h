#ifndef _OLED_GUI_H
#define _OLED_GUI_H	

#include "delay.h"
#include "key.h"
#include "BMP.h"
#include "oled.h"
#include "bme280.h"
#include "GPS.h"

extern unsigned int MenuFirst_Flag;
extern unsigned int MenuFirst_Top_Flag;

void GUI_Init(void);
void GUI_MainFuction(void);


#endif	