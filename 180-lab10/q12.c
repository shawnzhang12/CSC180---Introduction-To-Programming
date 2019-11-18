int histogram(int* n,struct blah* m,int size){
   int i=0;
   int j=0;
   int found=0;
   if(n==NULL){return -1;}
   if(m==NULL){return -1;}
   for(i=0;i<size;i++){
      found=0;
      for(j=0;j<size,j++){
         if((m[j]).valid==1){
            if((m[j]).value==n[j]){
               (m[j]).freq+=1
               found=1;
            }else{
            break;
            }
         }
         if(found==0){
            (m[j]).valid=1;
            (m[j]).value=n[j];
            (m[j]).freq=1;
         }
      }
   }
   return 0;
}
