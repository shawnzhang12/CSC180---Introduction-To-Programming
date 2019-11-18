/*#include <stdio.h>
*/

int anlboard(char *T, int sizeT);

int anlboard(char *T, int sizeT){
   if (sizeT != 9){
      return -1;
   }
   
   {
   int i=0;
   for (i=0;i<9;i++){
      if ((T[i] != 'X') && (T[i] != 'O') && (T[i] != '-')){
         return -1;
      } 
   }
   }
   
   {
   int countx = 0;
   int counto = 0;
   int i = 0;
   for (i=0;i<9;i++){
      if (T[i] == 'X'){
         countx = countx + 1;
      }else if (T[i] == 'O'){
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

   if ((T[0] == 'X') && (T[1] == 'X') && (T[2] == 'X')){
      xwin = 1;
   }else if ((T[3] == 'X') && (T[4] == 'X') && (T[5] == 'X')){
      xwin = 1;
   }else if ((T[6] == 'X') && (T[7] == 'X') && (T[8] == 'X')){
      xwin = 1;
   }else if ((T[0] == 'X') && (T[3] == 'X') && (T[6] == 'X')){
      xwin = 1;
   }else if ((T[1] == 'X') && (T[4] == 'X') && (T[7] == 'X')){
      xwin = 1;
   }else if ((T[2] == 'X') && (T[5] == 'X') && (T[8] == 'X')){
      xwin = 1;
   }else if ((T[0] == 'X') && (T[4] == 'X') && (T[8] == 'X')){
      xwin = 1;
   }else if ((T[2] == 'X') && (T[4] == 'X') && (T[6] == 'X')){
      xwin = 1;
   }

   if ((T[0] == 'O') && (T[1] == 'O') && (T[2] == 'O')){
      owin = 2;
   }else if ((T[3] == 'O') && (T[4] == 'O') && (T[5] == 'O')){
      owin = 2;
   }else if ((T[6] == 'O') && (T[7] == 'O') && (T[8] == 'O')){    
      owin = 2;
   }else if ((T[0] == 'O') && (T[3] == 'O') && (T[6] == 'O')){
      owin = 2;
   }else if ((T[1] == 'O') && (T[4] == 'O') && (T[7] == 'O')){
      owin = 2;
   }else if ((T[2] == 'O') && (T[5] == 'O') && (T[8] == 'O')){
      owin = 2;
   }else if ((T[0] == 'O') && (T[4] == 'O') && (T[8] == 'O')){
      owin = 2;
   }else if ((T[2] == 'O') && (T[4] == 'O') && (T[6] == 'O')){
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
      if (T[i] == '-'){
         return 0;
      }
   }
   }
   
   {
   int i = 0;
   int drawcheck = 1;
   for (i=0;i<9;i++){
      if (T[i] == '-'){
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
   char T[9] = "OX-XOX-OX";
   printf("%d",anlboard(T,9));
   return 0;
}*/

