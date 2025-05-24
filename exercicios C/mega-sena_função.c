#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define numerossorteados 6
#define maxnum 60
void myEscolha (int numerosescolhidos[]){ //função que recebe e valida os números
    int i, j, repetido;
    for (i = 0; i < numerossorteados; i++){
        do{
            repetido = 0;
            printf("escolha um numero de 1 a 60: ");
            scanf("%i", &numerosescolhidos[i]);
            if (numerosescolhidos[i] > 60 || numerosescolhidos[i] < 1){
                do{
                    printf("numero invalido, escolha outro: ");
                    scanf ("%i", &numerosescolhidos[i]);
                }while (numerosescolhidos[i] > 60 || numerosescolhidos[i] < 1);
            }
            for (j = 0; j < i; j++){
                if (numerosescolhidos[j] == numerosescolhidos[i]){
                    printf("numero repetido digite outro\n");
                    repetido = 1;
                    break;
                }
            }
        } while (repetido);
    }
}

void MyOrdem (int sequencia[]){ //função que organiza sequencias (do tamanho da costante)
    int j, i, aux;
    for (i = 0; i < numerossorteados; i++){
        for (j = i +1; j < numerossorteados; j++){
            if (sequencia[i] > sequencia[j]){
                aux = sequencia[i];
                sequencia[i] = sequencia[j];
                sequencia[j] = aux;
            }
        }
    }
}

int mySorteio (int numeros[]){ //função pra sortear os numeros
    int i, j, numeroaleatorio;
    for (i = 0; i < numerossorteados; i++){
        do{
            numeroaleatorio = rand() % maxnum + 1;
            numeros[i] = numeroaleatorio;
            int repetido = 0;
            for (j = 0; j < i; j++){
                if (numeros[j] == numeros[i]){
                    repetido = 1;
                    break;
                }
            }
            if (repetido) {
                numeros[i] = 0;
            }
        }while (numeros[i] == 0);
    }
}

int MyAcerto (int a[], int b[]){ //função pra ver se acertou
    int i;
    for (i = 0; i < numerossorteados; i++){
        if (a[i] != b[i]){
            return 0; //retorna falso se algum for diferente
        }
    }
    return 1; //retorna verdadeiro se todos forem verdade
}

int main (){
    int numeros[numerossorteados], i = 0, rodada = 0, numerosescolhidos[numerossorteados];
    srand(time(NULL)); 

    myEscolha(numerosescolhidos); //escolhe os numeros
    MyOrdem(numerosescolhidos);  //ordena os mesmos

    do{
        rodada++;
        mySorteio(numeros); //sorteia
        MyOrdem(numeros); //ordena
        printf("%i° rodada ", rodada);
        for (i = 0; i < numerossorteados; i++){
            printf("%i ", numeros[i]);
        }
        printf("\n");
    }while (!MyAcerto(numeros, numerosescolhidos));

    printf ("PARABENS!!!!!, os numeros foram acertados em %i tentativas\n", rodada);
return 0;
}