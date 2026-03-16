/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void printarArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/*
Selection Sort

A ideia do algoritmo é procurar o menor (ou maior) elemento do vetor e movimentá-lo diretamente para a primeira (ou última) posição.
Esse processo de busca e troca é repetido para todos os n elementos até que o vetor esteja completamente ordenado.
Ele apresenta uma das menores quantidades de movimentações entre os elementos quando comparado a outros algoritmos de ordenação.
Essa característica pode representar um ganho de desempenho significativo quando há a necessidade de ordenar estruturas de dados complexas.
A sua principal desvantagem é que o número de comparações executadas é o mesmo em qualquer situação, seja no melhor caso, caso médio ou pior caso.
sso significa que, mesmo que o vetor já esteja completamente ordenado desde o início, o custo de tempo do algoritmo continuará sendo quadrático (n^2).

*/
void SelectionSort(int *array, int tamanho) {
    int i, j, menor, troca;
    for (i = 0; i < tamanho - 1; i++) {
        menor = i;
        for (j = i + 1; j < tamanho; j++) {
            if (array[j] < array[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            troca = array[i];
            array[i] = array[menor];
            array[menor] = troca;
        }
    }
}

/*
Bubble Sort

Ele compara pares de elementos adjacentes (vizinhos) e os troca de lugar se eles estiverem na ordem errada (se o de baixo for maior que o de cima).
Esse processo de varredura e troca se repete continuamente até que o vetor seja percorrido sem que nenhuma troca seja necessária,
indicando que os elementos estão ordenados.
Casos de desempenho: O melhor caso para o BubbleSort ocorre quando o vetor já está previamente ordenado.
Por outro lado, o pior caso se dá quando o vetor está ordenado de maneira decrescente (na ordem inversa).

*/

void BubbleSort(int *vetor, int tamanho) {
    int SWAP, temp, i;
    do {
        SWAP = 0;
        for (i = 0; i < tamanho - 1; i++) {
            printf("%d) ", i);
            PrintarVetor(vetor, tamanho);
            printf("%d maior que %d? ", vetor[i], vetor[i + 1]);
            if (vetor[i] > vetor[i + 1]) {
                printf("SIM\n");
                temp = vetor[i + 1];
                vetor[i + 1] = vetor[i];
                vetor[i] = temp;
                SWAP = 1;
            } else
            printf("NAO\n");
        }
        printf("Voltando ao inicio.\n");
    } while (SWAP);
}

/*
Insertion Sort

O seu método de ordenação é muito semelhante à forma como ordenamos as cartas de um baralho.
O algoritmo pega um elemento de cada vez (como se fosse uma carta) e o coloca no seu devido lugar,
garantindo que a parte do vetor que já foi percorrida (as cartas que já estão na mão) fique sempre em ordem.

*/

void InsertionSort(int *vetor, int tamanho) {
    int i, j, temp;
    for (i = 1; i < tamanho; i++) {
        for (j = i; j > 0; j--) {
            if (vetor[j] < vetor[j - 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j - 1];
                vetor[j - 1] = temp;
            } else break;
            PrintarVetor(vetor, tamanho);
        }
    }
}


int main()
{
    int array[9] = {4, 78, 34, 1, 23, 5, 33, 78, 90};
    printarArray(array, 9);
    selectionSort(array, 9);
    printarArray(array, 9);

    return 0;
}