#include <stdio.h>	
#include  <string.h>

int nombre (char *p,char nb[100],int ta, int tb); 

int main() 
{
	FILE *archivo;
	FILE *copia;
	char na[100], nb[100];
	char *p;
	char frase[200];
	int ta, tb, tc, v;
	char nc[100]="ArchivoCopia";
	printf("\nIngrese el nombre del archivo sin su extención: ");
	fgets (na,100,stdin); 
	printf("\nIngrese su extención (recuerde ingresar el '.' primero):");
	fgets (nb,100,stdin);
	p = &na[0];
	ta = strlen(na);
	ta--;
	tb = strlen(nb);
	tb--;
	v = nombre(p,nb,ta,tb);
	if(v==2)
	{
		printf("\nEl nombre ingresado es correcto");
		strcat(na,nb);
		na[ta]='\0';
		archivo = fopen(na, "a");
		printf("\nIngrese la frase que desea añadir en el archivo: ");
		fgets(frase,200,stdin);
		fputs(frase, archivo);
		strcat(nc,nb);
		tc = strlen(nc);
		nc[tc-1]='\0';
		copia = fopen(nc, "a");
		fputs(frase, copia);
		fclose (copia);
		copia = fopen(nc, "r");
		fclose (archivo);
		fclose (copia);
	}
	else 
	{
		printf("Error");
	}
} 

int nombre (char *p,char nb[100],int ta, int tb)
{
	int b=0,t=0;
	for(int i=0;i<ta;i++)
	{			
		if((*p>'A' || *p<'Z') && (*p>'a' || *p<'z'))
		{
			if((*p>'0' || *p<'9'))
			{
				
			}
			else
			{
				b=1;
			}
		}
		p++;
	}
	if(b==1)
	{
		printf("\nNombre incorrecto");
	}
	else 
	{
		t++;
	}
	int c;
	c=strcmp(nb,".txt\n");
	if(c==0)
	{
		t++;
	}
	c=0;
	c=strcmp(nb,".c\n");
	if(c==0)
	{
		t++;
	}
	c=0;
	c=strcmp(nb,".cpp\n");
	if(c==0)
	{
		t++;
	}
	return(t);
}

