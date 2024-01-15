#ifndef FUNZIONI_H
#define FUNZIONI_H

#define ArrayLenght(x) (sizeof(x) / sizeof(x[0]))

//se vuoi puoi fare uno struct per il cibo che pensandoci un po e piu comodo
//anche se li devi inizializzare a  mano
const char FoodNames[][64] = {"Meiloorun","Tartare di Bantha","Torta di Frutta","Toast al Fiore di Milla","Batuu Bits","Bantell Mits","Ossessione di Ogas","Mix dell\'Avamposto",
"Biscotti Wookiee","Patatine Moss","Carne Fritta di Zuchii","Noci di Crask","Alcool","Ardees","Succo Jet","Revnog","Te al Moogan"};
int FoodPrice[20] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40};

const char ClientNames[][64] = {"Carlos","Greg","GianmaWalker C.","Principessa Michelina","Darth Moli","Giovanni","Questo non e\' un bug",
"Pringles","#freepalpatine","Odio la conio.h","SpaceStation 5","Kristian G."};

struct Player{
	int Credit;
	int Inv[ArrayLenght(FoodNames)];   // se fai lo struct cambia questa
	int day;
	int time;
	int Lvl;
	int Xp;
	int XpNeeded;
};

struct Client{
	int* order;
	int numOrders;
	int* selected;
	char* name;
	int sprite;
};

int SaveData(struct Player* player);

int LoadData(struct Player* player);

struct Player* InitPlayer();

//ho usato uno struct perche e piu comodo
typedef struct {
    int height;
    int width;
    char** Screen;
} mWindow;

int Menu(mWindow* win);

void MoveCursor(int x, int y);

void Erase(mWindow* win);

void Refresh(mWindow* win);

char** InitScreen(mWindow* self);

void DrawRectangle(mWindow* win, int x, int y, int width, int height);

void DestroyWin(mWindow* win);

#endif