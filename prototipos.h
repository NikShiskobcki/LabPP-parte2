#ifndef PROTOTIPOS_H
#define PROTOTIPOS_H
int menu();

void gestionUsuarios(usuario usuarios[], int &pos);
void consultas(usuario usuarios[],int posUsuarios);
void apostar(usuario usuarios[], int posUsuarios, int &ronda);

void alta(usuario usuarios[],int &pos);
void modificar(usuario usuarios[],int pos);

void listadoJugadores(usuario usuarios[],int pos);
void listadoApuestasPorJugador(usuario usuarios[], int posUsuarios);

string ingresoTexto();
fecha ingresoFecha();
documento ingresoCi();

int buscarAlias(string auxAlias, usuario usuarios[],int pos);

bool ciValida(documento ci, int i);
bool fechaValida(fecha fAux);

bool confirmar();

void copiarUsuarios(usuario usuarios[],usuario usuariosOrdenados[], int pos);
void ordenar(usuario usuariosOrdenados[],int pos);

int generarCopa(int i); 
void mostrarCopas(char c, int copa);

#endif
