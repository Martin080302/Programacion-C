#include <stdio.h>	
#include  <string.h>

int main()
{
	char origen[100], destino[100], palabra1[100], palabra2[100];
	char lineas[10000];
	char *p;
	FILE *archivoorigen;
	FILE *archivodestino;
	printf("\nIngrese el nombre del archivo que desea verificar: ");
	scanf("%s", origen);
	
	archivoorigen = fopen(origen, "r");
	if(archivoorigen == NULL)
	{
		printf("\nEL archivo ingresado no se puede abrir o no existe");
		return 0;
	}
	printf("\nIngrese el nombre del segundo archivo que desea verificar:");
	scanf("%s", destino);
	archivodestino = fopen(destino,"w");
	if(archivoorigen == NULL)
	{
		printf("\nEL archivo ingresado no se puede abrir o no existe");
		return 0;
	}
	printf("\nIngrese la primer palabra: ");
	scanf("%s", palabra1);
	printf("\nIngrese la segunda palabra: ");
	scanf("%s", palabra2);
	int tp;
	tp = strlen(palabra1);
	while (fgets(lineas, sizeof(lineas), archivoorigen) != NULL)
	{
	}
	p = strstr(lineas, palabra1);
	if(p == '\0')
	{
		printf("La palabra ingresada no se encuentra en el archivo");
	}
	while(p != '\0')
	{
		strncpy(p, palabra2, tp);
		p = strstr(lineas, palabra1);
	}
	fputs(lineas, archivodestino);
	fclose(archivoorigen);
	fclose(archivodestino);
}
