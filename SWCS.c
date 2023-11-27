#include <stdio.h>
#include "src/data.c"
//Star Wars: Cantina Simulator V0.002

int main(){
    struct Bar plr;
    
	SaveData(1,&plr);
    MainMenu(&plr);
}
