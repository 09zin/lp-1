#include <stdio.h>

void MyInit(int vetor[], int t){
    for (int i = 0; i < t; i++){
        vetor[i] = 0;
    }

}

void MyAnaliseNotas (int P[20], int notas[5]){ 
    for (int i = 0; i < 20; i++){ //count each value
        if (P[i] == 0){
            notas[0]++;
        }else if (P[i] == 1){
            notas[1]++;
        }else if (P[i] == 2){
            notas[2]++;
        }else if (P[i] == 3){
            notas[3]++;
        }else if (P[i] == 4){
            notas[4]++;
        }else if (P[i] == 5)
            notas[5]++;
    }   
}

int main(){
    int P[20], notas[5]; 
    MyInit(notas, 5);
    MyInit(P, 20);
    for (int i = 0; i < 20; i++){
        printf("qual a nota da %i° pessoa?(0-5): ", ++i); 
        i--;
        scanf("%i", &P[i]); //store each note
        while(P[i] < 0 || P[i] > 5){ //asks again case its wrong
            printf("nota invalida por favor digite novamente: ");
            scanf("%i", &P[i]);
        }
    }
    MyAnaliseNotas(P, notas); //shows everything
    for (int i = 0; i <= 5; i++){
        printf("quantidade de notas %i: %i\n",i, notas[i]);
    }
return 0;
}