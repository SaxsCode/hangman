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
return 0;

}