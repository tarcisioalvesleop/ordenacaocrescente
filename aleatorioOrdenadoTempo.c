#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//ordenação bubble
void bubbleSort(int array[], int length)
{
    int i, j;
    for(i = length - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(array[j] > array[j+1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
//ordenação insert
void insert_sort(int vetor[], int n)
{
    int j, temp;
    for(int i=1; i< n; i++)
    {
        temp=vetor[i];
        j=i-1;
        while(j>=0 && temp < vetor[j])
        {
            vetor[j+1]=vetor[j];
            j--;
        }
        vetor[j+1]=temp;
    }

}
//ordenacao selection
void selectionSort(int vetor[], int n)
{
    int min, temp, i;
    for(i=0; i < n; i++)
    {
        min=i;
        for(int j=i+1; j<n; j++)
        {
            if(vetor[j]< vetor[min])
            {
                min=j;
            }
        }
        if(vetor[i]!=vetor[min])
        {
            temp=vetor[i];
            vetor[i]=vetor[min];
            vetor[min]=temp;
        }
    }

}

int main() {
    double start, stop, elapsed; // variaveis para medir o tempo

    srand(time(NULL)); // gera valores completamente aleatorios em cada execucao do programa
    int i, n = 100000;
    int vetor[n], vet2[n], vetBu[n];
    for(i=0; i<n; i++){
        vetor[i] = rand(); // preenche o vetor com valores aleatorios
        vet2[i]=vetor[i];
        vetBu[i]=vetor[i];
    }

    start = (double) clock() / CLOCKS_PER_SEC;
    bubbleSort(vetBu, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do BubbleSort: %f\n", elapsed);

    start = (double) clock() / CLOCKS_PER_SEC;
    // computacao
    insert_sort(vetor, n);
    // computacao
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do Insert: %f\n", elapsed);

    start = (double) clock() / CLOCKS_PER_SEC;
    selectionSort(vet2, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do Selection: %f\n", elapsed);

    //tempo dos vetores ordenados
    start = (double) clock() / CLOCKS_PER_SEC;
    bubbleSort(vetBu, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do BubbleSort ordenado: %f\n", elapsed);

    start = (double) clock() / CLOCKS_PER_SEC;
    selectionSort(vetor, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do Selection ordenado: %f\n", elapsed);

    start = (double) clock() / CLOCKS_PER_SEC;
    insert_sort(vet2, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do Insert ordenado: %f\n", elapsed);

    return 0;
}
