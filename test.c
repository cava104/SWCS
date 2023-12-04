#include <stdio.h>
#include "src/interface.c"


int main(){
    InitScreen();
	border();
	PrintScreen();
	DrawSprite(sprite, 10, 10);
	
	PrintScreen();


}
