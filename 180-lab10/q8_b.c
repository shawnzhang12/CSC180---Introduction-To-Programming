#include <q8_a>

int integrate(struct poly** poly){
   if(poly==NULL){return -1;}
   if(*poly==NULL){return -1;}

   while((*poly)->next!=NULL){
      (*poly)->power=(*poly)->power+1;
      (*poly)->coef=(*poly)->coef/(*poly)->power;
   }
   return 0;
}
