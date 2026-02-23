#include <stdio.h>
#include <math.h>
#define PI 3.14

void CalcularCilindro(double *a, double *v, double raio, double altura)
{
    *a = 2 * PI * raio * altura + 2 * PI * pow(raio, 2);
    *v = PI * altura * pow(raio, 2);
}

void LerCilindro(double *r, double *al)
{
    printf("Informe o raio: ");
    scanf("%lf", r);
    printf("Informe a altura: ");
    scanf("%lf", al);
}

void ExibirCilindro(double a, double v)
{
    printf("Cilindro:\nÁrea: %.2f\nVolume: %.2f\n", a, v);
}

int main(void)
{
    double Raio, Altura, Area, Volume;

    // Ler valores do usuário
    LerCilindro(&Raio, &Altura);

    // Calcular área e volume
    CalcularCilindro(&Area, &Volume, Raio, Altura);

    // Exibir os resultados
    ExibirCilindro(Area, Volume);

    return 0;
}