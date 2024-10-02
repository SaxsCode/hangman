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


int haveToGuess[MAX_WORD_LENGTH];
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

    removeElement(haveToGuess, &wordLength, userLetter);

    printf("Characters to guess:\n");
    for (int i = 0; i < wordLength; i++) {
        printf("%d => %c\n", i, haveToGuess[i]);
    }


    printf("Guess a letter: \n");
    scanf(" %c", &userLetter);

} else {
    printf("WRONG!");
    printf("Guess a letter: \n");
    scanf(" %c", &userLetter);
}

return 0;

}

void removeElement(int arr[], int *size, int element) {
    int i, j, found = 0;

    // Find the index of the element
    for (i = 0; i < *size; i++) {
        if (arr[i] == element) {
            found = 1;
            break;
        }
    }

    // If element is found
    if (found) {
        // Shift all elements after index i by one position to the left
        for (j = i; j < *size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        // Decrease the size of the array
        (*size)--;
        printf("Element %d removed successfully.\n", element);
    } else {
        printf("Element %d not found in the array.\n", element);
    }
}