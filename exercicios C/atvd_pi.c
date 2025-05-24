#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

double MyPI (int N, float raio); //declaro a função q foi feita em baixo

int main(){
   int N; float raio; double PI;
   printf("qual o numero de rodadas?: ");
   scanf("%i", &N);
   printf("qual o raio do circulo?: ");
   scanf("%f", &raio); // peço todas as variaveis e chamo a função
   PI = MyPI(N, raio);
   printf("o PI calculado foi de: %lf\n", PI);
return 0;
}

double MyPI (int N, float raio){ //função que calcula PI
   srand(time(NULL)); 
   int i, pontostot = 0, pontoscir = 0;
   for (i = 0; i < N; i++){
      pontostot ++;
      double ponto1 = (double)rand() / RAND_MAX * 2 * raio - raio;
      double ponto2 = (double)rand() / RAND_MAX * 2 * raio - raio; //é necessário por o - raio pois se os números negativos n forem considerados os ponto são gerados do em 1/4 do quadrado, dando erro
      if (((ponto1*ponto1) + (ponto2*ponto2)) <= (raio*raio))
         pontoscir++; // adciona os pontos no circulo
   }
   return 4*((double)pontoscir/pontostot); //formula que retorna o pi calculado
} 