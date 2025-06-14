#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max_string 100 //max size of string

int main (){
    char name[max_string];
    int size, space = 0;
    printf("what's your name?: ");
    fgets(name, max_string, stdin); //read the name and already adds the /0  on the and
    printf("hi %s", name); //output the normal name
    size = strlen(name) - 1; 
    for (int i = 0; i < size; i ++){
        if (isspace(name[i]))
        space++;
    }
    size -=space; //calcs the numbers of letters already subtarcting the "\0" and the spaces
    printf ("your name has %i letters\n", size); //output the number of letters
    printf("name word by word: ");
    for (int i = 0; i < strlen(name) ; i++){
        if(isspace(name[i])){ 
            printf("\n");
            continue;
        }
        printf("%c", name[i]); //print the name letter by letter and if spaces break the line
    }
    printf ("reverse name: ");
    for (int i = strlen(name); i > -1; i--){
        printf("%c", name[i]); //travels the string printing the letters back to front till "0" thats the first letter
    }
    printf ("\n"); 
    printf("character by character: ");
    for (int i = 0; i < strlen(name); i++){
        if (isspace(name[i]))
            continue;
        printf("%c\n", name[i]); //print 1 letter by line if its space doesn't print anything
    }
return 0;
}