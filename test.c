#include <stdio.h>
#include "src/interface.c"


int main(){
    InitScreen();
	border();
	DrawSprite(sprite1, 30, 10);

	PrintScreen();
	for(int i=0; i<30; i++){
		RandSprite();
	}
}
