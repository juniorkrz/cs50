#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // Check if the KEY was passed as a parameter
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    // Checks if the KEY contains 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check the KEY
    char duplicates[26] = {};
    for (int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        for (int s = 0; s < 26; s++)
        {
            // Checks if the character is repeated
            if (argv[1][i] == duplicates[s])
            {
                printf("Usage: ./substitution KEY\n");
                return 1;
            }
        }
        duplicates[i] = argv[1][i];

        // Checks if the character is a digit or is a space
        if (isdigit(argv[1][i]) || isspace(argv[1][i]))
        {
            printf("Usage: ./substitution KEY\n");
            return 1;
        }
    }

    // Ask the user for input
    string plaintext = get_string("plaintext:  ");

    // Show the result
    printf("ciphertext: ");

    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                printf("%c", toupper(argv[1][(int)((plaintext[i] - 'A') % 26)]));
            }
            else if (islower(plaintext[i]))
            {
                printf("%c", tolower(argv[1][(int)((plaintext[i] - 'a') % 26)]));
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