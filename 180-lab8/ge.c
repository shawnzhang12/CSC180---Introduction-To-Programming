#include <stdio.h>
/*Sorry doesn't work I'll try and fix this over the weekend*/
int ge_fw(float *matrix, int rows, int cols, float *matrix_out);
int ge_bw(float *matrix, int rows, int cols, float *matrix_out);

int ge_fw(float *matrix, int rows, int cols, float *matrix_out){
   int t = 0;
   int k = 0;
   int skip = 0;
   int i = 0;
   int j = 0;
   float temp = 0;
 
   if (matrix == NULL){
      return -1;
   }
   if(rows <= 0){
      return -1;
   }else if(cols <=0){
      return -1;
   }
 
   if (rows >= cols){
      t = cols;
   }else{
      t = rows;
   }

   matrix_out = matrix;
   for(i=0;i<rows;i++){
      for(j=0;j<cols;j++){
         printf("%8.3f ",matrix_out[i*cols+j]);
      }
      printf("\n");
   }   



   while (k < t){
      if (k+skip == t){
         break;
      }
      for(i=0+k;i<rows;i++){
         if(matrix_out[i*cols+0+k+skip] != 0){
            for(j=0;j<cols;j++){
               temp=(matrix_out[(0+k)*cols+j]);
               matrix_out[(0+k)*cols+j]=matrix_out[i*cols+j];
               matrix_out[i*cols+j]=temp;
            } 
         }
         break;
      }

      if (matrix_out[(0+k)*cols+0+k+skip] == 0){
         skip=skip+1;
      }else{
         for(i=1+k;i<rows;i++){
            temp=matrix_out[i*cols+0+k+skip];
            for(j=0+k+skip;j<cols;j++){
               matrix_out[i*cols+j]=matrix_out[i*cols+j] - (matrix_out[(0+k)*cols+j]*(temp/matrix_out[k*cols+0+k+skip]));
               printf("%8.3f ",matrix_out[i*cols+j]);
            }
         }
         
         k=k+1;
         /* printf("%d, %d\n",k,skip);*/
      }
   }
   return 0;
}


int main(void){
   float arr[9]={1,2,3,4,5.5,6,7,8,9};
   float arrout[9];
   int x=0, y=0;
   int i=1;
   int r=0;
   /*
   for(x=0;x<3;x++){
      for(y=0;y<3;y++){
         printf("%8.3f ",arr[x*3+y]);
      }
      printf("\n");
   }
   */

   r=ge_fw(&(arr[0]),3,3,&(arrout[0]));
   for(x=0;x<3;x++){
      for(y=0;y<3;y++){
         printf("%8.3f ",arrout[x*3+y]);
      }
      printf("\n");
   }

   return 0;
}

