#include <stdio.h>

int main()
{
    printf("\tos operadores fundamentais da linguagem C são:\n +, -, *, /, %%\n");
    printf("exemplos de operações com esses operadores são%i", 100 * 50);
    printf("\n%i\n",100/50);
    printf("%i\n", 100+50);
    printf("%i\n", 100-50);
    printf("%i\n", 100%12);
    printf("\tNa linguagem C a ordem de precedência das dos operadores fundamentais é a seguinte\n 1° ()\n 2°%%\n 3°/ e *\n 4°+ ou -\n");
    printf("Alguns exemplos práticos são:\n %i",10+20/2);
    printf(" e %i \nque são a mesma expressão mudando apenas o ()", (10+20)/2);
    printf("\nOutros exemplos dessa vez usando - e * sao:\n %i", 30-5*4);
    printf(" e %i \nque também são a mesma expressão com e sem ()", (30-5)*4);
    printf("\nPor fim temos exemplos com / e %%:\n %i", 10%8/2);
    printf(" e %i \ntambém são a mesma expressão com e sem ()",10%(8/2));
    return 0;
}