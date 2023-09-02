#include <stdio.h>

void contador(char *cadena, int *letras, int *numeros, int *especiales);

int main()
{
	char cadena[100];
	int letras = 0, numeros = 0, especiales = 0;
	
	printf("Ingrese una cadena: ");
	fgets(cadena, 100, stdin);
	
	contador(cadena, &letras, &numeros, &especiales);
	
	printf("Cantidad de letras: %d\n", letras);
	printf("Cantidad de numeros: %d\n", numeros);
	printf("Cantidad de caracteres especiales: %d\n", especiales);
}

void contador(char *cadena, int *letras, int *numeros, int *especiales)
{
	while (*cadena != '\0') {
		if(*cadena >= '0' && *cadena <='9')
		{
			(*numeros) ++;
		}
		else if ((*cadena >= 'A' && *cadena <= 'Z') || (*cadena >= 'a' && *cadena <= 'z'))
		{
			(*letras) ++;
		}
		else if (*cadena == ' ' || *cadena == '\n')
		{
			
		}
		else
		{
			(*especiales) ++;
		}
		cadena++;
	}
}
