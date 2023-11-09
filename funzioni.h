void menu(){
	char n;
	printf("Star Wars: Cantina Simulator\n\n");
	printf("1) Nuova Partita\n");
	printf("2) Carica Partita\n\n");
	printf("v0.002\n");
	do{
		scanf("%c", &n);	
	}while(n < '1' || n > '2');
	
	switch(n){
		case '1':
			system("cls");
			printf("Nuova Partita\n\n");
			printf("1) Slot 1 | VUOTO |\n");
			printf("2) Slot 2 | VUOTO |\n");
			printf("3) Slot 3 | VUOTO |\n");
			printf("4) Indietro\n");
			do{
				scanf("%c", &n);	
			}while(n < '4' || n > '4');
			switch(n){
				case '4':
					system("cls");
					menu();
					break;
			}
			
			break;
		case '2':
			system("cls");
			printf("Carica\n");
			sleep(10);
			break;
	}
}
