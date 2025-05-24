#include <stdio.h>
#include <float.h>
int main (){
   int ex1 = 0; long long int ex2 = 0; unsigned int ex3 = 0; short int ex4 = 0; float ex5 =0; double ex6 = 0; long double ex7 = 0;
   //int comun possui 4 bytes logo 32 bits podendo representar até 4294967295 sendo metade desses negativos logo até 2147483647
   ex1 = 2147483647;
   printf("%d\n", ex1); //o número é printado normalmente por estar dentro do limite da variavel
   ex1 = 2147483648;
   printf("%d\n", ex1); //ao tentar guardar um valor maior que o permitido o comportamento é indefinido, o compilador interpreta esse numero de maneira errada, podendo voltar ao numero maximo negativo ou aparecer algo estranho
   ex3 = 4294967295; //ao usar unsinged int é possivel representar valores 2x maiores ao não ultilizar os numeros negativos
   printf("%u\n", ex3);
   ex3 = 4294967296; 
   printf("%u\n", ex3); //o mesmo problema ocorre ao passar do limite
   ex2 = 9223372036854775807; // esse numero é o limite pro long int normal jaq é metade de 18.446.744.073.709.551.616 (menos 1), lembrando que no windows é necessário usar "long long int"
   printf("%lli\n", ex2);
   ex2 = 9223372036854775808; 
   printf("%lli\n", ex2); //novamente occore o problema ao passar o limite
   ex4 = 32767;
   printf("%i\n", ex4); // numero maximo pra um short int por ser 2^16/2 - 1 (metade de 65535)
   ex4 = 32768;
   printf("%i\n", ex4); //novamente o bug ocorre
   ex5 = FLT_MAX;
   printf("%f\n", ex5); //valor maximo representado por float
   ex5 = FLT_MAX + 1;
   printf("%f\n", ex5); //não causa bug por 1 ser insignificante perto do fltmax logo é "arredondado"
   ex5 = FLT_MAX * 10;
   printf("%f\n", ex5); //agora causa bug
   ex6 = DBL_MAX;
   printf("%e\n", ex6); //valor maximo do double
   ex6 = DBL_MAX * 10;
   printf("%e\n", ex6);// agora ocorre o bug
   ex7 = LDBL_MAX;
   printf("%le\n", ex7); //valor maximo do long double
   ex7 = LDBL_MAX * 10;
   printf("%le\n", ex7);// agora ocorre o bug
    return 0;
}