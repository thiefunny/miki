#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(int argc, string argv[])
{

// valid key check

// check of number of arguments

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
// check of number of letters
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
// check of isalpha
    int i;
    string key = argv[1];
    for (i = 0; i < 26; i++)
    {
        if ((key[i] < 65) || (key[i] > 122) || ((key[i] > 90) && (key[i] < 97)))
        {
            printf("Key accepts only letters.\n");
            return 1;
        }
    }
// check of duplicated letters
    int j;
    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (key[i] == key[j])
            {
                printf("Every letter in the key MUST be used only once.\n");
                return 1;
            }
        }
    }

// variables

    string alfa = "abcdefghijklmnopqrstuvwxyz";
//    string key = argv[1];
    string input = get_string("plaintext: ");
    int lt = strlen(alfa), lk = strlen(key), li = strlen(input);
    int output[li];
    int asciialfa[lt], asciikey[lk], diff[lk], z, keylower[lk];

// key to lowercase

    for (i = 0; i < lk; i++)
    {
        keylower[i] = tolower(key[i]);
    }

// calculates ASCII difference

    for (i = 0; i < lt; i++)
    {
        asciialfa[i] = alfa[i];
        asciikey[i] = keylower[i];
        diff[i] = asciikey[i] - asciialfa[i];
    }

// assings key to output

    for (i = 0; i < li; i++)
    {
        for (j = 0; j < lk; j++)
        {
            if (input[i] == alfa[j])
            {
                output[i] = keylower[j];
            }
            else if (input[i] == alfa[j] - 32)
            {
                output[i] = keylower[j] - 32;
            }
            else if (isalpha(input[i]) == 0)
            {
                output[i] = input[i];
            }
        }
    }

// prints output

    printf("ciphertext: ");
    for (i = 0; i < li; i++)
    {
        printf("%c", output[i]);
    }
    printf("\n");
}