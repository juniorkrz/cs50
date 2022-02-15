#include <stdio.h>
#include <math.h>
#include <cs50.h>

// Declarando funções
float get_positive_float(string);
int calculo_moedas(float);

// Inicio
int main(void)
{
    float troco = get_positive_float("Qual o troco do cliente? ");
    int moedas = calculo_moedas(troco);
    //printf("Total de moedas utilizadas: %i\n", moedas);
    printf("%i\n", moedas);
}

// Pergunta qual o valor do troco
float get_positive_float(string s)
{
    float f = 0;
    do
    {
        f = get_float("%s", s);
    }
    while (f < 0);
    return f;
}

// Realiza o cálculo das moedas
int calculo_moedas(float t)
{
    int m = 0;
    t = round(t * 100);
    while (t >= 1)
    {
        if (t >= 25)
        {
            //printf("Use uma moeda de R$0.25\n");
            t -= 25;
        }
        else if (t >= 10)
        {
            //printf("Use uma moeda de R$0.10\n");
            t -= 10;
        }
        else if (t >= 5)
        {
            //printf("Use uma moeda de R$0.05\n");
            t -= 5;
        }
        else if (t >= 1)
        {
            //printf("Use uma moeda de R$0.01\n");
            t -= 1;
        }
        m++;
    }
    return m;
}