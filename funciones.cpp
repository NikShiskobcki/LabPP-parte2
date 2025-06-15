#include<iostream>
#include <stdio_ext.h>
#include <string.h>
#include "estructuras.h"

//Menu principal
int menu(){
	int op;
	do{
		printf("1- Gestionar Usuarios\n");
		printf("2- Consultas\n");
		printf("3- Apostar\n");
		printf("4- Salir\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &op);
		if (op < 1 || op > 4){
			printf("\nOpcion no existe, vuelva a intentarlo\n");
			getchar();getchar();
			system("clear");
		}
	}while(op < 1 || op > 4);
	return op;	
}
	
//Validaciones ***************************************************

//Valida ci segun el digito verificador; 
//Compara si el ultimo digito del arreglo coincide con el digito verificador del calculo
//Retorna true si coinciden
bool ciValida(documento ci, int i){
	if (i==8){
		int dVerificador= (ci.numero[0]*2)+
							(ci.numero[1]*9)+
							(ci.numero[2]*8)+
							(ci.numero[3]*7)+
							(ci.numero[4]*6)+
							(ci.numero[5]*3)+
							(ci.numero[6]*4);
		dVerificador = dVerificador % 10;
		if (dVerificador == ci.numero[7]){
			return true;
		}
	}	
	printf("Cedula no valida, vuelva a ingresarla de manera correcta\n");
	return false;
}

//Valida los dias segun el mes; valida anios bisiestos
// Retorna true si la fecha es valida
bool fechaValida(fecha fAux){
	bool valida = true;
	if (fAux.anio > 2025 || fAux.anio < 1925){
		valida = false;
	}
	switch (fAux.mes){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (fAux.dia > 31 || fAux.dia < 1){
				valida = false;
			}
			break;
		case 4: case 6: case 9: case 11:
			if (fAux.dia > 30 || fAux.dia < 1){
				valida = false;
			}
			break;
		case 2:
			if (fAux.dia > 28 || fAux.dia < 1){
				valida = false;
			}
			if (fAux.dia == 29 && fAux.anio%4==0){
				valida=true;
			}
			break;
		default:
			valida = false;
			break;
	}
	if (!valida){
	printf("Fecha incorrecta, vuelva a ingresarla\n");
	}
	return valida;
}
//Fin validaciones ************************************************

	
//Ingresos ********************************************************
string ingresoTexto(){
	__fpurge(stdin);
	char cAux;
	string textoAux;
	int i;
	for (i=0;i<MAXLARGOSTRING;i++){
		cAux=getchar();
		if (cAux!='\n'){
			textoAux.texto[i]=cAux;
		}else{
				break;
		}
	}
	textoAux.largo=i;
	return textoAux;
}
	
documento ingresoCi(){
	documento ciAux;
	int i;
	do{
		__fpurge(stdin);
		for (i=0;i<8;i++){
			ciAux.numero[i] = getchar();
			if (ciAux.numero[i]=='\n'){
				break;
			}
			ciAux.numero[i]-=48;
		}
	}while (!ciValida(ciAux,i));
	ciAux.largo=8;
	return ciAux;
}

fecha ingresoFecha(){
	fecha fAux;
	do{
		scanf("%d/%d/%d", &fAux.dia, &fAux.mes, &fAux.anio);
	}while(!fechaValida(fAux));
	return fAux;
}
//Fin Ingresos ************************************************************	

//Retorna el index en donde se encuentra el alias; Retorna -1 si no existe en el array
int buscarAlias(string auxAlias, usuario usuarios[],int pos){
	int index=-1;
	for (int i = 0; i<pos;i++){
		if (strcmp(usuarios[i].datos.alias.texto, auxAlias.texto) == 0){
			index=i;
			break;
		}
	}
	return index;
}

//Pregunta al usuario si desea confirmar; Retorna true si el usuario ingresa 's'
bool confirmar(){
	__fpurge(stdin);
	char c;
	printf("Confirma datos? s/n ");
	scanf("%c", &c);
	__fpurge(stdin);
	if (c=='S' || c == 's'){
		return true;
	}else{
		return false;
	}
}
	
//Procedimiento que muestra un usuario del array segun el index brindado
void mostrarUsuario(usuario usuarios[], int pos){
	printf("\nCI: ");
	for (int i=0;i<8;i++){
		printf("%d",usuarios[pos].datos.ci.numero[i]);
	}
	printf("\nNombre: ");
	for (int i=0;i< usuarios[pos].datos.nombre.largo;i++){
		putchar(usuarios[pos].datos.nombre.texto[i]);
	}
	printf("\nApellido: ");
	for (int i=0;i< usuarios[pos].datos.apellido.largo;i++){
		putchar(usuarios[pos].datos.apellido.texto[i]);
	}
	printf("\nAlias: ");
	for (int i=0;i< usuarios[pos].datos.alias.largo;i++){
		putchar(usuarios[pos].datos.alias.texto[i]);
	}

}

	
//Opcion 1 del submenu Gestion de Usuarios (op 1 - 1)
//Verifica que la CI sea valida al igual que la fecha de nacimiento
//Verifica que el alias no exista
void alta(usuario usuarios[],int &pos){
	int repetido=-1;
	printf("Ingrese el alias: ");
	string auxAlias = ingresoTexto();
	repetido = buscarAlias(auxAlias, usuarios,pos);
	if (repetido == -1){
		printf("Ingrese Ci: ");
		documento ciAux= ingresoCi();
		printf("Ingrese fecha de nacimiento (dd/mm/aaaa): ");
		fecha fechaAux = ingresoFecha();
		printf("Ingrese Nombre: ");
		string nombreAux = ingresoTexto();
		printf ("Ingrese Apellido: ");
		string apellidoAux = ingresoTexto();
		if (confirmar()){
			usuarios[pos].datos.alias = auxAlias;
			usuarios[pos].datos.ci = ciAux;
			usuarios[pos].datos.fechaNacimiento = fechaAux;
			usuarios[pos].datos.nombre = nombreAux;
			usuarios[pos].datos.apellido = apellidoAux;
			usuarios[pos].saldo = 1000;
			usuarios[pos].activo = true;
			usuarios[pos].aciertosSeguidos = 0;
			pos++;
			printf("El usuario se ha creado correctamente\n");
			mostrarUsuario(usuarios,pos-1);
			
			printf("\nFecha de Nacimiento: ");
			printf("%d/%d/%d",usuarios[pos-1].datos.fechaNacimiento.dia,
				   usuarios[pos-1].datos.fechaNacimiento.mes,
				   usuarios[pos-1].datos.fechaNacimiento.anio);
		}else{
			printf("El usuario no ha sido creado\n");
		}
	}else{
		printf("Ya existe un usuario con ese Alias\n");
	}
	printf("\nPresione enter para continuar");
	getchar();
	system("clear");	
}
	
//Opcion 3 del submenu Gestion de Usuarios(op 1 - 3)
void modificar(usuario usuarios[],int pos){
	string aliasAux;
	int i;
	printf("Ingrese alias del usuario que desea modificar: ");
	aliasAux = ingresoTexto();
	i = buscarAlias(aliasAux,usuarios,pos);
	if (i!=-1){
		printf("Ingrese Ci: ");
		documento ciAux= ingresoCi();
		printf("Ingrese fecha de nacimiento (dd/mm/aaaa): ");
		fecha fechaAux = ingresoFecha();
		printf("Ingrese Nombre: ");
		string nombreAux = ingresoTexto();
		printf ("Ingrese Apellido: ");
		string apellidoAux = ingresoTexto();
		if (confirmar()){
			usuarios[pos].datos.alias = aliasAux;
			usuarios[pos].datos.ci = ciAux;
			usuarios[pos].datos.fechaNacimiento = fechaAux;
			usuarios[pos].datos.nombre = nombreAux;
			usuarios[pos].datos.apellido = apellidoAux;
			mostrarUsuario(usuarios,i);
			
			printf("\nFecha de Nacimiento: ");
			printf("%d/%d/%d",usuarios[pos].datos.fechaNacimiento.dia,
				   usuarios[pos].datos.fechaNacimiento.mes,
				   usuarios[pos].datos.fechaNacimiento.anio);
			printf("\nEl usuario se modifico correctamente\n");
		}else{
			printf("\nEl usuario no se ha modificado\n");
		}
		
	}else{
		printf("No existe un usuario con ese Alias\n");
	}
	printf("\nPresione enter para continuar");
	getchar();
	system("clear");
}
	
//Submenu Gestion de usuarios(op 1)
void gestionUsuarios(usuario usuarios[], int &pos){
	int op;
	system("clear");
	printf("Bienvenido a Gestion de Usuarios\n");
	
	do{
		printf("1- Alta de Jugador\n");
		printf("2- Baja de Jugador\n");
		printf("3- Modificacion de Jugador\n");
		printf("4- Volver al menu\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &op);
		if (op < 1 || op > 4){
			printf("\nOpcion no existe, vuelva a intentarlo\n");
			getchar();getchar();
			system("clear");
		}
		system("clear");
	}while(op < 1 || op > 4);
	switch (op){
		case 1:
			alta(usuarios,pos);
			break;
		case 3:
			modificar(usuarios,pos);
			break;
	}
}
	
//copia los usuarios de una struct a otra
void copiarUsuarios(usuario usuarios[],usuario usuariosOrdenados[], int pos){
	for (int i=0;i<pos;i++){
		usuariosOrdenados[i]=usuarios[i];
	}
}
	
//bubble sort	
void ordenar(usuario usuariosOrdenados[],int pos){
	usuario aux;
	for (int i=0;i<pos-1;i++){
		for (int j=0;j<pos-1;j++){
			if (strcmp(usuariosOrdenados[j].datos.alias.texto,usuariosOrdenados[j+1].datos.alias.texto)>0){
				aux = usuariosOrdenados[j];
				usuariosOrdenados[j]=usuariosOrdenados[j+1];
				usuariosOrdenados[j+1]=aux;
			}
		}
	}
}
	
//Muestra el listado de todos los jugadores activos
//ci nombre apellido alias saldo actual
//ordenado por alias ascendente
void listadoJugadores(usuario usuarios[],int pos){
	usuario usuariosOrdenados[pos];
	copiarUsuarios(usuarios,usuariosOrdenados,pos);
	ordenar(usuariosOrdenados,pos);
	for (int i=0;i<pos;i++){
		if (usuariosOrdenados[i].activo){
			mostrarUsuario(usuariosOrdenados,i);
			printf("\nSaldo Actual: %d", usuariosOrdenados[i].saldo);
			printf("\n");
		}
	}
	printf("\nPresione enter para continuar");
	getchar();getchar();
	system("clear");
	
}

//Submenu Consultas (op 2)
void consultas(usuario usuarios[],apuesta apuestas[],int posUsuarios,int posApuestas){
	int op;
	system("clear");
	printf("Bienvenido a Consultas\n");
	do{
		printf("1- Listado de Jugadores\n");
		printf("2- Listado de todas las Apuestas\n");
		printf("3- Listado de Apuestas por Jugador\n");
		printf("4- Volver al menu\n");
		printf("Seleccione una opcion: ");
		scanf("%d", &op);
		if (op < 1 || op > 4){
			printf("\nOpcion no existe, vuelva a intentarlo\n");
			getchar();getchar();
			system("clear");
		}
		system("clear");
	}while(op < 1 || op > 4);
	switch (op){
		case 1:
			listadoJugadores(usuarios,posUsuarios);
			break;
	//case 3:
		//listadoApuestasPorJugador(alias,apuestas,posApuestas);
		//break;
	}
}
