#include "ord.h"

void radixSort(int *vetor, int tamanho) {
    
    system("clear"); //Limpa a tela
    printf("\t\tRADIX SORT\n");
    int i, exp = 1, *b;
    int maior = vetor[0];

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }
 
    while (maior/exp > 0) {
        int bucket[BASE] = { 0 };

    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % BASE]++;
 
    	for (i = 1; i < BASE; i++)
    	    bucket[i] += bucket[i - 1];

    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % BASE]] = vetor[i];

    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];

    	exp *= BASE;
    }

    free(b);
}


void countingSort(int v[], int tam)
{
    system("clear"); //Limpa a tela
    printf("\t\tCOUNTING SORT\n");
    int count[10000] = {0}, i, j, max=0, n=0;

    for(i=0; i<MAX-1; i++)
	if(v[i]>max)
	    max=v[i];

    for(i=0; i<tam; i++)
	count[v[i]]=count[v[i]]+1;

    for(i=0; i<=max; i++)
	for(j=1; j<=count[i]; j++)
	{
	    v[n] = i;
	    n++;
	}
}


