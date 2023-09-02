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
	
	// Obtener los par�metros de la funci�n lineal
	printf("Ingrese la pendiente: ");
	scanf("%f", &pendiente);
	printf("Ingrese la ordenada al origen: ");
	scanf("%f", &ordenada_al_origen);
	
	// Generar los puntos de la funci�n y almacenarlos en el arreglo
	for (i = 0; i < N; i++) {
		puntos[i].x = -5 + (i * 0.1);
		puntos[i].y = pendiente * puntos[i].x + ordenada_al_origen;
	}
	
	// Verificar si la l�nea corta a la funci�n y cu�ntas veces lo hace
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
		printf("La l�nea corta la funci�n.");
		if (cortes > 1) {
			printf(" La l�nea corta la funci�n m�s de una vez en el rango de x de -5 a +5.");
		} else {
			printf(" La l�nea corta la funci�n una vez en el rango de x de -5 a +5.");
		}
	} else {
		printf("La l�nea no corta la funci�n.");
	}
	
	return 0;
}
