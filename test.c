#include "src/interface.c"
<<<<<<< Updated upstream
#include <stdio.h>

int main() {
  InitScreen();
  border();
  DrawSprite(sprite);
  // carlos
  PrintScreen();
}
=======
//#include "src/game.c"

int main(){
   // struct Client* client = NewClient();
   // printClient(client); 
    InitScreen();
    PrintScreen();
    ClearScreen();
    border();
    DrawSprite(sprite[4],100-8, 25-4);
    //DrawBox();
    DrawToScreen(text, 30, 100, 10);
     PrintScreen();
}
>>>>>>> Stashed changes
