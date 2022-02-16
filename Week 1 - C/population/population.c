#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Declarando funções
int get_minimum_int(string, int);
int get_years(int, int, int, int);

int main(void)
{
    int birth = 3;// Taxa de natalidade (population/birth)
    int death = 4;// Taxa de mortalidade (population/death)
    int minimum_population = 9;// População mínima

    // Solicita valor inicial e final ao usuário
    int population = get_minimum_int("Start size: ", minimum_population);
    int end_population = get_minimum_int("End size: ", population);

    // Obtem o número de anos
    int years = get_years(population, end_population, birth, death);

    // Exibe o resultado
    printf("Years: %i\n", years);
}

// Solicita valor inteiro mínimo ao usuário
int get_minimum_int(string text, int min)
{
    int n;
    do
    {
        n = get_int("%s\n", text);
    }
    while (n < min);
    return n;
}

// Calcula o número de anos até o limite
int get_years(int population, int end_population, int birth, int death)
{
    int years;
    for (years = 0; population < end_population; years++)
    {
        population = population + round((population / birth)) - round((population / death));
    }
    return years;
}