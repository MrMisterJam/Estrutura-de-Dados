/*
Arquivo: forca_v3.c
Versão 3.0
----------------------------
Começando a implementação da interface velha.h
Corrigir entrada de letra minúscula

*/
#include "velha.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

bool faltaLetra(char *palavra);
bool trocarLetra(char *p, char *pj, char c);
bool letraRepetida(char *letrasJogadas, char chute);

int main(void)
{
    srand(time(NULL));
    inicializar_dicionario();
    char *palavra = sortear_palavra();
    int tamanho = strlen(palavra) + 1;
    char palavraJogo[tamanho], letrasJogadas[26];
    memset(palavraJogo, '-', tamanho);
    memset(letrasJogadas, 0, 26);
    palavraJogo[tamanho - 1] = '\0';
    char chute;
    int vidas = 8;

    while (faltaLetra(palavraJogo) && vidas)
    {
        printf("%s\n", palavraJogo);
        printf("Vidas restantes: %d\n", vidas);
        printf("Chute uma letra: ");
        scanf(" %c", &chute);
        chute = toupper(chute); // Letra maiúscula
        if (letraRepetida(letrasJogadas, chute))
        {
            continue;
        }
        if (!trocarLetra(palavra, palavraJogo, chute))
        {
            vidas--;
        }
    }
    if (vidas)
    {
        printf("GANHOU O JOGO!\n");
    }
    else
    {
        printf("PERDEU\n");
        printf("A palavra era: \"%s\"", palavra);
    }
    return 0;
}

bool faltaLetra(char *palavra)
{
    for (char *p = palavra; *p; p++)
    {
        if (*p == '-')
        {
            return true;
        }
    }
    return false;
}

bool trocarLetra(char *p, char *pj, char c)
{
    bool acertou = false;
    for (char *i = p; *i; i++)
    {
        if (*i == c)
        {
            *pj = c;
            acertou = true;
        }
        pj++;
    }
    return acertou;
}

bool letraRepetida(char *letrasJogadas, char chute)
{
    int i = 0;
    while (letrasJogadas[i])
    {
        if (letrasJogadas[i] == chute)
        {
            printf("Essa letra foi jogada. Tente outra.\n");
            return true;
        }
        i++;
    }
    letrasJogadas[i] = chute;
    letrasJogadas[i + 1] = '\0';
    return false;
}