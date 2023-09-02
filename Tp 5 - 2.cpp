#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct sensor {
	char marca[25];
	char model[20];
	char tipo[20];
	char unidad[10];
};

struct medicion {
	struct sensor sens_us;
	char fecha[11];
	char hora[6];
	int valor_med;
	char coment[50];
	struct medicion *siguiente;
	struct medicion *anterior;
};

void nueva_med(struct medicion *&);
void imp_str( struct medicion *);
void elim_med(struct medicion *&,int);
void bus_sen(struct medicion *, char[]);
void bus_val_med(struct medicion *, int);
void recuperar_lista();
void guardarMediciones();
void ordenar_lista();
	
struct medicion *lista = NULL;

int main() {
	int n, el, val;
	char tipo[20];
	
	struct sensor list_sen[3];
	
	// Sensor 1 (de luz)
	strcpy(list_sen[0].marca, "Texsalux");
	strcpy(list_sen[0].model, "F1000");
	strcpy(list_sen[0].tipo, "Sensor de luz");
	strcpy(list_sen[0].unidad, "Lux");
	
	// Sensor 2 (de temperatura)
	strcpy(list_sen[1].marca, "Candy-Ho");
	strcpy(list_sen[1].model, "Lm35");
	strcpy(list_sen[1].tipo, "Sensor de temperatura");
	strcpy(list_sen[1].unidad, "°C");
	
	// Sensor 3 (de sonido)
	strcpy(list_sen[2].marca, "Candy-Ho");
	strcpy(list_sen[2].model, "Lm386");
	strcpy(list_sen[2].tipo, "Sensor de sonido");
	strcpy(list_sen[2].unidad, "dB");

	int cont = 0;
	
	printf("     --    Bienvenido a la base de datos de mediciones    --\n");
	
	do {
		printf("\n  Seleccione una opción:\n");
		printf("  1- Agregar una nueva medición.\n");
		printf("  2- Eliminar una medición existente.\n");
		printf("  3- Búsqueda por sensor.\n");
		printf("  4- Búsqueda por valor medido.\n");
		printf("  5- Guardar en archivo.\n");
		printf("  6- Recuperar mediciones del Archivo.\n");
		printf("  7- Mostrar Mediciones ordenadas por fecha\n");
		printf("  8- Salir.\n\n");
		printf("Opción seleccionada: ");
		scanf("%d", &n);
		
		switch (n) {
		case 1:
			if (cont != 10) {
				nueva_med(lista);
				imp_str(lista);
				cont++;
				getchar();
			} else {
				printf("\n Ya ingresó el máximo de mediciones soportadas.");
			}
			break;
		case 2:
			if (cont == 0) {
				printf("\nERROR, no ingresó ninguna medición.");
			} else {
				printf("\n Ingrese el número de medición a eliminar: ");
				scanf("%d", &el);
				elim_med(lista, el);
			}
			break;
		case 3:
			if (cont == 0) {
				printf("\nERROR, no ingresó ninguna medición.");
			} 
			else {
				printf("\n Ingrese el tipo de sensor a buscar: ");
				fgets(tipo,20,stdin);
				bus_sen(lista, tipo);
			}
			break;
		case 4:
			if (cont == 0) {
				printf("\nERROR, no ingresó ninguna medición.");
			} else {
				printf("\n Ingrese el valor a buscar: ");
				scanf("%d", &val);
				
				bus_val_med(lista, val);
			}
			break;
		case 5:
			guardarMediciones();
		break;
		case 6:
			recuperar_lista();
		break;
		case 7:
			ordenar_lista();
		break;
		case 8:
			printf("\n  --  Adiós  --\n");
			break;
		default:
			printf("\nOpción no válida, por favor intente nuevamente.");
			break;
		}
	} while (n != 8);
}

void nueva_med(struct medicion *&lista) {
	
	medicion *nuevo_nodo = new medicion();
	
	printf("\nIngrese la marca del sensor: ");
	scanf("%s",nuevo_nodo->sens_us.marca);
	
	printf("\nIngrese el modelo del sensor: ");
	scanf("%s",nuevo_nodo->sens_us.model);
	
	printf("\nIngrese el tipo del sensor: ");
	scanf("%s",nuevo_nodo->sens_us.tipo);
	
	printf("\nIngrese la unidad de medida: ");
	scanf("%s",nuevo_nodo->sens_us.unidad);
	
	printf("\nIngrese la fecha (formato dd/mm/yyyy): ");
	scanf("%s",nuevo_nodo->fecha);
	
	printf("\nIngrese la hora (formato hh:mm): ");
	scanf("%s",nuevo_nodo->hora);
	
	printf("\nIngrese comentario");
	scanf("%s",nuevo_nodo->coment);
	
	nuevo_nodo->siguiente = lista;
	lista = nuevo_nodo;
	printf("\nMedicion insertada correctamente en la lista");
}

void imp_str(struct medicion *actual) {
	
	printf("\nMarca del sensor: %s\n", lista->sens_us.marca);
	printf("Modelo del sensor: %s\n", lista->sens_us.model);
	printf("Tipo del sensor: %s\n", lista->sens_us.tipo);
	printf("Unidad de medida: %s\n", lista->sens_us.unidad);
	printf("Fecha: %s\n", lista->fecha);
	printf("Hora: %s\n", lista->hora);
	printf("Valor medido: %d\n", lista->valor_med);
	printf("Comentario: %s\n", lista->coment);
}

void elim_med(struct medicion *&lista, int el) {
	if (lista != NULL) {
		struct medicion *aux_borrar = lista;
		struct medicion *anterior = NULL;
		
		while (aux_borrar != NULL && aux_borrar->valor_med != el) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
}
		
		if (aux_borrar == NULL) {
			printf("\nLa medición no existe.");
			return;
}
		
		if (anterior == NULL) {
			lista = lista->siguiente;
} else {
			anterior->siguiente = aux_borrar->siguiente;
}
		
		free(aux_borrar);
		printf("\nLa medición se eliminó correctamente.");
} else {
		printf("\nLa lista está vacía.");
}
}
void bus_sen(struct medicion *lista, char *tipo) {
	struct medicion *actual = lista;
	bool band = false;
	
	while (actual != NULL) 
	{
		if (strcmp(actual->sens_us.tipo, tipo) == 0) 
		{
			band = true;
			imp_str(actual);
		}
		actual = actual->siguiente;
	}
	if (!band) {
		printf("\nEl tipo de sensor no fue encontrado");
	}
}


void bus_val_med(struct medicion *lista, int val) {
	struct medicion *actual = lista; 
	bool band = false;
	
	while (actual != NULL) 
	{
		if (actual->valor_med == val) // Cambiar "=" por "=="
		{
			band = true;
			imp_str(actual);
		}
		actual = actual->siguiente;
	}
	
	if (!band) {
		printf("\nEl valor del sensor no fue encontrado");
	}
}

void recuperar_lista(){
	FILE *archivo = fopen("Imagenes.bin", "rb");
	if (archivo == NULL) 
	{
		printf("No se pudo abrir el archivo para lectura.\n");
		return;
	}
	
	struct medicion medicion;
	
	while (fread(&medicion, sizeof(struct medicion), 1, archivo) == 1) 
	{
		struct medicion *nuevaMedicion = (struct medicion *)malloc(sizeof(struct medicion));
		if (nuevaMedicion == NULL) 
		{
			printf("Error al asignar memoria para la nueva medicion.\n");
			break;
		}
		
		*nuevaMedicion = medicion;
		
		nuevaMedicion->siguiente = lista;
		lista = nuevaMedicion;
	}
	
	fclose(archivo);
	printf("La lista se recuperó correctamente.\n");
	
	struct medicion *actual = lista;
	
	while(actual != NULL)
	{
		imp_str(actual);
		actual = actual->siguiente;
	}
}
void guardarMediciones(){
	FILE *archivo = fopen("Mediciones.bin","ab+");
	if(archivo == NULL)
	{
		printf("\nNo se pudo abrir el archivo para escritura.");
	}
	//Recorro la lista y escribo cada elemento en el archivo 
	medicion *actual = lista;
	while(actual != NULL)
	{
		fwrite(actual,sizeof(struct medicion),1,archivo);
		actual = actual->siguiente;
	}
	fclose(archivo);
	printf("\nLa medicion se guardo correctamente.");
}
void ordenar_lista() {
	if (lista == NULL) {
		printf("No hay mediciones en la lista");
		return;
	} else if (lista->siguiente == NULL) {
		// No hay elementos o solo hay uno, no se necesita ordenar
		return;
	}
	
	struct medicion *nueva_Lista = NULL;
	struct medicion *actual = lista;
	
	while (actual != NULL) {
		struct medicion *siguiente = actual->siguiente;
		if (nueva_Lista == NULL || strcmp(actual->fecha, nueva_Lista->fecha) < 0) {
			actual->siguiente = nueva_Lista;
			nueva_Lista = actual;
		} else {
			struct medicion *temp = nueva_Lista;
			while (temp->siguiente != NULL && strcmp(actual->fecha, temp->siguiente->fecha) > 0) {
				temp = temp->siguiente;
			}
			actual->siguiente = temp->siguiente;
			temp->siguiente = actual;
		}
		actual = siguiente;
	}
		
	lista = nueva_Lista;
	printf("Lista ordenada por fecha:\n");
	
	struct medicion *actual1 = lista;
	while (actual1 != NULL) {
		imp_str(actual1);
		actual1 = actual1->siguiente;
	}
}
	
