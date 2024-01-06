#include "src/game.c"

int main(){
    mWindow win = {
        .height = 20,
        .width = 100,
        .Screen = InitScreen(&win)
    };

    struct Client client = NewClient();
    DrawSprite(&win,client.sprite,10,10);

    Refresh(&win);
}
