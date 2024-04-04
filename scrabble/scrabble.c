#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int WordScore(string s);
const int score[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                     1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int main(void)
{
    // Prompt Players for words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    // Check letters of words for numbers and add them
    int scoreplayer1 = WordScore(player1);
    int scoreplayer2 = WordScore(player2);

    // Compare the two numbers and print winner
    if (scoreplayer1 < scoreplayer2)
    {
        printf("Player 2 wins!\n");
    }
    else if (scoreplayer1 == scoreplayer2)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player 1 wins!\n");
    }
}
int WordScore(string s)
{

    int points = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isupper(s[i]))
        {
            points += score[s[i] - 'A'];
        }
        else if (islower(s[i]))
        {
            points += score[s[i] - 'a'];
        }
    }
    return points;
}
