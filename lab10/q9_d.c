int fil(float* matrixIn, int rows, int cols, float** matrixOut){
   int i=0;
   int j=0;
   if((matrixIn==NULL) || (matrixOut==NULL)){ 
      return -1;
   }
   *matrixOut=(float*)malloc(rows*cols*sizeof(float));
   for(i=0;i<rows;i++){
      for(j=0;j<cols;j++){
         if(matrixIn[i*cols+j]<0){
            (*matrixOut)[i*cols+j]=0;
         }else{
            (*matrixOut)[i*cols+j]=matrixIn[i*cols+j];
         }
      }
   }
   return 0;
}
