#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    // Counting letter in word
    int word_length = strlen(word);

    // Get points for every letter in word
    int points = 0;
    for (int i = 0; i < word_length; i++)
    {
        // Check if character is uppercase
        if (isupper(word[i]))
        {
            // Get position from ASCII - position of 'A' in ASCII
            // Calculate points
            int position_points = word[i] - 65;
            points += POINTS[position_points];
            printf("Letter: %c %i\n", word[i], POINTS[position_points]);
        }

        // Check if character is lowercase
        else if (islower(word[i]))
        {
            // Get position from ASCII - position of 'a' in ASCII
            // Calculate points
            int position_points = word[i] - 97;
            points += POINTS[position_points];
            printf("Letter: %c %i\n", word[i], POINTS[position_points]);
        }
    }
    // Return score
    printf("Final score %in\n", points);
    return points;
}
