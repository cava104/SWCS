#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//Star Wars: Cantina Simulator V0.002
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
			PlaySound(TEXT("ButtonPressed.wav"),NULL,SND_ASYNC | SND_NOSTOP);
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
					PlaySound(TEXT("ButtonPressed.wav"),NULL,SND_ASYNC | SND_NOSTOP);
					system("cls");
					menu();
					break;
			}
			
			break;
		case '2':
			PlaySound(TEXT("ButtonPressed.wav"),NULL,SND_ASYNC);
			system("cls");
			printf("Carica\n");
			sleep(10);
			break;
	}
}
int main(){
	PlaySound(TEXT("MenuTheme.wav"),NULL,SND_ASYNC | SND_NOSTOP);
	menu();
}
