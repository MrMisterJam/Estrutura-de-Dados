#include "velha.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_PALAVRAS 100  // Número máximo de palavras no dicionário
#define TAM_MAX_PALAVRA 50  // Tamanho máximo de uma palavra

static char dicionario[MAX_PALAVRAS][TAM_MAX_PALAVRA];  // Armazena as palavras
static int totalPalavras = 0;

void inicializar_dicionario() {
    FILE *palavras = fopen("palavras.txt", "r");
    int c, letraAtual = 0;
    if (!palavras) {
        perror("Erro ao abrir o arquivo de dicionário");
        exit(EXIT_FAILURE);
    }
    while ((c = getc(palavras)) != EOF) {
        if (c == '\n' || c == '\r' || c == ' ') {
            if (letraAtual > 0) { // Se já temos uma palavra sendo lida
                dicionario[totalPalavras][letraAtual] = '\0'; // Finaliza a string
                totalPalavras++;
                letraAtual = 0; // Reinicia o índice para a próxima palavra
            }
        } else {
            if (letraAtual < TAM_MAX_PALAVRA - 1) { // Garante que não ultrapasse o limite
                dicionario[totalPalavras][letraAtual] = c;
            letraAtual++;
            }
        }
        if (totalPalavras >= MAX_PALAVRAS) { 
            break; // Evita ultrapassar o limite do array
        }
    }


    fclose(palavras);
};

char *sortear_palavra() {
    if (totalPalavras == 0) return NULL; // Evita erro caso o dicionário esteja vazio
    int palavra = rand() % totalPalavras;
    return dicionario[palavra];
}