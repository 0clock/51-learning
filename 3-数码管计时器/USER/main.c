#include "main.h"

uint TIME[8];

void main(){
	InitDS1302();
	while(1){
		DigDisplay(0,(23&0x01));
	}
}