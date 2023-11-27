struct Inventory{
	//snack
	int Meiloorun;
	int BanthaTartare;
	int FruitPie;
	int MillaFlowerToast;
	int BatuuBits;
	int MantellMits;
	int OgasObsession;
	int OutpostMix;
	int WookieeCookie;
	int MossChip;
	int FlashFriedZuchii;
	int CrackNut;
	//Bibite
	int Alcohol;
	int Ardees;
	int JetJuice;
	int Revnog;
	int MooganTea;
};

struct Player{
	int Credit;
	struct Inventory inv;	
};

void Menu(struct Bar* bar);

int SaveData(int currentSlot,struct Bar* bar);
int LoadData(int Slot,struct Bar *bar);
