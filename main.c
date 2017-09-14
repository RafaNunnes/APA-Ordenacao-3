#include "ord.h" //Arquivo com as implementações das funções de ordenação


int main()
{
	char url[]="couting.txt";
	int ord[MAX], desord[MAX], valor;
	int key, exit = 0;

	clock_t inicio, fim;
	double timeCount;
	
	FILE *arq;

	arq = fopen(url, "r");

	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		for(int i=0; (fscanf(arq,"%d\n", &valor))!=EOF; i++)
		{
			desord[i] = valor;
		}

	system("clear"); //Limpa a tela;

	while(!exit)
	{
		for(int i=0; i<MAX; i++) //Desordena o Array
		{
			ord[i] = desord[i];
		}

		printf("\nEscolha o metodo de Ordenacao:\n  \t1. Radix Sort\n \t2. Counting Sort\n \t0. SAIR\n");
		scanf("%i", &key);

		switch(key)
		{
			case 0:
				exit = 1;
				continue;
			case 1:
				inicio = clock();
				radixSort(ord, MAX);
				fim = clock();
				
				timeCount = (double)(fim - inicio) / CLOCKS_PER_SEC;
				printf("\nTempo de execucao (Radix): %5.1f microssegundos\n", 1000000 * timeCount);
				break;
			case 2:
				inicio = clock();
				countingSort(ord, MAX);
				fim = clock();

				timeCount = (double)(fim - inicio) / CLOCKS_PER_SEC;
				printf("\nTempo de execucao (Counting): %5.1f microssegundos\n", 1000000 * timeCount);
				break;
			default:
				system("clear");
				printf("\nValor invalido!!\n");
				continue;
		}

		printf("\nArray Desordenado: \t\t Array Ordenado:\n");
		for(int i = 0; i<MAX; i++)
		{
			printf(" vetor[%d] = %d \t\t\t vetor[%d] = %d \n", i, desord[i], i, ord[i]);
		}
	}

	fclose(arq);
	system("clear");
	return 0;
}
