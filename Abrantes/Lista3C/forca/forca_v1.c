/*
Arquivo: forca_v1.c
Versão 1.0
----------------------------
Primeira versão do jogo da forca mais simples.
Meu objetivo aqui é fazer revelar a palavra pré-determinada aos poucos, pedindo a letra ao jogador.




*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool faltaLetra(char *palavra);

int main(void) {
    char palavra[] = "DETERMINADO"; // tamanho 12
    int tamanho = strlen(palavra) + 1;
    char palavraJogo[tamanho];
    memset(palavraJogo, '-', tamanho);
    palavraJogo[tamanho - 1] = '\0';
    char chute;

    // for (int i = 0; i < tamanho; i++)
    // {
    //    printf("%c", palavraJogo[i]);
    // }
    
    
while (faltaLetra(palavraJogo)) {
    printf("Chute uma letra: ");
    scanf(" %c", &chute);
    for (int i = 0; palavra[i]; i++) {
        if (palavra[i] == chute) {
            palavraJogo[i] = chute;
        }
    }
    printf("%s\n", palavraJogo);
}

    return 0;
}


bool faltaLetra(char *palavra) {
    for (char *p = palavra; *p; p++) {
        if (*p == '-') {
            return true;
        }
    }
    return false;
}