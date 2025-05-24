algoritmo "sem nome"
var
   N1,N2, N3: inteiro
   resp: real
inicio
   escreval ("os operadores basicos são +, -, *, / e %")
   escreval ("a ordem de precedencia é 1° (), 2° %, 3° * e /, 4° + e -")
   n1 <- 30
   n2 <- 6
   resp <- (n1 + n2)/ n2
   escreval("conta com + e / com ():",resp)
   resp <- n1+n2/n2
   escreval("conta com + e / sem ():",resp)
   n1 <- 30
   n2 <- 5
   n3 <- 4
   resp <- (n1-n2)* n3
   escreval("conta com - e * com ():",resp)
   resp <- n1-n2*n3
   escreval("conta com - e * sem ():",resp)
   n1 <-10
   n2 <-8
   n3 <-2
   resp <- n1%(n2/n3)
   escreval("conta com % e / com ():",resp)
   resp <- n1 % n2/n3
   escreval("conta com % e / sem ():",resp)
fimalgoritmo