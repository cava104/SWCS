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

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "sprite.h"

#define HeightScreen 60
#define WidthScreen 200

const int TextBoxWidth = 180;
const int TextBoxHeight = 20;
const int TextBoxX = 9;
const int TextBoxY = 35;

char screen[HeightScreen][WidthScreen] = {0};

const char* text = "Se ni’ mondo esistesse un po’ di bene e ognun si honsiderasse suo fratello ci sarebbe meno pensieri e meno pene e il mondo ne sarebbe assai più bello";

void InitScreen(){
  int i,j;
  system("cls");
  for(i = 0; i < HeightScreen; i++){
    for(j = 0; j < WidthScreen; j++){
      screen[i][j] = ' ';
    }
  } 
}

void PrintScreen(){
  system("Cls");
  int i,j;
  for(i = 0; i < HeightScreen; i++){
    for(j = 0; j < WidthScreen; j++){
      printf("%c",screen[i][j]);
    }
    printf("\n");
  }
}

void ClearScreen(){
  int i,j;

  for(i = 0; i < HeightScreen; i++){
    for(j = 0; j < WidthScreen; j++){
      screen[i][j] = ' ';
    }
  }

  PrintScreen();
}

void border(){
  int x=0, y=0;
  for(y = 0; y < HeightScreen; y++){
      for(x = 0; x < WidthScreen; x++){
        if(x==0 || y==0 || x == 1 || x==WidthScreen-1 || x==WidthScreen-2 || y==HeightScreen - 1){
          screen[y][x] = 219;
      }
    }
  }
}

void DrawSprite(char sprite[][64] ,int SpritePosX,int SpritePosY){ // e questa :thumbsup:
  const int SpriteSizeX = 54;
  const int SpriteSizeY = 22;   

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

void DrawToScreen(const char* Text,int x, int y,int MaxWidth){  //non so se usare sta roba
  if(x > WidthScreen || x < 0 || y > HeightScreen || y < 0){    //la console si aggiorna troppo lentamente
    return;
  }

  int t = x;

  while(*Text != '\0' ){
    if(*Text == '\n' || x >= MaxWidth){
      y++;
      x = t;
    }
    screen[y][x] = *Text;
    x++;
    Text++;
  
  }
}