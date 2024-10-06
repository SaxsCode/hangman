#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_ERRORS 9
#define MAX_WORDS 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    char guessed[MAX_WORD_LENGTH];
    int wordLength;
    int errors;
} GameState;

typedef struct {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int wordCount;
} WordsList;

bool loadWords(WordsList *wordsList, const char *filename);
void initializeGame(GameState *game, const WordsList *wordsList);
bool makeGuess(GameState *game, char letter);
void displayGame(const GameState *game);
void displayEndScreen(const GameState *game, bool won);
void clearInputBuffer(void);
int getUnguessedCount(const GameState *game);
bool playAgainPrompt(void);

int main() {
    WordsList wordsList;
    GameState game;
    char userLetter;
    bool playAgain = true;

    // Load words from file
    if (!loadWords(&wordsList, "textfiles/words.txt")) {
        printf("Error loading words file. Make sure 'words.txt' exists in the same directory.\n");
        return 1;
    }
    
    srand(time(NULL));

    while (playAgain)
    {
        initializeGame(&game, &wordsList);
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

        playAgain = playAgainPrompt();
        if (playAgain) {
            printf("\n=== Starting New Game ===\n\n");
        }
    }
    
    printf("Thanks for playing! Goodbye!\n");
    return 0;
}

bool playAgainPrompt(void) {
    char response;
    bool validResponse = false;
    bool playAgain = false;
    
    while (!validResponse) {
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &response);
        clearInputBuffer();
        
        if (response == 'y' || response == 'Y') {
            validResponse = true;
            playAgain = true;
        } else if (response == 'n' || response == 'N') {
            validResponse = true;
            playAgain = false;
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }
    
    return playAgain;
}

bool loadWords(WordsList *wordsList, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return false;
    }

    wordsList->wordCount = 0;
    while (fgets(wordsList->words[wordsList->wordCount], MAX_WORD_LENGTH, file) != NULL) {
        // Remove newline character if present
        size_t len = strlen(wordsList->words[wordsList->wordCount]);
        if (len > 0 && wordsList->words[wordsList->wordCount][len-1] == '\n') {
            wordsList->words[wordsList->wordCount][len-1] = '\0';
        }
        
        wordsList->wordCount++;
        if (wordsList->wordCount >= MAX_WORDS) {
            break;
        }
    }

    fclose(file);
    return wordsList->wordCount > 0;
}

void initializeGame(GameState *game, const WordsList *wordsList) {
    int randomKey = rand() % wordsList->wordCount;
    strcpy(game->word, wordsList->words[randomKey]);
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