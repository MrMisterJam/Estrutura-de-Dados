/*
Arquivo: forca_v2.c
Versão 2.0
----------------------------
Vou fazer agora a condição de derrota com vidas


*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool faltaLetra(char *palavra);
bool trocarLetra(char *p, char *pj, char c);

int main(void) {
    char palavra[] = "DETERMINADO"; // tamanho 12
    int tamanho = strlen(palavra) + 1;
    char palavraJogo[tamanho];
    memset(palavraJogo, '-', tamanho);
    palavraJogo[tamanho - 1] = '\0';
    char chute;
    int vidas = 8;

    // for (int i = 0; i < tamanho; i++)
    // {
    //    printf("%c", palavraJogo[i]);
    // }
    
    
while (faltaLetra(palavraJogo) && vidas) {
    printf("Vidas restantes: %d\n", vidas);
    printf("Chute uma letra: ");
    scanf(" %c", &chute);
    if (!trocarLetra(palavra,palavraJogo,chute)) {
        vidas--;
    }
    printf("%s\n", palavraJogo);
}
    if (vidas) {
        printf("VOCÊ GANHOU!\n");
    } else {
        printf("VOCÊ PERDEU\n");
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

bool trocarLetra(char *p, char *pj, char c) {
    for (char *i = p; *i; i++) {
        if (*i == c) {
             *pj = c;
            return true;
        }
        pj++;
    }
    return false;
}