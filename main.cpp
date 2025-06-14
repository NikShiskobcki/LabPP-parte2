#include<iostream>
#include "estructuras.h"
#include "prototipos.h"

using namespace std;

int main (int argc, char *argv[]) {
	usuario usuarios[MAXCANTJUGADORES];
	apuesta apuestas[20];
	int posUsuarios = 0;
	int posApuestas = 0;
	
	int op;
	printf("**********Bienvenido!**********\n");
	do{
		op = menu();
		switch (op){
		case 1:
			gestionUsuarios(usuarios,posUsuarios);
			break;
		case 2:
			consultas(usuarios,apuestas,posUsuarios,posApuestas);
			break;
		}
	} while(op!=4);
	return 0;
}
