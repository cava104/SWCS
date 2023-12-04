#include "funzioni.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
    
#define DataPath "data/"

char IntToChar(int val){
   return char ch = '0' + val; 
}

int SaveData(int currentSlot,struct Bar* bar){
    char* str  = malloc(2);
    sprintf(str,"%d",currentSlot);
    char* SavePath = (char*)malloc(strlen(DataPath)+strlen(str)+4);
    strcpy(SavePath,DataPath);
    strcat(SavePath,"Save-");
    strcat(SavePath,IntToChar(currentSlot));
    strcat(SavePath,".txt");
    FILE* Save = fopen(SavePath,"wb");

    if(!Save){
        printf("Couldn't Save:\n");
        free(SavePath);
        return -1;
    }
    fwrite(bar,sizeof(struct Bar),1,Save);
    fclose(Save);
    free(SavePath);
    return 1;
}

int LoadData(int Slot,struct Bar* bar){
    char* str = malloc(2);
    sprintf(str,"%d",Slot);
    char* LoadPath = (char*)malloc(strlen(DataPath)+strlen(str)+4);
    strcpy(SavePath,DataPath);
    strcat(SavePath,"Save-");
    strcat(SavePath,IntToChar(currentSlot);
    strcat(SavePath,".txt");
    FILE* Load = fopen(LoadPath,"rb");

    if(!Load){
        perror("");
        free(LoadPath);
        return -1;
    }

    fread(bar, sizeof(struct Bar), 1, Load);

    fclose(Load);
    free(LoadPath);
    return 1;
}

bool FileExist(int Slot){
    char* str = malloc(2);
    sprintf(str,"%d",Slot);
    char* findFile = (char*)malloc(strlen(DataPath)+strlen(str)+4);
    strcpy(SavePath,DataPath);
    strcat(SavePath,"Save-");
    strcat(SavePath,IntToChar(currentSlot);
    strcat(SavePath,".txt");

    FILE* file = fopen(findFile,"r");

    if(file == NULL){
        return false;
    }
    free(findFile);
    return true;
}