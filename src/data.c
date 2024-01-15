#include "funzioni.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
    
#define DataPath "data/"

int SaveData(struct Player* player){
    char* fullpath = (char*)malloc(strlen(DataPath)+9);
    strcpy(fullpath,DataPath);
    strcat(fullpath,"Save");
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

int LoadData(struct Player* player){
    char* fullpath = (char*)malloc(strlen(DataPath)+9);
    strcpy(fullpath,DataPath);
    strcat(fullpath,"Save");
    strcat(fullpath,".txt");
    FILE* Load = fopen(fullpath,"rb");

    if(!Load){
        perror("");
        free(fullpath);
        return -1;
    }
    
    if(player){
        free(player);
    }
    
    fread(player, sizeof(struct Player), 1, Load);

    fclose(Load);
    free(fullpath);
    return 1;
}

bool FileExist(){ //la usi nel menu per vedere i salvataggi
    char* fullpath = (char*)malloc(strlen(DataPath)+9);
    strcpy(fullpath,DataPath);
    strcat(fullpath,"Save");
    strcat(fullpath,".txt");

    FILE* file = fopen(fullpath,"r");

    if(file == NULL){
        return false;
    }
    free(fullpath);
    fclose(file);
    return true;
}