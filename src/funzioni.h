#ifndef FUNZIONI_H
#define FUNZIONI_H

#define ArrayLenght(x) (sizeof(x) / sizeof(x[0]))

//se vuoi puoi fare uno struct per il cibo che pensandoci un po e piu comodo
//anche se li devi inizializzare a  mano
const char FoodNames[][64] = {"Meiloorun","Bantha Tartare","Fruit Pie","Milla Flower Toast","Batuu Bits","Bantell Mits","Ogas Obsession","Outpost Mix",
"Wookiee Cookie","Moss Chip","Flash Fried Zuchii","Crask Nut","Alcohol","Ardees","Jet Juice","Revnog","Moogan Tea"};
const int FoodPrice[20] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40};

const char ClientNames[][64] = {"Carlos","Greg","GianmaWalker C.","Principessa Michelina","Darth Moli","Giovanni","Questo non e\' un bug",
"Pringles","#freepalpatine","Odio la conio.h","SpaceStation 5","Kristian G."};

struct Player{
	int Credit;
	int* Inv;   // se fai lo struct cambia questa
	int day;
};

struct Client{
	char** order;
	int numOrders;
	char* name;
	char sprite[8][64];
};

int SaveData(int currentSlot,struct Player* player);

int LoadData(int Slot,struct Player* player);

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