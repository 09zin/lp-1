#include <stdio.h>
int main(){
    float altura = .0, peso = .0, IMC = .0;
    printf("Qual sua altura?: ");
    scanf("%f", &altura);
    printf("Qual seu peso?:");
    scanf("%f", &peso);
    IMC = peso / (altura*altura);
    printf("seu IMC é de %2.2f ", IMC);
    if (IMC < 18.5){
        printf("e seu estado atual é de magreza");
    }else if (IMC >= 18.5 && IMC < 25){
        printf("e seu estado atual é normal");
    }else if (IMC >= 25 && IMC < 30){
        printf("e seu estado atual é de sobrepeso");
    }else if (IMC >= 30 && IMC < 40){
        printf("e seu estado atual é obesidade");
    }else{
        printf("e seu estado atual é obesidade grave");
    }
    return 0;
}