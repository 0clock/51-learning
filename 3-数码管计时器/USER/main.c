#include "main.h"

struct sTime {  //日期时间结构体定义
    unsigned int  year;
    unsigned char mon;
    unsigned char day;
    unsigned char hour;
    unsigned char min;
    unsigned char sec;
    unsigned char week;
};
struct sTime bufTime;  //日期时间缓冲区

void main(){
	InitDS1302();
	GetRealTime(&bufTime);
	while(1){
		GetRealTime(&bufTime);
		DigDisplay(0,bufTime.sec & 0x0F);
	}
}