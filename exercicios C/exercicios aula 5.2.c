#include <stdio.h>
int main(){
    int b1 = 2, b2 =3, b3= 2;
    for (int numb = 0; numb <7; numb++){
        printf("%i ", numb);
        if (numb % 2 == 0){
            printf("bloco 1 torre:%i\n", b1);
            b1 ++;
        }
            if (b1 == 4){
                b1 = 1;
            }
        if (numb - 3 == 0){
            printf("bloco 3 torre:%i\n", b3);
        }else if((numb+7) % 2 == 0){
            printf("bloco 2 torre:%i\n", b2);
            b2--;
        }
    }
    return 0;
}