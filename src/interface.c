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

#define Height 25
#define Width 100

void PrintScreen();
void ClearScreen();

char screen[Height][Width] = {0};

void InitScreen(){
  int i,j;
  system("cls");
  for(i = 0; i < Height; i++){
    for(j = 0; j < Width; j++){
      screen[i][j] = ' ';
    }
  } 
}

void PrintScreen(){
  int i,j;
  for(i = 0; i < Height; i++){
    for(j = 0; j < Width; j++){
      printf("%c",screen[i][j]);
    }
    printf("\n");
  }
}

void ClearScreen(){
  int i,j;

  for(i = 0; i < Height; i++){
    for(j = 0; j < Width; j++){
      screen[i][j] = ' ';
    }
  }

  PrintScreen();
}

void border(){

int x=0, y=0;
for(y = 0; y < Height; y++){
    for(x = 0; x < Width; x++){
      if(x==0 || y==0 || x==Width-1 || y==Height - 1){
        
        screen[y][x] = '#';

      }
    }
  }


}

void DrawSprite(char sprite[8][16] ){

//int xl=16,yl=8;
int x=16,y=8;

  for(y=0; y<8; y++){
    for(x=0; x<16; x++)

        screen[y][x] = sprite[y][x];
  }
}



