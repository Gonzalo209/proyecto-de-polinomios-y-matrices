#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

void guardarMatriz(const char nombreArchivo[], int **matriz, int tamanio){
	
	FILE *archivo = fopen(nombreArchivo, "w");
	char linea[80], buffer[10];
	int i, j, longitud = 0;
	
	if (! archivo){
	
		printf("No se pudo abrir el archivo");
	
	}else{
	
		sprintf(linea, "%d \n", tamanio);
		
		fputs(linea, archivo);
		
		for(i = 0; i < tamanio; i++){
			
			linea[0] = '\0';
			
			for(j = 0; j < tamanio; j++){
				
				sprintf(buffer, "%d ", matriz[i][j]);
			
				strcat(linea, buffer);
			
			}
			
			longitud = strlen(linea);
			
			linea[longitud - 1] = '\n';
			
			fputs(linea, archivo);
		
		}
	
	}
		
	fclose(archivo);
	
}

int** matrizA(const char nombreArchivo[], int* tamanio){
	
	FILE *archivo = fopen(nombreArchivo, "r");
	char linea[80];
	int i, j;
	if (! archivo){
	
		printf("No se pudo abrir el archivo");
	
	}else{
	
		fgets(linea, 79, archivo); 
		
		char *token = strtok(linea, " ");
		
		*tamanio = atoi(token);
		
		int **matriz = (int**) malloc(*tamanio * sizeof(int *));;
		
		for (i = 0; i < *tamanio; i++) {
			
			matriz[i] = (int*) malloc(*tamanio * sizeof(int));
			
			fgets(linea, 79, archivo);
			
			token = strtok(linea, " ");
			
			matriz[i][0] = atoi(token);
			
			for (j = 1; j < *tamanio; j++) {
		
				token = strtok(NULL, " ");
				
				matriz[i][j] = atoi(token);
			
			}
		
		}
		
		return matriz;
		
	}
	
	fclose(archivo);
	
	
}

int** reservarMemoriaMatriz(int tamanio){
	
	int** matriz;
	int i;
	
	matriz = (int**) malloc(tamanio * sizeof(int *));
	
	for(i = 0; i < tamanio; i++){
		
		matriz[i] = (int*) malloc(sizeof(int) * tamanio);
		
	}
	
	return matriz;
	
}

void liberarMemoriaMatriz(int **matriz, int tamanio){
	
	int i;

	if(tamanio != 0){
	
		for(i = 0; i < tamanio; i++){
		
			free(matriz[i]);
		
		}
	
		free(matriz);
	
	}
	
}

void leerMatriz(int **matriz, int tamanio){
	
	int i, j;
	
	for(i = 0; i < tamanio; i++){
		
		for(j = 0; j < tamanio; j++){
			
			printf("Ingrese el numero [%d, %d]: ", i + 1, j + 1);
			scanf("%d", &matriz[i][j]);
			
		}
		
	}
	
}

void mostrarMatriz(int **matriz, int tamanio){
	
	int i, j;
	
	for(i = 0; i < tamanio; i++){
		
		for(j = 0; j < tamanio; j++){
	
			printf("%d ", matriz[i][j]);
			
		}
		printf("\n");
	}
	
}

void sumarMatrices(int **matriz1, int **matriz2, int tamanio){
	
	int i, j;
	int** suma = reservarMemoriaMatriz(tamanio);
	
	if(suma != NULL){
	
		for(i = 0; i < tamanio; i++){
			
			for(j = 0; j < tamanio; j++){
				
				suma[i][j] = matriz1[i][j] + matriz2[i][j];
				
			}
			
		}
		
		mostrarMatriz(suma, tamanio);
		
		liberarMemoriaMatriz(suma, tamanio);
	
	}else{
		
		printf("No se pudo reservar memoria");
		
	}
	
}

void restarMatrices(int **matriz1, int **matriz2, int tamanio){
	
	int i, j;
	int** resta = reservarMemoriaMatriz(tamanio);
	
	if(resta != NULL){
	
		for(i = 0; i < tamanio; i++){
			
			for(j = 0; j < tamanio; j++){
				
				resta[i][j] = matriz1[i][j] - matriz2[i][j];
				
			}
			
		}
		
		mostrarMatriz(resta, tamanio);
		
		liberarMemoriaMatriz(resta, tamanio);
	
	}else{
		
		printf("No se pudo reservar memoria");
		
	}
	
}

void multiplicarMatrices(int **matriz1, int **matriz2, int tamanio){
	
	int i, j, k, result;
	int** multiplicacion = reservarMemoriaMatriz(tamanio);

	if(multiplicacion != NULL){
	
		for(i = 0; i < tamanio; i++){
			
			for(j = 0; j < tamanio; j++){
		
				multiplicacion[i][j] = 0;
			
				for(k = 0; k < tamanio; k++){
				
					result = matriz1[i][k] * matriz2[k][j];
					
					multiplicacion[i][j] += result;
					
				}
				
			}
			
		}
	
		mostrarMatriz(multiplicacion, tamanio);
	
		liberarMemoriaMatriz(multiplicacion, tamanio);
	
	}else{
		
		printf("No se pudo reservar memoria");
		
	}
	
}

void multiplicarMatrizPorEscalar(int **matriz, int tamanio){
	
	int i, j, mult = 1;
	int** multiplicacion = reservarMemoriaMatriz(tamanio);
	
	if(multiplicacion != NULL){
		
		for(i = 0; i < tamanio; i++){
		
			for(j = 0; j < tamanio; j++){

				mult = 2 * matriz[i][j]; 
				
				multiplicacion[i][j] = mult;
				
			}
		
		}

		mostrarMatriz(matriz, tamanio);
		
		liberarMemoriaMatriz(matriz, tamanio);

	}else{
		
		printf("No se pudo reservar memoria");
		
	}

}

void transpuesta(int **matriz, int tamanio){
	
	int i, j;
	
	for(i = 0; i < tamanio; i++){
		
		for(j = 0; j < tamanio; j++){
	
			printf("%d ", matriz[j][i]);
			
		}
		printf("\n");
	}
	
}

void inversa(int **matriz, int tamanio){
	
	int reduccion, i, j, k, noDiagonal;
	int** identidad = reservarMemoriaMatriz(tamanio);
	
	matrizIdentidad(identidad, tamanio);
	
	for(i = 0; i < tamanio; i++){
			
		reduccion = matriz[i][i];
			
		for(j = 0; j < tamanio; j++){
				
			matriz[i][j] /= reduccion;
			
			identidad[i][j] /= reduccion;
								
		}
			
		for(k = 0; k < tamanio; k++){
				
			if(i != k){
					
				noDiagonal = matriz[k][i];
					
				for(j = 0; j < tamanio; j++){
						
					matriz[k][j] -= noDiagonal * matriz[i][j];
					
					identidad[k][j] -= noDiagonal * identidad[i][j];		
								
				}
					
			}
				
		}
			
	}
	
	printf("MOSTRANDO MATRIZ: \n\n");
		
	mostrarMatriz(matriz, tamanio);

	printf("\nMOSTRANDO IDENTIDAD: \n\n");

	mostrarMatriz(identidad, tamanio);
		
}

void matrizIdentidad(int **matriz, int tamanio){
	
	int i, j;
	
	for(i = 0; i < tamanio; i++){
	
		for(j = 0; j < tamanio; j++){
		
			matriz[i][j] = 0;
			
			if(i == j){
				
				matriz[i][j] = 1;
				
			}
		
		}
		
	}
	
}

void determinante(int **matriz, int tamanio){
	
	
}	
