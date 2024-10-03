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

    char haveToGuess[MAX_WORD_LENGTH];  
    int wordLength = strlen(word);

    printf("%s\n", word);
    char userLetter;

    for (int i = 0; i < wordLength; i) {  
        printf("Guess a letter: \n");
        scanf(" %c", &userLetter);

        int key = getKeyByValue(word, wordLength, userLetter); 

        if (key != -1)
        {
            printf("The word does contain: %c\n", userLetter);   
            removeElement(word, &wordLength, userLetter);
        } else 
        {
            printf("WRONG!\n");
        }
    }

    return 0;
}

int getKeyByValue(char arr[], int size, char value) {  
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void removeElement(char arr[], int *size, char element) {  
    int i, j, found = 0;

    for (i = 0; i < *size; i++) {
        if (arr[i] == element) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (j = i; j < *size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        (*size)--;
        printf("Element %c removed successfully.\n", element);
    } else {
        printf("Element %c not found in the array.\n", element);
    }
}