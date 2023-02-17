
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value)
{
NodePtr new_node=(NodePtr)malloc(sizeof(Node));
  if(new_node){
    value = new_node->data;
    new_node->nextPtr=s->top;
    s->top=new_node;
    s->size=s->size+1;
  }
}
char pop(StackPtr s)
{
  char Value;
  NodePtr t = s->top;
  if((s->size)>0){ 
   Value=t->data;
    s->top = t->nextPtr;
    (s->size)--;
   free(t);
  return Value;  
  }
}
void pop_all(StackPtr s){
while(s->top!=NULL){
  char Value;
  NodePtr t = s->top;
  if((s->size)>0){ 
   Value = t->data;
    s->top = t->nextPtr;
    (s->size)--;
    free(t);
    }
  }
}
#endif
