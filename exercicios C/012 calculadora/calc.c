#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define num_max 100

double MyCalc (double a, double b, char op){
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

int MyCorrecaoBug (const char* expressao, int i) {
    int k = i - 1;
    while (k >= 0 && isspace(expressao[k])) k--;  // pula espaços pra trás
    return (k < 0) || (strchr("+-*/", expressao[k]) != NULL);
}

double MyRateExpr (const char* expressao){
    double numeros[num_max];
    char ops[num_max];
    int nume_top = -1, op_top = -1, i = 0;
    while (expressao[i] != '\0'){
        if (isspace(expressao[i])){
            i++;
            continue;
        }
    
    if (expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '/' || expressao[i] == '*'){
        while (op_top >= 0 && ((ops[op_top] == '*' || ops[op_top] == '/') || ((expressao[i] == '+' || expressao[i] == '-') && (ops[op_top] == '+' || ops[op_top] == '-')))){
            double b = numeros[nume_top--];
            double a = numeros[nume_top--];
            char op = ops[op_top--];
            numeros[++nume_top] = MyCalc(a, b, op); 
        }
        ops[++op_top] = expressao[i++];
    }else if (isdigit(expressao[i]) || expressao[i] == '.' ||
        (expressao[i] == '-' && MyCorrecaoBug(expressao, i))){
        char nume_string[num_max];
        int j = 0;
        if (expressao[i] == '-') {
        nume_string[j++] = expressao[i++];
        while (isspace(expressao[i])) i++;
        }
        while (isdigit(expressao[i]) || expressao[i] == '.'){
            nume_string[j++] = expressao[i++];
        }
        nume_string[j] = '\0';
        numeros[++nume_top] = atof(nume_string);
        continue;
    }else{
        printf("caractere invalido na expressão: %c\n", expressao[i]);
        exit(1);
    }
    }
    while (op_top >= 0){
        double b = numeros[nume_top--];
        double a = numeros[nume_top--];
        char op = ops[op_top--];
        numeros[++nume_top] = MyCalc(a, b, op);
    }
    return numeros[nume_top];
}

int main (){ //não funciona
    char calculo[num_max];
    printf("calculadora funcional, operadores: +, -, *, / (sem parenteses)\n");
    printf("digite o calculo a ser resolvido(ex: 5 + 17 - 2 * 4):");
    fgets(calculo, num_max, stdin);
    calculo[strcspn(calculo, "\n")] = '\0';
    double result = MyRateExpr(calculo);
    printf("o resultado e: %.2f\n", result);

    return 0;
}