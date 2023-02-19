#ifndef MATRIZ_H
#define MATRIZ_H

void guardarMatriz(const char [], int **, int );

int** matrizA(const char [], int *); 

int** reservarMemoriaMatriz(int );

void liberarMemoriaMatriz(int **, int );

void leerMatriz(int **, int );

void mostrarMatriz(int **, int );

void sumarMatrices(int **, int **, int );

void restarMatrices(int **, int **, int );

void multiplicarMatrices(int **, int **, int );

void multiplicarMatrizPorEscalar(int **, int );

void transpuesta(int **, int );

void inversa(int **, int );

void matrizIdentidad(int **, int );

void determinante(int **, int );

#endif
