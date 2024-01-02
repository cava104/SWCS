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
    fprintf(stdout,"\e[%d;%dH",y,x);
}

//mette il cursore in alto a sinistra e scrive sopra alla roba gia esistente senza dover cancellare tutto
void Erase(mWindow* win){    
    MoveCursor(0,0);
    char* row = (char*)malloc(sizeof(char)*win->width+1);

    int i,j;
    for(i = 0; i < win->height; i++){
        for(j = 0; j < win->width; j++){
            row[j] = ' ';
        }
        puts(row);
    }
}

//stessa roba di Erase() ma disegna la roba nella "window"
void Refresh(mWindow* win){
    MoveCursor(0,0);
    char* row = (char*)malloc(sizeof(char)*win->width+1);

    int i,j;
    for(i = 0; i < win->height; i++){
        for(j = 0; j < win->width; j++){
            row[j] = win->Screen[i][j];
        }
        puts(row);
    }
}

//inizializza lo schermo alla grandezza che vuoi te
char** InitScreen(mWindow* self){
    clear();
    int i,j;
    char** screen = (char**)malloc(sizeof(char*)*self->height);
    for(i = 0; i < self->height; i++){
        screen[i] = (char*)malloc(sizeof(char)*self->width);
        for(j = 0; j < self->width; j++){
            screen[i][j] = ' ';  
        }
    }

    return screen;
}

//cubo
void DrawRect(mWindow* win,char ch, int x, int y, int w, int h) {
    int i, j;
    for (i = y; i < y + h; i++) {
        for (j = x; j < x + w; j++) {
            if (i == y || j == x || i == y + h - 1 || j == x + w - 1) {
                win->Screen[i][j] = ch;
            }
        }
    }
}
//se vuoi togli scrollingText se non vuoi che il testo si aggiorna lettera per lettera
void DrawToScreen(mWindow* win,const char* Text,int x, int y,int MaxWidth,bool scrollingText){  
  if(x > win->width || x < 0 || y > win->height || y < 0){   
    return;
  }

  int t = x; //nuova variabile per ritornare all'inizio della riga quando si va a capo

  while(*Text != '\0' ){
    if(*Text == '\n' || x >= MaxWidth){ // quando la x e maggiore o uguale di MaxWidth
      y++;                              // o nel text ce uno \n va a capo.
      x = t;
    }
    win->Screen[y][x] = *Text;
    x++; 
    Text++;

    if(scrollingText){
        Refresh(win);
        usleep(10000);
    }

  }
}

void DestroyWin(mWindow* win){
    int i;
    for(i = 0; i < win->height; i++){
        free(win->Screen[i]);
    }
    free(win->Screen);
}

void DrawSprite(mWindow* win,char sprite[2][64] ,int SpritePosX,int SpritePosY){ // e questa :thumbsup:
  const int SpriteSizeX = 16;
  const int SpriteSizeY = 8;   

  int x,y;
  for(y=SpritePosY; y<SpriteSizeY+SpritePosY; y++){
    for(x=SpritePosX; x<SpriteSizeX+SpritePosX; x++)
        win->Screen[y][x] = sprite[y-SpritePosY][x-SpritePosX];
  }
}






//puoi farlo in 2 modi:
//1)cancelli tutto nello schermo e ci disegni sopra

//2)crei una nuova "window" e disegni li
void PrintShop(mWindow*win,int sel){ 
  const int offsetX = 20;
}
