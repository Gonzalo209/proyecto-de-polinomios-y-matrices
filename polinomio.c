#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"
#include <string.h>

void guardarPolinomio(const char nombreArchivo[], Polinomio *polinomio, int total){
	
	FILE *archivo = fopen(nombreArchivo, "w");
	char linea[80], buffer[10];
	int i, j, longitud = 0;
	
	if (! archivo){
	
		printf("No se pudo abrir el archivo");
	
	}else{
	
		sprintf(linea, "%d \n", total);
		
		fputs(linea, archivo);
		
		for(i = 0; i < total; i++){
			
			linea[0] = '\0';
			
			sprintf(buffer, "%d %d", polinomio[i].termino.coeficiente, polinomio[i].termino.exponente);
			
			strcat(linea, buffer);
		
			longitud = strlen(linea);
			
			linea[longitud - 1] = '\n';
			
			fputs(linea, archivo);
		
		}
	
	}
		
	fclose(archivo);
	
}

Polinomio* polinomioA(const char nombreArchivo[], int *total){
	
	FILE *archivo = fopen(nombreArchivo, "r");
	char linea[80];
	int i, j;
	if (! archivo){
	
		printf("No se pudo abrir el archivo");
	
	}else{
	
		fgets(linea, 79, archivo); 
		
		char *token = strtok(linea, " ");
		
		*total = atoi(token);
		
		Polinomio *polinomio = (Polinomio*) malloc(*total * sizeof(Polinomio));
		
		for (i = 0; i < *total; i++) {
			
			fgets(linea, 79, archivo);
			
			token = strtok(linea, " ");
			
			polinomio[i].termino.coeficiente = atoi(token);

			token = strtok(linea, " ");

			polinomio[i].termino.exponente = atoi(token);

					
		}
		
		return polinomio;
		
	}
	
	fclose(archivo);
	
	
}

Polinomio* reservarMemoria(int total){
	
	Polinomio* polinomio;
	
	polinomio = malloc(sizeof(Polinomio) * total);
	
	return polinomio;	
}

void liberarMemoria(Polinomio *polinomio, int total){
	
	if(total != 0){

		free(polinomio);

	}
	
}

void leerPolinomio(Polinomio *polinomio, int cantidadPolinomio){
	
	int i;
		
	for(i = 0; i < cantidadPolinomio; i++){
		
		printf("\n\n:::::::::::::::::::::::::::::::::\n");
		printf("Polinomio: %d\n", i + 1);
		printf(":::::::::::::::::::::::::::::::::\n");
		
		printf("Digite coeficiente del cuadrado: "); 
		scanf("%d", &polinomio[i].termino.coeficiente);		

		printf("Digite coeficiente de grado: "); 
		scanf("%d", &polinomio[i].termino.exponente);
		
	}
	
}

void mostrarPolinomio(Polinomio *polinomio, int totalPolinomio){
	
	int i;
	
	for(i = totalPolinomio - 1; i >= 0; i--){
		
		if(polinomio[i].termino.coeficiente >= 0){
			
			printf(" + ");
			
		}
		
		printf(" %d", polinomio[i].termino.coeficiente);
			
		printf("x%d", polinomio[i].termino.exponente);
	
	}
			
}

void sumarPolinomios(Polinomio *polinomio1, Polinomio *polinomio2, int totalPolinomio1,
					int totalPolinomio2){
	
	int i, j, totalPolinomios;
	Polinomio* suma = reservarMemoria(totalPolinomio1 + totalPolinomio2);
	
	totalPolinomios = 0;
	i = 0;
	j = 0;
	
	if(suma != NULL){
	
		while(i < totalPolinomio1 && j < totalPolinomio2){
		
			if(polinomio1[i].termino.exponente == polinomio2[j].termino.exponente){
			
					suma[totalPolinomios].termino.exponente = polinomio1[i].termino.exponente;
				
					suma[totalPolinomios++].termino.coeficiente = polinomio1[i].termino.coeficiente + polinomio2[j].termino.coeficiente;
					
			}else{	
			
				suma[totalPolinomios++].termino = polinomio1[i].termino = polinomio2[j].termino;
			
			}
		
			i++; j++;
		
		}
			
		mostrarPolinomio(suma, totalPolinomios);
	
		liberarMemoria(suma, totalPolinomios);
	
	}else{
		
		printf("No se pudo reservar memoria");
		
	}
	
}

void restarPolinomios(Polinomio *polinomio1, Polinomio *polinomio2, int cantidadPolinomio1, 
				int cantidadPolinomio2){
	
	int i;

	cambiarSigno(polinomio2, cantidadPolinomio2);

	sumarPolinomios(polinomio1, polinomio2, cantidadPolinomio1, cantidadPolinomio2);
	
	cambiarSigno(polinomio2, cantidadPolinomio2);

}

void multiplicarEscalarPolinomio(Polinomio *polinomio, int totalPolinomio){
	
	Polinomio *multPoli;
	int total = 0, i, mult = 1;
	
	multPoli = reservarMemoria(totalPolinomio);
	
	if(multPoli != NULL){
	
		for(i = 0; i < totalPolinomio; i++){
			
			mult = 2 * polinomio[i].termino.coeficiente;
			
			multPoli[total++].termino.coeficiente = mult;
			
		}
		
		mostrarPolinomio(multPoli, total);
		
		printf("\n\n");
		
		for(i = 0; i < total; i++){
			
			printf("%dx%d ", multPoli[i].termino.coeficiente, polinomio[i].termino.exponente);
			
		}
		
		liberarMemoria(multPoli, total);
	
	}else{
		
		printf("No se pudo reservar memoria");
		
	}
	
}

void dividirPolinomio(Polinomio *polinomio, int totalPolinomio){
	
	Polinomio *divPol;
	int mult = 1, residuo = 0, tot = 0, resultado;
	int i;
	
	divPol = reservarMemoria(totalPolinomio);

	if(divPol != NULL){
		
		printf("Ingrese el residuo: ");
		scanf("%d", &residuo);
		
		divPol[tot++].termino.coeficiente = polinomio[0].termino.coeficiente;
		int t = 0;
		
		mult = residuo * (polinomio[0].termino.coeficiente *= -1);
		
		for(i = 1; i < totalPolinomio; i++){
			
			resultado = mult + (polinomio[i].termino.coeficiente *= 1);
			
			divPol[tot++].termino.coeficiente = resultado;
			
			mult = (residuo * resultado) * -1;
				
		}
		
		for(i = 0; i < tot; i++){
			
			printf("%d ", divPol[i].termino.coeficiente);
			
		}
		
	
	}else{
		
		printf("No se pudo reservar memoria");
		
	}
	
}

void multiplicarPolinomios(Polinomio *polinomio1, Polinomio *polinomio2, 
							int totalPolinomio1, int totalPolinomio2){
	
	int i, j, k, mult = 1, sum = 0, l = 0, p, o;
	Polinomio* multiplicacion;
	
	multiplicacion = reservarMemoria(totalPolinomio1 * totalPolinomio2);
	
	if(multiplicacion != NULL){
					
		for(i = 0; i < totalPolinomio1; i++){
			
			multiplicacion[k].termino.coeficiente = 0;
			
			multiplicacion[l].termino.exponente = 0;
				
			for(j = 0; j < totalPolinomio2; j++){
					
				mult = polinomio1[i].termino.coeficiente * polinomio2[j].termino.coeficiente;
					
				sum = polinomio1[i].termino.exponente + polinomio2[j].termino.exponente;	
					
				multiplicacion[k++].termino.coeficiente = mult;
					
				multiplicacion[l++].termino.exponente = sum;	
			}
				
		}
				
		for(i = 0; i < k && i < l; i++){
			
			printf("%dx%d ", multiplicacion[i].termino.coeficiente, multiplicacion[i].termino.exponente);
			
		}
		
		printf("\n\nSuma de Polinomio\n\n");
		
		sumarPolinomio(multiplicacion, k, l);
		
		liberarMemoria(multiplicacion, totalPolinomio1 + totalPolinomio2);
			
	}else{
		
		printf("No se pudo reservar memoria");
		
	}
			
}

void sumarPolinomio(Polinomio *multiplicacion, int coeficiente, int exponente){
	
	Polinomio *suma;
	int i, j, p;
	
	suma = reservarMemoria(coeficiente + exponente);
	
	if(suma != NULL){
		
		i = 0;
		j = 0;
		p = 0;
		
		int sumar = 0;
				
		while(i < coeficiente && i < exponente){
				
			if(multiplicacion[i].termino.exponente == multiplicacion[i + 1].termino.exponente){
					
				suma[p].termino.exponente = multiplicacion[i].termino.exponente; 
					
				sumar = multiplicacion[i].termino.coeficiente + multiplicacion[i].termino.coeficiente;
					
				suma[p++].termino.coeficiente = sumar;
					
			}else{
					
				suma[p++].termino = multiplicacion[i].termino;
					
			}
				
			i++;
				
		}
		
		mostrarPolinomio(suma, p);
		
		liberarMemoria(suma, p);
		
	}else{
		
		printf("No se pudo reservar memoria");
		
	}
		
}

void ordenarPolinomio(Polinomio *polinomio, int cantidadPolinomio){
	
	int intercambio, i, j;
	
	for(i = 1; i < cantidadPolinomio; i++){
		
		for(j = 0; j < cantidadPolinomio - i; j++){
			
			if(polinomio[j].termino.exponente > polinomio[j + 1].termino.exponente){
				
				intercambio = polinomio[j].termino.exponente;
				
				polinomio[j].termino.exponente = polinomio[j + 1].termino.exponente;
				
				polinomio[j + 1].termino.exponente = intercambio;
				
			}
			
			
		}
		
	}
	
}

void cambiarSigno(Polinomio *polinomio2, int cantidadPolinomio){
	
	int i;
	
	for(i = 0; i < cantidadPolinomio; i++){
		
		polinomio2[i].termino.coeficiente *= -1;
		
	}
	
}
