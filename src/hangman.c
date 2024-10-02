#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORD_LENGTH 11

int getKeyByValue(char arr[], int size, char value);
void removeElement(char arr[], int *size, char element);

int main() {

srand(time(NULL));

char words[][MAX_WORD_LENGTH] = {"boomhut", "apenstaart", "flapdrol", "hangman"}; 
int numWords = sizeof(words) / sizeof(words[0]);

int randomKey = rand() % numWords;
const char *word = words[randomKey];


int haveToGuess[MAX_WORD_LENGTH];
int wordLength = strlen(word);
int guessLength = sizeof(haveToGuess) / sizeof(haveToGuess[0]);



for (int i = 0; i < wordLength; i++) {
    haveToGuess[i] = word[i];
}

printf("%s\n", word);
printf("Characters to guess:\n");
    for (int i = 0; i < wordLength; i++) {
        printf("%d => %c\n", i, haveToGuess[i]);
    }


char userLetter;

for (int i = 0; i < guessLength; i++) {

    printf("Guess a letter: \n");
    scanf(" %c", &userLetter);

    int key = getKeyByValue(haveToGuess, &wordLength, userLetter);
    printf("key = %c\n", key);

    if (haveToGuess[key] != NULL)
    {
        printf("The word does contain:  %c\n", userLetter);   
        removeElement(haveToGuess, &wordLength, userLetter);
    } else 
    {
        printf("WRONG!");
    }

}

return 0;

}

int getKeyByValue(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;  // Return the index (key) if value is found
        }
    }
    return -1;  // Return -1 if value is not found
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