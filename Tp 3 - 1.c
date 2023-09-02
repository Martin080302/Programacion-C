/*EJERCICIO 1 - Introducción e inicialización
Defina una estructura que permita almacenar los datos de una persona:
? Apellido
? Nombre
? Edad
? Altura
Use los tipos de variables adecuados para el dato que se indica (char, int,
etc)
Declare un arreglo de estructuras.
Realice una función donde inicializa/carga el arreglo de estructuras usando
pasaje por valor y otra función de carga donde use pasaje por referencia.
Ejemplifique el uso de cada función cargando al menos tres personas, sin usar
ni requerir carga por parte del usuario.
Muestre el arreglo de estructuras por pantalla.
Deberá mostrar los puntos donde se produce/n el/los cortes de manera
ordenada o el intervalo de la intersección.*/
#include <stdio.h>

struct Persona {
	char apellido[50];
	char nombre[50];
	int edad;
	float altura;
};

void cargarPersonasPorValor(struct Persona personas[]);
void cargarPersonasPorReferencia(struct Persona *personas);
void mostrarPersonas(struct Persona personas[], int cantidad);

int main() {
	struct Persona personas1[3]; 
	struct Persona personas2[3]; 
	
	cargarPersonasPorValor(personas1);
	cargarPersonasPorReferencia(personas2); 
	
	mostrarPersonas(personas1, 3);
	mostrarPersonas(personas2, 3);
}

void cargarPersonasPorValor(struct Persona personas[]) {
	struct Persona persona1 = {"Perez", "Sergio", 30, 1.75};
	struct Persona persona2 = {"Verstappen", "Max", 25, 1.60};
	struct Persona persona3 = {"Sainz", "Carlos", 35, 1.80};
	
	personas[0] = persona1;
	personas[1] = persona2;
	personas[2] = persona3;
}

void cargarPersonasPorReferencia(struct Persona *personas) {
	struct Persona persona1 = {"Hamilton", "Lewis", 28, 1.68};
	struct Persona persona2 = {"Leclerc", "Charles", 32, 1.70};
	struct Persona persona3 = {"Alonso", "Fernando", 27, 1.62};
	
	*personas = persona1;
	*(personas + 1) = persona2;
	*(personas + 2) = persona3;
}

void mostrarPersonas(struct Persona personas[], int cantidad) {
	printf("Personas:\n");
	for (int i = 0; i < cantidad; i++) {
		printf("Persona %d:\n", i + 1);
		printf("Apellido: %s\n", personas[i].apellido);
		printf("Nombre: %s\n", personas[i].nombre);
		printf("Edad: %d\n", personas[i].edad);
		printf("Altura: %.2f\n", personas[i].altura);
		printf("\n");
	}
}
