#include <stdio.h>
int main(){
    float salariob, descontos = 0, aumentos = 0, salariol; int cs;
    printf("qual seu salario bruto?: ");
    scanf("%f", &salariob);
    printf("deseja contruibuir para o conselho sindical?[1 para sim, 2 para não]: ");
    scanf("%i", &cs);
    if (cs == 1){
        descontos += salariob*0.1; // conselho sindical
    }
    descontos += salariob*0.06; // vale transportem, quando o vale passa de R$220 reais ele deixa de valer a pena
    aumentos += salariob*0.15; // auxilio alimentação
    if (salariob < 1518.01){ // aninhamento referente ao inss
        descontos += salariob*7.5/100;
    } else if (salariob < 2793.88){
        descontos += salariob*9/100-22.77;
    } else if (salariob < 4190.84){
        descontos += salariob*12/100 - 106.59;
    } else{
        descontos += salariob*14/100-190.4;
    }
    if (salariob > 2428.81 && salariob < 2826.66){ // aninhamento referente ao IFPF
        descontos += salariob*7.5/100 - 182.16;
    } else if (salariob < 3751.06){
        descontos += salariob*15/100 - 394.16;
    } else if (salariob < 4664.68){
        descontos += salariob*22.5/100 - 675.49;
    } else{
        descontos += salariob*27.5/100 - 908.73;
    }
    salariol = (salariob - descontos) + aumentos;
    if (salariol < 1412){
        printf("seu salario liquido é menor que o minimo e vc deve receber: R$: 1412");
    } else {
        printf("seu salario liquido é de: R$%.2f", salariol);
    }
return 0;
}