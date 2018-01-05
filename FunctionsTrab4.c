#include "FunctionsTrab4.h"

int* lerVetor(int n)
{
	int i;
	int *vet = (int*) malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
		scanf("%d\n",&vet[i]);

	return vet;
}

void imprimirVetor(int *vet, int n)
{
	int i;

	for(i=0;i<n;i++)
		printf("%d\n",vet[i]);
}

void bubleSort( int vetorDesordenado[], int tamanhoVetor )
{
   int i, j;
   for( i = 0; i < ( tamanhoVetor -1 );  i++ )
   {
      for( j=0; j <( tamanhoVetor -( i +1 ) ); j++ )
      {
         if( vetorDesordenado[j] > vetorDesordenado[j+1] )
         {
            trocarPosicaoValores( &vetorDesordenado[j], &vetorDesordenado[j+1] );
         }
      }
   }
}

void trocarPosicaoValores( int *posicaoA, int *posicaoB )
{
   int temporario;
   temporario = *posicaoA;
   *posicaoA = *posicaoB;
   *posicaoB = temporario;
}

#define try_swap { if (a[i] < a[i - 1])\
	{ t = a[i]; a[i] = a[i - 1]; a[i - 1] = t; t = 0;} }

void shakeSort(int *a, size_t len)
{
	size_t i;
	int t = 0;
	while (!t) {
		for (i = 1, t = 1; i < len; i++) try_swap;
		if (t) break;
		for (i = len - 1, t = 1; i; i--) try_swap;
	}
}

void insertion_sort (int *a, int n)
{
    int i, j, t;
    for (i = 1; i < n; i++) {
        t = a[i];
        for (j = i; j > 0 && t < a[j - 1]; j--) {
            a[j] = a[j - 1];
        }
        a[j] = t;
    }
}

void shell_sort (int *a, int n)
{
    int h, i, j, t;
    for (h = n; h /= 2;) {
        for (i = h; i < n; i++) {
            t = a[i];
            for (j = i; j >= h && t < a[j - h]; j -= h) {
                a[j] = a[j - h];
            }
            a[j] = t;
        }
    }
}

void selection_sort (int *a, int n)
{
    int i, j, m, t;
    for (i = 0; i < n; i++) {
        for (j = i, m = i; j < n; j++) {
            if (a[j] < a[m]) {
                m = j;
            }
        }
        t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}

void rankSort(int *a, int n, int *r)
{
	int i,j;
	for(i=0;i<n;i++)
	r[i]=0;
	for(i=1;i<n;i++)
		{
		 for(j=0;j<i;j++)
			{
			 if(a[j]<=a[i]) r[i]++;

					else r[j]++;
		 }
	}

}

void rearrange(int *a, int n, int *r)
{
	int i,u[n];

	for(i=0;i<n;i++)
		u[r[i]]=a[i];

	for(i=0;i<n;i++)
		a[i]=u[i];
}


void quickSortPrimeiro( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
   	
       j = partition( a, l, r);
       quickSortPrimeiro( a, l, j-1);
       quickSortPrimeiro( a, j+1, r);
   }
	
}



int partition( int a[], int l, int r)
 {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
		
   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}

void quickSortCentral (int *a, int n)
{
    int i, j, p, t;
    if (n < 2)
        return;
    p = a[n / 2];
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i] < p)
            i++;
        while (p < a[j])
            j--;
        if (i >= j)
            break;
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    quickSortCentral(a, i);
    quickSortCentral(a + i, n - i);
}


int random_partition(int* arr, int start, int end)
{
    srand(time(NULL));
    int pivotIdx = start + rand() % (end-start+1);
    int pivot = arr[pivotIdx], tmp;
    arr[pivotIdx] = arr[end];
    arr[end] = pivot;
    pivotIdx = end;
    int i = start -1;

    for(int j=start; j<=end-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i = i+1;
            tmp  = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    tmp = arr[pivotIdx];
    arr[pivotIdx] = arr[i+1];
    arr[i+1] = tmp;

    return i+1;
}



void quickSortRandom(int* arr, int start, int end)
{
    if(start < end) {
        int mid = random_partition(arr, start, end);
        quickSortRandom(arr, start, mid-1);
        quickSortRandom(arr, mid+1, end);
    }
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
	return ;
}

int median3(int a[], int left, int right)//Uses median of three partitioning technique
{
	int center = (left + right)/2;
	if (a[center] < a[left])
		swap(&a[left],&a[center]);
	if (a[right] < a[left])
		swap(&a[left],&a[right]);
	if (a[right]< a[center])
		swap(&a[center],&a[right]);

	swap(&a[center], &a[right - 1]);//since the largest is already in the right.
	return a[right - 1];
}

void quickSortMediana3(int a[], int left, int right)
{
  if (left < right) {
	int pivot = median3(a,left,right);
	if (left == right - 1) return;
	int i = left;
	int j = right - 1;
	for ( ; ;) {
		while(a[++i]<pivot) {}
		while(pivot<a[--j]) {}
		if ( i < j)
			swap(&a[i],&a[j]);
		else
			break ;
	}
	swap(&a[i],& a[right -1]);
	quickSortMediana3(a,left,i-1);
	quickSortMediana3(a,i+1,right);
  }
	return ;
}

void merge (int *a, int n, int m)
{
    int i, j, k;
    int *x = malloc(n * sizeof (int));
    for (i = 0, j = m, k = 0; k < n; k++) {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) {
        a[i] = x[i];
    }
    free(x);
}

void merge_sort (int *a, int n)
{
    if (n < 2)
        return;
    int m = n / 2;
    merge_sort(a, m);
    merge_sort(a + m, n - m);
    merge(a, n, m);
}



#define IS_LESS(v1, v2)  (v1 < v2)



void heapsort( int *a, int count)
{
    int start, end;

    /* heapify */
    for (start = (count-2)/2; start >=0; start--) {
        siftDown( a, start, count);
    }

    for (end=count-1; end > 0; end--) {
        swap(&a[end],&a[0]);
        siftDown(a, 0, end);
    }
}

void siftDown( int *a, int start, int end)
{
    int root = start;

    while ( root*2+1 < end ) {
        int child = 2*root + 1;
        if ((child + 1 < end) && IS_LESS(a[child],a[child+1])) {
            child += 1;
        }
        if (IS_LESS(a[root], a[child])) {
            swap( &a[child], &a[root] );
            root = child;
        }
        else
            return;
    }
}


void radixSort(int vetor[], int tamanho)
{
     int i;
     int *b;
     int maior = LENMAX;
     int exp = 1;

     b = (int *)calloc(tamanho, sizeof(int));

   

     while (maior/exp > 0) {
         int bucket[10] = { 0 };
     	for (i = 0; i < tamanho; i++)
     	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
     	    bucket[i] += bucket[i - 1];
     	for (i = tamanho - 1; i >= 0; i--)
     	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
     	for (i = 0; i < tamanho; i++)
     	    vetor[i] = b[i];
     	exp *= 10;
     }

    free(b);
}

void radix(int byte, int N, int *source, int *dest)
{
  int* count = (int*)calloc(256, sizeof(int));
  int index[256];
  int i;

  for(i=0; i<N; ++i){
    count[((source[i])>>(byte*8))&0xff]++;
  }

  index[0]=0;
  for(i=1; i<256; ++i){
    index[i] = index[i-1] + count[i-1];
  }

  for(i=0; i<N; ++i){
    dest[index[((source[i])>>(byte*8))&0xff]++] = source[i];
  }
  free(count);
}

void radixSortBinario(int vet[], int tamanho){
  int temp[tamanho];
  radix(0, tamanho, vet, temp);
  radix(1, tamanho, temp, vet);
  radix(2, tamanho, vet, temp);
  radix(3, tamanho, temp, vet);
}



