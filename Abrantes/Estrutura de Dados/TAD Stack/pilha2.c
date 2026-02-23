#include <stdio.h>
#include "pilha.h"
#include <stdlib.h>

#define TAMMAX 0
#define TAMINI 2

static void aumentar_stack(stackTAD);

struct stackTCD
{
    elementoT *dados;
    int contagem;
    int tamanho;
};

stackTAD criar_stackTAD(void)
{
    stackTAD S = malloc(sizeof(struct stackTCD));
    if (S == NULL)
    {
        return NULL;
    }
    S->dados = malloc(sizeof(elementoT) * TAMINI);
    if (S->dados == NULL)
    {
        free(S);
        S = NULL;
        return NULL;
    }
    S->contagem = 0;
    S->tamanho = TAMINI;
    return S;
}

void remover_stack(stackTAD *stack)
{
    if (*stack != NULL)
    {
        free((*stack)->dados);
        (*stack)->dados = NULL;
        free(*stack);
        *stack = NULL;
    }
}

void push(stackTAD stack, elementoT elemento)
{
    if (stack == NULL)
    {
        printf("Erro");
        return;
    }
    if (stack->contagem == stack->tamanho)
        aumentar_stack(stack);
    stack->dados[stack->contagem++] = elemento;
    
}

static void aumentar_stack(stackTAD stack) {
    elementoT *temp;
    int novo_tamanho = stack->tamanho * 2;
    temp = realloc(stack->dados, sizeof(elementoT) * novo_tamanho);
    if (temp == NULL)
    {
        exit(1);
    }

    stack->dados = temp;
    stack->tamanho = novo_tamanho;
}

bool cheia(stackTAD stack) {
    return false;
}

