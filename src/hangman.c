#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 20

int getKeyByValue(char arr[], int size, char value);
void showCensoredWord(char arr[], int size, char guessed[]);

int main() {
    srand(time(NULL));

    char words[][MAX_WORD_LENGTH] = {"boomhut", "apenstaart", "flapdrol", "hangman"}; 
    int numWords = sizeof(words) / sizeof(words[0]);

    int randomKey = rand() % numWords;
    char word[MAX_WORD_LENGTH];
    strcpy(word, words[randomKey]);

    int wordLength = strlen(word);
    char guessed[MAX_WORD_LENGTH] = {0};

    showCensoredWord(word, wordLength, guessed);
    
    char userLetter;
    int remainingLetters = wordLength;

    while (remainingLetters > 0) {  
        printf("Guess a letter: ");
        scanf(" %c", &userLetter);

        int key = getKeyByValue(word, wordLength, userLetter); 

        if (key != -1 && !strchr(guessed, userLetter))
        {
            printf("The word does contain: %c\n", userLetter);   
            guessed[strlen(guessed)] = userLetter;
            remainingLetters--;
        } else 
        {
            printf("WRONG!\n");
        }
        printf("%c", remainingLetters);

        showCensoredWord(word, wordLength, guessed);
    }

    printf("Congratulations! You guessed the word: %s\n", word);

    return 0;
}

void showCensoredWord(char arr[], int size, char guessed[])
{
    for (int i = 0; i < size; i++) {
        if (strchr(guessed, arr[i]))
        {
            printf("%c", arr[i]);
        } else {
            printf("_");
        }
    }
    printf("\n");
}

int getKeyByValue(char arr[], int size, char value) {  
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}