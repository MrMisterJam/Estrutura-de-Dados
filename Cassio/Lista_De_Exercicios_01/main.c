/*
Lista de Exercícios 01
*/
#include <stdio.h>
#include <stdlib.h>
#include "input_jamm.h"
int main(void)
{
    /*
    // 1)
    int a, b, temp;
    printf("Digite o valor de A:\n");
    scanf("%d", &a);
    printf("Digite o valor de B:\n");
    scanf("%d", &b);
    temp = a;
    a = b;
    b = temp;
    printf("Novos valores: A = %d B = %d", a, b);
    */
    
    /*
    // 2)
    float nota, soma, media;
    for(int i = 0; i < 4; i++) {
        scanf("%f", &nota);
        soma += nota;
    }
    media = soma / 4;
    printf("%.2f", media);
    */

    /*
    // 3)
    float real, cotacao, dolar;
    
    scanf("%f", &real);
    scanf("%f", &cotacao);
    dolar = real / cotacao;
    printf("%.2f", dolar);
    */

    /*
    // 22)
    const char *meses[] = {
        "Janeiro",
        "Fevereiro",
        "Marco",
        "Abril",
        "Maio",
        "Junho",
        "Julho",
        "Agosto",
        "Setembro",
        "Outubro",
        "Novembro",
        "Dezembro"
    };
    int mes;
    mes = pegar_int() - 1;
    printf("Mes selecionado: %s\n", meses[mes]);
    */

    /*
    // 23)
    double num1, num2, result;
    char operador;
    num1 = pegar_double();
    num2 = pegar_double();
    operador = pegar_char();

    switch (operador)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        result = num1 / num2;
        break;
    default:
        printf("Houve um erro, encerrando o programa...");
        exit(EXIT_FAILURE);
        break;
    }

    printf("%f", result);
    */
    
    /*
    // 24)
    char idiom = pegar_char();
    switch (idiom)
    {
    case 'E':
        printf("Hello World!");
        break;
    case 'P':
        printf("Ola Mundo!");
        break;
    case 'S':
        printf("Hola Mundo!");
        break;
    default:
        printf("Idioma invalido, encerrando o programa...");
        exit(EXIT_FAILURE);
        break;
    }
    */
    
    /*
    // 25)
    int pontuacao = 0;
    char cor;
    do {
        printf("Pontuacao atual: %d\n", pontuacao);
        cor = pegar_char();
        switch(cor)
        {
        case 'V':
            pontuacao += 10;
            break;
        case 'A':
            pontuacao += 5;
            break;
        case 'Z':
            pontuacao += 20;
            break;
        default:
            printf("Cor invalida.\n");
            break;
        }
        
    } while (pontuacao < 100);
    
    printf("Voce ganhou o jogo!");
    
    */
    
    // 34)
    
    for (int i = 2; i <= 20; i += 2) {
        printf("%d\n", i);
    }
    
    for (int i = 2; i <= 20; i++) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}