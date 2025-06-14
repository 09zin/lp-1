#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void MyOrder (int array[], int s){ //function that order the array
    int aux;
    for (int i = 0; i < s; i++){
        for (int j = i +1; j < s; j++){
            if (array[i] > array[j]){
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

int main(){
    srand(time(NULL)); 
    clock_t start,end;
    float time;
    start = clock(); //start of clock measurement
    int array[20];
    for (int i = 0; i < 20; i++){
        array[i] = 1 + rand() % 25; //assigned ramdom values to the array
    }
    MyOrder(array, 20); //calls the function to order it 
    printf("array in crescent order: "); //output the array in correct order
    for (int i = 0; i < 20; i++){
        printf("%i ", array[i]);
    }
    end = clock(); //end of clock measurement
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n");
    printf("time of execution: %.6f", time); 
return 0;
}