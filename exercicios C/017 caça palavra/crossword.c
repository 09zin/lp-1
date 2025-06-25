#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define maxletters 10

void MyTip (char answer){
    printf("1° word, want VERY MUCH\n2° word, NOT past\n3° word, the opssite of lowerest\n");
        do{
            printf("continue to the guess?[y/n]:");
            scanf(" %c", &answer);
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }while (answer != 'y' && answer != 'Y');
}

void MyToLower(char user_guess[3][maxletters]) {
    for (int i = 0; i < 3; i++){
        for (int j = 0; user_guess[i][j] != '\0'; j++) {
            user_guess[i][j] = tolower((unsigned char)user_guess[i][j]);
        }
    }
}

void MyInit (char display_word[3][maxletters], char correct[3][maxletters]){
    for (int i = 0; i < 3; i++){
        int len = strlen(correct[i]);
        for (int j = 0; j < len; j++){
            display_word[i][j] = '?';
        }
    display_word[i][len] = '\0';
    }
}

void MyDisplay(int hits, char display_word[3][maxletters]){
    printf("words corrects = %i\n", hits);
    for (int i = 0; i < 3; i++) {
        printf("%i° word: %s\n", i + 1, display_word[i]);
    }
}

void MyWords (char correct[3][maxletters]){
    strcpy(correct[0], "craving");
    strcpy(correct[1], "present");
    strcpy(correct[2], "highest");
}

int MyGuesses (char user_guess[3][maxletters], char correct[3][maxletters], char display_word[3][maxletters]){
    int corrects_words = 0;

    fflush(stdin);
    printf("1° word guess: ");
    fgets (user_guess[0], maxletters, stdin);
    user_guess[0][strcspn(user_guess[0], "\n")] = 0;

    printf("2° word guess: ");
    fgets (user_guess[1], maxletters, stdin);
    user_guess[1][strcspn(user_guess[1], "\n")] = 0;

    printf("3° word guess: ");
    fgets (user_guess[2], maxletters, stdin);
    user_guess[2][strcspn(user_guess[2], "\n")] = 0;
    MyToLower(user_guess);

    for (int j = 0; j < 3; j++){
        for (int i = 0; i < maxletters; i++){
            if (correct[j][i] == '\0')
            break;
            if (correct[j][i] == user_guess[j][i]){
                display_word[j][i] = user_guess[j][i];
            }
        }
        if (strcmp(correct[j], user_guess[j]) == 0)
            corrects_words++;
    }
return corrects_words;
}

int main (){
    //craving, present, highest
    char answer;
    char user_guess[3][maxletters], correct[3][maxletters], display_word[3][maxletters];
    int hits = 0;

    MyWords(correct);
    MyInit(display_word, correct);

    printf("\tCROSSWORD GAME\n\n");
    printf("1° word letters = 7 | 2° = 7 | 3° = 7\n");
    printf("wanna a tip before try a shot?[Y/N]:");
    scanf(" %c", &answer);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (answer == 'Y' || answer == 'y'){
        MyTip(answer);
    }
    system("cls");

    hits = MyGuesses(user_guess, correct, display_word);
    MyDisplay (hits, display_word);

    printf("try again?[y/n]:");
    scanf(" %c", &answer);
    while ((c = getchar()) != '\n' && c != EOF);
    do{
        system("cls");
        MyDisplay (hits, display_word);
        printf("wanna see the tips?[Y/N]:");
        scanf(" %c", &answer);
        if (answer == 'Y' || answer == 'y'){
        MyTip(answer);
        }
        hits = MyGuesses(user_guess, correct, display_word);
        MyDisplay (hits, display_word);
        if (hits == 3){
            printf("Congratulations!!!!\n");
            break;
        }else
        printf("try again?[y/n]:");
        scanf(" %c", &answer);
        while ((c = getchar()) != '\n' && c != EOF);
    }while (answer == 'Y' || answer == 'y');

return 0;
}