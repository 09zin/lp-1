#include <stdio.h>

int main(){
int testearray3d [80][80][80]; //depois desse numero não rodou mais
    for (int i  = 0; i <80; i++){
        for (int j = 0; j < 80; j++){
            for (int o = 0; o <80; o++){
                testearray3d[i][j][o] = i+j+o;
                printf("%i ", testearray3d[i][j][o]);
            }
        }
    }
    
return 0;
}