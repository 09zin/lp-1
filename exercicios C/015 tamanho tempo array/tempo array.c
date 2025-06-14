#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double tempo, tempo1;
    setbuf(stdout, NULL); //configuração do buffer de saida (faz o codigo sair assim q é feito e não todo de vez quando o progama terminar ou a memoria atual encher)
    int MyArray[1000][500];
    long int sum = 0, sum1 = 0;

    start = clock(); //medir tempo com i maior que o J

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 500; j++) {
            MyArray[i][j] = 1;
        }
    }

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 500; j++) {
            sum += MyArray[i][j];
        }
        printf("."); //soma e print de "." para mostrar o progresso sem poluir muito o terminal
    }
    printf("\n");
    
    end = clock(); //fim do primeiro timer
    tempo = ((double)(end - start)) / CLOCKS_PER_SEC; //calculo que mostra o tempo da primiera execução
    printf("soma do array: %ld | tempo de execução: %.6f \n", sum, tempo);

    start = clock(); //inicio do segundo timer com J maior q i

    for (int i = 0; i < 500; i++) { //reultização do mesmo array
        for (int j = 0; j < 1000; j++) {
            MyArray[i][j] = 1;
        }
    }

    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < 1000; j++) {
            sum1 += MyArray[i][j];
        }
        printf(".");
    }
    printf("\n");
    
    end = clock();
    tempo1 = ((double)(end - start)) / CLOCKS_PER_SEC; //calculo do tempo da execução 2
    printf("soma do array: %ld | tempo de execução: %.6f \n", sum1, tempo1);
    if (tempo > tempo1){ //if que seleciona o maior tempo e mostra q o oposto foi mais eficiente
        printf("O J maior (caso 2) maior é mais eficiente | a diferença de tempo foi: %.6f\n", (tempo-tempo1));
    }else
        printf("O i maior (caso 1) é mais eficiente | a diferença de tempo foi: %.6f\n", (tempo1-tempo));
    
    return 0;
}
/*com isso fica provado pelo teste de tempo de ambos os casos que uso de arrays é otimizado usando Y (segunda dimensão) maior que a X (primeira dimensão) oque pode aumentar muito o desempenho de codigos grandes, ja que em mais de 30 execuções todas deram o caso 2 como mais eficaz*/