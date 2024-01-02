#include "funzioni.h"
#include <time.h>
#include <windows.h>

void InitPlayer(struct Player* player){ //Funzione che mina i bit coin
    player->Credit = 1000;
    player->day = 0;
    player->Inv = malloc(sizeof(int)*ArrayLenght(FoodNames));

    int i;
    for(i = 0; i < ArrayLenght(FoodNames); i++){
        player->Inv[i] = 0;
    }
}

struct Client NewClient(){
    struct Client client;

    srand(time(NULL));

    int numOrders = rand() % 4+1;

    client.order = (char**)malloc(sizeof(char*)*numOrders);
    int i;
    for(i = 0; i < numOrders; i++){
        int item = rand() %  ArrayLenght(FoodNames) + 0;
        client.order[i] = malloc(sizeof(char)*strlen(FoodNames[item])+1);
        strcpy(client.order[i],FoodNames[item]);
    }
    int randName = rand() % ArrayLenght(ClientNames) + 0;
    client.name = malloc(sizeof(char)*strlen(ClientNames[randName])+1);

    strcpy(client.name,ClientNames[randName]);

    return client; 
}

void printClient(struct Client* client){
    printf("%s\n",client->name);
    int i;
    for(i = 0; i < 4; i++){
        printf("%s\n",client->order[i]);
    }
}

int Input(int* sel, int sceltaMax){
    if(kbhit()){
        char ch = getch();
        switch(ch){
            case 'w':
                if(sel > 0)
                    sel-=1;
                return 1;
            break;
            case 's':
                if(sel < sceltaMax)
                    sel+=1;
                return 1;
            break;
            case 13:
                return 2;
            break;
            default:
                return 0;
            break;
            
        }
    }
    return 0;
}
                            //mi dimetto (finally)
void Shop(struct Player* player){
    int quit = 0;
    int sel = 0;

    while(!quit){
        int sel2 = Input(&sel,ArrayLenght(FoodNames));
        
        switch(sel2){
            case 1:
                //far vedere a video la selezione con >
            break;
            case 2:
                //scrivere a video quanta roba vuoi coglione
                char* quantString;
                unsigned int quantInt = 0;
                do{
                    scanf("%s", quantString);
                    while(*quantString != '\0'){
                        if(*quantString >= '0' && *quantString <= '9'){
                            quantInt *= 10;
                            quantInt = *quantString - '0';
                        }
                        quantString++;
                    }
                }while(quantInt < 1 || quantInt > 100);

                if(FoodPrice[sel] * quantInt <= player->Credit){
                    player->Credit -= FoodPrice[sel] * quantInt;
                    player->Inv[sel] += quantInt;
                } else{
                    printf("\nNon puoi permetterti %d %s\n",quantInt,FoodNames[sel]);
                    Sleep(1);
                }
                quit = 1;
            break;
            default:
            break;
        }
    }
}

