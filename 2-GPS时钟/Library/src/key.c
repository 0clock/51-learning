#include "key.h"

void FirstMenukey()
{
	if(key1==0)
		{
			Delay10ms();Delay10ms();Delay10ms();Delay10ms();
			if(key1==0)
			{
				MenuFirst_Flag++;
				if(MenuFirst_Flag==5)
					{
						MenuFirst_Flag=1;	
						Delay10ms();Delay10ms();Delay10ms();Delay10ms();
					}
					while(!key1);
			}
		}
}

