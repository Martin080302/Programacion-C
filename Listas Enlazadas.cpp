#include <iostream>
#include <conio.h>
#include <stdlib.h>

struct Nodo{
	int dato;
	struct Nodo *siguiente;
};

void insertarLista(struct Nodo *&lista, int n);
void mostrarLista(struct Nodo *lista);
void buscarLista(struct Nodo *lista, int n);
void eliminarNodo(struct Nodo *&lista, int n);
void eliminarLista(struct Nodo *&lista, int &n);

Nodo *lista = NULL;

int main()
{
	int dato;
	printf("Inserte un dato");
	scanf("%d",&dato);
	insertarLista(lista,dato);
	
	printf("Inserte un dato");
	scanf("%d",&dato);
	insertarLista(lista,dato);
	
	printf("Inserte un dato");
	scanf("%d",&dato);
	insertarLista(lista,dato);
	
	mostrarLista(lista);
}

void insertarLista(Nodo *&lista, int n)
{
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato < n)){  //(aux1->dato < n) ordena la lista de menor a mayor
		aux2 = aux1;
		aux1 = aux1 -> siguiente;
	}
	if(lista == aux1)
	{
		lista = nuevo_nodo;
	}
	else 
	{
		aux2->siguiente = nuevo_nodo;	
	}
	nuevo_nodo->siguiente = aux1;
	printf("\nElemento %d insertado correctamente a la lista",n);
}
void mostrarLista(Nodo *lista)
{
	Nodo *actual = new Nodo();
	
	actual = lista;
	while(actual != NULL)
	{
		printf("\n%d",actual->dato);
		actual = actual->siguiente;
	}
}
void buscarLista(Nodo *lista, int n)
{
	Nodo *actual = new Nodo();
	actual = lista; 
	bool band = false; 
	
	while((actual != NULL) && (actual->dato <= n ))
	{
		if(actual->dato == n)
		{
			band = true;
		}
		actual = actual->siguiente;
	}
	if(band == true)
	{
		printf("\nEL elemento %d si fue encontrado en la lista",n);
	}
	else
	{
		printf("\nEL elemento %d no fue encontrado en la lista",n);
	}
}
void eliminarNodo(Nodo *&lista, int n)
{
	if(lista != NULL)
	{
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		
		aux_borrar = lista;
		//Recorre la lista
		while((aux_borrar != NULL) && (aux_borrar->dato != n))
		{
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		//EL elemento no fue encontrado
		if(aux_borrar == NULL)
		{
			printf("\nEl elemento no existe");
		}
		//El primer elemento es el que vamos a eliminar
		else if(anterior == NULL)
		{
			lista = lista->siguiente;
			delete aux_borrar;
		}
		//EL elemento esta en la lista pero no es el primer nodo
		else
		{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
	else
	{
		printf("\nLa lista esta vacia");
	}
}
void eliminarLista(Nodo *&lista, int &n)
{
	while(lista !=NULL)
	{	
		Nodo *aux = lista;
		n=aux->dato;
		lista = aux->siguiente;
		delete aux;
	}
}
