#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int LetterCount(string text);
int WordCount(string text);
int SentenceCount(string text);

int main(void)
{
    // Prompt User for Text input
    string text = get_string("Text: ");
    // Count the number of letters in the text

    int letters = LetterCount(text);
    // Count the number of words in the text with the spaces +1
    int words = WordCount(text);
    // Count the number of punctuations to get the number of sentences
    int sentences = SentenceCount(text);
    // Use Coleman-Liau index 0.0588 * Average number of letters per 100 words - 0.296 * Average
    // number of sentences per 100 words - 15.8
    float l = (float) letters / words * 100;

    float s = (float) sentences / words * 100;

    int result = round(0.0588 * l - 0.296 * s - 15.8);

    if (result >= 1 && result < 16)
    {
        printf("Grade %i\n", result);
    }
    else if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}
int LetterCount(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int WordCount(string text)
{
    int words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words + 1;
}

int SentenceCount(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
