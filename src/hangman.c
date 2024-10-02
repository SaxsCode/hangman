#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 11


int main() {

srand(time(NULL));

char words[][MAX_WORD_LENGTH] = {"boomhut", "apenstaart", "flapdrol", "hangman"}; 
int numWords = sizeof(words) / sizeof(words[0]);

int randomKey = rand() % numWords;
const char *word = words[randomKey];


char haveToGuess[MAX_WORD_LENGTH];
int wordLength = strlen(word);

for (int i = 0; i < wordLength; i++) {
    haveToGuess[i] = word[i];
}

printf("%s\n", word);
printf("Characters to guess:\n");
    for (int i = 0; i < wordLength; i++) {
        printf("%d => %c\n", i, haveToGuess[i]);
    }

char userLetter;

printf("Guess a letter: \n");
scanf(" %c", &userLetter);


if (strchr(word, userLetter) != NULL)
{
    printf("The word does contain:  %c\n", userLetter);    
    printf("Guess a letter: \n");
    scanf(" %c", &userLetter);

} else {
    printf("WRONG!");
    printf("Guess a letter: \n");
    scanf(" %c", &userLetter);
}

return 0;

}