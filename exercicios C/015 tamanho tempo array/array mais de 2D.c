#include <stdio.h>

int main (){
    int vetor [2][2][2][2][2][2][2][2][2][2][2][2]; //declaração de um array de 12 D
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int o = 0; o < 2; o++){
                for (int k = 0; k < 2; k++){
                    for (int l = 0; l < 2; l++){
                        for (int n = 0; n < 2; n++){
                            for (int i2 = 0; i2 < 2; i2++){
                                for (int j2 = 0; j2 < 2; j2++){
                                    for (int o2 = 0; o2 < 2; o2++){
                                        for (int k2 = 0; k2 < 2; k2++){
                                            for (int l2 = 0; l2 < 2; l2++){
                                                for (int n2 = 0; n2 < 2; n2++){
                                                    vetor [i][j][k][o][l][n][i2][j2][k2][o2][l2][n2] = 1; //todas as posições recebem 1 apenas para ilustrar
                                                    printf("%i ", vetor[i][j][k][o][l][n][i2][j2][k2][o2][l2][n2]); //mostra todas as posições do array
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
return 0;
}
/*pelo oque eu pesquisei não ha limitação da linguagem C em si para a quantidade de dimensões que um array pode ter, as limitações vem do hardware, do consumo de memoria e dos compiladores, minha maquina não da resposta no terminal se eu subir os indices do array de 2 para 3 por exemplo por limitação de memoria, o padrão da linguagem C exige q os compiladores aceitem pelo menos 12 dimensões, na pratica os compiladores atuais geralmente aceitam até 256 dimensões, os computadores modernos de hoje em dia (não é o caso do meu) conseguem lidar com ate 20 dimensões eficientemente em media, mas depois de 6 dimensões o codigo começa a se tornar ilegivel e dificil de manusear/dar manuntenção então não é aconselhado*/