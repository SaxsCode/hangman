#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_ERRORS 9
#define MAX_WORDS 4

typedef struct {
    char word[MAX_WORD_LENGTH];
    char guessed[MAX_WORD_LENGTH];
    int wordLength;
    int errors;
} GameState;

void initializeGame(GameState *game, const char words[][MAX_WORD_LENGTH]);
bool makeGuess(GameState *game, char letter);
void displayGame(const GameState *game);
void displayEndScreen(const GameState *game, bool won);
void clearInputBuffer(void);
int getUnguessedCount(const GameState *game);

int main() {
    const char words[][MAX_WORD_LENGTH] = {"boomhut", "apenstaart", "flapdrol", "hangman"};
    GameState game;
    char userLetter;
    
    srand(time(NULL));
    initializeGame(&game, words);
    displayGame(&game);

    while (getUnguessedCount(&game) > 0 && game.errors < MAX_ERRORS) {
        printf("Guess a letter: ");
        scanf(" %c", &userLetter);
        
        if (!makeGuess(&game, userLetter)) {
            game.errors++;
            printf("WRONG! Errors: %d/%d\n", game.errors, MAX_ERRORS);
        }
        
        displayGame(&game);
    }

    bool won = (getUnguessedCount(&game) == 0);
    displayEndScreen(&game, won);

    return 0;
}

void initializeGame(GameState *game, const char words[][MAX_WORD_LENGTH]) {
    int randomKey = rand() % MAX_WORDS;
    strcpy(game->word, words[randomKey]);
    game->wordLength = strlen(game->word);
    memset(game->guessed, 0, MAX_WORD_LENGTH);
    game->errors = 0;
}

bool makeGuess(GameState *game, char letter) {
    bool letterFound = false;
    for (int i = 0; i < game->wordLength; i++) {
        if (game->word[i] == letter) {
            letterFound = true;
        }
    }

    if (letterFound && !strchr(game->guessed, letter)) {
        game->guessed[strlen(game->guessed)] = letter;
        printf("The word does contain: %c\n", letter);
        return true;
    }
    return false;
}

void displayGame(const GameState *game) {
    for (int i = 0; i < game->wordLength; i++) {
        if (strchr(game->guessed, game->word[i])) {
            printf("%c", game->word[i]);
        } else {
            printf("_");
        }
    }
    printf("\n");
}

void displayEndScreen(const GameState *game, bool won) {
    if (won) {
        printf("Congratulations! You guessed the word: %s\n", game->word);
    } else {
        printf("Oof! You failed! The word was: %s\n", game->word);
    }
    
    printf("Press Enter to end the program...");
    clearInputBuffer();
    getchar();
}

void clearInputBuffer(void) {
    while (getchar() != '\n');
}

int getUnguessedCount(const GameState *game) {
    int count = 0;
    for (int i = 0; i < game->wordLength; i++) {
        if (!strchr(game->guessed, game->word[i])) {
            count++;
        }
    }
    return count;
}