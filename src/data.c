#include "funzioni.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DataPath "data/Save"

int SaveData(int currentSlot,struct Bar* Bar){
    char* str  = malloc(2);
    sprintf(str,"%d",currentSlot);
    char* SavePath = (char*)malloc(strlen(DataPath)+7);
    strcat(SavePath,DataPath);
    strcat(SavePath,str);
    strcat(SavePath,".Txt");
    FILE* Save = fopen(SavePath,"wb");

    if(!Save){
        printf("Couldn't Save:\n");
        free(SavePath);
        return -1;
    }
    fwrite(Bar,sizeof(struct Bar),1,Save);
    fclose(Save);
    free(SavePath);
    return 1;
}

int LoadData(int Slot,struct Bar* Bar){
    char* str = malloc(2);
    sprintf(str,"%d",Slot);
    char* LoadPath = (char*)malloc(strlen(DataPath)+6);
    strcat(LoadPath,DataPath);
    strcat(LoadPath,str);
    strcat(LoadPath,".Txt");
    FILE* Load = fopen(LoadPath,"rb");

    if(!Load){
        perror("");
        free(LoadPath);
        return -1;
    }

    fread(Bar, sizeof(struct Bar), 1, Load);

    fclose(Load);
    free(LoadPath);
    return 1;
}