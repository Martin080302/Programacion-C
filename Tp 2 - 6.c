#include <stdio.h>

#define N 5
#define M 50

void marca(char cadena[N][M], char *p2);
void modelo(char cadena[N][M], char *p2);
void serie(char cadena[N][M], char *p2);
int tamano(char *valor);

int main() 
{
	char cadena[N][M] = {"-samsung-s23-44231-", "-motorola-G stylus-08977-", "-samsung-S20-S8493874-", "-FIAT-Palio-5234523-", "-Platinum-Biblioteca tres estantes-BP435-"};
	char valor[M];
	int n;
	
	printf("----------------BUSQUEDA DE DATOS----------------\n\n");
	printf("MENU:\n1. Busquda por marca.\n2. Busqueda por modelo.\n3. Busqueda por numero de serie.\n4. Salir.\n\n"); 
	
	printf("Ingrese un numero del 1 al 4: ");
	scanf("%d", &n);
	getchar();
	
	switch(n) 
	{
	case 1:
		printf("Ingrese la marca a buscar: ");
		fgets(valor, M, stdin);
		marca(cadena, valor);
		break;
	case 2:
		printf("Ingrese el modelo a buscar: ");
		fgets(valor, M, stdin);
		modelo(cadena, valor);
		break;
	case 3:
		printf("Ingrese la serie a buscar: ");
		fgets(valor, M, stdin);
		serie(cadena, valor);
		break;
	case 4:
		break;
	default:
		printf("Opcion invalida.\n");
		break;
	}	
}

int tamano(char *valor)
{
	int t=0;
	char *p = valor;
	while(*p != '\0')
	{
		t++;
		p++;
	}
	t--;
	return (t);
}
void marca(char cadena[N][M], char *p2)
{
	int i=0, q;
	int t = tamano(p2);
	for (i=0; i<N; i++)
	{
		q=0;
		char *p1 = cadena[i];
		for(int j=0; j<t; j++)
		{
			p1++;
			if(*p1 == *p2)
			{
				q++;
			}
			p2++;
		}
		if(q==t)
		{
			for(int j=0;j<t;j++)
			{
				p1--;
			}
			for(int j=0;j<t;j++)
			{
				p2--;
			}
			while(*p1 != '\n' && *p1 != '\0' && *p1 != '\t')
			{
				printf("%c",*p1);
				p1++;
			}
			printf("\n");
			
		}
		else
		{
			for(int j=0;j<t;j++)
			{
				p2--;
			}
		}
		
	}
}

void modelo(char cadena[N][M], char *p2)
{
	int l, s;
	int i=0, q;
	int t = tamano(p2);
	for (i=0; i<N; i++)
	{
		char *p1 = cadena[i];
		s=0;
		l=0;
		while(l!=2)
		{
			if(*p1 == '-')
			{
				s++;
				l++;
				p1++;
			}
			else
			{
				s++;
				p1++;
			}			
		}
		q=0;
		for(int j=s; j<s+t; j++)
		{
			if(*p1 == *p2)
			{
				q++;
			}
			p2++;
			p1++;
		}
		if(q==t)
		{
			for(int j=0;j<s+t;j++)
			{
				p1--;
			}
			for(int j=0;j<t;j++)
			{
				p2--;
			}
			while(*p1 != '\n' && *p1 != '\0' && *p1 != '\t')
			{
				printf("%c",*p1);
				p1++;
			}
			printf("\n");
			
		}
		else
		{
			for(int j=0;j<t;j++)
			{
				p2--;
			}
		}
		
	}
}

void serie(char cadena[N][M], char *p2)
{
	int l, s;
	int i=0, q;
	int t = tamano(p2);
	for (i=0; i<N; i++)
	{
		char *p1 = cadena[i];
		s=0;
		l=0;
		while(l!=3)
		{
			if(*p1 == '-')
			{
				s++;
				l++;
				p1++;
			}
			else
			{
				s++;
				p1++;
			}			
		}
		q=0;
		for(int j=s; j<s+t; j++)
		{
			if(*p1 == *p2)
			{
				q++;
			}
			p2++;
			p1++;
		}
		if(q==t)
		{
			for(int j=0;j<s+t;j++)
			{
				p1--;
			}
			for(int j=0;j<t;j++)
			{
				p2--;
			}
			while(*p1 != '\n' && *p1 != '\0' && *p1 != '\t')
			{
				printf("%c",*p1);
				p1++;
			}
			printf("\n");
			
		}
		else
		{
			for(int j=0;j<t;j++)
			{
				p2--;
			}
		}
		
	}
}
