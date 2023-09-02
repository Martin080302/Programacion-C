#include <stdio.h>

void funcion_contador(char *cadena, int *letras, int *numeros, int *especial);

int main()
{
	char cadena[100];
	int letras = 0, numeros = 0, especial = 0;
	printf("Ingrese una cadena de caracteres: ");
	fgets(cadena,100,stdin);
	
	funcion_contador(cadena, &letras, &numeros, &especial);
	printf("La cantidad de letras que hay en la cadena son de: %d",letras);
	printf("La cantidad de numeros que hay en la cadena son de: %d",numeros);
	printf("La cantidad de simbolos especiales que hay en la cadena son de: %d",especial);
}

void funcion_contador(char *cadena, int *letras, int *numeros, int *especial)
{
	while(*cadena !='\n')
	{
		if(*cadena != ' ')
		{
		    ;	
		}
		else
		{
		if(*cadena >= '0' && *cadena <='9')
		{
			(*numeros) ++;
		}
		else if ((*cadena >= 'A' && *cadena <= 'Z') || (*cadena >= 'a' && *cadena <= 'z'))
		{
			(*letras) ++;
		}
		else
		{
			(*especial) ++;
		}
		}
	}
}
