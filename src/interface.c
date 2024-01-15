/*

                                  @@@@@@@@@@@@   @@@@
                             @@   @   ,,****,@@  @@***&@@@@
                          @@@*@%  @@  ,,*****@@ @@,*******@@
                       %@@****%@  @@,,,,,****@@ @@*******@@%
                     @@@*******@@@@@,,,,,***************#@@
                      @@@*********,,,,,,,***************@@
                        @@********,,,,,,,,*************@@
                         @@********,,,,,,,************#@
                          @@********,,,,%%#(((#%#*****@@
                           @@***,%(((((((((((((((((((@@
                             @@(((((((((((((((((((((@@
                               @@@((((((((((((@@@@@

                                   ,@@@@@@@@@@@@@@@@@
                       @@@@  @@,,******************@@,/@@&
                      @@@@@@@@@@@@@**********,@@@@@@@@@@@@@
                      @@@@@@@@@@@@,***********%@@@@@@@@@@@@
                      ,@@@@%,********(*************//*@@@@@@                     
                       @@***********@,******%***********@@                      
                     @@&**@@@@@@****@*******%****,@@@@@**@@                     
             @@@@@@@@@,******,@@,***@*******%**,@@@/**#(**@@ @@@@@@@@@          
            @@@@@@@@@@**************@*******%*****//*******@@@@@@@@@@@@         
            @@@@@@@@@@@@@@@@@@@@,****************@@@@@@@@@@@@@@@@@@@@@(         
             @@@@@@@@@@@@@@@@@@*******************@@@@@@@@@@@@@@@@@@@@          
              @%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@            
            @@@%%,                                            #%%@@@@           
          @@@@@%%%%%       .            .                   %%%%%@@@@@          
        @@@@@@@%%%%%%%%    .            .               #%%%%%%%%@@@@@@@        
       @@@@@@@@%%%%%%%%%%%%%%%%%,              (%%%%%%%%%%%%%%%%%@@@@@@@@       
     @@@@@@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@      
      @@@@@@@@@@%%%%%%%%%%%%%%%%%&&&&&&&%%&&&&&%%%%%%%%%%%%%%%%%@@@@@@@@@       
        @@@@@@@@@ %%%%%%%%%%%%####%&&&&%%%&&&#########%%%%%%%% @@@@@@@@         
          @@@@@@@@     %%%%%#############&#(##########(%%.    @@@@@@@           
            @@@@@@@@              ,//(((((*,                @@@@@@@@@           
            @@#@@@@@@@@                 .                 @@@@@@@@##@@          
           @@#####@@@@@@@@%             .             @@@@@@@@@#####%@@         
          @@(((######@@@@@@@@@@@,       ,       *@@@@@@@@@@@#####((((@@@        
         @@(((((((######&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#####((((((((@@,       
        @@((@@@((((((#######@@@@@@@@@@@@@@@@@@@@@@@@@######((((((((@@@(@@       
       @@#(((((((@@((((((###/////@@@@@@@@@@@@@@@@////(##((((((@@&(((((((@@      
      @@&(((((((((((((%@@(((**///////@@@@@@@#///////**(#@@%((((((((((((((@@     
  // @@@((((((((((((((((((((((@@@@/***///////**@@@&(((((((((((((((((((((((@@
//  @@@(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((#@@ */

#include "sprite.h"
#include "funzioni.h"
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>


//gotoxy ma fatta con gli escape code ascii cosi andava anche su linux
void MoveCursor(int x,int y){
  printf("\e[%d;%dH",y,x);
}

void ClearScreen(mWindow* win){
  int i,j;
  for(i = 0; i < win->height; i++){
    for(j = 0; j < win->width; j++){
      win->Screen[i][j] = ' ';
    }
  }
}

//stessa roba di Erase() ma disegna la roba nella "window"
void Refresh(mWindow* win){
    MoveCursor(0,0);
    char row[200];

    int i,j;
    for(i = 0; i < win->height; i++){
        for(j = 0; j < win->width; j++){
            row[j] = win->Screen[i][j];
        }
        row[j] = '\0';
        puts(row);
    }
}

//inizializza lo schermo alla grandezza che vuoi te
char** InitScreen(mWindow* self){
    system("cls");
    int i,j;
    char** screen = (char**)malloc(sizeof(char*)*self->height);
    for(i = 0; i < self->height; i++){
        screen[i] = (char*)malloc(sizeof(char)*self->width);
        for(j = 0; j < self->width; j++){
            screen[i][j] = ' ';  
        }
        screen[i][j] = '\0';
        //piango se lo hai fixato cosi è fixato (grazie a luca m) (il miglio)
    }

    return screen;
}

//cubo
void DrawRectangle(mWindow* win, int x, int y, int width, int height) {
    int i, j;
    for (i = y; i < y + height; i++) {
        for (j = x; j < x + width; j++) {
            if ((i == y || j == x || i == y + height - 1 || j == x + width - 1)) {
                win->Screen[i][j] = '#';
            }
        }
    }
}

//se vuoi togli scrollingText se non vuoi che il testo si aggiorna lettera per lettera
void printW(mWindow* win,const char* Text,int x, int y,int MaxWidth,bool ScrollText){  
  int startofLine = x; //nuova variabile per ritornare all'inizio della riga quando si va a capo

  while(*Text != '\0' || y > win->height-1){
    if(*Text == '\n' || x > MaxWidth || x > win->width-1){ // quando la x e maggiore o uguale di MaxWidth
      y++;                              // o nel text ce uno \n va a capo.
      x = startofLine;
    }
    win->Screen[y][x] = *Text;
    x++; 
    Text++;

    if(ScrollText){
      Refresh(win);
      Sleep(20);
    }
  }
}

void printInt(mWindow* win,int Text,int MaxX, int y){  
  int x = MaxX;
  char arr[10] = {'0','1','2','3','4','5','6','7','8','9'};
  int val = 0;
  do{
    if (Text >= 100){
      val = Text%10;
      Text /= 10;
    }
    else if (Text >= 10){
      val = Text%10;
      Text /= 10;
    }
    else{
      val = Text;
      Text /= 10;
    }
    win->Screen[y][x] = arr[val];
    x--;
  }while(Text != 0);
}

//così canossa non rompe a noi non serve
void DestroyWin(mWindow* win){
    int i;
    for(i = 0; i < win->height; i++){
        free(win->Screen[i]);
    }
    free(win->Screen);
}

void DrawSprite(mWindow* win,char Face[][64] ,int SpritePosX,int SpritePosY){ // e questa :thumbsup:
  int x,y;
  for(y=SpritePosY; y<SpriteSizeY+SpritePosY; y++){
    for(x=SpritePosX; x<SpriteSizeX+SpritePosX; x++)
        win->Screen[y][x] = Face[y-SpritePosY][x-SpritePosX];
  }
}

//puoi farlo in 2 modi:
//1)cancelli tutto nello schermo e ci disegni sopra

//2)crei una nuova "window" e disegni li

//3)crei cnap fl

//4)ha vinto l'odio è morto maradona

//nvm esplode (nvidia esplode) si processore amd e scheda grafica nvidia possono funzionare insieme e vice versa?

void PrintMenu(mWindow* win){
  printW(win,"Star Wars: Cantina Simulator V1.0",2,2,win->width-1,true);
  printW(win,"   Nuova Partita",2,4,win->width-1,true);
  printW(win,"   Carica Partita",2,5,win->width-1,true);
  printW(win,"   Crediti",2,6,win->width-1,true);
}

void PrintGame(mWindow* win,struct Client* client,struct Player* player){
    printW(win,"Ore:    Giorno:   ",2,2,win->width-1,false);
    printInt(win,player->time,8,2);
    printInt(win,player->day,19,2);
    printW(win,client->name,2,win->height-13,win->width-1,false);
    printW(win,"$",win->width-3,win->height-13,win->width-1,false);
    printW(win,"Inventario: I | Consegna: C",4,win->height-4,win->width-1,false);
    printW(win,"Ordine                    Piatto",4,win->height-11,win->width-1,false);
    printInt(win,player->Credit,win->width-5,win->height-13);
    DrawSprite(win,sprite[client->sprite],10,10);
    DrawRectangle(win,2,win->height-12,win->width-4,10);
    int i;
    for(i = 0; i < client->numOrders; i++){
      printW(win,FoodNames[client->order[i]],4,win->height-10 + i,win->width-6,false);
    }
    for(i = 0; i < 4; i++){
      if (client->selected[i] != -1)
        printW(win,FoodNames[client->selected[i]],30,win->height-10 + i,win->width-6,false);
    }
}

//se non va forse è colpa di questo
void PrintInv(mWindow* win,struct Player* player){ 
  int i;
  printW(win,"Inventario",win->width/2+14,2,win->width-1,false);
  DrawRectangle(win,win->width/2+10,0,win->width/2,24);
  for (i = 0;i<ArrayLenght(FoodNames);i++){
    if (i < player->Lvl){
      printW(win,FoodNames[i],win->width/2+14,i+3,win->width-1,false);
      printInt(win,player->Inv[i],win->width/2 + 40, i + 3);
    }
    else
      printW(win,"BLOCCATO",win->width/2+14,i+3,win->width-1,false);
  }
  printW(win,"Acquista: A | Muovi: W/S",win->width/2+14,20,win->width-1,false);
  printW(win,"Servi: E | Togli: D | Indietro: B",win->width/2+14,21,win->width-1,false);
  Refresh(win);

}

void PrintLvl(mWindow* win,struct Player* player){
  printW(win,"Livello ",40,win->height-13,win->width-1,false);
  float val = (float)player->Xp/(float)player->XpNeeded;
  if (val*100 > 80){
    printW(win,"[####-]",48,win->height-13,win->width-1,false); 
  }
  else if (val*100 > 60){
    printW(win,"[###--]",48,win->height-13,win->width-1,false); 
  }
  else if (val*100 > 40){
    printW(win,"[##---]",48,win->height-13,win->width-1,false); 
  }
  else if (val*100 > 20){
    printW(win,"[#----]",48,win->height-13,win->width-1,false); 
  }
  else
    printW(win,"[-----]",48,win->height-13,win->width-1,false);
  if (player->Lvl < 20)
    printInt(win,player->Lvl,57,win->height-13);
  else
    printW(win,"MAX",56,win->height-13,win->width-1,false); 
}

void PrintCredit(mWindow* win){
  printW(win,"Miranda Perez Juan Carlos",4,8,win->width-1,true);
  printW(win,"Luca Cavallaro",4,9,win->width-1,true);
  printW(win,"Luca Molinari",4,10,win->width-1,true);
}