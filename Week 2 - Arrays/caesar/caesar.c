#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        if (isdigit(argv[1][i]) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                printf("%c", ((plaintext[i] - 'A' + key) % 26) + 'A');
            }
            else if (islower(plaintext[i]))
            {
                printf("%c", ((plaintext[i] - 'a' + key) % 26) + 'a');
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}