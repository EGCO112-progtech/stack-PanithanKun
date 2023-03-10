#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include "stack.h"

int main(int argc, char **argv){
  
  int i,N,j,*a;
  NodePtr top=NULL;
 
/*  for(i=1;i<argc;i++){
      push(&top,atoi(argv[i]));
    }
    while(top){
      printf("Remove %d\n",pop(&top));
     }*/

 Stack s;
  s.top=NULL;
  s.size=0;
 //printf("Checking the parentheses in argv arguments\n");
   
  for(i=1;i<argc;i++){
     int Error=0;
     int Count=0;
    for(j=0;j<strlen(argv[i]); j++)
      {
        switch(argv[i][j])
          {
            case '{':
            case '[':  
              push(&s,argv[i][j]);
              Count++;
              break;
            case '}':
              Count--;
            if(pop(&s)!='{')
            {
               Error=1;
               
            }
            break;
            case ']':
              Count--;
            if(pop(&s)!='[')
            {
               Error=1;
               
            }
            break;
          }
        if(Error==1) break;
      }
    if(Count>0)
    {
    printf("argv %d incorrect: too many open parenthesis!\n",i);
    }else if(Count<0)
    {
    printf("argv %d incorrect: too many closed parenthesis!\n",i);
    }else if(Error==0 && Count==0){
      printf("argv %d Correct!\n",i);
    }else if(Error==1 && Count==0){
      printf("argv %d incorrect: mismatch!\n",i);
    }
    pop_all(&s);
  }
   return 0;
}
