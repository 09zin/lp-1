#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define max 100 //maximun size of string

void MyUpperLowerCase (char name[], int size){
    int upper = 0, lower = 0;
    for (int i = 0; i < size; i++){
        if (name[i] == '\0' ||name[i] == '\n') //stores the numbers of upper and lower case letters
            continue;
        if (isupper(name[i]))
            upper++;
        if (islower(name[i]))
            lower++;
    }
    printf("you write %i uppercase letters and %i lowercase letters\n", upper, lower);

}

void MyNumber (char number[], int size){
    char realnumber[size];
    float numberb;
    int j = 0;
    for (int i = 0; i < size; i++){
        if (number[i] == ' ')
        continue;
        while (isdigit(number[i]) || number[i] == '-' || number[i] == '.'){
        realnumber[j++] = number[i++];
        realnumber[j] = '\0'; //reads the num,bers and adds \0 at the end
        }
    }
    numberb = atof(realnumber) / 2; //just for demonstration
    printf ("your favorite number / 2 is: %.2f\n", numberb); //shows the number
}

void MyFullName (char name1[],char name2[]){
    name1[strcspn(name1, "\n")] = ' '; //space so the name will not appear together
    name2[strcspn(name2, "\n")] = 0;
    strcat(name1, name2);
    int i = 0;
    printf("your name is: ");
    while (name1[i] != '\0'){
    printf("%c", name1[i++]);
    }
    printf("\nand has %i letters\n", strlen(name1)-1); //prints the name
}

int main(){
    char name1[max], name2[max], number[max];
    printf("whats your 1° name?: ");
    fgets(name1, max, stdin);
    fflush(stdin);
    printf("whats your surname?: ");
    fgets(name2, max, stdin);
    fflush(stdin);
    printf("whats your favorite number?: ");
    fgets(number, max, stdin);
    fflush(stdin); //read everything

    MyFullName(name1, name2); //calls the fucction with the name and surname as arguments
    MyUpperLowerCase(name1, strlen(name1)); //calls with the name added of the surname anf the total lentgh
    MyNumber(number, strlen(number)); //calls with the number and its size
return 0;
}