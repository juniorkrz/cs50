#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void readability(string);

int main(void)
{
    // Solicita texto ao usuário
    string text = get_string("Text: ");
    readability(text);
}

void readability(string text)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Verifica todos os caracteres do texto recebido
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // Verifica se o caractere é uma letra ou número
        if (isalnum(text[i]))
        {
            letters++;// Conta letras
        }
        // Verifica se o caractere é um espaço em branco
        else if (isspace(text[i]))
        {
            words++;// Conta palavras
        }
        // Verifica se o caractere é uma pontuação
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;// Conta frases
        }
    }

    // Calcula a média de letras e frases para cada 100 palavras
    float l = ((float) letters / words) * 100;
    float s = ((float) sentences / words) * 100;

    // Fórmula Coleman-Liau
    int index = round(((0.0588 * l) - (0.296 * s) - 15.8));

    // Imprime o resultado
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}