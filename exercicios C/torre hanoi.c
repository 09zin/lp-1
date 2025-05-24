#include <stdio.h>
#include <math.h>
int main(){
    int numb = 0, blocos =0, b1 = 2, b2 =3, b3= 2, b4= 3, b5=2, b6 = 3, b7 = 2, b8 = 3, auxb2= 1, auxb3= 3, auxb4 = 7, auxb5= 15, auxb6= 31, auxb7 = 63, auxb8 = 127;
    printf("quantos blocos?[3,4,5,6,7,8]:");
    scanf("%i", &blocos);
    blocos = pow(2,blocos)-1;
    for(numb; numb <blocos; numb++){
        printf("%i ", numb);
        if (numb %2 == 0){
            printf ("bloco 1 torre:%i\n", b1);
            b1++;
            if (b1 == 4){
                b1 = 1;
            }
        }
        if (numb - auxb2 == 0){
            printf("bloco 2 torre:%i\n",b2);
            b2--;
            auxb2 += 4;
            if (b2 == 0){
                b2 = 3; }
        }
        if (numb - auxb3 == 0){
            printf("bloco 3 torre:%i\n",b3);
            b3++;
            if (b3 == 4){
                b3 = 1;
            }
            auxb3 +=8;
        } 
        if (numb - auxb4 ==0){
            printf("bloco 4 torre:%i\n",b4);
            b4--;
            auxb4 += 16;
            if (b4 == 0){
                b4 = 3; }
        }
        if (numb - auxb5 ==0){
            printf("bloco 5 torre:%i\n", b5);
            b5 ++;
            auxb5 += 32;
            if (b5 == 4){
                b5 = 1;
            }
        } if (numb - auxb6 == 0){
            printf("bloco 6 torre:%i\n", b6);
            b6--;
            auxb6 += 64;
            if (b6 == 0){
                b6 = 3; }
        } if (numb - auxb7 == 0){
            printf("bloco 7 torre:%i\n", b7);
            b7++;
            auxb7 += 128;
            if (b7 == 4){
                b7 = 1;
            }
        } if (numb - auxb8 == 0){
            printf("bloco 8 torre:%i\n", b8);
        }
    }
    return 0;
}