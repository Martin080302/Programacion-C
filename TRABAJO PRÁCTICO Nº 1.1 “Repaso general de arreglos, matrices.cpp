#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int const m=10;
int A[m][m];
int B[m][m];
int c[m];
int a,b,C,n,z,p;
int k=0;
int D[m][m];
int M[m];
double norma;
void Suma(int A[m][m],int B[m][m],int a,int b);
void Multiplicacion(int A[m][m],int B[m][m],int c[m],int a,int b,int C);
void Norma(int c[m],int C);

int main() 
{
	srand(time(NULL));
	printf("CALCULADORA para álgebra versión 0.0.1");
	do
	{
		k=0;
		do
		{
			printf("\nIngrese el tamaño de la Matriz A: ");
			scanf("%d",&a);
		} while(a<=0||a>10);
		do
		{
			printf("\nIngrese el tamaño de la Matriz B: ");
			scanf("%d",&b);
		} while(b<=0||b>10);
		do
		{
			printf("\nIngrese el tamaño del Vector c: ");
			scanf("%d",&C);
		} while(C<=0||C>10);
		printf("\n¿Quiere rellenar la Matriz A?\n\n Ingrese 1 por si o 2 por no: ");
		do
		{
			scanf("%d",&p);
		} while(p<=0 || p>2);
		if(p==1)
		{
			printf("\n\nIngresar los valores de la Matriz A: ");
			for(int i=0;i<a;i++)
			{
				printf("\n");
				for(int j=0;j<a;j++)
				{
					printf("\n A[%d][%d] = ",i,j);
					scanf("%d",&A[i][j]);
				}
			}
			for(int i=0;i<a;i++)
			{
				printf("\n");
				for(int j=0;j<a;j++)
				{
					printf("%d ",A[i][j]);
				}
			}
			printf("\n");
		}
		else
		{
			printf("\n");
			for(int i=0;i<a;i++)
			{
				printf("\n");
				for(int j=0;j<a;j++)
				{
					A[i][j]=rand()%11;
					printf("%d ",A[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n¿Quiere rellenar la Matriz B?\n Ingrese 1 por si o 2 por no: ");
		do
		{
			scanf("%d",&p);
		} while(p<=0 || p>2);
		if(p==1)
		{
			printf("\n\nIngresar los valores de la Matriz B: ");
			for(int i=0;i<b;i++)
			{
				for(int j=0;j<b;j++)
				{
					printf("\n B[%d][%d] = ",i,j);
					scanf("%d ",&B[i][j]);
				}
			}
			for(int i=0;i<b;i++)
			{
				printf("\n");
				for(int j=0;j<b;j++)
				{
					printf("%d ",B[i][j]);
				}
			}
			printf("\n");
		}
		else
		{
			printf("\n");
			for(int i=0;i<b;i++)
			{
				printf("\n");
				for(int j=0;j<b;j++)
				{
					B[i][j]=rand()%11;
					printf("%d ",B[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n¿Quiere rellenar el Vector c?\n Ingrese 1 por si o 2 por no: ");
		do
		{
			scanf("%d",&p);
		} while(p<=0 || p>2);
		if(p==1)
		{
			printf("\n\nIngresar los valores del Vector c: ");
			for(int i=0;i<C;i++)
			{
					printf("\n c[%d] = ",i);
					scanf("%d",&c[i]);
			}
			printf("[");
			for(int i=0;i<C;i++)
			{
				printf("%d",c[i]);
			}
			printf("]\n");
			printf("\n");
		}
		else
		{
			printf("\n");
			printf("[");
			for(int i=0;i<C;i++)
			{
				c[i]=rand()%11;
				printf("%d ",c[i]);
			}
			printf("]\n");
			printf("\n");
		}
		do
		{
		printf("\n\nSeleccionar del Menu:\n\n1.Suma de Matrices\n2.Multiplicación de matriz con vector\n3.Calcular la norma del vector\n4.Volver a cargar las matrices\n5.Salir\n");
		do
		{
			scanf("%d",&z);
		} while(z<=0 || z>5);
		switch(z)
		{
		case 1:
			printf("\n");
			Suma(A,B,a,b);
			printf("\n");
			break;
		case 2:
			printf("\n");
			Multiplicacion(A,B,c,a,b,C);
			printf("\n");
			break;
		case 3:
			printf("\n");
			Norma(c,C);
			printf("\n");
			break;
		case 4:
			k=1;
			break;
		case 5:
			z--;
		}
		}while(z<4 || z>4);
	}while(k==1);
}


void Suma(int A[m][m],int B[m][m],int a,int b)
{
	if(a==b)
	{
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<a;j++)
			{
				D[i][j]=A[i][j]+B[i][j];
			}
		}
		for(int i=0;i<a;i++)
		{
			printf("\n");
			for(int j=0;j<a;j++)
			{
				printf("%d  ",D[i][j]);
			}
		}
		printf("\n");
	}
	else
	{
		printf("\n");
		printf("Este menu no se puede realizar ya que las matrices son de distinto orden");
	}
}

void Multiplicacion(int A[m][m],int B[m][m],int c[m],int a,int b,int C)
{
	printf("\n¿Que matriz desea utilizar?\n 1 por la Matriz A / 2 por la Matriz B: ");
	do
	{
		scanf("%d",&p);
	} while(p<=0 || p>2);
	if(p==1)
	{
		if(a==C)
		{
			for(int i=0;i<C;i++)
			{
				int valor = 0;
				for(int j=0;j<C;j++)
				{
					valor=valor+A[i][j]*c[j];
				}
				M[i]=valor;
			}
			for(int i=0;i<C;i++)
			{
				printf("%d ",M[i]);
			}
			printf("\n");
		}
		else
		{
			printf("No se puede realizar el producto entre Matriz y Vector");
		}
	}
	else
	{
		if(b==C)
		{
			for(int i=0;i<C;i++)
			{
				M[i]=0;
			}
			for(int i=0;i<C;i++)
			{
				for(int j=0;j<C;j++)
				{
					M[i]+=B[i][j]*c[j];
				}
			}
			for(int i=0;i<C;i++)
			{
				printf("%d ",M[i]);
			}
			printf("\n");
		}
		else
		{
			printf("No se puede realizar el producto entre Matriz y Vector");
		}
	}
}

void Norma(int c[m],int C)
{
	double v=0;
	printf("\n");
	for(int i=0;i<C;i++)
	{
		v= v+(c[i]*c[i]);
	}
	printf("La norma del vector es: %f",sqrt(v));
	printf("\n");
}
