#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define num_max 100

double MyCalc (double a, double b, char op){ //makes the calcs 2 by 2 numbers and retuns error if / 0
    switch (op){
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            if (b == 0){
                printf("ivalido divisão por 0\n");
                exit(1);
            }
            return a / b;
        break;
        default:
            printf("operador invalido %c\n", op);
            exit(1);
    }
}

int MyCorrecaoBug (const char* expressao, int i) { //detect if theres nothing or other operator before a "-" so the code considers it as a negative number
    int k = i - 1;
    while (k >= 0 && isspace(expressao[k])) k--; 
    return (k < 0) || (strchr("+-*/", expressao[k]) != NULL);
}

double MyRateExpr (const char* expressao){
    double numeros[num_max];
    char ops[num_max];
    int nume_top = -1, op_top = -1, i = 0; //declares the arrays for the numbers, operators, and piles of they
    while (expressao[i] != '\0'){ //skips the " "
        if (isspace(expressao[i])){
            i++;
            continue;
        }
    
    if (isdigit(expressao[i]) || expressao[i] == '.' ||
        (expressao[i] == '-' && MyCorrecaoBug(expressao, i))){
        char nume_string[num_max]; //if the current position is a number a "." or a "-" of a negative number
        int j = 0;
        if (expressao[i] == '-') {
        nume_string[j++] = expressao[i++];
        while (isspace(expressao[i])) i++;
        }
        while (isdigit(expressao[i]) || expressao[i] == '.'){
            nume_string[j++] = expressao[i++];
        } //create a string to store the current number read while is number or . and adds \0 at the and
        nume_string[j] = '\0';
        numeros[++nume_top] = atof(nume_string); //uses atof to transfor the current string into a number, and puts it in the position 0 if is empty or 1 of the pile
        continue;
    }else if (expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '/' || expressao[i] == '*'){
        // if its a operator
        while (op_top >= 0 && ((ops[op_top] == '*' || ops[op_top] == '/') || ((expressao[i] == '+' || expressao[i] == '-') && (ops[op_top] == '+' || ops[op_top] == '-')))){
         //its checks the precedence order, if theres something on the operator pile thats "*" or "/", or theres "+" or "-" but the current is + or - too, uses the operator on the pile
            double b = numeros[nume_top--];
            double a = numeros[nume_top--]; //variables a and b receives the numbers 0 and 1 of the pile
            char op = ops[op_top--]; //receive the operator on the pile and turns back into 0 (-1)
            numeros[++nume_top] = MyCalc(a, b, op);  //calcs and puts at position 0 on numbers pile
        }
        ops[++op_top] = expressao[i++]; //and put the current operator on pile
    }else{
        printf("caractere invalido na expressão: %c\n", expressao[i]);
        exit(1);
    }
    }
    while (op_top >= 0){ //do the same if there are no more predecence order
        double b = numeros[nume_top--];
        double a = numeros[nume_top--];
        char op = ops[op_top--];
        numeros[++nume_top] = MyCalc(a, b, op);
    }
    return numeros[nume_top];
}

int main (int argc, char *argv[]){
    if (argc != 2){
        printf("Uso correto: %s \"expressão\"\n", argv[0]);
        printf("Exemplo: %s \"5 + 3 * 2 - 4\"\n", argv[0]);
        return 1;
    }
    const char *expressao = argv[1];
    double result = MyRateExpr(expressao);
    printf("o resultado e: %.2f\n", result); //shows the result

    return 0;
}