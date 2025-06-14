#include <stdio.h>

int main (){
    float precoGASO = 0, precoe = 0, precognv, limitee = 0, limitegnv = 0; 
    printf("qual o valor da gasolina?: ");
    scanf("%f", &precoGASO);
    printf("qual o preço do GNV: ");
    scanf("%f", &precognv);
    printf("qual o valor do etanol?: ");
    scanf("%f", &precoe);
    limitee = precoGASO * 0.7f; // compensa se for menor que 70% da gasolina
    limitegnv = precoGASO * 0.6f; // compensa se for menor que 60% da gasolina
    if (precoe <= limitee + 0.0001f && precognv <= limitegnv + 0.0001f){
        printf("tando etanol quanto GNV são mais eficientes que a gasolina\n");
    } else if (precoe <= limitee + 0.0001f){ //para evitar erros com a precisão de float
        printf("apenas o etanol é mais eficiente que a gasolina\n");
    } else if (precognv <= limitegnv + 0.0001f){
        printf("apenas o GNV é mais eficiente que a gasolina\n");
    } else{
        printf("a gasolina é a melhor opção\n");
    }
return 0;
}