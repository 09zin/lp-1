#include <stdio.h>

int main (){
    float custoKM_GNV, custoKM_ETA, custoKM_GASO, precoGASO = 0, precoe = 0, precoGNV, limitee = 0, limitegnv = 0; 
    int aux = 0;
    printf("qual o valor da gasolina?: ");
    scanf("%f", &precoGASO);
    printf("qual o preço do GNV: ");
    scanf("%f", &precoGNV);
    printf("qual o valor do etanol?: ");
    scanf("%f", &precoe);
    limitee = precoGASO * 0.7f; // compensa se for menor que 70% da gasolina
    limitegnv = precoGASO * 0.6f; // compensa se for menor que 60% da gasolina
    if (precoe <= limitee + 0.0001f && precoGNV <= limitegnv + 0.0001f){
        printf("tando etanol quanto GNV são mais eficientes que a gasolina\n");
    } else if (precoe <= limitee + 0.0001f){
        printf("apenas o etanol é mais eficiente que a gasolina\n");
    } else if (precoGNV <= limitegnv + 0.0001f){
        printf("apenas o GNV é mais eficiente que a gasolina\n");
    } else{
        printf("a gasolina é a melhor opção\n");
    }
    printf ("considerar os preços na eficiencia espeficica da Ford Ranger?[1 sim, 2 nao]: ");
    scanf("%i", &aux);
    if (aux >2 || aux < 1){
        do{
            printf("numero invalido digite novamente: ");
            scanf("%i", &aux);
        }while (aux >2 || aux < 1);
    }
    if (aux == 1){
        custoKM_GNV = precoGNV/10.0f; //pois faz 10km por metro cubico de GNV na estrada
        custoKM_ETA = precoe/5.65f; //pois faz 5,65km por litro na estrada
        custoKM_GASO = precoGASO/8.25f; //pois a ford ranger faz 8.25km por litro na estrada
        if (custoKM_GASO < custoKM_ETA && custoKM_GASO < custoKM_GNV){
            printf("gasolina é a melhor opção para sua Ford Ranger nesse caso\n");
        }else if (custoKM_GNV < custoKM_ETA){
            printf("GNV é a melhor opção para sua Ford Ranger nesse caso\n");
        }else{
            printf("Etanol é a melhor opção para sua Ford Ranger nesse caso\n"); //em caso de empate mostrara o etanol
        }
    }
return 0;
}