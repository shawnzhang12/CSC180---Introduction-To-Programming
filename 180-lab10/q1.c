#include <stdio.h>

float avg(float* array, int size){
   int i=0;
   float avg=0;
   if(array==NULL){
      return -0;
   }

   for(i=0;i<size;i++){
      avg+=array[i];
   }
   return avg;
}

int main(void){
   float x[4]={1,2,3,4};
   float r=0;
   r=avg(x,4);
   printf("%f",r);
}
