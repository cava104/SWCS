#ifndef FUNZIONI_H
#define FUNZIONI_H

#define ArrayLenght(x) (sizeof(x) / sizeof(x[0]))

const char FoodNames[][20] = {"Meiloorun","Bantha Tartare","Fruit Pie","Milla Flower Toast","Batuu Bits","Bantell Mits","Ogas Obsession","Outpost Mix",
"Wookiee Cookie","Moss Chip","Flash Fried Zuchii","Crask Nut","Alcohol","Ardees","Jet Juice","Revnog","Moogan Tea"};

const int FoodPrice[ArrayLenght(FoodNames)] = {0};

struct Player{
	int Credit;
	int* Inv;
	int day;
};

struct Client(){
	char* name;
	char** order;
}
void Menu(struct Bar* bar);

int SaveData(int currentSlot,struct Bar* bar);
int LoadData(int Slot,struct Bar *bar);

void InitPlayer(struct Player* player);

void display_screen();
void clear_screen();

#endif