#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H
int menu();
void gestionUsuarios(usuario usuarios[], int &pos);
void alta(usuario usuarios[],int &pos);
string ingresoTexto();
int buscarAlias(string auxAlias, usuario usuarios[],int pos);
bool ciValida(documento ci, int i);
documento ingresoCi();
fecha ingresoFecha();
bool fechaValida(fecha fAux);
bool confirmar();
void modificar(usuario usuarios[],int pos);
void consultas(usuario usuarios[],apuesta apuestas[],int posUsuarios,int posApuestas);
void listadoJugadores(usuario usuarios[],int pos);
void copiarUsuarios(usuario usuarios[],usuario usuariosOrdenados[], int pos);
void ordenar(usuario usuariosOrdenados[],int pos);
#endif
