#include "mediah.h"
#include <stdio.h>
#include <stdlib.h>

double sortearnumero() {
    double num = (double) rand() / RAND_MAX;
    return num;
}

double tirarmedia(double *p, int tamanho) {
    double soma = 0, media = 0;
    for (int i = 0; i < tamanho; i++, p++) {
        soma += *p;
    }
    media = soma / (double) tamanho;
    return media;
}