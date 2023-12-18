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
#include <conio.h>
#include <stdio.h>
#include <windows.h>

<<<<<<< Updated upstream
#define Height 25
#define Width 100
=======
#define HeightScreen 50
#define WidthScreen 200
>>>>>>> Stashed changes

void PrintScreen();
void ClearScreen();

<<<<<<< Updated upstream
char screen[Height][Width] = {0};
=======
static char screen[HeightScreen][WidthScreen] = {0};
>>>>>>> Stashed changes

void InitScreen() {
  int i, j;
  system("cls");
  for (i = 0; i < Height; i++) {
    for (j = 0; j < Width; j++) {
      screen[i][j] = ' ';
    }
  }
}

void PrintScreen() {
  int i, j;
  for (i = 0; i < Height; i++) {
    for (j = 0; j < Width; j++) {
      printf("%c", screen[i][j]);
    }
    printf("\n");
  }
}

void ClearScreen() {
  int i, j;

  for (i = 0; i < Height; i++) {
    for (j = 0; j < Width; j++) {
      screen[i][j] = ' ';
    }
  }

  PrintScreen();
}

void border() {

  int x = 0, y = 0;
  for (y = 0; y < Height; y++) {
    for (x = 0; x < Width; x++) {
      if (x == 0 || y == 0 || x == Width - 1 || y == Height - 1) {

        screen[y][x] = '#';
      }
    }
  }
}

<<<<<<< Updated upstream
void DrawSprite(char sprite[8][16]) {
  const int SpriteSizeX = 16, SpriteSizeY = 8;
  const int SpritePosX = 42, SpritePosY = 4;
  int x, y;
  for (y = SpritePosY; y < SpriteSizeY + SpritePosY; y++) {
    for (x = SpritePosX; x < SpriteSizeX + SpritePosX; x++) {
      screen[y][x] = sprite[y - SpritePosY][x - SpritePosX];
    }
  }
}
=======
void DrawSprite(char sprite[2][64] ,int SpritePosX,int SpritePosY){ // e questa :thumbsup:
  const int SpriteSizeX = 16;
  const int SpriteSizeY = 8;   

  int x,y;
  for(y=SpritePosY; y<SpriteSizeY+SpritePosY; y++){
    for(x=SpritePosX; x<SpriteSizeX+SpritePosX; x++)
        screen[y][x] = sprite[y-SpritePosY][x-SpritePosX];
  }
}

void DrawBox(int width, int height, int X, int Y){
  if(X+width > WidthScreen || height+Y > HeightScreen || X < 0 || Y < 0){
    printf("devi inserire un numero minore della grandeza della window");
    Sleep(1);
    return;
  }

  int i,j;

  for(i = Y; i <= height+Y; i++){
    for(j = X; j <= width+X; j++){
      if( i == Y || j == X || j == X+1 || i == height+Y || j == width+X ){
        screen[i][j] = 219;
      }
    }
  }
}


//funzione per scrivere nello schermo
//Text: il testo che vuoi scrivere nello schermo;
//x: variabile per scegliere in che punto nell asse x si vuole inserire il testo
//y: variabile per scegliere in che punto nell asse y si vuole inserire il testo
//MaxWidth: quanto puo essere lunga una riga
void DrawToScreen(const char* Text,int x, int y,int MaxWidth){  
  if(x > WidthScreen || x < 0 || y > HeightScreen || y < 0){   
    return;
  }

  int t = x; //nuova variabile per ritornare all'inizio della riga quando si va a capo

  while(*Text != '\0' ){
    if(*Text == '\n' || x >= MaxWidth){ // quando la x è maggiore o uguale di MaxWidth
      y++;                              // o nel teto ce uno \n va a capo.
      x = t;
    }
    screen[y][x] = *Text;
    x++; 
    Text++;
  }
}

void PrintShop(int* sel){
  const int offsetX = 20;
}
>>>>>>> Stashed changes
