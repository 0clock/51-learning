#include "main.h"


void main(){
	LCD_12864_Init();
	Hanzi_Disp(0,0,"�ܱ����취���ޱ�");
	Set_12864_Point(1,1,1);
	while(1){
		LCD_12864_DrawLine(0,10,0,100);
		
	}
}