#ifndef POLINOMIO_H
#define POLINOMIO_H

//Declaración de la estructura Polinomio.
typedef struct{ 
	
	int exponente;
	int coeficiente; 
		  
}Termino;

typedef struct{
	
	Termino termino;
	
}Polinomio;

void guardarPolinomio(const char [], Polinomio *, int );

Polinomio* polinomioA(const char [], int *); 

Polinomio* reservarMemoria(int );

void liberarMemoria(Polinomio *, int );

void leerPolinomio(Polinomio *, int );

void mostrarPolinomio(Polinomio *, int );

void sumarPolinomios(Polinomio *, Polinomio *, int , int );

void restarPolinomios(Polinomio *, Polinomio *, int , int);

void multiplicarEscalarPolinomio(Polinomio *, int );

void dividirPolinomio(Polinomio *, int );

void multiplicarPolinomios(Polinomio *, Polinomio *, int, int );

void sumarPolinomio(Polinomio *, int, int );

void ordenarPolinomio(Polinomio *, int );

void cambiarSigno(Polinomio *, int );

#endif
