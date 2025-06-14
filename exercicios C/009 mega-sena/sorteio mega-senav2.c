#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define numerossorteados 6
#define maxnum 60
int main (){
    int numeros[numerossorteados], numeroaleatorio = 0, i = 0, j = 0, aux = 0, rodada = 0; //i, j e aux são necassarios pra vericar se o numero ja foi sorteado e pra ordernar os numeros
    int numerosescolhidos[numerossorteados];
    srand(time(NULL)); //começa o gerador ramdomico
    for (i = 0; i < numerossorteados; i++){ //escolha dos números
        printf ("escolha um numero entre 1 e 60(não repita os mesmo numeros): ");
        scanf("%i", &numerosescolhidos[i]);
    }
    for (i = 0; i < numerossorteados; i++){ //precesso para ordernar os números escolhidos
        for (j = i +1; j < numerossorteados; j++){
            if (numerosescolhidos[i] > numerosescolhidos[j]){
                aux = numerosescolhidos[i];
                numerosescolhidos[i] = numerosescolhidos[j];
                numerosescolhidos[j] = aux;
            }
        }
    }
    do{
        rodada++;
        for (i = 0; i < numerossorteados; i++){
            do {
                numeroaleatorio = 1 + rand() % maxnum; //sorteia um numero aleatorio entre 1 e 60
                for (j = 0; j <i; j++){
                    if (numeros[j] == numeroaleatorio){
                        numeroaleatorio = 0;
                        break;  //testa todos os numeros pra ver se é igual ao sorteado, caso seja o numero sorteado sera trocado para 0 e resorteado
                    }
                }
            } while (numeroaleatorio == 0); //repete o processo enquanto o número ainda for igual
            numeros[i] = numeroaleatorio;
        }
        for (i = 0; i < numerossorteados; i++){ //precesso para ordernar os números sorteados
            for (j = i +1; j < numerossorteados; j++){
                if (numeros[i] > numeros[j]){
                    aux = numeros[i];
                    numeros[i] = numeros[j];
                    numeros[j] = aux;
                }
            }
        }
        printf("rodada N:%i ", rodada);
        for (i = 0; i < numerossorteados; i++) {
            printf("%d ", numeros[i]);
        }
        printf("\n");
        int acerto = 1;
        for (i = 0; i < numerossorteados; i++){
            if (numeros[i] != numerosescolhidos[i]){
                acerto = 0;
                break;
            }
        }
        if (acerto) break;
    }while (rodada < 10000000);
    printf ("PARABENS!!!!!, os numeros foram acertados em %i tentativas\n", rodada);
    return 0;
}