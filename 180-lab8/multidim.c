#include <stdio.h>

int print2d_2x3(int p[2][3]){
   int x,y;
   for(x=0;x<2;x++){
      for(y=0;y<3;y++){
         printf("%3d ",p[x][y]);
      }
      printf("\n");
   }
   return 0;
}

int print2d_3col(int p[][3], int rows){
   int x,y;
   for (x=0;x<rows;x++){
      for (y=0;y<3;y++){
         printf("%3d ",p[x][y]);
      }
      printf("\n");
   }
   return 0;
}

int print2d(int *p,int rows,int cols){
   int x,y;
   for(x=0;x<rows;x++){
      for(y=0;y<cols;y++){
         printf("%3d ",p[x*cols + y]);
      }
      printf("\n");
   }
   return 0;
}

int print2df(float p[2][3]){
   int x,y;
   for(x=0;x<2;x++){
      for(y=0;y<3;y++){
         printf("%8.3f ",p[x][y]);
      }
      printf("\n");
   }
   return 0;
}

int main(void){
   float arr2df[2][3];
   int arr2d[2][3];
   int x=0, y=0;
   int i=0;
   int r=0;
   float j=1.0;

   for(x=0;x<2;x++){
      for(y=0;y<3;y++){
         arr2d[x][y]=i;
         arr2df[x][y]=j;
         i=i+1;
         j=j+1.50;
      }
   }

   r=print2d_2x3(arr2d);
   r=print2d_3col(arr2d,2);
   r=print2d(&arr2d[0][0],2,3);
   r=print2d((int *)arr2d   ,2,3);
   r=print2df(arr2df);
   return 0;
}
