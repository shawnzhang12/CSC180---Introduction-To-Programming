#include "sort.c"
#include <stdio.h>

int main(void){
   int i = 0;
   int r = 0;
   int array[5];
   
   array[0] = 1;
   array[1] = -4;
   array[2] = 100;
   array[3] = 2;
   array[4] = -1;

   r = bubbleSort(array,5);
   printf("%d ",r);
   printf("\n");
   for (i=0;i<5;i++){
      printf("%d ",array[i]);
   }
   return 0;
}
