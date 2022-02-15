#include <stdio.h>
#include <math.h>
#include <cs50.h>

// Declarando funções
int conta_digitos(long);
void verifica_cartao(long);

int main(void)
{
    long cartao = get_long("Número do Cartão: ");// Entrada do usuário
    verifica_cartao(cartao);// Verificando cartão
}

// Conta quantos digitos o cartão possui
int conta_digitos(long digitos)
{
    int num_digitos;
    for (num_digitos = 0; digitos > 0; num_digitos++)
    {
        digitos = round(digitos / 10);
    }
    return num_digitos;
}

// Aplica o algoritmo de Luhnn
void verifica_cartao(long cartao)
{
    int num_digitos = conta_digitos(cartao);
    int num;
    int somapar = 0;
    int somaimpar = 0;
    int epar = 0;
    int num_iniciais;

    // Varredura dos números da direita pra esquerda
    while (cartao > 0)
    {
        num = cartao % 10;
        epar++;
        cartao = cartao / 10;
        
        // Verifica se o número é par
        if (epar % 2 == 0)
        {
            num *= 2;

            // Se for maior que 10 então precisará separar os algarismos para soma-los
            if (num >= 10)
            {
                num = (num % 10) + (num / 10);
            }
            somapar += num;
        }
        else
        {
            somaimpar += num;
        }

        // Checar quais sãos os dois primeiros digitos do cartão
        if (cartao < 100 && cartao >= 10)
        {
            num_iniciais = cartao;
        }
    }

    // Verifica se atende ao algorismo de Luhnn e se tem entre 12 e 19 digitos
    // ... e exibe o resultado.
    if (((somapar + somaimpar) % 10) == 0 && num_digitos >= 12 && num_digitos <= 19)
    {
        if (num_iniciais == 34 || num_iniciais == 37)
        {
            printf("AMEX\n");
        }
        else if (num_iniciais >= 51 && num_iniciais <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (num_iniciais / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}