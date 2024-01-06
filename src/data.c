#include "funzioni.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
    
#define DataPath "data/"

char* IntToChar(int val){
    static char ch[2];
    ch[0] = '0' + val;
    ch[1] = '\0';
    return ch;
}

int SaveData(int Slot,struct Player* player){
    char* fullpath = (char*)malloc(strlen(DataPath)+12);
    strcpy(fullpath,DataPath);
    strcat(fullpath,"Save-");
    strcat(fullpath,IntToChar(Slot));
    strcat(fullpath,".txt");
    FILE* Save = fopen(fullpath,"wb");
    if(!Save){
        printf("Couldn't Save:\n");
        free(fullpath);
        return -1;
    }
    fwrite(player,sizeof(struct Player),1,Save);
    fclose(Save);
    free(fullpath);
    return 1;
}

int LoadData(int Slot,struct Player* player){
    char* str = malloc(2);
    sprintf(str,"%d",Slot);
    char* fullpath = (char*)malloc(strlen(DataPath)+12);
    strcpy(fullpath,DataPath);
    strcat(fullpath,"Save-");
    strcat(fullpath,IntToChar(Slot));
    strcat(fullpath,".txt");
    FILE* Load = fopen(fullpath,"rb");

    if(!Load){
        perror("");
        free(fullpath);
        return -1;
    }

    fread(player, sizeof(struct Player), 1, Load);

    fclose(Load);
    free(fullpath);
    return 1;
}

bool FileExist(int Slot){ //la usi nel menu per vedere i salvataggi
    char* fullpath = (char*)malloc(strlen(DataPath)+12);
    strcpy(fullpath,DataPath);
    strcat(fullpath,"Save-");
    strcat(fullpath,IntToChar(Slot));
    strcat(fullpath,".txt");

    FILE* file = fopen(fullpath,"r");

    if(file == NULL){
        return false;
    }
    free(fullpath);
    fclose(file);
    return true;
}