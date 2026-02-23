#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "pilha.h"

#define TAMMAX 1000

struct stackTCD
{
    elementoT dados[TAMMAX];
    int contagem;
};

stackTAD criar_stackTAD(void)
{
    stackTAD S = malloc(sizeof(struct stackTCD));
    if (S == NULL)
    {
        return NULL;
    }
    S->contagem = 0;
    return S;
};

void remover_stackTAD(stackTAD *stack)
{
    if (*stack != NULL)
    {
        free(*stack);
        *stack = NULL;
    }
}

void push(stackTAD stack, elementoT elemento)
{
    if (stack == NULL)
    {
        printf("Erro");
    }
    else if (cheia(stack))
    {
        printf("Erro");
    }
    else
    {
        stack->dados[stack->contagem++] = elemento;
    }
}

elementoT pop(stackTAD stack)
{
    if (stack == NULL)
    {

        return NAN;
    }
    else if (vazia(stack))
    {
        return NAN;
    }

    return stack->dados[--stack->contagem];
}

bool vazia(stackTAD stack)
{
    if (stack == NULL)
    {
        exit(1);
    }
    return (stack->contagem == 0);
}
bool cheia(stackTAD stack)
{
    if (stack == NULL)
    {
        exit(1);
    }
    return (stack->contagem == TAMMAX);
}

long int tamanho(stackTAD stack)
{
    if (stack == NULL)
    {
        return -1;
    }
    return (long int)TAMMAX;
}

long int qtdElementos(stackTAD stack)
{
    if (stack == NULL)
    {
        return -1;
    }
    return stack->contagem;
}

long int espacoRestante(stackTAD stack)
{
    if (stack == NULL)
    {
        return -1;
    }
    else if (TAMMAX == 0)
    {
        return 0;
    }
    return TAMMAX - stack->contagem;
}

elementoT verElemento(stackTAD stack, int posicao)
{
    if (stack == NULL)
    {
        return NAN;
    }
    else if (vazia(stack))
    {
        return NAN;
    }
    else if (posicao < 0 || posicao >= stack->contagem)
    {
        return NAN;
    }
    return stack->dados[posicao];
}

void imprimirStack(stackTAD stack, int limite)
{
    if (stack == NULL)
    {
        print("Erro");
    }
    else if (vazia(stack))
    {
        printf("Erro");
    }
    else if (limite < 0 || limite > stack->contagem)
        limite == stack->contagem;
    for (int i = 0; i < stack->contagem && i < limite; i++)
    {
        printf("%g\n", stack->dados[i]);
    }
}