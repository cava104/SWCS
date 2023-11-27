//ci metti le robe per fare i drink o cibo idk
struct Inventory{
	int carlos;

	int moli;
};

//praticamente il player
struct Bar{		
	int Money;
	int day;
	struct Inventory Inv;
};

//cliente
struct Clients{
	char* Name;
	char* affiliation;
	char* Order;
};

const char affiliations[3][10] = {"Empire","Rebel","Civilians"};

struct Bar* Init();
struct Clients* newClient();

void Menu(struct Bar* bar);

int SaveData(int currentSlot,struct Bar* bar);
int LoadData(int Slot,struct Bar *bar);

void displayGame(struct Bar* bar,struct Clients* CurrentClient);
void Dialogs(); 

void gotoxy(int x,int y);
