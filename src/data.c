#include "funzioni.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <sys/stat.h>
    
#define DataPath "data/Save"

int SaveData(int currentSlot,struct Bar* bar){
    char* str  = malloc(2);
    sprintf(str,"%d",currentSlot);
    char* SavePath = (char*)malloc(strlen(DataPath)+strlen(str)+4);
    strcpy(SavePath,DataPath);
    strcat(SavePath,str);
    strcat(SavePath,".Txt");
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
    strcat(LoadPath,DataPath);
    strcat(LoadPath,str);
    strcat(LoadPath,".Txt");
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
    strcat(findFile,DataPath);
    strcat(findFile,str);
    strcat(findFile,".Txt");

    FILE* file = fopen(findFile,"r");

    if(!file){
        return false;
    }
    free(findFile);
    return true;
}

void MainMenu(struct Bar* bar){
    system("cls");
    printf("Star Wars: Cantina Simulator\n\n");
	printf("1) Nuova Partita:\n");
	printf("2) Carica Partita:\n\n");
	printf("v0.002\n");

    char ch;
    switch(ch = getch()){
        case '1':
            printf("Seleziona lo slot:");
            for(int i = 0; i <= 4; i++){
                if(FileExist(i)){
                    printf("%d) Data %d\n",i,i);
                }
                else printf("%d) Nuova Partita\n",i);
            }
        break;

        case '2':
            printf("Seleziona lo slot:");
            for(int i = 0; i < 4; i++){
                if(FileExist(i)){
                    printf("%d) Data %d\n",i,i);
                }
                else printf("%d) No Data\n",i);
            }
        break;

        default:
        MainMenu(bar);
        break;
    }
}