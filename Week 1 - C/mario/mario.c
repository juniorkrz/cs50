#include <stdio.h>
#include <cs50.h>

// Declara funções
void piramide(int);
int get_valid_int(string);

// Inicio
int main(void)
{
    int h = get_valid_int("Qual a altura da pirâmide? ");// Solicita a altura
    piramide(h);// Faz a pirâmide
}

// Solicita o tamanho válido da altura da pirâmide (de 1 à 8)
int get_valid_int(string text)
{
    int h = 0;
    do
    {
        h = get_int("%s", text);
    }
    while (h < 1 || h > 8);
    return h;

}

// Faz a pirâmide
void piramide(int h)
{
    for (int l = 0; l < h; l++)
    {
        for (int i = 0; i < h - l - 1; i++)
        {
            printf(" ");
        }
        for (int i = 0; i < l + 1; i++)
        {
            printf("#");
        }
        printf("  ");                   // Comente essa linha para o Resultado do Ex01 - Mario (versão fácil)
        for (int i = 0; i < l + 1; i++) // Comente essa linha para o Resultado do Ex01 - Mario (versão fácil)
        {                               // Comente essa linha para o Resultado do Ex01 - Mario (versão fácil)
            printf("#");                // Comente essa linha para o Resultado do Ex01 - Mario (versão fácil)
        }                               // Comente essa linha para o Resultado do Ex01 - Mario (versão fácil)
        printf("\n");
    }
}