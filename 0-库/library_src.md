# 51单片机库源码

## 输入设备

### 1.  按键;key.c\key.h

```c
//key.c
/**
  * @brief  获取独立按键键码
  * @param  无
  * @retval 按下按键的键码，范围：0~4，无按键按下时返回值为0
  */
unsigned char Keyscan(){
	unsigned char KeyNumber=0;
	if(P3_1==0){Delay(20);while(P3_1==0);Delay(20);KeyNumber=1;}
	if(P3_0==0){Delay(20);while(P3_0==0);Delay(20);KeyNumber=2;}
	if(P3_2==0){Delay(20);while(P3_2==0);Delay(20);KeyNumber=3;}
	if(P3_3==0){Delay(20);while(P3_3==0);Delay(20);KeyNumber=4;}
	return KeyNumber;
}
key.h
#ifndef __KEY_H__
#define __KEY_H__
unsigned char Keyscan();
#endif
```

