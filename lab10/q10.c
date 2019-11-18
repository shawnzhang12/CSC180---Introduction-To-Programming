int nsum(float* a, float* b, int n, float** output){
   int i=0;
   if(output==NULL){return -1;}
   if(a==NULL){return -1;}
   if(b==NULL){return -1;}

   *output=(float*)malloc(n*sizeof(float));
   if(output==NULL){return -1;}

   for(i=0;i<n;i++){
      (*output)[i]= a[i]+ b[i];
   } 
   return 0;
}
