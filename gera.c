#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#define LENMAX 1000000


int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("Numero de argumentos insuficientes!\n");
		exit(1);
	}
	if(atoi(argv[2]) >  LENMAX || atoi(argv[2]) < 0 )
	{
		printf("Numero invalido, n tem que ser maior que zero e menor ou igual que 100 milhoes\n");
		exit(1);
	}

	int i,n = atoi(argv[2]);
	if(!strcmp(argv[1],"-a"))
	{
		srand(time(NULL));
		int x = rand() % LENMAX;
		for(i=0;i<n;i++)
			printf("%d\n", x);

	}
	
	if(!strcmp(argv[1],"-c"))
	{
		for(i=0;i<n;i++)
			printf("%d\n",i+1);
	}
	
	if(!strcmp(argv[1],"-d"))
	{
		for(i=n;i>0;i--)
			printf("%d\n",i);
	}

	return 0;
}




