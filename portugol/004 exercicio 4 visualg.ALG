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
         escreval ("seu IMC � de ",imc:5:2," e sua classifica��o � de magreza")
      senao
           se (imc < 25) entao
              escreval ("seu IMC � de ",imc:5:2," e sua classifica��o � normal")
           senao
                se (imc < 30) entao
                   escreval ("seu IMC � de ",imc:5:2," e sua classifica��o � de sobrepeso")
                senao
                     se (imc < 40)entao
                        escreval ("seu IMC � de ",imc:5:2," e sua classifica��o � de obesidade")
                     senao
                        escreval ("seu IMC � de ",imc:5:2," e sua classifica��o � de obesidade grave")
                     fimse
                fimse
           fimse
      fimse

fimalgoritmo