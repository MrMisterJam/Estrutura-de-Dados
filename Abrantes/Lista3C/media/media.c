/*
Escreva um programa que repetidamente cria um número aleatório entre 0 e 1 e mostre a média
desses números após uma certa quantidade de rodadas solicitadas pelo usuário
*/

#include "mediah.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int tamanho;
    printf("Este programa calcula a média de uma série de números aleatórios entre 0 e 1.\n");
    printf("Quantas rodadas serão executadas? ");
    scanf("%d", &tamanho);
    double numeros[tamanho], media;
    for (int i = 0; i < tamanho; i++) {
        numeros[i] = sortearnumero();
    }
    media = tirarmedia(numeros, tamanho);
    printf("A média apos %d rodadas é %f", tamanho, media);
    return 0;
}