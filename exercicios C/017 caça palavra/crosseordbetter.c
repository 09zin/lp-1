#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define maxletters 11 //max of letters that a word can have (+2 because of \0 and \n)
#define number_words 7 //number of words

void MyTip (char answer){ //function thats shows the tips for the player
    printf("1° word, want VERY MUCH\n2° word, NOT past\n3° word, the opssite of lowerest\n");
    printf("4° word, classsic music instrument\n 5° word, its a very pretty view\n");
    printf("6° word, every good history has\n 7° word, you can see yourself on it\n");
        do{
            printf("continue to the guess?[y/n]:");
            scanf(" %c", &answer);
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }while (answer != 'y' && answer != 'Y');
}

void MyToLower(char user_guess[number_words][maxletters]) { //puts all in lower case avoiding problems to comparate the words
    for (int i = 0; i < number_words; i++){
        for (int j = 0; user_guess[i][j] != '\0'; j++) {
            user_guess[i][j] = tolower((unsigned char)user_guess[i][j]);
        }
    }
}

void MyInit (char display_word[number_words][maxletters], char correct[number_words][maxletters]){
//puts "?" on all letters of the words that will apear in the screen (the right letters will overwrite it)
    for (int i = 0; i < number_words; i++){
        int len = strlen(correct[i]);
        for (int j = 0; j < len; j++){
            display_word[i][j] = '?';
        }
    display_word[i][len] = '\0';
    }
}

void MyDisplay(int hits, char display_word[number_words][maxletters]){
//shows the number of corrects words and the letters that are correct
    printf("corrects words = %i\n", hits);
    for (int i = 0; i < number_words; i++) {
        printf("%i° word: %s\n", i + 1, display_word[i]);
    }
}

void MyWords (char correct[number_words][maxletters]){
//copy every word to a string
    strcpy(correct[0], "craving");
    strcpy(correct[1], "present");
    strcpy(correct[2], "highest");
    strcpy(correct[3], "piano");
    strcpy(correct[4], "sunset");
    strcpy(correct[5], "adventure");
    strcpy(correct[6], "mirror");
}

int MyGuesses (char user_guess[number_words][maxletters], char correct[number_words][maxletters], char display_word[number_words][maxletters]){

    int corrects_words = 0;
    fflush(stdin);
    for (int i = 0; i < number_words; i++){
    printf("%i° word guess: ", i + 1); //read all the guesses of the player 
    fgets (user_guess[i], maxletters, stdin);
    user_guess[i][strcspn(user_guess[i], "\n")] = 0; //remove the "\n" of the string to avoid problens
    }
    MyToLower(user_guess); //uses the fuction to put all in lower case

    for (int j = 0; j < number_words; j++){ 
        int correct_word = 1;
        for (int i = 0; correct[j][i] != '\0'; i++){ //runs until the word over
            if (correct[j][i] == user_guess[j][i]){ //compares the words written by the player and the correct words
                display_word[j][i] = user_guess[j][i]; //if the the letter is correct then overwrite the display letter
            }else{
                correct_word = 0; //if the word isn't the same then correct word is false
            }
        }
        if (correct_word)
            corrects_words++; //add the number of correct hits
    }
return corrects_words;
}

int main (){
    char answer;
    char user_guess[number_words][maxletters], correct[number_words][maxletters], display_word[number_words][maxletters];
    int hits = 0;

    MyWords(correct); //int every correct word
    MyInit(display_word, correct); //puts "?" in all

    printf("\tCROSSWORD GAME\n\n");
    for (int i = 0; i < number_words; i++){
        printf("number of letters %i° word:%i\n", i+1, strlen(correct[i]));
    } //starts the game by saying the number of letters of each word
    printf("wanna a tip before try a shot?[Y/N]:");
    scanf(" %c", &answer); //asks if the player wants the tips

    int c;
    while ((c = getchar()) != '\n' && c != EOF); //clears the input (better then fflush by my research)

    if (answer == 'Y' || answer == 'y'){
        MyTip(answer); //shows the tips
    }
    system("cls"); //clear the screen

    hits = MyGuesses(user_guess, correct, display_word);
    MyDisplay (hits, display_word); //1° interaction of the game

    if (hits == number_words) {
        printf("Congratulations!!!! you won\n");
        return 0; //if all words are right ends the program
    }

    printf("try again?[y/n]:");
    scanf(" %c", &answer); //ask if the player wants to try again
    while ((c = getchar()) != '\n' && c != EOF); //clears the input
    if (answer == 'n' || answer == 'N')
        return 0; //ends the program if the user doenst wanna try again
    do{
        system("cls"); //clear the screen
        MyDisplay (hits, display_word); //shows the words/letters that the player already hit
        printf("wanna see the tips?[Y/N]:");
        scanf(" %c", &answer); //ask tips
        if (answer == 'Y' || answer == 'y'){
        MyTip(answer); //tips
        }
        hits = MyGuesses(user_guess, correct, display_word);
        MyDisplay (hits, display_word); //do the others interactions of the program
        if (hits == number_words){
            printf("Congratulations!!!! you won\n");
            return 0; //ends when all right
        }
        printf("try again?[y/n]:");
        scanf(" %c", &answer);
        while ((c = getchar()) != '\n' && c != EOF);
        if (answer == 'N' || answer == 'n')
            return 0; //ends if dont wanna try again
    }while (answer == 'Y' || answer == 'y');

return 0;
}