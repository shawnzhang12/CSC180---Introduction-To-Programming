/*#include <stdio.h>
*/

int anlboard(int *T, int sizeT);

int anlboard(int *T, int sizeT){
   if (sizeT != 9){
      return -1;
   }
   
   {
   int i=0;
   for (i=0;i<9;i++){
      if ((T[i] != 0) && (T[i] != 1) && (T[i] != 2)){
         return -1;
      } 
   }
   }
   
   {
   int countx = 0;
   int counto = 0;
   int i = 0;
   for (i=0;i<9;i++){
      if (T[i] == 1){
         countx = countx + 1;
      }else if (T[i] == 2){
         counto = counto + 1;
      }
   }
   
   if ((countx - counto >= 2) || (counto - countx >= 2)){
      return -1;
   }
   }
   
   {
   int xwin = 0;
   int owin = 0;

   if ((T[0] == 1) && (T[1] == 1) && (T[2] == 1)){
      xwin = 1;
   }else if ((T[3] == 1) && (T[4] == 1) && (T[5] == 1)){
      xwin = 1;
   }else if ((T[6] == 1) && (T[7] == 1) && (T[8] == 1)){
      xwin = 1;
   }else if ((T[0] == 1) && (T[3] == 1) && (T[6] == 1)){
      xwin = 1;
   }else if ((T[1] == 1) && (T[4] == 1) && (T[7] == 1)){
      xwin = 1;
   }else if ((T[2] == 1) && (T[5] == 1) && (T[8] == 1)){
      xwin = 1;
   }else if ((T[0] == 1) && (T[4] == 1) && (T[8] == 1)){
      xwin = 1;
   }else if ((T[2] == 1) && (T[4] == 1) && (T[6] == 1)){
      xwin = 1;
   }

   if ((T[0] == 2) && (T[1] == 2) && (T[2] == 2)){
      owin = 2;
   }else if ((T[3] == 2) && (T[4] == 2) && (T[5] == 2)){
      owin = 2;
   }else if ((T[6] == 2) && (T[7] == 2) && (T[8] == 2)){    
      owin = 2;
   }else if ((T[0] == 2) && (T[3] == 2) && (T[6] == 2)){
      owin = 2;
   }else if ((T[1] == 2) && (T[4] == 2) && (T[7] == 2)){
      owin = 2;
   }else if ((T[2] == 2) && (T[5] == 2) && (T[8] == 2)){
      owin = 2;
   }else if ((T[0] == 2) && (T[4] == 2) && (T[8] == 2)){
      owin = 2;
   }else if ((T[2] == 2) && (T[4] == 2) && (T[6] == 2)){
      owin = 2;
   }

   if ((xwin == 1) && (owin == 2)){
      return -1;
   }
   
   if ((xwin == 1) && (owin != 2)){
      return 1;
   }else if ((owin == 2) && (xwin != 1)){
      return 2;
   }
   }
   
   {
   int i = 0;
   for (i=0;i<9;i++){
      if (T[i] == 0){
         return 0;
      }
   }
   }
   
   {
   int i = 0;
   int drawcheck = 1;
   for (i=0;i<9;i++){
      if (T[i] == 0){
         drawcheck = -1;
      }
   }
   if (drawcheck == 1){
    return 3;
   }  
   }
}

/*
int main(void){
   int i = 0;
   int T[9];
   T[0]=1;
   T[1]=1;
   T[2]=2;
   T[3]=2;
   T[4]=2;
   T[5]=1;
   T[6]=1;
   T[7]=2;
   T[8]=1;
   printf("%d",anlboard(T,9));
   return 0;
}
*/
