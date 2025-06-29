algoritmo "torre hanoi"
var
   b1, b2, b3, aux2, aux3, numb, rodada: inteiro
inicio
      b1 <- 2
      b2 <- 3
      b3 <- 2
      aux2 <- 1
      aux3 <- 3
      para numb <- 0 ate  6 faca
         rodada <- numb + 1
         escreva (rodada, " ")
         se (numb%2 = 0) entao
            escreval ("bloco 1 torre ", b1)
            b1 <- b1 + 1
            se (b1 = 4) entao
               b1 <- 1
            fimse
         fimse
         se (numb - aux2 = 0) entao
            escreval ("bloco 2 torre ",b2)
            b2 <- b2 - 1
            aux2 <- aux2 + 4
            se (b2 = 0) entao
               b2 <- 3
            fimse
         fimse
         se (numb - aux3 = 0) entao
            escreval ("bloco 3 torre ",b3)
         fimse
      fimpara
fimalgoritmo