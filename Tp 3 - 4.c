#include <stdio.h>

struct punto {
	float x;
	float y;
};

int main() {
	int n = 100;
	struct punto funcion[n];
	float paso = 10.0 / n;
	float x = -5.0;
	for (int i = 0; i < n; i++) {
		funcion[i].x = x;
		funcion[i].y = x * x;
		x += paso;
	}
	
	float m, b;
	printf("Ingrese la pendiente: ");
	scanf("%f", &m);
	printf("Ingrese la ordenada al origen: ");
	scanf("%f", &b);
	
	int corta = 0;
	int corta_mas_de_una_vez = 0;
	for (int i = 0; i < n; i++) {
		float y_linea = m * funcion[i].x + b;
		if (y_linea == funcion[i].y) {
			corta = 1;
			if (i > 0 && y_linea == funcion[i-1].y) {
				corta_mas_de_una_vez = 1;
			}
			if (i < n-1 && y_linea == funcion[i+1].y) {
				corta_mas_de_una_vez = 1;
			}
		}
	}
	
	if (corta) {
		printf("La línea corta la función");
		if (corta_mas_de_una_vez) {
			printf(" más de una vez.\n");
		} else {
			printf(" una vez.\n");
		}
	} else {
		printf("La línea no corta la función.\n");
	}
	
	return 0;
}
