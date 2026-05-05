#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int conteudo;
    struct elemento *prox;
} Elem;

typedef Elem *Pilha;

struct fila {
    int qtd;
    Elem *inicio;
    Elem *fim;
};

typedef struct fila Fila;

/*
Pilha criar_pilha(void) {
    Pilha p = malloc(sizeof(Elem));
    if (Pilha == NULL) return NULL;
    return p;
}

void remover_pilha(Pilha *pilha) {
    if (*pilha != NULL) {
        free(*pilha);
        *pilha = NULL;
    }
}

void push_pilha(Pilha pilha, int elemento) {
    if (pilha == NULL) printf("Erro");
    else pilha
}

*/

Pilha* cria_pilha(){
    Pilha *pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL){
    *pi=NULL;
    }
    return pi;
}

void libera_pilha(Pilha* pi){
    if(pi==NULL) {
      printf("Erro");
      return;
    }
    Elem* aux;
    while(*pi!=NULL){ // *pi = topo da pilha
      aux = *pi;
      *pi =(*pi)->prox;
      free(aux);
    }
    free(pi);
    pi = NULL; // prevenir erros
  
}


int main()
{
    
    printf("Hello World");

    return 0;
}