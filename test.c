#include <stdio.h>
#include <stdbool.h>
#include "src/interface.c"


int main(){

	bool start = 1;

	menu(&start);
	if(start==0){
	
	InitScreen();
	PrintScreen();
	border();
	DrawSprite(sprite1);
	for(int i=0; i<30; i++){
		RandSprite();
	}
	}
}

