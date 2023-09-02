#include <stdio.h>

#define N 100

typedef struct {
	float x;
	float y;
} Punto;

int main() {
	float pendiente, ordenada_al_origen;
	int i, corta_funcion = 0, cortes = 0;
	Punto puntos[N];
	
	// Obtener los parámetros de la función lineal
	printf("Ingrese la pendiente: ");
	scanf("%f", &pendiente);
	printf("Ingrese la ordenada al origen: ");
	scanf("%f", &ordenada_al_origen);
	
	// Generar los puntos de la función y almacenarlos en el arreglo
	for (i = 0; i < N; i++) {
		puntos[i].x = -5 + (i * 0.1);
		puntos[i].y = pendiente * puntos[i].x + ordenada_al_origen;
	}
	
	// Verificar si la línea corta a la función y cuántas veces lo hace
	for (i = 0; i < N; i++) {
		if ((puntos[i].y >= -1) && (puntos[i].y <= 1)) {
			cortes++;
			if (!corta_funcion) {
				corta_funcion = 1;
			}
		}
	}
	
	// Mostrar los resultados
	if (corta_funcion) {
		printf("La línea corta la función.");
		if (cortes > 1) {
			printf(" La línea corta la función más de una vez en el rango de x de -5 a +5.");
		} else {
			printf(" La línea corta la función una vez en el rango de x de -5 a +5.");
		}
	} else {
		printf("La línea no corta la función.");
	}
	
	return 0;
}
