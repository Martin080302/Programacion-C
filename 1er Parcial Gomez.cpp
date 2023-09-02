#include <stdio.h>
#include <string.h>
#define M 50

struct funcion{
	int x;
	int y;
	int z;
};

void busqueda(int n);
void cambiardatos(int *px, int *py,int n);
struct funcion stockpuntos[M];

int main()
{
	int n=0,Z,opcion;
	printf("Calculo de z con la funcion f(x,y)=(2*x)*(x+y)"); 
	do
	{
	printf("\nMenu");
	printf("\n1.Añadir x e y");
	printf("\n2.Buscar un valor de z aproximado a algun valor cargado");
	printf("\n3.Intercambiar valores");
	printf("\n4.Salir.");
	printf("\nIngrese la opcion desada: ");
	scanf("%d",&opcion);
	int *px,*py;
	px=&stockpuntos[0].x;
	py=&stockpuntos[0].y;
	switch(opcion)
	{
	case 1:
		if(n != M)
		{
			struct funcion nuevacoordenada;
			printf("\nIngrese un punto en x: ");
			scanf("%d",&nuevacoordenada.x);
			printf("\nIngrese un punto en y: ");
			scanf("%d",&nuevacoordenada.y);
			Z=(2*nuevacoordenada.x)*(nuevacoordenada.x+nuevacoordenada.y);
			nuevacoordenada.z=Z;
			stockpuntos[n]=nuevacoordenada;
			n++;
			printf("\nf(x,y)=(2*%d)*(%d+%d) es igual a z=%d",nuevacoordenada.x,nuevacoordenada.x,nuevacoordenada.y,nuevacoordenada.z); 
		}
		else
		{
			printf("\nYa supero la cantidad maxima de ingreso de puntos permitida");
		}
		break;
	case 2:
		busqueda(n);
		break;
	case 3:
		cambiardatos(px,py,n);
		break;
	case 4:
		break;
	default:
		printf("\nOpcion invalida");
		break;
	}
	}while(opcion != 4);
}
void busqueda(int n)
{
	float c;
	int q=0;
	printf("\nIngrese un valor de z: ");
	scanf("%f",&c);
	
	for(int i=0;i<n;i++)
	{
		if(c==stockpuntos[i].z)
		{
			printf("\nEl valor ingresado corresponde a: \nx=%d\ny=%d",stockpuntos[i].x,stockpuntos[i].y);
			q++;
		}
		else if(c<=stockpuntos[i].z+2 && c>=stockpuntos[i].z-2)
		{
			printf("\nEL valor ingresado esta aproximado a: \nx=%d\ny=%d",stockpuntos[i].x,stockpuntos[i].y);
			q++;
		}
	}
	if(q==0)
	{
		printf("\nEl valor ingresado no es igual ni esta aproximado en un rango de +2 o -2"); 
	}
}
void cambiardatos(int *px, int *py,int n)
{
	int opcion,vx,nx,vy,ny,a=0;
	printf("\n¿Desea cambiar datos de x o de y?");
	printf("\n1.Cambiar datos de x");
	printf("\n2.Cambiar datos de y");
	printf("\nIngrese la opcion deseada");
	scanf("%d",&opcion);
	switch(opcion)
	{
	case 1:
		printf("\nQue valor de x desea cambiar: ");
		scanf("%d",&vx);
		for(int i=0;i<n;i++)
		{
			if(vx != *px)
			{
				a++;
			}
			else
			{
				printf("\nIngrese el nuevo valor de x: ");
				scanf("%d",&nx);
			}
			px++;
		}
		if(a == n)
		{
			printf("\nEl numero ingresado es incorrecto");
		}
		break;
	case 2:
		printf("\nQue valor de y desea cambiar: ");
		scanf("%d",&vy);
		for(int i=0;i<n;i++)
		{
			if(vy != *py)
			{
				a++;
			}
			else
			{
				printf("\nIngrese el nuevo valor de x: ");
				scanf("%d",&ny);
			}
			py++;
		}
		if(a == n)
		{
			printf("\nEl numero ingresado es incorrecto");
		}
		break;
	default:
		printf("\nOpcion invalida");
		break;		
	}
}
