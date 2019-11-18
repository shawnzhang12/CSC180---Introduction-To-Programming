#include <stdio.h>
int bubbleSort(int *array, int size);

int bubbleSort(int *array, int size){
   int swapped = 0;
   int i = 0;

   if (size <= 0){
      return -1;
   }else if (array == NULL){
      return -1;
   }

   while(swapped == 0){
      swapped = -1;
      for (i=1;i<size;i++){
         if (array[i-1] > array[i]){
            int temp = 0;
            temp=array[i];
            array[i]=array[i-1];
            array[i-1]=temp;
            swapped = 0;        
         }
      }
   }
   return 0;
   
}

/*
int main(void){
   int array[] = {1,4,5,6,8,7,3};
   int r = 0;
   int i = 0;
   array[4]=1000;
   r = bubbleSort(array,7);
   
   for (i=0;i<7;i++){
   printf("%d ", array[i]);
   }
}
*/
