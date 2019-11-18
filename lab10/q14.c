int fibo(int n){
   if(n<0){
      return -1;
   }
   if(n==0){
      return 1;   
   }else if(n==1){
      return 1;
   }else if(n==2){
      return 1;
   }else{
      return fibo(n-1) + fibo(n-2) + fibo(n-3);
   }
}
