#include <stdio.h>
#include <stdlib.h>

void MyInit(int array[], int Lines, int columns, int deep){
    for (int d = 0; d < deep; d++){
        for (int i = 0; i < Lines; i++){
            for (int j = 0; j < columns; j++){ //add the deep on the loop for
                int value = (d * Lines * columns) + (i * columns) + j; //math thats simules a 2d array using a 1d
                array[value] = value + 1; //any value assigned just for demonstration
            }
        }
    }
}

void MyInit0(int array[], int Lines, int columns, int deep){
    for (int d = 0; d < deep; d++){
        for (int i = 0; i < Lines; i++){
            for (int j = 0; j < columns; j++){ //add the deep on the loop for
                int value = (d * Lines * columns) + (i * columns) + j; //math thats simules a 2d array using a 1d
                array[value] = 0; //init 0
            }
        }
    }
}

void MyMultplyArray (int response[], int array1[], int array2[], int L1, int C2, int C1L2, int deep){
    for (int d = 0; d < deep; d++){ //add the deep on the most external loop for
        for (int i = 0; i < L1; i++){
            for (int j = 0; j < C2; j++){
                int sumarray = 0;
                for (int k = 0; k < C1L2; k++){
                    int index1 = (d * L1 * C1L2) + (i * C1L2)+ k; //finds the index of 1° array
                    int index2 = (d * C2 *C1L2) + (k * C2) + j; //finds the index of array 2
                    sumarray += array1[index1] * array2[index2]; //sums the response of each multply
                } 
                response[(d * L1 * C2) + (i * C2) + j] = sumarray; //put in the answer array
            }
        }
    }
}

void MyPrintArray(int array[], int L, int C, int deep){
    for (int d = 0; d < deep; d++){
        for (int i = 0; i < C; i++){
            for (int j = 0; j < L; j++){
                printf("array[%i][%i][%i]: %i\n", j, i, d, array[(d * L * C)+(j * C) + i]); //"j" e "i" are inverted because a mistake of wrinting, when i notice was easier to just invert they both
            }
        } //print every array by passing the array, lines and columns
    }
    printf("\n");
}

int main(){
    int *array = (int *)malloc((4* 3 * 3) * sizeof(int)); //allocation of memory for the array2d
    int *array2 = (int *)malloc((3* 4 * 3) * sizeof(int)); //allocation of memory for the 2° array2d
    int *response = (int *)malloc((4* 4 *3) * sizeof(int)); //allocation of memory for the response array
    int line, column, deep; //for access the array after
    char access;

    MyInit(array, 4, 3, 3);
    MyInit(array2, 3, 4, 3); //iniciation of each array
    printf("1° array:");
    MyPrintArray(array, 4, 3, 3);
    printf("2° array:");
    MyPrintArray(array2, 3, 4, 3); //shpws the arrays

    MyInit0(response, 3, 3, 3); //put 0 in the response because is a += operation

    MyMultplyArray(response, array, array2, 4, 4, 3, 3); /*multiply the arrays by passing the response array, each that will be multiplied the lines of the 1° one, the columns of the 2° one,and the colunms/lines of the 1° and 2° one respectively*/
    printf("response array:");
    MyPrintArray(response, 3, 3, 3); //shows the array multiplied
    printf("Wish to access any specify position of the respose array?[y/n]: ");
    scanf("%c", &access);
    if (access == 'y' || access =='Y'){
        printf("what position?(lines); ");
        scanf("%i", &line);
        printf("what position?(columns); ");
        scanf("%i", &column);
        printf("what position?(deep); ");
        scanf("%i", &deep); //gets the variables to access the index of simulated array
        printf("response array[%i][%i][%i] = %i\n", line, column, deep, response[(deep * 3 * 3) + (line * 3) + column]); //do the math and shows the array that the users wants to see
    }
    return 0;
}