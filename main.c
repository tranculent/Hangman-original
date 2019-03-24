#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// #include "randomtopicwords.h"
// #include "askforinput.c"

/*
 * GIVE A RANDOM WORD FROM A HUGE LIST TO GUESS
 * FOR HOWEVER MANY LETTERS THERE ARE IN THE WORD, GIVE THIS MANY UNDERSCORES (______)
 * GIVE OPTION FOR USER INPUT TO GIVEN RANDOM LETTERS FROM THE ALPHABET. ONCE USED A CERTAIN LETTER, CANNOT BE USED AGAIN,
 * IF THE USER HAS GUESSED CORRECTLY AND THERE ARE LETTERS IN THE GIVEN WORD, SHOW ALL OF THE LETTERS THAT ARE IN THE WORD
 * THE PLAYER'S GOT 5 ATTEMPTS TO GUESS THE WORD
*/

void askforinput(char *word);
char *generateStrings();

int main() {
    srand(time(NULL));
    // the randomly selected word
    char *word = generateStrings();

    printf("%s\n", word);
    askforinput(word);

    return 0;
}

void askforinput(char *word) {
    printf("DID IT WORK");
    char chosenLetter;
    char sampleArray[strlen(word)];
    while (1) {
        scanf("%c", &chosenLetter);
        for (int i = 0; i < strlen(word); i++) {
            if (word[i] == chosenLetter) {
                sampleArray[i] = chosenLetter;
                printf("%c ", sampleArray[i]);
            }
            else if (i == 0) {
                printf("_");
            }
            else {
                sampleArray[i] = '_';
                printf(" %c ", sampleArray[i]);
            }
        }
        printf("\n");
    }
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

    char *chosenWord = "az sum gei";

    return chosenWord;
}
