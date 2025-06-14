#include <stdio.h>
#include <math.h>
int main(){

    int rodadas = 0, numb = 0, blocos =0, b1 = 2, b2 =3, b3= 2, b4= 3, b5=2, b6 = 3, b7 = 2, b8 = 3, b9 = 2, b10 = 3, b11 = 2, b12 = 3, b13 = 2, auxb2= 1, auxb3= 3, auxb4 = 7, auxb5= 15, auxb6= 31, auxb7 = 63, auxb8 = 127, auxb9 = 255, auxb10 = 511, auxb11 = 1023, auxb12 = 2047, auxb13 = 4095;

    printf("quantos blocos?[3,4,5,6,7,8,9,10,11,12,13]:");
    scanf("%i", &blocos);
    blocos = pow(2,blocos)-1; //calc to discover how manys round will have based on the number of blocks
    for(numb; numb <blocos; numb++){
        rodadas = numb +1;
        printf("rodada %i -> ", rodadas);
        if (numb %2 == 0){ //if its a pair round is the 1° block that moves always to 1 position more 
            printf ("bloco 1 torre: %i\n", b1);
            b1++;
            if (b1 == 4){
                b1 = 1;
            }
        }
        if (numb - auxb2 == 0){ //from this point on the block that moves is picked using auxs thats grows based on the potency of 2 of the block, blocks pair goes always for less 1 position and unpair always for a 1 more position
            printf("bloco 2 torre: %i\n",b2);
            b2--;
            auxb2 += 4;
            if (b2 == 0){
                b2 = 3; }
        }
        if (numb - auxb3 == 0){
            printf("bloco 3 torre: %i\n",b3);
            b3++;
            if (b3 == 4){
                b3 = 1;
            }
            auxb3 +=8;
        } 
        if (numb - auxb4 ==0){
            printf("bloco 4 torre: %i\n",b4);
            b4--;
            auxb4 += 16;
            if (b4 == 0){
                b4 = 3; }
        }
        if (numb - auxb5 ==0){
            printf("bloco 5 torre: %i\n", b5);
            b5 ++;
            auxb5 += 32;
            if (b5 == 4){
                b5 = 1;
            }
        } if (numb - auxb6 == 0){
            printf("bloco 6 torre: %i\n", b6);
            b6--;
            auxb6 += 64;
            if (b6 == 0){
                b6 = 3; }
        } if (numb - auxb7 == 0){
            printf("bloco 7 torre: %i\n", b7);
            b7++;
            auxb7 += 128;
            if (b7 == 4){
                b7 = 1;
            }
        } if (numb - auxb8 == 0){
            printf("bloco 8 torre: %i\n", b8);
            b8--;
            auxb8 += 256;
            if (b8 == 0){
                b8 = 3;
            }
        } if (numb - auxb9 == 0){
            printf("bloco 9 torre: %i\n", b9);
            b9++;
            auxb9 += 512;
            if (b9 == 4){
                b9 = 1;
            }

        } if (numb - auxb10 == 0){
            printf("bloco 10 torre: %i\n", b10);
            b10--;
            auxb10 += 1024;
            if (b10 == 0){
                b10 = 3;
            }
        } if (numb - auxb11 == 0){
            printf("bloco 11 torre: %i\n", b11);
            b11++;
            auxb11 += 2048;
            if (b11 == 4){
                b11 = 1;
            }

        } if (numb - auxb12 == 0){
            printf("bloco 12 torre: %i\n", b12);
            b12--;
            auxb12 += 4096;
            if (b12 == 0){
                b12 = 3;
            }
        } if (numb - auxb13 == 0){
            printf("bloco 13 torre: %i\n", b13);
            b13++;
        }
    }
    return 0;
} // Honda isso deu muito trabalho pq eu comecei com o primeiro bloco na torre 2 em vez da torre 3 (q nem todo mundo na internet faz) ent eu tive q fazer todos os calculos manualmente (tenho no caderno) e so consegui testar até o 8 mas se a matematica ta certa funciona até o 13 sem problema nenhum