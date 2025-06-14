#include <stdio.h>

int main(){
    int array0 [5][5];
    int array1 [5][5][5];
    int array2 [5][5][5][5];
    int array3 [5][5][5][5][5]; // declaração dos arrays de diferentes dimensões 
    printf("tamanho do array 1:%i\n", sizeof(array0));
    printf("tamanho do array 2:%i\n", sizeof(array1));
    printf("tamanho do array 3:%i\n", sizeof(array2));
    printf("tamanho do array 4:%i\n", sizeof(array3)); // sizeof de cada array

    int testearray2d [1000][500]; //dps do 1000 x 500 eu comecei a ter problemas para rodar o codigo mas pesquisando vi que o limite seria 1000 x 1000 sem usar heap
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j <500; j++){
            testearray2d[i][j] = i+j;
            printf("%i ", testearray2d[i][j]); 
        }
    }

    int testearray3d [80][80][80];/*foi o tamanho maximo que consegui chegar (não nesse codigo pois há um vetor enorme nesse codigo, mas sim no auxiliar desse codigo que também foi enviado para demonstração) após 80x80x80 o terminal não deu mais resposta*/
    for (int i  = 0; i < 80; i++){
        for (int j = 0; j <80; j++){
            for (int o = 0; o < 80; o++){
                testearray3d[i][j][o] = i+j+o;
                printf("%i ", testearray3d[i][j][o]);
            }
        }
    }
    
return 0;
} /*podemos percerber que o array tem o tamanho do seu tipo de variavel multiplicado por cada indice, logo como é "int" que possui 4 bytes, temos 4x5x5  e dps 4x5x5x5 e assim por diante*/