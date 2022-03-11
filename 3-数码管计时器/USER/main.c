#include "main.h"

uint TIME[8];

void main(){
	InitDS1302();
	while(1){
		DigDisplay(2, DS1302SingleRead(5));
	}
}