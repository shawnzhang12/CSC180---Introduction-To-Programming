float bsqrt(float, float);
float bsqrt(float x, float tol){
   float est = x * 0.5;
   float diff = 0.0;

   while (1){
      if (x - (est*est) <= 0){
         diff = (est*est) - x;
      }else{
         diff = x - (est*est);
      }
      if (diff < tol){
         break;
      }
      est = (est + (x/est))/2;
      }
   return est;
}


