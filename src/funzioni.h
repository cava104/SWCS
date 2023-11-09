#ifndef FUNZIONI_H
#define FUNZIONI_H

#define BUFFER 256

#define NUM_DRINKS 2
#define MAX_QUEUE 10

//ci metti le robe per fare i drink o cibo idk
struct Inventory{
	int temp;
};

//praticamente il player
struct Bar{		
	unsigned int Money;
	int level;
	struct Inventory* Inv;
};

//cliente
struct Clients{
	char* Name;
	char* affiliation;
	char* Order;
};

const char affiliations[3][10] = {"Empire","Rebel","Civilians"};
const char drinks[NUM_DRINKS][10] = {""};

struct Bar* Init();
struct Clients* newClient();

int SaveData(int currentSlot,struct Bar* Bar);
int LoadData(int Slot,struct Bar *Bar);

void displayGame(struct Bar* Bar,struct Clients* CurrentClient);
void Dialogs(); 

void gotoxy(int x,int y);

#endif