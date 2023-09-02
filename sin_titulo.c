#include <stdio.h>
/*Ingresar un numero comprendido entre 10 y 20 y mostrar por pantalla */
int main()
{
	int N;
	do
	{
		printf("Ingrese un valor entre 10 y 20 \n");
		scanf("%d", &N);
	if(N<=10 || N>=20)
		printf("Error \n");
	} 
	while(N<=10 ||N>=20);
	printf("El numero ingresado es %d", N);
	
}

