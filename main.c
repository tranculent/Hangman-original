#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

#define NUMBER_OF_GUESSES 6

char ask_for_input();
char *generate_strings();
char *print_word(char sampleArray[], char *word);
int is_letter_already_gussed(char c, char array[]);
int contains(char c, char array[]);
void print_clue(char *chosenWord);
void hangman(int i);
void you_lost();

int main() {
    srand(time(NULL));
    // the randomly selected word
    char *original_word = generate_strings();
    char word_being_guessed[strlen(original_word)+1];
    word_being_guessed[strlen(original_word)] = '\0';
    for (int i = 0; i < strlen(original_word); i++) {
        word_being_guessed[i] = '_';
    }
    printf("%s\n", original_word);
    char *printedWord = print_word(word_being_guessed, original_word);
    return 0;
}

void draw_hangman(int i){			//A function that prints the hanged man ascii art according to how many wrong guesses the user has made.
        switch (i){
        case 0:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| | | / \n| |/ \n| | \n| | | \n| | \n| | \n| | | \n| | \n| | \n| | | \n| | \n|=========|_`-' `-' |===| \n|=|=======\\       '=|=| \n| |        \\        | | \n: :         \\       : : \n. .          `'       . . \n");
            break;
        case 1:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| | | /        ||.-''. \n| |/         |/  _  \\n| |          ||  `/,| \n| |          (\\`_.' \n| | | \n| | \n| | \n| | \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\\       '=|=| \n| |        \\        | | \n: :         \\       : : \n. .          `'       . . \n");
            break;
        case 2:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \\n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |           . .    \n| |          |   |    \n| |          | . |     \n| |          |   |      \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\\       '=|=| \n| |        \\        | | \n: :         \\       : : \n. .          `'       . . \n");
            break;
        case 3:
            printf("___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \\n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . .    \n| |       // |   |    \n| |      //  | . |     \n| |     ')   |   |      \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\\       '=|=| \n| |        \\        | | \n: :         \\       : : \n. .          `'       . . \n");
            break;
        case 4:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \\n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . . Y\\n| |       // |   | \\ \n| |      //  | . |  \\ \n| |     ')   |   |   (` \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\\       '=|=| \n| |        \\        | | \n: :         \\       : : \n. .          `'       . . \n");
            break;
        case 5:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \\n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . . Y\\n| |       // |   | \\ \n| |      //  | . |  \\ \n| |     ')   |   |   (` \n| |          ||    \n| |          ||    \n| |          ||    \n| |          ||    \n| |         / |    \n==========|_`-' `-' |===| \n|=|=======\\       '=|=| \n| |        \\        | | \n: :         \\       : : \n. .          `'       . . \n");
            break;
        case 6:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \\n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . . Y\\n| |       // |   | \\ \n| |      //  | . |  \\ \n| |     ')   |   |   (` \n| |          || || \n| |          || || \n| |          || || \n| |          || || \n| |         / | | \\ \n==========|_`-' `-' |===| \n|=|=======\\       '=|=| \n| |        \\        | | \n: :         \\       : : \n. .          `'       . . \n");
            break;
    }       
}

void you_lost() {
    printf("\n");
    printf("_    _             ___         ___\n");
    printf("\\   //            | |         | |\n");
    printf(" \\_//___    _     | | ___  ___| |_\n");
    printf("  \\/  _ \\ | | || | |/ _ \\ / __| __|\n");
    printf("   || (_) | |_| |  | | (_) \\__ \\ |_\n");
    printf("   |||___/ \\__,_| |_|/___/|___/\\__|\n");
}

char *print_word(char word_being_guessed[], char *original_word) {
    char letter;
    int x = 0;
    int losing_points = 0;
    int lost = 0;
    char already_selected_letters[strlen(original_word) + 6];
    int count = 0;

    while (1) {
        system("@cls||clear"); // clear cmd window every itereation of the loop
        if (x == 0) {
            //Ascii Art
            printf(" _                                             \n");
            printf("| |                                            \n");
            printf("| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
            printf("| '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
            printf("| | | | (_| | | | | (_| | | | | | | (_| | | | | \n");
            printf("|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n");
            printf("                    __/ |                      \n");
            printf("                   |___/  \n");
            print_clue(original_word);
            printf("\n");
        }
        
        if (x == 0) {
            for (int i = 0; i < strlen(original_word); i++) {
                printf("*");
            }
        }

        printf("\n");
        
        // --- WINNING CONDITION ---
        if (contains('_', word_being_guessed) == 0) {
            printf("Congratulations! You've got the word right!\n");    
            break;
        }

        if (x == 0) 
            for (int i = 0; i < strlen(original_word); i++) 
                printf("_");
        
        if (x > 0) { 
            draw_hangman(losing_points);
            printf("Current stage of word: %s", word_being_guessed);
        }

        printf("\n");
        printf("Give me a letter: ");
        letter = ask_for_input();
        printf("\n");

        if (losing_points >= NUMBER_OF_GUESSES)  {
            printf("You are out of guesses, sorry!");
            you_lost();
            break;
        }

        if (is_letter_already_gussed(letter, already_selected_letters) == 1) {
            printf("You already guessed that letter!");
            continue;
        }
        already_selected_letters[count] = letter;
        count++;
        // if the word[j] is the letter and word[j] is present in the already_selected_letters[] string array
        if (contains(letter, original_word) == 1) {
            for (int i = 0; i < strlen(original_word); i++) { 
                if (letter == original_word[i]) {
                    word_being_guessed[i] = letter; 
                }
            }
        } else {
            losing_points++;
        }

        x++;
    }   
     printf("\n");
     return word_being_guessed;
}


// ask user for character input
char ask_for_input() {
    char chosenLetter;
    scanf("%c", &chosenLetter);
    return chosenLetter;
}

int contains(char c, char array[]) {
   for (int i = 0; i < strlen(array); i++) 
       if (array[i] == c) // if a letter is in array return 1
           return 1;

   return 0;
}

int is_letter_already_gussed(char c, char array[]) {
    if (contains(c, array) == 1){ 
        return 1;
    }
    return 0;
}

void print_clue(char *chosenWord) {
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
}

char *generate_strings() {
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
    
    return chosenWord;
}

