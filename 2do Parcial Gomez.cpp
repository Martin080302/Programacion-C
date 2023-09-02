/*Programa para adquirir, resguardar, presentar y buscar datos, relativos de:	
	Tema 2 ·         Variables climáticas.	
	Funciones del programa:
	·         Solicitar datos permanentemente, hasta que el usuario lo desee.  (Aprobado Básico)
	·         Contener algunos o todos los datos, en alguna etapa del programa en una lista enlazada.  (Aprobado Básico)
	·         Utilización de estructuras adecuadamente. (Aprobado Básico)
	-----------------
	·         Utilización de funciones. (+1)
	·         Resguardar datos en un archivo.  (+1)
	·         Permitir obtener los datos, posteriormente desde un archivo. (+1)
	·         Permitir realizar búsquedas de datos al usuario, según algún criterio elegido. (+2)*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

struct Nodo{
	char localidad[50];
	int temperatura;
	int dia;
	int mes;
	struct Nodo *siguiente;
};

void mostrarClima(struct Nodo *nodo);
void agregarClima();
void guardarClima();
void recuperarClima();
void buscarTemperatura();
void buscarLocalidad();
void buscarMes();

Nodo *lista = NULL;

int main()	{
	int z;
	
	do{
		printf("\n---------Menu---------");
		printf("\n\n1. Agregar clima"); 
		printf("\n2. Guardar climas en un archivo");
		printf("\n3. Recuperar climas de un archivo");
		printf("\n4. Realizar busqueda de Temperatura");
		printf("\n5. Realizar busqueda de Localidad");
		printf("\n6. Realizar busqueda por Mes");
		printf("\n7. Mostrar Lista de Climas");
		printf("\n8. Salir");
		printf("\n\n Ingrese una opcion: ");
		scanf("%d",&z);
		
		switch(z)
		{
		case 1:
			agregarClima();
			break;
		case 2:
			guardarClima();
			break;
		case 3:
			recuperarClima();
			break;
		case 4:
			buscarTemperatura();
			break;
		case 5: 
			buscarLocalidad();
			break;
		case 6:
			buscarMes();
			break;
		case 7:
			if(lista == NULL)
			{
				printf("No hay climas cargados");
				break;
			}
			while(lista != NULL)
			{
				mostrarClima(lista);
				lista = lista->siguiente;
			}
			break;
		case 8:
			printf("\nHasta luego!!");
			break;
		default:
			printf("Opción inválida. Por favor, intente nuevamente.\n");
			break;
		}
		
		
		
	} while(z != 8);
	
	
}

void agregarClima()
{
	
	struct Nodo *nuevo_nodo = new Nodo();
	
	printf("\nIngrese Temperatura: ");
	scanf("%d", &nuevo_nodo->temperatura);
	getchar();
	
	printf("\nIngrese la localidad: ");
	fgets(nuevo_nodo->localidad, 50, stdin);
	nuevo_nodo->localidad[strcspn(nuevo_nodo->localidad, "\n")] = '\0';
	
	printf("\nIngrese el dia: ");
	scanf("%d", &nuevo_nodo->dia);
	
	printf("\nIngrese el mes: ");
	scanf("%d", &nuevo_nodo->mes);
	
	nuevo_nodo->siguiente = lista;
	lista = nuevo_nodo;
	
	printf("\n\nClima agregado correctamente.\n");
}
void guardarClima()
{
	FILE *archivo = fopen("Climas.bin","ab+");
	if(archivo == NULL)
	{
		printf("\nNo se pudo abrir el archivo para escritura.");
		return;
	}
	Nodo *actual = lista;
	while(actual != NULL)
	{
		fwrite(actual,sizeof(struct Nodo),1,archivo);
		actual = actual->siguiente;
	}
	fclose(archivo);
	printf("\nEl archivo se guardo correctamente.");
}
void recuperarClima()
{
	FILE *archivo = fopen("Climas.bin", "rb");
	if (archivo == NULL) 
	{
		printf("No se pudo abrir el archivo para lectura.\n");
		return;
	}
	
	struct Nodo nodo;
	
	while (fread(&nodo, sizeof(struct Nodo), 1, archivo) == 1) 
	{
		struct Nodo *nuevo_nodo = (struct Nodo *)malloc(sizeof(struct Nodo));
		if (nuevo_nodo == NULL) 
		{
			printf("Error al asignar memoria para el nuevo clima.\n");
			break;
		}
		
		*nuevo_nodo = nodo;
		
		nuevo_nodo->siguiente = lista;
		lista = nuevo_nodo;
	}
	
	fclose(archivo);
	printf("La lista se recuperó correctamente.\n");
	
	Nodo *actual = lista;
	
	while(actual != NULL)
	{
		mostrarClima(actual);
		actual = actual->siguiente;
	}
}
void mostrarClima(struct Nodo *nodo) 
{
	printf("\n\nTemperatura: %d\n", nodo->temperatura);
	printf("Localiad: %s\n", nodo->localidad);
	printf("Dia: %d\n", nodo->dia);
	printf("Mes: %d\n\n", nodo->mes);
}
void buscarTemperatura()
{
	int temp;
	printf("\nIngrese la temperatura a buscar: ");
	scanf("%d", &temp);
	
	Nodo *actual = lista;
	bool band = false;
	
	while(actual != NULL)
	{
		if (actual->temperatura == temp)
		{
			band = true;
			mostrarClima(actual); 
			break;
		}
		actual = actual->siguiente;
	}
	if (!band)
	{
		printf("\nLa temperatura %d no fue encontrada en la lista\n", temp);
	}
}
void buscarLocalidad()
{
	char localidad[50];
	printf("\nIngrese la Localidad a buscar: ");
	scanf("%s", localidad);
	
	Nodo *actual = lista;
	bool band = false;
	
	while(actual != NULL)
	{
		if(strcmp(actual->localidad,localidad) == 0)
		{
			band = true;
			mostrarClima(actual);
		}
		actual = actual->siguiente;
	}
	if(!band)
	{
		printf("\nLa localidad %s no fue encontrada en la lista", localidad);
	}
}
void buscarMes()
{
	int mes;
	printf("\nIngrese el mes a buscar: ");
	scanf("%d", &mes);
	
	Nodo *actual = lista;
	bool band = false;
	
	while(actual != NULL)
	{
		if (actual->mes == mes)
		{
			band = true;
			mostrarClima(actual); 
			break;
		}
		actual = actual->siguiente;
	}
	if (!band)
	{
		printf("\nEl mes %d no fue encontrado en la lista\n", mes);
	}
}
