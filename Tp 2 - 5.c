#include <stdio.h>

int main() {
	char cadena[100];
	char *ptr;
	
	printf("Ingrese una cadena: ");
	fgets(cadena, 100, stdin);
	
	ptr = cadena;
	
	// mover el puntero al final de la cadena
	while (*ptr != '\0') {
		ptr++;
	}
	
	ptr--; // retroceder un caracter para evitar el carácter nulo
	
	// imprimir los caracteres en orden inverso
	while (ptr >= cadena) {
		printf("%c", *ptr);
		ptr--;
	}
	
	printf("\n");
}
