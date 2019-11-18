#include <stdio.h>

int fibore(int n);

int main(void){
   int i = 0;
   for (i=0;i<20;i++){
      int f = fibore(i);
      printf("fibore(%d)=%d\n",i,f);
   }
   return 0;
}

int fibore(int n){
   if (n==0){
      return 1;
   }else if (n==1){
      return 1;
   }else{
      return (fibore(n-1) + fibore(n-2));
   }
}
