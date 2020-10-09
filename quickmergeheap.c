#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int array[], int length)
{
    int i, j, cont=0;
    for(i = length - 1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(array[j] > array[j+1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                cont++;
            }
        }
    }
    printf("Houve %d mudancas de posicoes. \n", cont);
}
 void quicksort(int values[], int began, int end)
{
    int i, j, pivo, aux;
    i = began;
    j = end-1;
    pivo = values[(began+end)/2];
    while(i <= j)
    {
        while(values[i] < pivo && i < end) i++;
        while(values[j] > pivo && j > began) j--;
        if(i <= j)
        {
            aux = values[i];
            values[i] = values[j];
            values[j] = aux;
            i++;
            j--;
        }
    }
    if(j > began)
    quicksort(values, began, j+1);
    if(i < end)
    quicksort(values, i, end);
}
//mergeSort
void mergesort(int vec[], int vecSize){
    int mid;
    if (vecSize >1){
        mid=vecSize/2;
        mergesort(vec, mid);
        mergesort(vec + mid,vecSize - mid);
        merg(vec, vecSize);
    }

}
void merg(int vec[], int vecSize){
    int mid, i, j, k;
    int *tmp;
    tmp=(int*)malloc(vecSize * sizeof(int));//criando um espaco para o vetor
    if(tmp==NULL){
        exit(1);
    }
    mid=vecSize/2;
    i=0;
    j=mid;
    k=0;
    while((i < mid)&&(j< vecSize)){
        if(vec[i] < vec[j]){
            tmp[k]=vec[i];
            i++;
        }
        else{
            tmp[k]=vec[j];
            j++;
        }
        k++;
    }
    if(i==mid){
        while(j < vecSize){
            tmp[k]=vec[j];
            j++;
            k++;
        }
    }
    else{
        while(i < mid){
            tmp[k]=vec[i];
            i++;
            k++;
        }
    }
    for(i=0; i<vecSize;i++){
        vec[i]=tmp[i];
    }
    free(tmp);
}
//exit mergeSort
//heapsort
void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(n^2) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n <= 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}

void Imprime(int vet[], int tam)
{
    int i;
    for(i=0; i< tam; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}


int main()
{
    double start, stop, elapsed; // variaveis para medir o tempo

    srand(time(NULL)); // gera valores completamente aleatorios em cada execucao do programa
    int i, n = 100000;
    int vetor[n], mer[n], heap[n];
    for(i=0; i<n; i++){
        vetor[i] = rand(); // preenche o vetor com valores aleatorios
        mer[i]=vetor[i];
        heap[i]=vetor[i];
    }
    start = (double) clock() / CLOCKS_PER_SEC;//quickSort
    quicksort(vetor, 0, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do QuickSort: %f\n", elapsed);
    start = (double) clock() / CLOCKS_PER_SEC;//mergeSort
    mergesort(mer, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do MergeSort: %f\n", elapsed);
    start = (double) clock() / CLOCKS_PER_SEC;//heapsort
    heapsort(heap, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do HeapSort: %f\n", elapsed);

    // vetores ordenados
    start = (double) clock() / CLOCKS_PER_SEC;
    quicksort(vetor, 0, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do QuickSort ordenado: %f\n", elapsed);
    start = (double) clock() / CLOCKS_PER_SEC;//mergeSort
    mergesort(mer, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do MergeSort ordenado: %f\n", elapsed);
    start = (double) clock() / CLOCKS_PER_SEC;//heapsort
    heapsort(heap, n);
    stop = (double) clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("Tempo total em segundos do HeapSort: %f\n", elapsed);

    return 0;
}
