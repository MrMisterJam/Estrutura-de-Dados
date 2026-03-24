/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stblib.h>
#include <math.h>
void printarArray(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void merge (int *v, int inicio, int meio, int fim) {
    int *temp, i, j, k, tamanho, p1, p2, fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int*)malloc(tamanho*(sizeof(int)));
    if (temp != NULL) {
        for(i = 0; i < tamanho; i++) {
            if(!fim1 && !fim2) {            // compara se nenhum chegou ao fim e avança
                if (v[p1] < v[p2]) {
                    temp[i] = v[p1];
                    p1++;
                } else {
                    temp[i] = v[p2++];
                }
            } else {                        // se um dos vetores chegarem ao fim
                if (!fim1) {
                    temp[i] = v[p1++];
                } else {
                    temp[i] = v[p2++];
                }
            }
        }
        for (j = 0, k = inicio; j<tamanho; j++, k++) {
            v[k] = temp[j];
        }
        free(temp);
        
    }
    
}


void mergeSort(int *v, int inicio, int fim) {
    int meio;
    if(inicio<fim){
        meio = floor((inicio+fim)/2);
        mergeSort(v, inicio, meio);
        mergeSort(v, meio+1, fim);
        merge(v, inicio, meio, fim);
    }
}

void particiona(int *v, int inicio, int fim) {
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = v[inicio];
    while (esq < dir) {
        while (esq <= final && v[esq] <= pivo) {
            esq++;
        }
        
        while (dir >= 0 && v[dir] > pivo) {
            dir--;
        }
        
        if (esq < dir) {
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}

void quickSort(int *v, int inicio, int fim) {
    int pivo;
    if(fim > inicio) {
        pivo = particiona(v, inicio, fim);
        quickSort(v, inicio, pivo - 1);
        quickSort(v, pivo + 1, fim);
    }
}













int main()
{
    printf("Hello World");

    return 0;
}