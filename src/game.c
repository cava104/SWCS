#include "interface.c"
#include <conio.h>
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

    player->Lvl = 1;
    player->Xp = 0;
    player->XpNeeded = 40;

    return player;
}

struct Client NewClient(){
    struct Client client;

    client.numOrders = rand() % 4+1;
    int i,j;

    client.order = malloc(sizeof(char)*client.numOrders);
    
    for(i = 0; i < client.numOrders; i++){
        int item = rand() %  ArrayLenght(FoodNames) + 0;
        client.order[i] = item;
    }
    
    client.selected = malloc(sizeof(int)*4);

    for(i = 0; i < 4; i++){
        client.selected[i] = -1;
    }

    int randName = rand() % ArrayLenght(ClientNames) + 0;
    client.name = malloc(sizeof(char)*strlen(ClientNames[randName])+1);

    strcpy(client.name,ClientNames[randName]);
    client.name[strlen(client.name)+1] = '\0';

    client.sprite = rand() % 4;
    return client; 
}

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
                            printW(win," >",2,i+4,win->width-1,false);
                        else 
                            printW(win,"  ",2,i+4,win->width-1,false);
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
void Inv(mWindow* win,struct Player* player,struct Client* client){
    int quit = 0;
    int sel = 0;
    //5)evasione fiscale a verona porta nuova
    while(!quit){
        if (kbhit()){
            int sel2 = Input(&sel,ArrayLenght(FoodNames));
            PrintInv(win,player);
            Refresh(win);
            switch(sel2){
                case 1:
                    int i;
                    for(i = 0; i < ArrayLenght(FoodNames); i++){
                        if(i == sel)
                            printW(win," >",win->width/2 - 3,i+3,win->width-1,false);
                        else 
                            printW(win,"  ",win->width/2 - 3,i+3,win->width-1,false);
                    }
                    Refresh(win);
                break;
                case 2:
                    ClearScreen(win);
                    DrawRectangle(win,0,0,win->width,win->height);
                    printW(win,FoodNames[sel],2,3,win->width-1,false);

                    printW(win,"Acquistare: a | Seleziona/Deseleziona: s | Esci: e",2,4,win->width-1,false);
                    Refresh(win);
                    
                    while (1){
                        if (kbhit()){
                            char ch = getch();
                            switch(ch){
                                case 'a':
                                    int quantInt = 0;
                                    do{
                                        printW(win,"Quanti ne vuoi acquistare? (puoi averne massimo 100)",2,8,win->width-1,false);
                                        Refresh(win);
                                        scanf("%d", &quantInt);
                                    }while(quantInt < 0 || quantInt > 100);
                                    
                                    if(player->Inv[sel] + quantInt > 100){
                                        quantInt = 100 - player->Inv[sel]; 
                                    }

                                    if(FoodPrice[sel] * quantInt <= player->Credit){
                                        player->Credit -= FoodPrice[sel] * quantInt;
                                        player->Inv[sel] += quantInt;
                                    }
                                    else{
                                        ClearScreen(win);
                                        printW(win,"Povero",2,6,win->width-1,true);
                                        Refresh(win);
                                    }
                                    Refresh(win);
                                    return;  
                                break;
                                case 's':
                                    if (player->Inv[sel] <= 0){
                                        printW(win,"Non hai nessun piatto di questo tipo",2,6,win->width-1,false);
                                        Refresh(win);
                                    }
                                    else {
                                        int i;
                                        for (i = 0; i < 4; i++){
                                            //client->selected[i] = (sel == client->selected[i]) ? -1 : sel;
                                            if(client->selected[i] == -1){
                                                client->selected[i] = sel;
                                                break;
                                            }
                                            else if(sel == client->selected[i]){
                                                client->selected[i] = -1;
                                                break;
                                            }
                                        }
                                        return;             
                                    }
                                break;
                                case 'e':
                                    return;
                                break;
                                default:
                                break;
                            }
                        }
                    }
                break;
                default:
                break;
            } 
        }
    }
}

void Consegna(mWindow* win,struct Player* player,struct Client* client){
    int i, j;
    float multiplier = 1; //markiplier
    int satisfaction = 0;
    for (i=0;i<client->numOrders;i++){
        for (j=0;j<4;j++){
            if (client->order[i] == client->selected[j]){
                multiplier += 0.2;
                satisfaction++;
            }
        }
        j = 0;
    }
    i = 0;

    for (i=0;i<client->numOrders;i++){
        for (j=0;j<4;j++){
            if (client->order[i] == client->selected[j])
                player->Credit += FoodPrice[client->order[i]] * multiplier;
        }
        j = 0;
    }
    i = 0;
    switch(satisfaction){
        case 0:
            printW(win,"Questo non e\' quello che ho ordinato.",4,win->height-7,win->width-1,true);
            break;
        case 1:
            if (client->numOrders > 1)
                printW(win,"Hai sbagliato alcune cose.",4,win->height-7,win->width-1,true);
            else
                printW(win,"Grazie mille",4,win->height-7,win->width-1,true);
            player->Xp += 10;
            break;
        case 2:
            if (client->numOrders > 2)
                printW(win,"Hai sbagliato alcune cose.",4,win->height-7,win->width-1,true);
            else
                printW(win,"Grazie mille",4,win->height-7,win->width-1,true);
            player->Xp += 20;
            break;
        case 3:
            printW(win,"Grazie mille",4,win->height-7,win->width-1,true);
            player->Xp += 30;
            break;
    }
    if (player->Xp >= player->XpNeeded){
        player->Xp -= player->XpNeeded;
        player->XpNeeded += 20;
        player->Lvl++;
    }
    Sleep(1000);
}

void TimeManager(struct Player* player){
    static int time = 4;
    time += 2;
    if (time == 24){
        time = 4;
        player->day++;
        SaveData(player);
    }
}