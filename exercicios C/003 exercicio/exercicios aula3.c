/*os operadores primitivos da linguagem C são 5, char, int, float, double e void que correspondem respctivamente a caractere, inteiro, ponto flutuante, ponto flutuante de precisão dupla e sem valor, os outros tipos de variaveis são baseados neles*/
#include <stdio.h> 
int main (){
    char nome; int var1, var2, var3, resp; float deci; double deci2;
    nome = ('A');
    printf("%c\n", nome); // char pode receber uma letra ou frase (sequencia de caracteres)
    printf("char possui %i bytes\n", sizeof nome); // pode possuir mais bytes conforme o número de caracteres
    var1 = 100;
    printf("%i\n", var1); // int recebe um valor inteiro
    printf("int possui %i bytes\n", sizeof var1);
    deci = 10.5;
    printf("%f\n", deci); // float recebe um número com casas decimais
    printf("float possui %i bytes\n",sizeof deci);
    /*pelo oque pesquisei ambos ocupam 4 bytes pois na maioria das arquituras dos compiladores modernos eles ocupam 4 bytes e a diferença é a forma na qual eles ficam armazenados na memoria da maquina*/
    deci2 = 200.39;
    printf("%f\n", deci2); //double também exibe um número decimal porém com uma precisão muito maior
    printf("duble possui %i bytes\n", sizeof deci2);
    /*sobre o tipo void, não é possivel declarar uma variavel void, void é usado para funções sem retorno como o hello world comun e nos parametros de funções que não recebe, argumoentos, agora farei as operações usando variaveis*/
    var1= 30; var2= 6;
    resp = (var1 + var2) / var2;
    printf ("%i\n", resp); // + e / com ()
    resp = var1 + var2 / var2;
    printf ("%i\n", resp); // + e / sem ()
    var1=30; var2=5; var3=4;
    resp = (var1 - var2) * var3;
    printf("%i\n", resp); // - e * com ()
    resp = var1 - var2 * var3;
    printf("%i\n", resp); // - e * sem ()
    var1=10; var2=8; var3=2;
    resp = var1 % (var2/var3); // % e / com ()
    printf ("%i\n", resp);
    resp = var1 % var2/var3; // % e / sem ()
    printf ("%i\n", resp);
    return 0;
}