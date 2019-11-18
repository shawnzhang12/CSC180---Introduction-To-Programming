#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

/* One of the lessons here is to see that if we want to use a function to malloc something that
 * is a POINTER in the CALLER of the function, then we must send in the ADDRESS of the POINTER
 * to that function.
 * 
 * Recap: if we want to use a function to modify a VARIABLE in the caller
 *        then the CALLER needs to send in the ADDRESS of the VARIABLE
 *
 * Similarly: if we want to use a function to modify a POINTER in the caller
 *            then the CALLER needs to send in the ADDRESS of the POINTER
 *
 * In the code below, ll_add_to_head and ll_add_to_tail are dynamically creating new
 * nodes to be added to the linked list. Any dynamic creation of a node must be via
 * malloc.
 */

int ll_add_to_head( llnode **head, int val) {
    llnode *old_head;
   if (head == NULL) {
      return -1;
   }
	old_head = *head;

   *head = ( llnode *) malloc(sizeof( llnode));
   (*head) -> val = val;
	(*head) -> next = old_head;
	return 0;
}

int ll_add_to_tail( llnode **head, int val) {
   if (head == NULL) {
      return -1;
   }
   if (*head == NULL) {
      *head = ( llnode *) malloc(sizeof( llnode));
      (*head) -> val = val;
      (*head) -> next = NULL;
      return 0;
   } else { /* recursively call ll_add_to_tail until we get to the tail
					which is the point where the pointer is NULL */
      return ll_add_to_tail(&((*head)->next), val);
   }
}

int ll_print( llnode *p) {
   if (p==NULL) {
      return 0;
   } else {
      printf("val = %d\n",p->val);
      return ll_print(p->next);
   }
}

int ll_free( llnode *p) {
   if (p==NULL) {
      return -1;
   } else {
      llnode *f=p->next;
      free(p);
      return ll_free(f);
   }
}

int ll_find_by_value(llnode *pList,int val){
   if(pList==NULL){
      return -1;
   }else if((*pList).val == val){
      return 0;     
   }else{
      return ll_find_by_value((*pList).next,val);
   }
}

int ll_del_from_tail(llnode **ppList){
   if(ppList==NULL){
      return -1;
   }else if(*ppList==NULL){
      return -1;
   }

   if((**ppList).next==NULL){
      free(*ppList);
      *ppList=NULL; 
      return 0;    
   }else{
     return ll_del_from_tail(&((**ppList).next));
   }
}

int ll_del_from_head(llnode **ppList){
   llnode *new_head;
   if(ppList==NULL){
      return -1; 
   }else if(*ppList==NULL){
      return -1;
   }
   new_head=(**ppList).next;
   free(*ppList);
   *ppList=NULL;
   *ppList=new_head;
   return 0;
}

int ll_del_by_value(llnode **ppList,int val){
   llnode *prev; 
   if(ppList==NULL){
      return -1;
   }else if(*ppList==NULL){
      return -1;
   }

   if((**ppList).val==val){
      free(*ppList);
      *ppList=NULL;
      return 0;
   }else if((**ppList).next==NULL){
      return -1;
   }else if((*(**ppList).next).val==val){
      prev=(*(**ppList).next).next;
      free((**ppList).next);
      (**ppList).next=prev;
      return 0;
   }else{
      return ll_del_by_value(&((**ppList).next),val);
   }
}

int ll_insert_in_order(llnode **ppList,int val){
   llnode *new_node;
   llnode *old_head;
   if(ppList==NULL){
      return -1;
   }
   if(*ppList==NULL){
      new_node=(llnode *)malloc(sizeof(llnode));
      (*new_node).next=NULL;
      (*new_node).val=val;
      *ppList=new_node;     
   }
  
   /*Checks if new node is last value*/
   if((val>=(**ppList).val) && (**ppList).next==NULL){
      new_node=(llnode *)malloc(sizeof(llnode));
      (*new_node).next=NULL;
      (*new_node).val=val;
      (**ppList).next=new_node;
      return 0;
   }

   /*Checks if new node is first value*/
   if(val<=(**ppList).val){
      new_node=(llnode *)malloc(sizeof(llnode));
      old_head=*ppList;
      (*new_node).val=val;
      (*new_node).next=old_head;
      *ppList=new_node;
      return 0;
   }

   /*Checks if new node is in between value*/
   if((val>=(**ppList).val) && (val<=(*(**ppList).next).val)){
      new_node=(llnode *)malloc(sizeof(llnode));
      (*new_node).next=(**ppList).next;
      (*new_node).val=val;
      (**ppList).next=new_node;
      return 0;     
   }else{
      return ll_insert_in_order(&((**ppList).next),val); 
   }
}

int ll_concat(llnode **pSrcA,llnode **pSrcB){

   if((pSrcA==NULL) || (pSrcB==NULL)){
      return -1;
   }else if(*pSrcA==NULL){
      *pSrcA=*pSrcB;
      return 0;     
  }

      if((**pSrcA).next==NULL){
         (**pSrcA).next=*pSrcB;
         /* pSrcB=NULL;*/
         return 0;
      }else{
         return ll_concat(&((**pSrcA).next), pSrcB);
   }
}

int ll_sort(llnode **ppList){
   int swapped = 1;
   llnode **chead;
   llnode *ipoint;
   llnode *nx;

   if(ppList==NULL){
      return -1;
   }
   
   while(swapped==1){
      swapped = 0;
      chead = ppList;
      ipoint = *ppList;
      nx = (*ppList)->next;
      while(nx){
         if(ipoint->val>nx->val){
            ipoint->next=nx->next;
            nx->next=ipoint;
            *chead=nx;
            swapped=1;
         }    
         chead=&ipoint->next;
         ipoint=nx;
         nx=nx->next;
      }  
   } 
   return 0;
}
