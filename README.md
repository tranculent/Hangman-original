# Hangman-original

This is my simple implementation of the hangman game that basically has the basic functionality. 
I have added only 6 attempts. However, feel free to add more or less. If you want to change it 
for whatever reason, this is the code ```#define NUMBER_OF_GUESSES 6``` you should change where 6
represents the amount of attempts allowed. This is on line 6.

The first couple of lines in my code are the libraries I will be using.
```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
```
I use ```time.h``` for my srand call on line 19. ``` srand(time(NULL)); ```. 
I use ``` string.h ``` for string commands such as strlen.

My ```main()``` function basically calls all of my written methods.

My ```void assign_and_print_underscores (char word_being_guessed[])``` method basically loops through
the array given as parameter and populates it with underscores.

My ```void draw_hangman(int i)``` method draws the hangman ASCII depending on the losing points of the
user. DISCLAIMER: I HAVE NOT USED THIS ASCII ART. THE LINK FROM WHERE I GOT IT: https://github.com/CedArctic/hangman

My ```void you_lost()``` method draws the ASCII art for "You lost" text. Pretty straightforward.

My ``` void print_word(char word_being_guessed[], char *original_word)``` method does all the functionality.
It starts with a infinite while loop ```while(1)``` and then only breaks on two conditions: win or lose.
For the first iteration of the loop, we print hangman ascii art, which again is not mine, it is from 
the github I provided upper in the text.

What essentially happens in the loop is, we ask for letter input, check if the original word contains that letter,
if it does then loop through the word and find all the instances of this letter in the word. If it does not find
any instances, simply add 1 to the losing points.

```char ask_for_input()``` asks for the input and returns the character.

```int contains(char c, char array[])``` checks if the letter is in the array provided.

```int is_letter_already_gussed(char c, char array[])``` checks if letter is in the array.

```void print_clue(char *chosenWord)``` prints clue to the correnspoding selected random word.

```char *randomly_generated_word()``` generates a random word from the options given within the method. Feel free to add as many word as you like!
