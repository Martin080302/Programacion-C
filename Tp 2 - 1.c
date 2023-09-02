#include <stdio.h>

int longitud_cadena(char *cadena);

int main ()
{
	char cadena1[100], cadena2[100], cadena3[100];
	
	printf("Ingrese la primera cadena de caracteres: ");
	fgets(cadena1, 100, stdin);
	int lon1 =  longitud_cadena(cadena1); 
	
	printf("Ingrese la segunda cadena de caracteres: ");
	fgets(cadena2, 100, stdin);
	int lon2 =  longitud_cadena(cadena2); 
	
	for(int i=0; i<lon1; i++)
	{
		cadena3[i]=cadena1[i];
	}
	cadena3[lon1]=' ';
	int s=lon1+lon2;
	int j=0;
	for(int i=lon1+1; i<=s+1; i++)
	{
		cadena3[i]=cadena2[j];
		j++;
	}
	printf("La cadena resultante es: %s\n", cadena3);
}

int longitud_cadena(char *cadena)
{
	int lon = 0;
	while (*cadena != '\0') 
	{
		if(*cadena != '\n')
		{
			lon++;
		}
		cadena++;
	}
	return lon;
}
