#include "interface.c"
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>

struct Player* InitPlayer(){ //Funzione che mina i bit coin
    struct Player* player = (struct Player*)malloc(sizeof(struct Player));
    player->Credit = 1000;
    player->day = 0;
    player->Inv = malloc(sizeof(int)*ArrayLenght(FoodNames));

    int i;
    for(i = 0; i < ArrayLenght(FoodNames); i++){
        player->Inv[i] = 0;
    }
    return player;
}

struct Client* NewClient(){
    struct Client* client = (struct Client*)malloc(sizeof(struct Client));

    client->numOrders = rand() % 4+1;

    client->order = (char**)malloc(sizeof(char*)*client->numOrders);
    int i,j;
    for(i = 0; i < client->numOrders; i++){
        int item = rand() %  ArrayLenght(FoodNames) + 0;
        client->order[i] = malloc(sizeof(char)*strlen(FoodNames[item])+1);
        strcpy(client->order[i],FoodNames[item]);
    }
    int randName = rand() % ArrayLenght(ClientNames) + 0;
    client->name = malloc(sizeof(char)*strlen(ClientNames[randName])+1);

    int randsprite = rand() % 4;

    for(i = 0; i < SpriteSizeY; i++){
        for(j = 0; j < SpriteSizeX; j++){
            client->sprite[i][j] = sprite[randsprite][i][j];
        }
    }

    strcpy(client->name,ClientNames[randName]);

    return client; 
}

void FreeClient(struct Client* client){
    int i;
    for(i = 0; i < client->numOrders;i++){
        free(client->order[i]);
    }
    free(client);
}

/*void printClient(struct Client* client){
    printf("%s\n",client->name);
    int i;
    for(i = 0; i < 4; i++){
        printf("%s\n",client->order[i]);
    }
}*/

int Input(int* sel, int sceltaMax){
    if(kbhit()){
        char ch = getch();
        switch(ch){
            case 'w':
                if(*sel > 0)
                    *sel-=1;
                return 1;
            break;
            case 's':
                if(*sel < sceltaMax)
                    *sel+=1;
                return 1;
            break;
            case 'e':
                return 2;
            break;
            default:
                return 0;
            break;
        }
    }
    return 0;
}
//non capisco perche esplode ora  
//fa cacare il terminale           
//lo so con linux funziona bene
//windows momento
//fra poco entro a giudicarvi
//la vera domanda è: palle o pisello?   cannone
//la strategia di questo gioco è molto affascinante zap e doma zap e miner zap col gigante
//non mi ricordo il testo
//skill issue

int Menu(mWindow* win){
    int sel = 0,sel2 = 0;
    while(1){   //nn capisco perche crasha odio il c anche io
        if(kbhit()){
            sel2 = Input(&sel,2);
            switch(sel2){
                case 1:
                    int i;
                    for(i = 0; i < 3; i++){
                        if(i == sel)
                            printW(win," >",2,i+4,win->width-1);
                        else 
                            printW(win,"  ",2,i+4,win->width-1);
                    }
                    Refresh(win);
                break;
                case 2:
                    return sel;
                break;
                default:
                break;
            }
        }
        
    }//se ocane ha un cane
}
//non e cambiatouncazo
                            //mi dimetto (finally)
void Shop(mWindow* win,struct Player* player){
    int quit = 0;
    int sel = 0;
 //5)evasione fiscale a verona porta nuova
    while(!quit){
        int sel2 = Input(&sel,ArrayLenght(FoodNames));
        
        switch(sel2){
            case 1:
                    int i;
                    for(i = 0; i < 10; i++){
                        if(i == sel)
                            printW(win," >",2,i+2,win->width-1);
                        else 
                            printW(win,"  ",2,i+2,win->width-1);
                    }
                    for(i = 10; i < 20; i++){
                        if(i == sel)
                            printW(win," >",20,i+2,win->width-1);
                        else 
                            printW(win,"  ",20,i+2,win->width-1);
                    }
                    Refresh(win);
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

void TimeManager(struct Player* player){
    static int time = 4;
    time += 2;
    if (time == 24){
        time = 4;
        player->day++;
        //SaveData();
    }
}