#include <stdio.h>

struct punto {
	float x;
	float y;
};

int main() {
	const int n = 100; // Tamaño fijo del arreglo
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
			if (i > 0 && y_linea == funcion[i - 1].y) {
				corta_mas_de_una_vez = 1;
			}
			if (i < n - 1 && y_linea == funcion[i + 1].y) {
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
	
	int z;
	FILE *file; // Declaramos file fuera del switch
	
	while (z != 3) {
		printf("\nMenu");
		printf("\n1. Guardar el archivo");
		printf("\n2. Mostrar el archivo");
		printf("\n3. Salir");
		printf("\n\nIngrese una opción: ");
		scanf("%d", &z);
		
		switch (z) {
		case 1:
			// Guardar en archivo
			file = fopen("funcion.bin", "wb"); // Abre el archivo en modo escritura binaria
			if (file == NULL) {
				printf("No se pudo abrir el archivo.\n");
				return 1;
			}
			fwrite(funcion, sizeof(struct punto), n, file); // Escribe el arreglo de estructuras en el archivo
			fclose(file); // Cierra el archivo
			printf("\nSe guardo correctamente");
			break;
		case 2:
			// Mostrar desde el archivo
			file = fopen("funcion.bin", "rb"); // Abre el archivo en modo lectura binaria
			if (file == NULL) {
				printf("No se pudo abrir el archivo.\n");
				return 1;
			}
			struct punto funcion_leida[n];
			fread(funcion_leida, sizeof(struct punto), n, file); // Lee el arreglo de estructuras desde el archivo
			fclose(file); // Cierra el archivo
			// Mostrar las estructuras leídas desde el archivo
			for (int i = 0; i < n; i++) {
				printf("Punto %d: (%f, %f)\n", i, funcion_leida[i].x, funcion_leida[i].y);
			}
			break;
		case 3:
			printf("\nHasta luego.\n");
			break;
		default: 
			printf("\nOpción inválida.\n");
			break;
		}
	}
	
	return 0;
}
