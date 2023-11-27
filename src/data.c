#include "funzioni.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
    
#define DataPath "data/Save"

int SaveData(int currentSlot,struct Bar* bar){
    char* str  = malloc(2);
    sprintf(str,"%d",currentSlot);
    char* SavePath = (char*)malloc(strlen(DataPath)+strlen(str)+4);
    strcpy(SavePath,DataPath);
    strcat(SavePath,str);
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
    strcat(LoadPath,DataPath);
    strcat(LoadPath,str);
    strcat(LoadPath,".txt");
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
    strcat(findFile,".txt");

    FILE* file = fopen(findFile,"r");

    if(file == NULL){
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
	printf("v0.003\n");
    int i;

    char ch;
    switch(ch = getch()){
        case '1':
        	system("cls");
            printf("Seleziona lo slot di salvataggio:\n");
            for(i = 1; i <= 5; i++){
                if(FileExist(i) == true){
                    printf("%d) Slot %d\n",i,i);
                }
                else printf("%d) | SLOT VUOTO |\n",i);
            }
        break;

        case '2':
        	system("cls");
            printf("Seleziona lo slot:\n");
            for(i = 1; i <= 5; i++){
                if(FileExist(i) == true){
                    printf("%d) Slot %d\n",i,i);
                }
                else printf("%d) | SLOT VUOTO |\n",i);
            }
        break;

        default:
        MainMenu(bar);
        break;
    }
}
