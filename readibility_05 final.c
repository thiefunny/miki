#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//variables

int charcount(), wordcount(), sentencecount();
int i = 0, n, ccount = 0, wcount = 0, scount = 0;
string text;

int main(void)
{
    text = get_string("Text: ");
//counts letters
    charcount();
//counts words
    wordcount();
//counts sentences
    sentencecount();
//calculates L
    float L = (float) ccount * 100 / wcount;
//calculates S
    float S = (float) scount * 100 / wcount;
//calculates index
    float index = round(0.0588 * L - 0.296 * S - 15.8);
//prints Grade
    if (index >= 1 && index <= 16)
    {
        printf("Grade %.0f\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}

//this functions calculates letters
int charcount()
{
    for (i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            ccount = ccount + 1;
        }
    }
    return ccount;
}

//this functions calculates words
int wordcount()
{
    for (i = 0; i < n; i++)
    {
        if ((isspace(text[i]) && isalpha(text[i + 1])))
        {
            wcount = wcount + 1;
        }
        else if ((isspace(text[i]) && ispunct(text[i + 1])))
        {
            wcount = wcount + 1;
        }
        else if ((i == 0) && (isalpha(text[i])))
        {
            wcount = wcount + 1;
        }
    }
    return wcount;
}

//this functions calculates sentences
int sentencecount()
{
    for (i = 0; i < n; i++)
    {
        if (
            (isalpha(text[i]) && (text[i + 1] == '.')) ||
            (isalpha(text[i]) && (text[i + 1] == '!')) ||
            (isalpha(text[i]) && (text[i + 1] == '?'))
        )
        {
            scount = scount + 1;
        }
    }
    return scount;
}