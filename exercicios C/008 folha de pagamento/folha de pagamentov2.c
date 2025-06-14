#include <stdio.h>
int main(){
    float salariob, descontos = 0, aumentos = 0, salariol, salarioempresa = 0, fgts =0, inssp = 0, decimo3 = 0, ferias = 0, multa = 0, custototal = 0, sat = 0, sistema = 0; int cs;
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
        printf("seu salario liquido é de: R$%.2f\n", salariol);
    }
    //parte da empresa agora
    printf("qual o salario do funcionario?: ");
    scanf("%f", &salarioempresa);
    inssp = salarioempresa*0.2; //20% de inss patronal
    fgts = salarioempresa*0.08; //8% de fgts
    decimo3 = salarioempresa/12; //1/12 avos por mês
    ferias = salarioempresa/3 /12; //reserva mensal para ferias
    multa = fgts * 0.4; //caso ocorra a multa o trabalhador recebera isso mais 1 salario bruto
    sat = salarioempresa* 0.03; //considerando uma atividade de risco
    sistema = salarioempresa *0.02; //auxilio a lazer e cursos
    custototal = salarioempresa + inssp + fgts + decimo3 + ferias + multa + sat + sistema;
    printf("o custo total da folha de pagamento desse funcionario mensalmente será de: %.2f\n", custototal);
    printf("em caso de demissão, o funcionario recebera: %.2f\n", multa + salarioempresa);
return 0;
}