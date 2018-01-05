#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#define LENMAX 1000000

typedef char* string;

int* lerVetor(int n);
void imprimirVetor(int *vet, int n);

void bubleSort( int vetorDesordenado[], int tamanhoVetor );
void trocarPosicaoValores( int *posicaoA, int *posicaoB );

void shakeSort(int *a, size_t len);

void insertion_sort (int *a, int n);

void shell_sort (int *a, int n);

void selection_sort (int *a, int n);

void rankSort(int a[], int n, int r[]);
void rearrange(int *a, int n, int *r);

void quickSortPrimeiro( int a[], int l, int r);
int partition( int a[], int l, int r);

void quickSortCentral (int *a, int n);

void quickSortRandom(int* arr, int start, int end);
int random_partition(int* arr, int start, int end);

void quickSortMediana3(int a[], int left, int right);
int median3(int a[], int left, int right);
void swap(int *x, int *y);

void merge_sort (int *a, int n);
void merge (int *a, int n, int m);

void siftDown( int *a, int start, int count);
void heapsort( int *a, int count);

void radixSort(int * array, int size);


void radix(int byte, int N, int *source, int *dest);
void radixSortBinario(int vet[], int tamanho);

