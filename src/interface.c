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


//gotoxy ma fatta con gli escape code ascii cosi andava anche su linux
void MoveCursor(int x,int y){
    printf("\e[%d;%dH",y,x);
}

//mette il cursore in alto a sinistra e scrive sopra alla roba gia esistente senza dover cancellare tutto
void Erase(mWindow* win){    
    MoveCursor(0,0);
    char* row = (char*)malloc(sizeof(char) * win->width+1);

    int i,j;
    for(i = 0; i < win->height; i++){
        for(j = 0; j < win->width; j++){
            row[j] = ' ';
        }
        
        row[j] = '\0';
        puts(row);
    }
    free(row);
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
    char* row = (char*)malloc(sizeof(char)*win->height+1);

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
        screen[i] = (char*)malloc(sizeof(char)*self->width+1);
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
void printW(mWindow* win,const char* Text,int x, int y,int MaxWidth){  
  if(x > win->width || x < 0 || y > win->height || y < 0){   
    return;
  }

  int startofLine = x; //nuova variabile per ritornare all'inizio della riga quando si va a capo

  while(*Text != '\0' ){
    if(*Text == '\n' || x > MaxWidth){ // quando la x e maggiore o uguale di MaxWidth
      y++;                              // o nel text ce uno \n va a capo.
      x = startofLine;
    }
    win->Screen[y][x] = *Text;
    x++; 
    Text++;
  }
  
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
  printW(win,"Star Wars: Cantina Simulator V0.01",2,2,win->width-1);
  printW(win,"   Nuova Partita",2,4,win->width-1);
  printW(win,"   Carica Partita",2,5,win->width-1);
  printW(win,"   Crediti",2,6,win->width-1);
}

void PrintGame(mWindow* win,struct Client* client,struct Player* player){
    printW(win,client->name,10,8,win->width-1);
    DrawSprite(win,client->sprite,10,10);
    DrawRectangle(win,2,38,197,30);
    int i;
    for(i = 0; i < client->numOrders; i++){
      if(i > 0)
        printW(win,client->order[i],4,win->height-10 + i,win->width-6);
    }
}

void PrintShop(mWindow* win){ 
  int i;
  for (i = 0;i<10;i++){
    printW(win,FoodNames[i],2,i+2,win->width-1);
  }
  for (i = 10;i<20;i++){
    printW(win,FoodNames[i],20,i+2,win->width-1);
  }
}