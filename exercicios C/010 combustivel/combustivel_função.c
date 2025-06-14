#include <stdio.h>

void MyEficiencia (float gaso, float eta, float gnv);
void MyFord(float gaso, float eta, float gnv);

int main (){
    float precoGASO, precoETA, precoGNV;
    int escolha;
    printf("qual o preço da gasolina?: ");
    scanf("%f", &precoGASO);
    printf("qual o preço do etanol?: ");
    scanf("%f", &precoETA);
    printf("qual o preço do GNV?: ");
    scanf("%f", &precoGNV);
    MyEficiencia (precoGASO, precoETA, precoGNV); //take the value to the comparative function
    printf("aplicar para a Ford Ranger em especifico?[1 sim, 2 não]: ");
    scanf ("%i", &escolha);
    if (escolha > 2 || escolha < 1){
        do{
            printf("resposta invalida tente novamente: ");
            scanf("%i", &escolha);
            if (escolha == 1 || escolha == 2)
            break;
        }while (1 < 2);
    }
    if (escolha == 1)
    MyFord (precoGASO, precoETA, precoGNV);
}

void MyEficiencia (float gaso, float eta, float gnv){
    float auxeta, auxgnv;
    auxeta = eta / gaso *100;
    auxgnv = gnv / gaso *100; //do the maths
    if (auxeta <= 70 && auxgnv <= 50){
        printf("tanto o etanol quanto o GNV são mais eficientes que a gasolina considerando a regra geral\n");
    }else if (auxeta <= 70){
        printf("apenas o etanol é mais eficiente que a gasolina considerando a regra geral\n");
    }else if (auxgnv <= 50){
        printf("apenas o GNV é mais eficiente que a gasolina considerando a regra geral\n");
    }else 
        printf("a gasolina é o mais eficiente considerando a regra geral\n"); //prints the options that are better then gasoline in these circuntances
}

void MyFord(float gaso, float eta, float gnv){
    float precokmgaso, precokmeta, precokmgnv;
    precokmgaso = gaso / 9;
    precokmeta = eta / 6.5;
    precokmgnv = gnv / 10;// do the math for the specific car
    if (precokmgaso < precokmeta && precokmgaso < precokmgnv){
        printf("gasolina é a melhor opção para esse carro!\n");
    }else if (precokmeta > precokmgnv){
        printf("GNV é a melhor opção para esse carro!\n");
    }else
    printf("etanol é a melhor opção pro carro!\n"); //prints the better option
}