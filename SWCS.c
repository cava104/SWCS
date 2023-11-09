#include <stdio.h>
#include "src/data.c"
//Star Wars: Cantina Simulator V0.002

int main(){
	struct Bar Bar;
    Bar.Money = 5;
    Bar.level = 1;
    Bar.Inv = NULL;

    printf("%d\n%d\n%d\n",Bar.Money,Bar.level,Bar.Inv);

    SaveData(1,&Bar);

    struct Bar Test;

    if(LoadData(1,&Test) < 1){
        printf("Loading Data Failed!");
        return -1;
    }

    printf("%d\n%d\n%d",Test.Money,Test.level,Test.Inv);
}
