#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>

typedef double elementoT;

typedef struct stackTCD *stackTAD;

stackTAD criar_stackTAD(void);

void remover_stackTAD(stackTAD *);

void push(stackTAD, elementoT);

elementoT pop(stackTAD);

bool vazia(stackTAD);
bool cheia(stackTAD);

#ifdef debug
long int tamanho(stackTAD);
long int qtdElementos(stackTAD);
long int espacoRestante(stackTAD);
elementoT verElemento(stackTAD, int);
void imprimirStack(stackTAD, int);
#endif
#endif