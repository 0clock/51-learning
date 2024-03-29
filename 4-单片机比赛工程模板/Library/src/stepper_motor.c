


#include "stepper_motor.h"

/*******************************************************************************
* 输    入       : Dir 1:正转   0:倒转  >2:停转
* 输    出    	 : 无
 ，每执行一次转动一定角度，执行间隔时间决定速度，可放在定时中断，改变中断时间
*******************************************************************************/
void stepper_motor(uchar Dir)
{	
	static char phase=0;
	if(Dir<2){
		switch(phase)
		{
		case(0):
			MOTOA = 1;
			MOTOB = 0;
			MOTOC = 0;
			MOTOD = 0;
			break;

		case(1):
			MOTOA = 0;
			MOTOB = 1;
			MOTOC = 0;
			MOTOD = 0;
			break;

		case(2):
			MOTOA = 0;
			MOTOB = 0;
			MOTOC = 1;
			MOTOD = 0;
			break;

		case(3):
			MOTOA = 0;
			MOTOB = 0;
			MOTOC = 0;
			MOTOD = 1;
			break;
		}
	}else{//停转
			MOTOA = 0;
			MOTOB = 0;
			MOTOC = 0;
			MOTOD = 0;
	
	}
	if(Dir==1)
		phase++;
	if(Dir==0)
		phase--;
	
	if(phase>3)
		phase=0;
	if(phase<0)
		phase=3;
}


