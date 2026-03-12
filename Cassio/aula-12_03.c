/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void PrintarVetor(int *v, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}



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
    int vetor[8] = {47, 22, 67, 90, 7, 40, 1, 33};
    int vetor2[8] = {47, 22, 67, 90, 7, 40, 1, 33};
    int vetorzinho[5] = {5, 4, 3, 2, 1};
    //BubbleSort(vetor, 8);
    printf("\n");
    InsertionSort(vetor2, 8);
    

    return 0;
}
