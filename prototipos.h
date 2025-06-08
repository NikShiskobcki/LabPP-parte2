#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H
int menu();
void gestionUsuarios(usuario usuarios[], int &pos);
void alta(usuario usuarios[],int &pos);
string ingresoTexto();
int buscarAlias(string auxAlias, usuario usuarios[],int &pos);
bool ciValida(documento ci);
documento ingresoCi();
fecha ingresoFecha();
bool fechaValida(fecha fAux);
bool confirmar();
#endif
