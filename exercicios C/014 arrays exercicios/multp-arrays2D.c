#include <stdio.h>
#define L1C2 3 //constant because the columns of the 1° array have to be equal to the lines of the 2° array 

void MyInit(int array[][L1C2], int lines){ //inicializator for arrays with 3 on the collumns
    for (int i = 0; i < lines; i++){
        for (int j = 0; j < L1C2; j++){
            array[i][j] = j+i;
        }
    } 
}

void MyInit2(int array[][2], int lines){ //inicializator for arrays with 2 on the collumns
    for (int i = 0; i < lines; i++){
        for (int j = 0; j < 2; j++){
            array[i][j] = i+j;
        }
    } 
}

void MyInit3(int array[][2], int lines){ //inicializator for arrays with 2 on the collumns, with 0 for result
    for (int i = 0; i < lines; i++){
        for (int j = 0; j < 2; j++){
            array[i][j] = 0;
        }
    } 
}

int main (){
    int array1[2][L1C2], array2[L1C2][2], result[2][2];

    MyInit(array1, 2);
    MyInit2(array2, L1C2);
    MyInit3(result, 2); //inicialization of all arrays

    for (int i = 0; i < 2; i++){ //travel for the lines of the 1° array
        for (int j = 0; j < 2; j++){ //travel for the collumns of the 2° array
            for (int k = 0; k < L1C2; k++){ //travel for the collumns of the 1° array and the lines of the 2°, multiplying they
                result[i][j] += array1[i][k] * array2[k][j]; //sums the result of each multiplication
            }
        }
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            printf("multiplied array[%i][%i]: %i\n", i, j, result[i][j]); //output the result
        }
    }

return 0;
}