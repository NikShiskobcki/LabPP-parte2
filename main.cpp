#include<iostream>
#include "estructuras.h"
#include "prototipos.h"

using namespace std;

int main (int argc, char *argv[]) {
	usuario usuarios[MAXCANTJUGADORES];
	int posUsuarios = 0;
	int ronda = 0;
	
	int op;
	printf("**********Bienvenido!**********\n");
	do{
		op = menu();
		switch (op){
		case 1:
			gestionUsuarios(usuarios,posUsuarios);
			break;
		case 2:
			consultas(usuarios,posUsuarios);
			break;
		case 3:
			apostar(usuarios,posUsuarios,ronda);
			break;
		}
	} while(op!=4);
	system("clear");
	printf("Gracias por jugar! :)");
	return 0;
}
