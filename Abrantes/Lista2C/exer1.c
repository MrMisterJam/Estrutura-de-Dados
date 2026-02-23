/*
Defina uma enumeração chamada de dia_da_semana_t, cujos elementos são os dias da semana. Escreva as funções “dia_seguinte”
e “dia_anterior”, que recebem um valor do tipo dia_da_semana_t e retornam o dia da semana que está após ou antes da data
especificada, respectivamente. Por exemplo: “dia_anterior(Domingo)” deve retornar
Sábado. Escreva também a função “incrementar_dia(dia_inicial, delta)”,
que retorna o dia da semana que ocorre delta dias a partir do dia_inicial. Assim, por
exemplo, incrementar_dia(Quinta, 4) deve retornar Segunda. A implementação
de incrementar_dia deve funcionar se delta for negativo, situação na qual os dias são
contados para trás.
*/
#include <stdio.h>

enum dia_da_semana_t
{
    SEGUNDA_FEIRA,
    TERCA_FEIRA,
    QUARTA_FEIRA,
    QUINTA_FEIRA,
    SEXTA_FEIRA,
    SABADO,
    DOMINGO
};

int dia_seguinte(enum dia_da_semana_t d)
{
    return ((d + 1) % d);
}

int dia_anterior(enum dia_da_semana_t d)
{
    return (d == SEGUNDA_FEIRA) ? DOMINGO : (d - 1);
}

int incrementar_dia(enum dia_da_semana_t d, int delta)
{
    // return ((d + delta) % 7); só delta positivo
    int novo_dia = d;
    if (delta > 0)
    {
        novo_dia = (d + delta) % 7;
    }
    else if (delta < 0)
    {
        for (int i = 0; i > delta; i--)
        {
            novo_dia = dia_anterior(novo_dia);
        }
    }
    return novo_dia;
}

int main(void)
{
    enum dia_da_semana_t t = incrementar_dia(QUINTA_FEIRA, -8);
    switch (t)
    {
    case SEGUNDA_FEIRA:
        printf("SEGUNDA-FEIRA");
        break;
    case TERCA_FEIRA:
        printf("TERÇA-FEIRA");
        break;
    case QUARTA_FEIRA:
        printf("QUARTA-FEIRA");
        break;
    case QUINTA_FEIRA:
        printf("QUINTA-FEIRA");
        break;
    case SEXTA_FEIRA:
        printf("SEXTA-FEIRA");
        break;
    case SABADO:
        printf("SÁBADO");
        break;
    case DOMINGO:
        printf("DOMINGO");
        break;
    default:
        break;
    }
    return 0;
}