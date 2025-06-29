algoritmo "semnome"
var
   i,j,k,cont1,cont2,cont3:inteiro
inicio
      para i <- 0 ate 10000 faca
           escreval (i)
      fimpara
      para i <- -10000 ate 10000 faca
           escreval (i)
      fimpara
      para i <- 0 ate 10000 passo 2 faca
           escreval (i)
      fimpara
      para i <- 1 ate 10000 passo 2 faca
           escreval (i)
      fimpara
      para i <- -100000 ate 100000 passo 3 faca
           escreval (i)
      fimpara
      para i <- 0 ate 9 faca
           cont1 <- cont1 + 1
           para j <- 0 ate 9 faca
                cont2 <- cont2 + 1
                para k <- 0 ate 9 faca
                     cont3 <- cont3 + 1
                     escreval (i,j,k)
                fimpara
           fimpara
      fimpara
      escreval ("interações de I:", cont1, " interações de J:", cont2, " interações de k:",cont3)
fimalgoritmo