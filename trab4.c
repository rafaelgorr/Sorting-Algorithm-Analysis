#include "FunctionsTrab4.h"


int main(int argc, string argv[])
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

	int n= atoi(argv[2]);
	int *vet = lerVetor(n);
	if( !strcmp(argv[1], "bubble") )
	{
		bubleSort(vet,n);
		imprimirVetor(vet,n);

		free(vet);
		return 0;
	}

	if(!strcmp(argv[1], "shake"))
	{
		shakeSort(vet, n);
		imprimirVetor(vet, n);

		free(vet);
		return 0;
	}

	if(!strcmp(argv[1], "insertion"))
	{
		insertion_sort(vet, n);
		imprimirVetor(vet, n);

		free(vet);
		return 0;
	}

	if(!strcmp(argv[1], "shell"))
	{
		shell_sort(vet, n);
		imprimirVetor(vet, n);

		free(vet);
		return 0;
	}

	if(!strcmp(argv[1], "selection"))
	{
		selection_sort(vet, n);
		imprimirVetor(vet, n);

		free(vet);
		return 0;
	}

	if(!strcmp(argv[1], "rank"))
	{
		int *r = (int*) malloc(sizeof(int)* n );
		rankSort(vet, n,r);
		rearrange(vet,n,r);
		imprimirVetor(vet, n);

		free(r);
		free(vet);
		return 0;
	}
	if(!strcmp(argv[1], "quickprimeiro"))
	{
		quickSortPrimeiro(vet, 0, n-1);
		imprimirVetor(vet, n);

		free(vet);
		return 0;
	}

	if(!strcmp(argv[1], "quickcentral"))
	{
		quickSortCentral(vet,n);
		imprimirVetor(vet, n);

		free(vet);
		return 0;
	}


	if(!strcmp(argv[1], "quickrandom"))
	{
		quickSortRandom(vet,0, n-1);
		imprimirVetor(vet, n);

		free(vet);
		return 0;
	}


	if(!strcmp(argv[1], "quickmediana3"))
	{
		quickSortMediana3(vet,0, n-1);
		imprimirVetor(vet, n);

		free(vet);
		return 0;
	}

	if(!strcmp(argv[1], "merge"))
	{
		merge_sort(vet,n);
		imprimirVetor(vet, n);

		free(vet);
		return 0;
	}

	if(!strcmp(argv[1], "heap"))
	{
		heapsort(vet,n);
		imprimirVetor(vet, n);

		free(vet);
		return 0;
	}

	if(!strcmp(argv[1], "radix"))
	{
		radixSort(vet,n);
		imprimirVetor(vet, n);

		free(vet);
		return 0;
	}

	if(!strcmp(argv[1], "radixbin"))
	{
		radixSortBinario(vet,n);
		imprimirVetor(vet, n);

		free(vet);
		return 0;
	}
	return 0;
}





