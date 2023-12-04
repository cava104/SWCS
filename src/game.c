#include "funzioni.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

void InitPlayer(struct Player* player){ //Funzione che mina i bit coin
    player->Credit = 1000;
    player->day = 0;
    player->Inv = malloc(sizeof(int)*ArrayLenght(FoodNames));

    int i;
    for(i = 0; i < ArrayLenght(FoodNames); i++){
        player->Inv[i] = 0;
    }
}

struct Client* NewClient(){
    struct Client* client = (struct Client*)malloc(sizeof(struct Client));

    srand(time(NULL));

    int numOrders = rand() % 4+1;

    client->order = (char**)malloc(sizeof(char*)*numOrders);
    int i;
    for(i = 0; i < numOrders; i++){
        int item = rand() %  ArrayLenght(FoodNames) + 0;
        client->order[i] = malloc(sizeof(char)*strlen(FoodNames[item])+1);
        strcpy(client->order[i],FoodNames[item]);
    }
    int randName = rand() % ArrayLenght(Names) + 0;
    client->name = malloc(sizeof(char)*strlen(Names[randName])+1);

    strcpy(client->name,Names[randName]);

    return client; 
}

void printClient(struct Client* client){
    printf("%s\n",client->name);
    int i;
    for(i = 0; i < 4; i++){
        printf("%s\n",client->order[i]);
    }
}