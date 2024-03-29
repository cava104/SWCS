#include "interface.c"
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>

struct Player* InitPlayer(){ //Funzione che mina i bit coin
    struct Player* player = (struct Player*)malloc(sizeof(struct Player));
    player->Credit = 100;
    player->day = 0;
    player->time = 6;

    int i;
    for(i = 0; i < ArrayLenght(FoodNames); i++){
        player->Inv[i] = 0;
    }

    player->Lvl = 1;
    player->Xp = 0;
    player->XpNeeded = 40;

    return player;
}

struct Client NewClient(struct Player* player){
    struct Client client;
        
    client.numOrders = rand() % 4+1;
    
    int i,j;

    client.order = malloc(sizeof(char)*client.numOrders);
    
    for(i = 0; i < client.numOrders; i++){
        client.order[i] = rand() %  player->Lvl + 0;
    }
    
    client.selected = malloc(sizeof(int)*4);

    for(i = 0; i < 4; i++){
        client.selected[i] = -1;
    }

    int randName = rand() % ArrayLenght(ClientNames) + 0;
    client.name = malloc(sizeof(char)*strlen(ClientNames[randName])+1);

    strcpy(client.name,ClientNames[randName]);
    client.name[strlen(client.name)+1] = '\0';

    client.sprite = rand() % 5;
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
            case 'a':
                return 3;
                break;
            case 'd':
                return 4;
                break;
            case 'b':
                return 5;
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
    PrintInv(win,player);
    Refresh(win);
    //5)evasione fiscale a verona porta nuova
    while(!quit){
        if (kbhit()){
            int sel2 = Input(&sel,(player->Lvl)-1);
            PrintInv(win,player);
            Refresh(win);
            switch(sel2){
                case 1:
                    int i;
                    for(i = 0; i < ArrayLenght(FoodNames); i++){
                        if(i == sel)
                            printW(win," >",win->width/2+11,i+3,win->width-1,false);
                        else 
                            printW(win,"  ",win->width/2+11,i+3,win->width-1,false);
                    }
                    Refresh(win);
                break;
                case 3:
                    ClearScreen(win);
                    DrawRectangle(win,0,0,win->width,win->height);
                    printW(win,FoodNames[sel],2,3,win->width-1,false);
                    printInt(win,FoodPrice[sel],3,4);
                    printW(win,"$",5,4,win->width-1,false);
                    printW(win,"Acquistare: A | Indietro: B",2,5,win->width-1,false);
                    Refresh(win);
                    
                    while (1){
                        if (kbhit()){
                            char ch = getch();
                            switch(ch){
                                case 'a':
                                    int quantInt = 0;
                                    do{
                                        printW(win,"Quanti ne vuoi acquistare? [MAX 100]",2,7,win->width-1,true);
                                        Refresh(win);
                                        MoveCursor(3,10);
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
                                        Sleep(1000);
                                    }
                                    Refresh(win);
                                    return;  
                                break;
                                case 'b':
                                    return;
                                break;
                                default:
                                break;
                            }
                        }
                    }
                break;
                case 2:
                    if (player->Inv[sel] <= 0){
                        printW(win,"Non hai nessun piatto di questo tipo",2,6,win->width-1,true);
                        Refresh(win);
                    }
                    else {
                        int i;
                        for (i = 0; i < 4; i++){
                            //client->selected[i] = (sel == client->selected[i]) ? -1 : sel;
                            if(client->selected[i] == -1){
                                client->selected[i] = sel;
                                player->Inv[client->selected[i]]--;
                                break;
                            }
                        }
                        return;
                    }
                    break;
                case 4:
                    int j;
                    for (j = 0; j < 4; j++){
                        if(sel == client->selected[j]){
                            client->selected[j] = -1;
                            player->Inv[sel]++;
                            break;
                        }
                    }
                    return;
                break;
                case 5:
                    return;
                    break;
                default:
                break;
            } 
        }
    }
}

void Consegna(mWindow* win,struct Player* player,struct Client* client,bool* consegna){
    int i, j;
    float multiplier = 1; //markiplier
    int satisfaction = 0;
    for (i=0;i<client->numOrders;i++){
        for (j=0;j<4;j++){
            if (client->order[j] == client->selected[i]){
                multiplier += 0.3;
                satisfaction++;
                j = 4;
            }
        }
        j = 0;
    }
    i = 0;

    for (i=0;i<client->numOrders;i++){
        for (j=0;j<4;j++){
            if (client->order[j] == client->selected[i]){
                player->Credit += FoodPrice[client->order[j]] * multiplier;
                j = 4;
            }
        }
        j = 0;
    }
    i = 0;

    switch(satisfaction){
        case 0:
            printW(win,"Questo non e\' quello che ho ordinato.",4,win->height-6,win->width-1,true);
            break;
        case 1:
            if (client->numOrders > 1)
                printW(win,"Hai sbagliato alcune cose.",4,win->height-6,win->width-1,true);
            else
                printW(win,"Grazie mille",4,win->height-6,win->width-1,true);
            player->Xp += 10;
            break;
        case 2:
            if (client->numOrders > 2)
                printW(win,"Hai sbagliato alcune cose.",4,win->height-6,win->width-1,true);
            else
                printW(win,"Grazie mille",4,win->height-6,win->width-1,true);
            player->Xp += 20;
            break;
        case 3:
            if (client->numOrders > 3)
                printW(win,"Hai sbagliato alcune cose.",4,win->height-6,win->width-1,true);
            else
                printW(win,"Grazie mille",4,win->height-6,win->width-1,true);
            player->Xp += 30;
            break;
        case 4:
            printW(win,"Grazie mille",4,win->height-6,win->width-1,true);
            player->Xp += 40;
            break;
    }
    if (player->Xp >= player->XpNeeded && player->Lvl != 20){
        player->Xp -= player->XpNeeded;
        player->XpNeeded += 20;
        player->Lvl++;
    }
    *consegna = true;
}

void TimeManager(struct Player* player){
    player->time += 2;
    if (player->time == 24){
        player->time = 6;
        player->day++;
        SaveData(player);
    }
}