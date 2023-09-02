#include <stdio.h>

int main() {
	int a,b,c;
	printf("\nIngrese el 1° numeros ");
	scanf("%d",&a);
	printf("\nIngrese el 2° numeros ");
	scanf("%d",&b);	
	printf("\nIngrese el 3° numeros ");
	scanf("%d",&c);
	if (a<b)
	{
		if(a<c)
		{
			if(b<c)
			{
				printf("\n%d\t%d\t%d",a,b,c);
			}
			else
			{
				printf("\n%d\t%d\t%d",a,c,b);
			}
		}
		else
		{
			printf("\n%d\t%d\t%d",c,a,b);
		}
			
			
	}

		

	else
	{
		if(b<c)
		{
			if(a<c)
			{
				printf("\n%d\t%d\t%d",b,a,c);
			}
			else
			{
				printf("\n%d\t%d\t%d",b,c,a);
			}
		}
		else
		{
			printf("\n%d\t%d\t%d",c,b,a);
		}
	}

}
