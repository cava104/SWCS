#include <stdio.h>
#include "src/interface.c"
#include "src/game.c"

int main(){
    struct Client* client = NewClient();

    printClient(client);
}
