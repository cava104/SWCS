
#include "src/game.c"
#include "src/data.c"

//Star Wars: Cantina Simulator V0.002
//orcamadonna
int main(){
    srand(time(NULL));

    mWindow win = {
        .height = 60,
        .width = 200,
        .Screen = InitScreen(&win)
    };
    
    DrawRectangle(&win,0,0,win.width,win.height);
    Refresh(&win);
    
    struct Player* player = InitPlayer(player);

    struct Client* client;
    int menuSel = 1;
    do{
        PrintMenu(&win);
        Refresh(&win);
        menuSel = Menu(&win);
        switch(menuSel){
            case 0:
                //SaveData(1,player);
            break;
            case 1:
                /*if(!LoadData(1,player))
                    SaveData(1,player);*/
            break;
            case 2:
                //stampa i crediti
            break;
        }
    }while(menuSel < 0 || menuSel > 2);

    bool gameover = false;

    ClearScreen(&win);
    DrawRectangle(&win,0,0,win.width,win.height);
    while(!gameover){
        client = NewClient();
        PrintGame(&win,client,player);
        Refresh(&win);

        FreeClient(client);
        Sleep(500);
    }
    ClearScreen(&win);
    Refresh(&win);

    DestroyWin(&win);
    
    MoveCursor(0,win.height+1);
}