/*#include <stdio.h>
*/

int swap(int *a, int *b);

/*
int main(void){
   int x = -456;
   int b = -1;
   int y;
   printf("x=(%d),b=(%d)",x,b);
   y = swap(&x,&b);
   printf("x=(%d),b=(%d)",x,b);
}*/

int swap (int *a, int *b){
   int tmp = *a;
   *a = *b;
   *b = tmp;
   return 1;
}
