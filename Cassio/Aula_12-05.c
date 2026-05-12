/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *esq;
    struct no *dir;
} no;

typedef struct no *ArvBin;

ArvBin* cria_ArvBin(void) {
    ArvBin *raiz = malloc(sizeof(ArvBin));
    if (raiz != NULL) {
        *raiz = NULL;
    }
    return raiz;
}

int insere_ArvBin(ArvBin *raiz, int valor) {
    
}



int main(void)
{
    printf("Hello World");

    return 0;
}