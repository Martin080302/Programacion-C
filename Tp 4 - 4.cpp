#include <stdio.h>
#include <string.h>

#define MAX_IMAGENES 100

struct Imagen 
{
	int codigo;
	char nombreArchivo[50];
	char extension[10];
	int tamano;
	float precio;
};

void mostrarImagen(struct Imagen imagen);
void agregarImagen();
void eliminarImagen();
void modificarImagen();
void buscarPorNombreArchivo();
void buscarPorExtension();
void buscarPorTamano();
void buscarPorCodigo();
void guardarImagenes();
void mostrarArchivo();

int main() 
{
	int opcion;
	
	do
	{
		printf("==== Menú ====\n");
		printf("1. Agregar una nueva imagen\n");
		printf("2. Eliminar una imagen existente\n");
		printf("3. Modificar los datos de una imagen existente\n");
		printf("4. Buscar imágenes por nombre de archivo\n");
		printf("5. Buscar imágenes por extensión\n");
		printf("6. Buscar imágenes por tamaño\n");
		printf("7. Buscar imágenes por codigo\n");
		printf("8. Guardar Imagenes\n");
		printf("9. Mostrar Archivo\n");
		printf("10. Salir\n\n");
		printf("Ingrese una opción: ");
		scanf("%d", &opcion);
		
		switch (opcion) 
		{
		case 1:
			agregarImagen();
			break;
		case 2:
			eliminarImagen();
			break;
		case 3:
			modificarImagen();
			break;
		case 4:
			buscarPorNombreArchivo();
			break;
		case 5:
			buscarPorExtension();
			break;
		case 6:
			buscarPorTamano();
			break;
		case 7:
			buscarPorCodigo();
			break;
		case 8:
			guardarImagenes();
			break;
		case 9:
			mostrarArchivo();
			break;
		case 10:
			printf("\n\n¡Hasta luego!\n");
			break;
		default:
			printf("Opción inválida. Por favor, intente nuevamente.\n");
			break;
		}
		printf("\n");
	} while (opcion != 10);
}

int numImagenes = 0;
struct Imagen stockImagenes[MAX_IMAGENES];

void mostrarImagen(struct Imagen imagen) 
{
	printf("\n\nCódigo de inventario: %d\n", imagen.codigo);
	printf("Nombre del archivo: %s\n", imagen.nombreArchivo);
	printf("Extensión: %s\n", imagen.extension);
	printf("Tamaño: %d bytes\n", imagen.tamano);
	printf("Precio: $%.2f\n", imagen.precio);
}

void agregarImagen() 
{
	if (numImagenes >= MAX_IMAGENES) 
	{
		printf("No se pueden agregar más imágenes. Stock lleno.\n");
		return;
	}
	
	struct Imagen nuevaImagen;
	
	printf("Ingrese el código de inventario: ");
	scanf("%d", &nuevaImagen.codigo);
	getchar();
	
	printf("Ingrese el nombre del archivo: ");
	fgets(nuevaImagen.nombreArchivo, 50, stdin);
	nuevaImagen.nombreArchivo[strcspn(nuevaImagen.nombreArchivo, "\n")] = '\0'; 
	
	printf("Ingrese la extensión del archivo: ");
	fgets(nuevaImagen.extension, 10, stdin);
	nuevaImagen.extension[strcspn(nuevaImagen.extension, "\n")] = '\0';
	
	printf("Ingrese el tamaño en bytes: ");
	scanf("%d", &nuevaImagen.tamano);
	
	printf("Ingrese el precio de la imagen: ");
	scanf("%f", &nuevaImagen.precio);
	
	stockImagenes[numImagenes] = nuevaImagen;
	numImagenes++;
	
	printf("\n\nImagen agregada correctamente.\n");
}

void eliminarImagen() 
{
	if (numImagenes == 0) 
	{
		printf("No hay imágenes en el stock para eliminar.\n");
		return;
	}
	
	int codigoEliminar;
	printf("Ingrese el código de inventario de la imagen a eliminar: ");
	scanf("%d", &codigoEliminar);
	
	int indiceEliminar = -1; // Variable para almacenar el índice de la imagen a eliminar
	
	// Buscar la imagen por su código de inventario
	for (int i = 0; i < numImagenes; i++) 
	{
		if (stockImagenes[i].codigo == codigoEliminar) 
		{
			indiceEliminar = i;
			break;
		}
	}
	
	if (indiceEliminar == -1) 
	{
		printf("No se encontró una imagen con el código de inventario especificado.\n");
	}
	else 
	{
		for (int i = indiceEliminar; i < numImagenes - 1; i++) 
		{
			stockImagenes[i] = stockImagenes[i + 1];
		}
		numImagenes--;
		printf("Imagen eliminada correctamente.\n");
	}
}

void modificarImagen() 
{
	if (numImagenes == 0)
	{
		printf("No hay imágenes en el stock para modificar.\n");
		return;
	}
	
	int codigoModificar;
	printf("Ingrese el código de inventario de la imagen a modificar: ");
	scanf("%d", &codigoModificar);
	
	int indiceModificar = -1; 
	
	for (int i = 0; i < numImagenes; i++) 
	{
		if (stockImagenes[i].codigo == codigoModificar) 
		{
			indiceModificar = i;
			break;
		}
	}
	
	if (indiceModificar == -1) 
	{
		printf("No se encontró una imagen con el código de inventario especificado.\n");
	} 
	else 
	{
		struct Imagen imagenModificada;
		
		printf("Ingrese el nuevo nombre del archivo: ");
		fgets(imagenModificada.nombreArchivo, 50, stdin);
		imagenModificada.nombreArchivo[strcspn(imagenModificada.nombreArchivo, "\n")] = '\0';
		
		printf("Ingrese la nueva extensión del archivo: ");
		fgets(imagenModificada.extension, 10, stdin);
		imagenModificada.extension[strcspn(imagenModificada.extension, "\n")] = '\0';
		
		printf("Ingrese el nuevo tamaño en bytes: ");
		scanf("%d", &imagenModificada.tamano);
		
		printf("Ingrese el nuevo precio de la imagen: ");
		scanf("%f", &imagenModificada.precio);
		
		stockImagenes[indiceModificar] = imagenModificada;
		
		printf("Imagen modificada correctamente.\n");
	}
}

void buscarPorNombreArchivo() 
{
	char nombreArchivo[100];
	printf("Ingrese el nombre de archivo a buscar: ");
	scanf("%s", nombreArchivo);
	
	printf("Imágenes encontradas por nombre de archivo:\n");
	for (int i = 0; i < numImagenes; i++) 
	{
		if (strcmp(stockImagenes[i].nombreArchivo, nombreArchivo) == 0) 
		{
			mostrarImagen(stockImagenes[i]);
		}
	}
}

void buscarPorExtension() 
{
	char extension[20];
	printf("Ingrese la extensión a buscar: ");
	scanf("%s", extension);
	
	printf("Imágenes encontradas por extensión:\n");
	for (int i = 0; i < numImagenes; i++) 
	{
		if (strcmp(stockImagenes[i].extension, extension) == 0) 
		{
			mostrarImagen(stockImagenes[i]);
		}
	}
}

void buscarPorTamano() 
{
	int tamano;
	printf("Ingrese el tamaño a buscar: ");
	scanf("%d", &tamano);
	
	printf("Imágenes encontradas por tamaño:\n");
	for (int i = 0; i < numImagenes; i++) 
	{
		if (stockImagenes[i].tamano >= tamano) 
		{
			mostrarImagen(stockImagenes[i]);
		}
	}
}

void buscarPorCodigo() 
{
	int codigoBuscar;
	printf("Ingrese el código de inventario a buscar: ");
	scanf("%d", &codigoBuscar);
	
	int indiceEncontrado = -1; 	
	
	for (int i = 0; i < numImagenes; i++) 
	{
		if (stockImagenes[i].codigo == codigoBuscar) 
		{
			indiceEncontrado = i;
			break;
		}
	}
	
	if (indiceEncontrado == -1) 
	{
		printf("No se encontró una imagen con el código de inventario especificado.\n");
	}
	else
	{
		mostrarImagen(stockImagenes[indiceEncontrado]);
	}
}
void guardarImagenes()
{
	FILE *archivo = fopen("Imagenes.bin","wb");
	if(archivo == NULL)
	{
		printf("\nno se pudo abrir el archivo para escritura.");
		return;
	}
	fwrite(stockImagenes,sizeof(struct Imagen), numImagenes, archivo);
	fclose(archivo);
	printf("EL archivo se guardo correctamente.\n");
}

void mostrarArchivo()
{
	FILE *archivo = fopen("Imagenes.bin","rb");
	if(archivo== NULL)
	{
		printf("No se pudo abrir el archivo para lectura.\n");
		return;
	}
	struct Imagen imagen;
	
	while(fread(&imagen,sizeof(struct Imagen),1,archivo) == 1)
	{
		mostrarImagen(imagen);
	}
	fclose(archivo);
}
