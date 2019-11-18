#include <stdio.h>

int squareInt(int x);
float bsqrt(float x, float acc);

int main(void) {
   int i;
   for (i=0;i<10;i++){
      float sqrt;
      sqrt=bsqrt((float)i,0.001);
      printf("the sqrt of %d is %f\n",i,sqrt);  

   }
   return 0;
}

float bsqrt(float x, float acc) {
   float est = x * 0.5;
   float diff = 0.0;

   while (1) {
      if (x - (est*est) <= 0) {
         diff = (est*est) - x;
      }else{
      diff = x - (est*est);
      }
      if (diff < acc){
         break;
      }
      est = (est + (x/est))/2;
   }
   return est;
}

int squareInt(int x) {
   return x*x;
}

