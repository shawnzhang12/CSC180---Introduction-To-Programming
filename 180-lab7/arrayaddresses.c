#include <stdio.h>

int main(void){
   int a[10];
   int i;
   printf("the size of an integer in my version of C is %d\n", sizeof(int));
   printf("a is %d\n",a);
   for (i=0;i<10;i++){
      printf(" the ADDRESS of a[%d] is %d\n",i,&(a[i]));
   }
   return 0;

}
