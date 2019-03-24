#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
/*
 * GIVE A RANDOM WORD FROM A HUGE LIST TO GUESS
 * FOR HOWEVER MANY LETTERS THERE ARE IN THE WORD, GIVE THIS MANY UNDERSCORES (______)
 * GIVE OPTION FOR USER INPUT TO GIVEN RANDOM LETTERS FROM THE ALPHABET. ONCE USED A CERTAIN LETTER, CANNOT BE USED AGAIN,
 * IF THE USER HAS GUESSED CORRECTLY AND THERE ARE LETTERS IN THE GIVEN WORD, SHOW ALL OF THE LETTERS THAT ARE IN THE WORD
 * THE PLAYER'S GOT 5 ATTEMPTS TO GUESS THE WORD
*/

/*
two problems: 
1. if i keep selecting an already selected letter, it increments to winningspree
2. losing condition doesn't work 
*/

char askforinput();
char *generateStrings();
char *printWord(char sampleArray[], char *word);
int isinarray(int value, char array[]);

int main() {
    srand(time(NULL));
    // the randomly selected word
    char *word = generateStrings();
    char sampleArray[strlen(word)+1];
    sampleArray[strlen(word)] = '\0';
    for (int i = 0; i < strlen(word); i++) {
        sampleArray[i] = '_';
    }
    printf("%s\n", word);
    char *printedWord = printWord(sampleArray, word);
    return 0;
}

char *printWord(char sampleArray[], char *word) {
    char letter;
    int stopLoop=0;
    int x = 0;
    int winningSpree = 0;
    int lost = 0;
    int maxnumberofinputs = strlen(word) + 6;
    char selected[maxnumberofinputs];
    int count = 0;

    while (1) {
        
        system("@cls||clear"); // clear cmd window every itereation of the loop
        printf("%s\n", word);
        
        if (winningSpree==strlen(word)) {
            printf("Congratulations! You've won!\n");
            printf("%s", sampleArray);
            break;
        }
        if (lost == 6) {
            printf("You lost!\n");
            printf("The word was: ", word, "\n");
            break;
        }
        if (x == 0) 
            for (int i = 0; i < strlen(word); i++) 
                printf("_");
        
        if (x > 0) 
            printf("Current stage of word: %s", sampleArray);

        printf("\n");
        printf("Give me a letter: ");
        letter = askforinput();
        printf("\n");

        if (count < maxnumberofinputs) {
            for (int j = 0; j < strlen(word); j++) {
                if (word[j] == letter && isinarray(word[j], selected) == 1) {
                    sampleArray[j] = letter;
                    selected[count] = letter;
                    count++;
                    winningSpree++;
                } else {
                    lost ++;
                }
            }
        }
        
        x++;
    }
    printf("\n");
    return sampleArray;
}

// ask user for character input
char askforinput() {
    char chosenLetter;
    scanf("%c", &chosenLetter);
    return chosenLetter;
}

int isinarray(int value, char array[]) {
    for (int i = 0; i < strlen(array); i++) 
        if (value == array[i]) 
            return 0;
    return 1;
}

char *generateStrings() {
    char *arrayOfWords[20];
    arrayOfWords[0] = "string";
    arrayOfWords[1] = "lettuce";
    arrayOfWords[2] = "telephone";
    arrayOfWords[3] = "photograph";
    arrayOfWords[4] = "microphone";
    arrayOfWords[5] = "lolipop";
    arrayOfWords[6] = "magician";
    arrayOfWords[7] = "farewell";
    arrayOfWords[8] = "manhunt";
    arrayOfWords[9] = "feather";
    arrayOfWords[10] = "significant";
    arrayOfWords[11] = "fahrenheit";
    arrayOfWords[12] = "temperature";
    arrayOfWords[13] = "physics";
    arrayOfWords[14] = "missile";
    arrayOfWords[15] = "sinister";
    arrayOfWords[16] = "matrices";
    arrayOfWords[17] = "folder";
    arrayOfWords[18] = "table";
    arrayOfWords[19] = "motorcycle";

    char *chosenWord = arrayOfWords[rand() % 20];
    int ret = strcmp(chosenWord, arrayOfWords[0]);

    if (strcmp(chosenWord, arrayOfWords[0]) == 0) {
        printf("The word is related to a data structure in C.");
    } else if (strcmp(chosenWord, arrayOfWords[1]) == 0) {
        printf("A type of salad.\n");
    } else if (strcmp(chosenWord, arrayOfWords[2]) == 0) {
        printf("A device that you talk on.\n");
    } else if (strcmp(chosenWord, arrayOfWords[3]) == 0) {
        printf("You take this when you use your camera.\n");
    } else if (strcmp(chosenWord, arrayOfWords[4]) == 0) {
        printf("You talk on this device.\n");
    } else if (strcmp(chosenWord, arrayOfWords[5]) == 0) {
        printf("You swallow while eating that.\n");
    } else if (strcmp(chosenWord, arrayOfWords[6]) == 0) {
        printf("He does tricks.\n");
    } else if (strcmp(chosenWord, arrayOfWords[7]) == 0) {
        printf("Harder to say than goodbye.\n");
    } else if (strcmp(chosenWord, arrayOfWords[8]) == 0) {
        printf("Prison break season 2.\n");
    } else if (strcmp(chosenWord, arrayOfWords[9]) == 0) {
        printf("The fur on a bird.\n");
    } else if (strcmp(chosenWord, arrayOfWords[10]) == 0) {
        printf("Better than good adjective.\n");
    } else if (strcmp(chosenWord, arrayOfWords[11]) == 0) {
        printf("Celsius.\n");
    } else if (strcmp(chosenWord, arrayOfWords[12]) == 0) {
        printf("Celsius or Fahrenheit.\n");
    } else if (strcmp(chosenWord, arrayOfWords[13]) == 0) {
        printf("Maths is the supplement science for this.\n");
    } else if (strcmp(chosenWord, arrayOfWords[14]) == 0) {
        printf("You fire this from a rocket.\n");
    } else if (strcmp(chosenWord, arrayOfWords[15]) == 0) {
        printf("There is a movie with this name that starts with S and is a horror.\n");
    } else if (strcmp(chosenWord, arrayOfWords[16]) == 0) {
        printf("The plural of matrix.\n");
    } else if (strcmp(chosenWord, arrayOfWords[17]) == 0) {
        printf("Files are in this.\n");
    } else if (strcmp(chosenWord, arrayOfWords[18]) == 0) {
        printf("You eat on this while sitting around it.\n");
    } else if (strcmp(chosenWord, arrayOfWords[19]) == 0) {
        printf("A very dangerous vehicle.\n");
    }
    return chosenWord;
}

