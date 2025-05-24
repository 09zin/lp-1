#include <stdio.h>

float MyDescontos (float salariob, int cs){ //função do vale transporte e conselho sindical
    float descontos = 0;
    if (cs == 1){
        descontos += salariob *0.1;
    }
    descontos += salariob*0.06;
    return descontos;
}

float MyINSS (float salariob){
    float inss = 0;
    if (salariob < 1518.01){ // aninhamento referente ao inss
        inss = salariob*7.5/100;
    } else if (salariob < 2793.88){
        inss = salariob*9/100-22.77;
    } else if (salariob < 4190.84){
        inss = salariob*12/100 - 106.59;
    } else{
        inss = salariob*14/100-190.4;
    }
return inss;
}

float MyIRPF(float salariob){
    float irpf = 0;
    if (salariob > 2428.81 && salariob < 2826.66){ // aninhamento referente ao IFPF
        irpf = salariob*7.5/100 - 182.16;
    } else if (salariob < 3751.06){
        irpf = salariob*15/100 - 394.16;
    } else if (salariob < 4664.68){
        irpf = salariob*22.5/100 - 675.49;
    } else{
        irpf = salariob*27.5/100 - 908.73;
    }
    return irpf;
}

float MySalarioliquido(float salariob, float descontos, float aumentos){
    float salariol = (salariob - descontos) + aumentos;
    if (salariol < 1412){
        printf("seu salario liquido é menor que o minimo e vc deve receber: R$: 1412");
        return 1412;
    } else {
        printf("seu salario liquido é de: R$%.2f\n", salariol);
        return salariol;
    }
}

void MyEmpresacustos (float salarioempresa){
    float inssp = salarioempresa*0.2; //20% de inss patronal
    float fgts = salarioempresa*0.08; //8% de fgts
    float decimo3 = salarioempresa/12; //1/12 avos por mês
    float ferias = salarioempresa/3 /12; //reserva mensal para ferias
    float multa = fgts * 0.4; //caso ocorra a multa o trabalhador recebera isso mais 1 salario bruto
    float sat = salarioempresa* 0.03; //considerando uma atividade de risco
    float sistema = salarioempresa *0.02; //auxilio a lazer e cursos
    float custototal = salarioempresa + inssp + fgts + decimo3 + ferias + multa + sat + sistema;

    printf("o custo total da folha de pagamento desse funcionario mensalmente será de: %.2f\n", custototal);
    printf("em caso de demissão, o funcionario recebera: %.2f\n", multa + salarioempresa);
}

int main(){
    float salariob, salariol, salarioempresa = 0; int cs;
    printf("qual seu salario bruto?: ");
    scanf("%f", &salariob);
    printf("deseja contruibuir para o conselho sindical?[1 para sim, 2 para não]: ");
    scanf("%i", &cs);
    float descontos = MyDescontos(salariob, cs);
    descontos += MyINSS(salariob);
    descontos += MyIRPF(salariob);
    float aumentos = salariob *0.15; //referente apenas ao vale alimentação de 15%
    salariol = MySalarioliquido(salariob, descontos, aumentos);
    
    printf("qual o salario do funcionario?: "); //parte empresa
    scanf("%f", &salarioempresa);
    MyEmpresacustos(salarioempresa);
return 0;
}