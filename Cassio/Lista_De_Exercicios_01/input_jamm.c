#include "input_jamm.h"
#include <stdio.h>

int pegar_int() {
    int x;
    printf("Digite um inteiro: ");
    scanf("%d", &x);
    return x;
}

double pegar_double() {
    double x;
    printf("Digite um numero: ");
    scanf("%lf", &x);
    return x;
}

char pegar_char() {
    char x;
    printf("Digite um caractere: ");
    scanf(" %c", &x);
    return x;
}