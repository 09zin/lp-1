algoritmo "semnome"
var
   altura, peso, imc: real
inicio
      escreva("qual seu peso: ")
      leia(peso)
      escreva("qual sua altura em metros: ")
      leia(altura)
      imc <- peso/(altura*altura)
      se (imc < 18) entao
         escreval ("seu IMC é de ",imc:5:2," e sua classificação é de magreza")
      senao
           se (imc < 25) entao
              escreval ("seu IMC é de ",imc:5:2," e sua classificação é normal")
           senao
                se (imc < 30) entao
                   escreval ("seu IMC é de ",imc:5:2," e sua classificação é de sobrepeso")
                senao
                     se (imc < 40)entao
                        escreval ("seu IMC é de ",imc:5:2," e sua classificação é de obesidade")
                     senao
                        escreval ("seu IMC é de ",imc:5:2," e sua classificação é de obesidade grave")
                     fimse
                fimse
           fimse
      fimse

fimalgoritmo