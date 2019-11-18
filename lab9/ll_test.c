#include <stdio.h>
#include "ll.h"

int main(void) {
   llnode *root = NULL;
   llnode *root2 = NULL;
   int r=0;
   int i=0;

   printf("List A\n");
   r=ll_add_to_tail(&root,100);
   r=ll_add_to_tail(&root,200);
   r=ll_add_to_tail(&root,300);
   for(i=0;i<10;i=i+1){
      r=ll_add_to_tail(&root,i*100);
   }
   r=ll_insert_in_order(&root,543);
   r=ll_print(root);
   r=ll_sort(&root);
   printf("sorted\n");
   r=ll_print(root);
   /* r=ll_free(root);*/

   printf("List B\n");
   root2=NULL;
   r=ll_add_to_tail(&root2,100);
   r=ll_add_to_tail(&root2,200);
   r=ll_add_to_tail(&root2,300);
   for(i=0;i<10;i=i+1){
      r=ll_add_to_head(&root2,i*100);
   }
   r=ll_del_from_tail(&root2);
   r=ll_del_from_head(&root2);
   r=ll_del_by_value(&root2,400);
   r=ll_insert_in_order(&root2,901);
   r=ll_print(root2);
   r=ll_find_by_value(root2, 10);

   printf("concat\n");
   r=ll_concat(&root,&root2);
   r=ll_print(root);
   printf("sort\n");
   r=ll_sort(&root);
   r=ll_print(root);
   printf("%d",r);

   r=ll_free(root);
   
   return 0;
}
