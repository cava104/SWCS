#include "funzioni.h"
#include <stdlib.h:
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
    struct Client* client;

    srand(time(NULL));

    int numOrders = rand % 1+4;

    client->orders = (char*)malloc(sizeof(char));
    int i;
    for(i = 0; i < numOrders; i++){
        int item = rand % 0 + ArrayLenght(FoodNames);
        client->orders[i] = malloc(sizeof(char)*strlen(FoodNames[item]+1));
        strcpy(client->orders[i],FoodNames[item]);
    }
    int randName = rand % 0+ ArrayLenght(Names);
    client->name = malloc(sizeof(char)*name[randName]+1);

    strcpy(client->name,Names[randName]);

    return client; 
}

void printClient(struct Client* client){
    printf("%s\n"client->name);
    int i;
    for(i = 0; i < 4; i++){
        printf("%s1n",client->order[i]);
    }
}