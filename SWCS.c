#include <stdio.h>
//Star Wars: Cantina Simulator V0.001
void menu(){
	char n;
	printf("Star Wars: Cantina Simulator\n\n");
	printf("1) Nuova Partita\n");
	printf("2) Carica Partita\n\n");
	printf("v0.001\n");
	do{
		scanf("%c", &n);	
	}while(n < '1' || n > '2');
	
	switch(n){
		case '1':
			system("cls");
			printf("Nuova\n");
			break;
		case '2':
			system("cls");
			printf("Carica\n");
			break;
	}
}
int main(){
	menu();
}
