#include<stdio.h>
int main(){
    int cont1=0, cont2=0, cont3=0;
    for (int i = 0; i <= 10000; i++){ //letra A
        printf("%i\n", i);
    }
    for (int i = -10000; i <= 10000; i++){ //Letra B
        printf("%i\n", i);
    }
    for (int i = 0; i <= 10000; i += 2){ //Letra c
        printf("%i\n", i);
    }
    for (int i = 1; i <= 10000; i+= 2){ //letra D
        printf("%i\n", i);
    }
    for (int i = -100000; i <= 100000; i+= 3){ //letra E
        printf("%i\n", i);
    }
    for (int i = 0; i < 10; i++){ //F 1° loop
        cont1 ++; // contador da interações da 1° camdada
        for (int j = 0; j < 10; j++){ //2° loop
            cont2 ++; //contador das interações da 2° camada
            for (int k = 0; k < 10; k++){ //3° loop
                cont3 ++; //contador das interações da 3° camada
                printf("I:%i J:%i K:%i\n", i,j,k);
            }
        }
    }
    printf("interações de I:%i interações de J:%i interações totais:%i", cont1,cont2,cont3);
    return 0;
}