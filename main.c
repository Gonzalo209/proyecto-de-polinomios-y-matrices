//Bibliotecas
#include <stdio.h>
#include "polinomio.h"

//Prototipos de funciones
void menuInicial();
void menuPolinomios();
void menuMatrices();

//Programa principal
int main(int argc, char *argv[]) {

	menuInicial();
	
	return 0;
}

void menuInicial(){
	
	int opcion;
	
	do{
		
		system("cls");
		printf("\t\t\tBIENVENIDO AL MENU INICIAL\n\n");
		printf("1. Menu de polinomios\n2. Menu de matrices\n3. Salir\n");
		printf("Ingrese una opcion > ");
		scanf("%d", &opcion);
		
		switch(opcion){
			
			
			case 1: 
				
				menuPolinomios();
							
				break;
			
			case 2: 
	
				menuMatrices();
			
				break;
			
			case 3: 
			
				printf("Saliendo del programa....\n");
				
				break;
			
			default: 
				
				printf("Opcion invalida");
			
		}
		
		printf("\n\n");
		system("pause");
		
	}while(opcion != 3);
	
}

void menuPolinomios(){
	
	int opcion, opcion2, totalPolinomio1 = 0, totalPolinomio2 = 0, ordenados;
	Polinomio* polinomio1, *polinomio2;
	FILE* archivo;
	
		
	do{
		
		system("cls");
		printf("\t\t\tBIENVENIDO AL MENU DE POLINOMIOS\n\n");
		printf("1. Leer Polinomios"
			   "\n2. Suma Polinomios"
			   "\n3. Resta Polinomios"
			   "\n4. Multiplicacion Polinomios"
			   "\n5. Multiplicacion Por Escalar"
			   "\n6. Division Polinomios"
			   "\n7. Ordenar Polinomio"
			   "\n8. Regresar al menu principal\n"
			   "Ingrese una opcion > ");
		scanf("%d", &opcion);
		
		switch(opcion){
			
			case 1:
				
				ordenados = 0;
				
				do{
					
					printf("1. Leer polinomios con archivo"
						   "\n2. Leer polinomios por teclado"
						   "\nElija una opcion: ");
					scanf("%d", &opcion2);
					
					if(opcion2 < 1 || opcion2 > 2){
						
						printf("Opcion invalida...\n");
						
					}
					
				}while(opcion2 < 1 || opcion2 > 2);
				
				switch(opcion2){
				
					case 1:
						
						if(archivo = fopen("polinomio1.txt", "r")){
							
							polinomio1 = polinomioA("polinomio1.txt", &totalPolinomio1);
							
							printf("\nCARGANDO POLINOMIO 1: \n\n");

							mostrarPolinomio(polinomio1, totalPolinomio1);
							
							ordenados = 1;
							
						}else{
							
							printf("No existe el archivo polinomio1.txt\n");
							
						}
						
						if(archivo = fopen("polinomio2.txt", "r")){
							
							polinomio2 = polinomioA("polinomio2.txt", &totalPolinomio2);
							
							printf("\nCARGANDO POLINOMIO 2: \n\n");

							mostrarPolinomio(polinomio2, totalPolinomio2);
							
						}else{
							
							printf("No existe el archivo polinomio2.txt\n");
							
						}
						
						break;
				
					case 2:
										
						printf("Ingrese el total del polinomio 1: "); 
						scanf("%d", &totalPolinomio1);				
						
						printf("Ingrese el total del polinomio 2: "); 
						scanf("%d", &totalPolinomio2);				
						
						polinomio1 = reservarMemoria(totalPolinomio1);
						
						polinomio2 = reservarMemoria(totalPolinomio2);
						
						if(polinomio1 != NULL && polinomio2 != NULL){
							
							printf("INGRESANDO DATOS DEL POLINOMIO 1: \n\n");					
							leerPolinomio(polinomio1, totalPolinomio1);				
		
							printf("\n\nINGRESANDO DATOS DEL POLINOMIO 2: \n\n");
							leerPolinomio(polinomio2, totalPolinomio2);

							guardarPolinomio("polinomio1.txt", polinomio1, totalPolinomio1);

							guardarPolinomio("polinomio2.txt", polinomio2, totalPolinomio2);
							
						}else{
							
							printf("No se pudo reservar memoria");
							
						}
					
						break;
					
				}
								
				break;
			
			case 2:
				
				if(! totalPolinomio1){
					
					printf("No se han ingresado datos");
				
				}else{
								
					if(ordenados){
								
						printf("MOSTRANDO LA SUMA DE POLINOMIOS: \n");				
				
						sumarPolinomios(polinomio1, polinomio2, totalPolinomio1, totalPolinomio2);
						
					}else{
						
						printf("Ordene los polinomios");
						
					}
							
				}
				
				break;
				
			case 3:
				
				if(! totalPolinomio1){
					
					printf("No se han ingresado datos");
				
				}else{
								
					if(ordenados){
								
						printf("MOSTRANDO LA RESTA DE POLINOMIOS: \n");				
				
						restarPolinomios(polinomio1, polinomio2, totalPolinomio1, totalPolinomio2);
					
					}else{
						
						printf("Ordene los polinomios");
						
					}
					
				}
				
				break;
			
			case 4:
				
				if(! totalPolinomio1){

					printf("No se han ingresado datos");
				
				}else{
					
					if(ordenados){
								
						printf("MOSTRANDO LA MULTIPLICACION DE POLINOMIOS: \n");				
					
						multiplicarPolinomios(polinomio1, polinomio2, totalPolinomio1, totalPolinomio2);
					
					}else{
						
						printf("Ordene los arreglos");
						
					}
					
				}
				
				break;
			
			
			case 5:
				
				if(! totalPolinomio1){
					
					printf("No se han ingresado datos");
					
				}else{
					
					printf("MOSTRANDO ESCALAR DEL POLINOMIO 1: \n\n");
				
					multiplicarEscalarPolinomio(polinomio1, totalPolinomio1);

					printf("\n\nMOSTRANDO ESCALAR DEL POLINOMIO 2: \n\n");

					multiplicarEscalarPolinomio(polinomio2, totalPolinomio2);
				
				}
				
				break;
			
			case 6:
				
				if(! totalPolinomio1){

					printf("No se han ingresado datos");
				
				}else{
				
					if(ordenados){
								
						printf("MOSTRANDO LA DIVISION DEL POLINOMIO 1: \n\n");
				
						dividirPolinomio(polinomio1, totalPolinomio1);
					
						printf("\n\nMOSTRANDO LA DIVISION DEL POLINOMIO 2: \n\n");
					
						dividirPolinomio(polinomio2, totalPolinomio2);
				
					}else{
						
						printf("Ordene los arreglos");
						
					}
				
				}
				
				break;
			
			case 7:
				
				if(! totalPolinomio1){

					printf("No se han ingresado datos");
				
				}else{
				
					ordenarPolinomio(polinomio1, totalPolinomio1);

					ordenarPolinomio(polinomio2, totalPolinomio2);

					printf("Los Polinomios han sido ordenados");
					
					ordenados = 1;
					
				}
					
				break;
			
			case 8: 
			
				printf("Regresando al menu principal....\n");
				
				liberarMemoria(polinomio1, totalPolinomio1);
	
				liberarMemoria(polinomio1, totalPolinomio2);
							
				break;
			
			default: 
				
				printf("Opcion invalida");
			
		}
		
		printf("\n\n");
		system("pause");
		
	}while(opcion != 8);	
	
}

void menuMatrices(){

	int opcion, opcion2, tamanio = 0;
	int** matriz1;
	int** matriz2;
	char nombreArchivo[20];
	FILE* archivo;
	
	do{
		
		system("cls");
		printf("\t\t\tBIENVENIDO AL MENU DE MATRICES\n\n");
		printf("1. Leer Matrices"
			   "\n2. Sumar Matrices"
			   "\n3. Restar Matrices"
			   "\n4. Multiplicar Matrices"
			   "\n5. Multiplicacion Por Escalar"
			    "\n6. Tranpuesta"
			    "\n7. Inversa"
			    "\n8. Determinante"
				"\n9. Regresar al menu principal"
				"\nIngrese una opcion > ");
		scanf("%d", &opcion);
		
		switch(opcion){
			
			case 1: 
				
				do{
					
					printf("1. Leer matriz con archivo"
						   "\n2. Leer matriz por teclado"
						   "\nElija una opcion: ");
					scanf("%d", &opcion2);
					
					if(opcion2 < 1 || opcion2 > 2){
						
						printf("Opcion invalida...\n");
						
					}
					
				}while(opcion2 < 1 || opcion2 > 2);
				
				switch(opcion2){
				
					case 1:
						
						if(archivo = fopen("matriz1.txt", "r")){
							
							matriz1 = matrizA("matriz1.txt", &tamanio);
							
							printf("\nCARGANDO MATRIZ 1: \n\n");

							mostrarMatriz(matriz1, tamanio);
							
						}else{
							
							printf("No existe el archivo matriz1.txt\n");
							
						}
						
						if(archivo = fopen("matriz2.txt", "r")){
							
							matriz2 = matrizA("matriz2.txt", &tamanio);
							
							printf("\nCARGANDO MATRIZ 2: \n\n");
							
							mostrarMatriz(matriz2, tamanio);
							
						}else{
							
							printf("No existe el archivo matriz2.txt\n");
							
						}
						
						break;
				
					case 2:
				
						printf("Ingrese el tamanio de las matrices: ");
						scanf("%d", &tamanio);
									
						matriz1 = reservarMemoriaMatriz(tamanio);	
	
	
						matriz2 = reservarMemoriaMatriz(tamanio);	
				
						if(matriz1 == NULL && matriz2 == NULL){
							
							printf("No se pudo reservar memoria");
							
						}else{
							
							printf("INGRESE LOS DATOS DE LA MATRIZ 1: \n\n");
							
							leerMatriz(matriz1, tamanio);
							
							printf("\n\nINGRESE LOS DATOS DE LA MATRIZ 2: \n\n");
							
							leerMatriz(matriz2, tamanio);
							
							guardarMatriz("matriz1.txt", matriz1, tamanio);
		
							guardarMatriz("matriz2.txt", matriz2, tamanio);
			
						}
						
					break;
					
				}
					
				break;
			
			case 2: 
			
				if(! tamanio){
				
					printf("No hay elementos ingresados");
				
				}else{
			
					printf("MOSTRANDO SUMA DE MATRICES: \n\n");
			
					sumarMatrices(matriz1, matriz2, tamanio);
			
				}
			
				break;
				
			case 3:
				
				if(! tamanio){
				
					printf("No hay elementos ingresados");
				
				}else{
				
					printf("MOSTRANDO RESTA DE MATRICES: \n\n");

					restarMatrices(matriz1, matriz2, tamanio);
				
				}
				
				break;
				
			case 4:
			
				if(! tamanio){
				
					printf("No hay elementos ingresados");
				
				}else{
							
					printf("MOSTRANDO MULTIPLICACION DE MATRICES: \n\n");
			
					multiplicarMatrices(matriz1, matriz2, tamanio);
			
				}
			
				break;
				
			case 5:
			
				if(! tamanio){
				
					printf("No hay elementos ingresados");
				
				}else{
				
					printf("MOSTRANDO LA MATRIZ ESCALAR 1: \n\n");
				
					multiplicarMatrizPorEscalar(matriz1, tamanio);

					printf("\n\nMOSTRANDO LA MATRIZ ESCALAR 1: \n\n");

					multiplicarMatrizPorEscalar(matriz2, tamanio);
				
				}
			
				break;		
			
			case 6:
				
				if(! tamanio){
				
					printf("No hay elementos ingresados");
				
				}else{
				
					printf("MOSTRANDO TRANSPUESTA DE MATRIZ 1: \n\n");
						
					transpuesta(matriz1, tamanio);
				
					printf("\n\nMOSTRANDO TRANSPUESTA DE MATRIZ 2: \n\n");

					transpuesta(matriz2, tamanio);
				
				}
				
				break;
			
			case 7:
				
				if(! tamanio){
				
					printf("No hay elementos ingresados");
				
				}else{
				
					printf("MOSTRANDO LA MATRIZ IDENTIDAD 1: \n\n");
				
					inversa(matriz1, tamanio);

					printf("\n\nMOSTRANDO LA MATRIZ IDENTIDAD 2: \n\n");

					inversa(matriz2, tamanio);
				
				}
				
				break;
				
			case 8:
			
					if(! tamanio){
				
					printf("No hay elementos ingresados");
				
				}else{
				
					printf("MOSTRANDO LA DETERMINANTE DE LA MATRIZ 1: \n\n");
				
					determinante(matriz1, tamanio);

					printf("\n\nMOSTRANDO LA DETERMINANTE DE LA MATRIZ 2: \n\n");

					determinante(matriz2, tamanio);
				
				}
			
				break;	
			
			case 9: 

				liberarMemoriaMatriz(matriz1, tamanio);

				liberarMemoriaMatriz(matriz2, tamanio);
			
				printf("Regresando al menu principal....\n");
				
				break;
			
			default: 
				
				printf("Opcion invalida");
			
		}
		
		printf("\n\n");
		system("pause");
		
	}while(opcion != 9);	
	
}
