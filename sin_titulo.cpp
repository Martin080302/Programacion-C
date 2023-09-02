#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
int a,b,m[10][10],f,c;
int main()
{
	srand(time(NULL));
	do
	{
		printf("\nIngrese el numero de filas de la matriz ");
		scanf("%d", &f);
		
	} 
	while(f<2||f>10);
	do
	{
		printf("\nIngrese el numero de columnas de la matriz ");
		scanf("%d", &c);
		
	} 
	while(c<2||c>10);
	for(a=1;a<=f;a++)
	{
		for(b=1;b<=c;b++)
		{
			m[a-1][b-1]=rand()%100;
		}
	}
	for(a=1;a<=f;a++)
	{
		printf("\n");
		for(b=1;b<=c;b++)
		{
			printf("\t%d", m[a-1][b-1]);
		}
	}
}
