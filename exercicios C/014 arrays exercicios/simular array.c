#include <stdio.h>
#include <stdlib.h>

#define colunm 5 //size of the first dimension of array
#define lines 5 // size of the second dimension of array
#define deep 5 // size of the third dimension of array

void MyArray3d (){
    int *indice2 = (int *)malloc((5 *5* 5) * sizeof(int)); //allocation of memory for the array3d
    int Pline, Pcolumn, Pdeep; //for access the array after
    for (int i = 0; i < colunm; i++){
        for (int j = 0; j < lines; j++){
            for (int o = 0; o < deep; o++){
                int value = (i * lines * colunm) + (j * colunm) + o; //math thats simules a 3d array using a 1d
                indice2[value] = value + 1; //any value assigned just for demonstration
            }
        }
    }

    for (int i = 0; i < colunm; i++){
        for (int j = 0; j < lines; j++){
            for (int o = 0; o < deep; o++){
                int numero = (i * lines * colunm) + (j * colunm) + o; //access to each position of the simulated array
                printf("array [%d][%d][%d] = %d\n", j, i, o, indice2[numero]); //output of the array values
            }
        }
    }

    printf("what position do you wanna access?(line): ");
    scanf("%i", &Pline);
    printf("what position do you wanna access?(colunm): ");
    scanf("%i", &Pcolumn);
    printf("what position do you wanna access?(deep): ");
    scanf("%i", &Pdeep);//read the variables to acess the array

    printf("array[%i][%i][%i]: %i\n", Pline, Pcolumn, Pdeep, indice2[(Pline * colunm * lines) + (Pcolumn * colunm) + Pdeep]); //do the math and shows the possition
    free(indice2); //release the allocated memory
}

int main(){
    int *indice = (int *)malloc((5* 5) * sizeof(int)); //allocation of memory for the array2d
    int Pline, Pcolumn; //for access the array after

    for (int i = 0; i < colunm; i++){
        for (int j = 0; j < lines; j++){
            int value = (i * colunm) + j; //math thats simules a 2d array using a 1d
            indice[value] = value + 1; //any value assigned just for demonstration
        }
    }

    for (int i = 0; i < colunm; i++){
        for (int j =0; j < lines; j++){
            int numero = (i * colunm) + j; //access to each position of the simulated array
            printf ("array [%d][%d] = %d\n", j, i, indice[numero]);  //output of the array values
        }
    }

    printf("what position do you wanna access?(line): ");
    scanf("%i", &Pline);
    printf("what position do you wanna access?(colunm): ");
    scanf("%i", &Pcolumn); //read the variables to acess the array
    printf("array[%i][%i]: %i\n", Pline, Pcolumn, indice[(Pline * colunm) + Pcolumn]); //do the math of the position

    printf("\nnow the 3d array\n\n"); //separation of the 2 different arrays
    free(indice); //release the allocated memory
    MyArray3d(); //call the function for the array 3d, just for organization 
return 0;
}