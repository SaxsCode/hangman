#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



int main() {

srand(time(NULL));

char words[][11] = {"boomhut", "apenstaart", "flapdrol", "hangman"}; 
int numWords = sizeof(words) / sizeof(words[0]);

int randomKey = rand() % numWords;
const char *word = words[randomKey];

printf("%s\n", word);

char userLetter;

printf("Guess a letter: \n");
fflush(stdout);
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