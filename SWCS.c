
#include "src/game.c"
#include "src/data.c"

//Star Wars: Cantina Simulator V0.002
//orcamadonna
int main(){
    srand(time(NULL));
    mWindow win = {
        .height = 40,
        .width = 100,
        .Screen = InitScreen(&win)
    };
    
    DrawRectangle(&win,0,0,win.width,win.height);
    Refresh(&win);
    
    struct Player* player = InitPlayer(player);

    struct Client client;
    int menuSel = 1;
    do{
        PrintMenu(&win);
        Refresh(&win);
        menuSel = Menu(&win);
        switch(menuSel){
            case 0:
                SaveData(player);
            break;
            case 1:
                if(!LoadData(player))
                    SaveData(player);
            break;
            case 2:
                //stampa i crediti
            break;
        }
    }while(menuSel < 0 || menuSel > 2);

    bool gameover = false;

    ClearScreen(&win);

    while(!gameover){
        client = NewClient(player);

        bool orderCompleted = false;

        while(!orderCompleted){
           
            DrawRectangle(&win,0,0,win.width,win.height);
            PrintLvl(&win,player);
            PrintGame(&win,&client,player);
            Refresh(&win); 
            char ch;
            switch(ch = getch()){
                case 'i':
                    Inv(&win,player,&client);
                break;
                case 'c':
                    Consegna(&win,player,&client);
                break;
                default:
                break;
            }
            ClearScreen(&win);
        }

        ClearScreen(&win);
        Refresh(&win);
        Sleep(1000);
    }
    ClearScreen(&win);
    Refresh(&win);

    DestroyWin(&win);
    
    MoveCursor(0,win.height+1);
}