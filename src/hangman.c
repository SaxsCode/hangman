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

// printf("Your letter is: %c\n", userLetter);

return 0;

}