#include <stdio.h>
#define L1C2 3 //constant because the columns of the 1° array have to be equal to the lines of the 2° array 
#define deep 2

void MyInit(int array[][2][L1C2], int depth){ //inicializator for arrays with 3 on the collumns
    for (int d = 0; d < depth; d++){ // for to deep dimension
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < L1C2; j++){
                array[d][i][j] = d + i + j; // adds D value
            }
        }
    } 
}

void MyInit2(int array[][L1C2][2], int depth){ //inicializator for arrays with 2 on the collumns
    for (int d = 0; d < depth; d++){ 
        for (int i = 0; i < L1C2; i++){
            for (int j = 0; j < 2; j++){
                array[d][i][j] = d + i + j; 
            }
        }
    } 
}

void MyInit3(int array[][2][2], int depth){ //inicializator for arrays with 2 on the collumns, with 0 for result
    for (int d = 0; d < depth; d++){ 
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                array[d][i][j] = 0;
            }
        }
    } 
}

int main (){
    int array1[deep][2][L1C2], array2[deep][L1C2][2], result[deep][2][2];

    MyInit(array1, deep);
    MyInit2(array2, deep);
    MyInit3(result, deep); //inicialization of all arrays

    for (int d = 0; d < deep; d++){ // //travel for the deep
        for (int i = 0; i < 2; i++){ //travel for the lines of the 1° array
            for (int j = 0; j < 2; j++){ //travel for the collumns of the 2° array
                for (int k = 0; k < L1C2; k++){ 
                    //adds depth to access the correct index
                    result[d][i][j] += array1[d][i][k] * array2[d][k][j]; //maths that sums the result
                }
            }
        }
    }
    for (int d = 0; d < deep; d++){ // for that travels the deep
        for (int i = 0; i < 2; i++){ // travels lines of response array
            for (int j = 0; j < 2; j++){ // travels columns of reponse array
                printf("multiplied array[%d][%i][%i]: %i\n", d, i, j, result[d][i][j]); //output the array
            }
        }
    }

return 0;
}