#define BUFFER 256

#define NUM_DRINKS 2
#define MAX_QUEUE 10

//ci metti le robe per fare i drink o cibo idk
struct Inventory{
	int x;

	int y;
};

//praticamente il player
struct Bar{		
	unsigned int Money;
	unsigned int day;
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

void Menu(struct Bar* bar);

int SaveData(int currentSlot,struct Bar* bar);
int LoadData(int Slot,struct Bar *bar);

void displayGame(struct Bar* bar,struct Clients* CurrentClient);
void Dialogs(); 

void gotoxy(int x,int y);