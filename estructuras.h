#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#define MAXLARGOSTRING 15
#define MAXCANTJUGADORES 5

typedef struct _string{
	char texto[MAXLARGOSTRING]={' '};
	int largo;
}string;

typedef struct _fecha{
	int dia;
	int mes;
	int anio;
}fecha;

typedef struct _documento{
	int numero[8];
	int largo;
}documento;

typedef struct _datosPersonales{
	documento ci;
	fecha fechaNacimiento;
	string nombre;
	string apellido;
	string alias;
}datosPersonales;

typedef struct _usuario{
	datosPersonales datos;
	int saldo;
	bool activo;
	int aciertosSeguidos;
}usuario;

typedef struct _apuesta{
	string aliasJ;
	int saldoJ;
	bool acerto;
	int montoApostado;
	int saldoResultante;
}apuesta;
#endif
