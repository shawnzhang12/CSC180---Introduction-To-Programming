#include <stdio.h>

int fibo(int n);

int main(void) {
   int i = 0;
   int bound;
   scanf("%d", &bound);
   for (i=0;i<bound;i=i+1){
      int f = fibo(i);
      printf("fibo(%d)=%d\n",i,f);
   }
   return 0;
}

int fibo(int n){
   int old=1;
   int oldold=1;
   int i;
   for (i=0;i<n;i=i+1){
      int tmp = old;
      old = old + oldold;
      oldold = tmp;
   }
   return oldold;
}
