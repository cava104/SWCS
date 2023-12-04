#include <stdio.h>
#include "src/interface.c"


int main(){
    InitScreen();
	border();
	DrawSprite(sprite, 30, 10);

	PrintScreen();
}
