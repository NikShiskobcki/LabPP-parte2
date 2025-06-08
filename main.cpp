#include<iostream>
#include "estructuras.h"
#include "prototipos.h"

using namespace std;

int main (int argc, char *argv[]) {
	usuario usuarios[MAXCANTJUGADORES];
	apuesta apuestas[20];
	int pos = 0;
	
	int op;
	printf("**********Bienvenido!**********\n");
	do{
		op = menu();
		switch (op){
		case 1:
			gestionUsuarios(usuarios,pos);
			break;
		}
	} while(op!=4);
	return 0;
}
