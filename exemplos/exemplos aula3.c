#include <stdio.h>
int main(){
    int var1 = 0, var2 = 0, resp = 0;
    var1 = 0;
    printf("variavel inteiro: %i\n", var1);
    var1 = 100;
    printf("variavel inteiro: %i\n", var1);
    var1 = 100 + 200;
    printf("variavel inteiro: %i\n", var1);
    var1= 100;
    var1+= 200;
    printf("variavel inteiro: %i\n", var1);
    var1 = 100;
    var1 ++;
    printf("variavel inteiro: %i\n", var1);
    //o mesmo vale para "--"//
    var1 = 100;
    printf("variavel inteiro: %i\n", var1++);
    printf("variavel inteiro: %i\n", var1);
    var1 = 100;
    printf("variavel inteiro: %i\n", ++var1);
    //com o ++ na frente a variavel ja aparece alterada//
    var1 = 100;
    var1++;
    printf("variavel inteiro %li bytes\n", sizeof(var1));
    var1 = 100;
    var2 = 200;
    var1 = var1 + var2;
    printf("variavel inteiro: %i\n", var1);
    var1 = 100;
    var2 = 200;
    resp = var1+var2;
    printf("variavel inteiro: %i\n", resp);
    return 0;
}