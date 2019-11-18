int isPrime(int n);
int isPrimeProduct(int n);

int isPrime(int n){
   int i = 0;
   for(i=1;i<n;i++){
      if(n%i==0){
         return -1;
      }
   }
   return 0;
}

int isPrimeProduct(int n);
   int leftover=0;
   int i=0;
   for(i=0;i<n;i++){
      if(isPrime(i)==0){
         if(n%i==0){
            leftover=n/i;
            if(isPrime(leftover)){
               return 0;
            }
         }
      }
   }
   return -1;
}
