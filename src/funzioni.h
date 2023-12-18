#ifndef FUNZIONI_H
#define FUNZIONI_H

#define ArrayLenght(x) (sizeof(x) / sizeof(x[0]))

const char FoodNames[][20] = {"Meiloorun","Bantha Tartare","Fruit Pie","Milla Flower Toast","Batuu Bits","Bantell Mits","Ogas Obsession","Outpost Mix",
"Wookiee Cookie","Moss Chip","Flash Fried Zuchii","Crask Nut","Alcohol","Ardees","Jet Juice","Revnog","Moogan Tea"};
<<<<<<< Updated upstream

const int FoodPrice[ArrayLenght(FoodNames)] = {0};
=======
const int FoodPrice[ArrayLenght(FoodNames)] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40};
>>>>>>> Stashed changes

struct Player{
	int Credit;
	int* Inv;
	int day;
};

void Menu(struct Bar* bar);

int SaveData(int currentSlot,struct Bar* bar);
int LoadData(int Slot,struct Bar *bar);

void InitPlayer(struct Player* player);

void display_screen();
void clear_screen();

#endif