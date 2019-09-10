#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include "iostream"
#include "malloc.h"
#include "stdio.h"

typedef char SElemType; 

typedef struct StackNode{
  SElemType data;
  struct StackNode *next;
}StackNode,*LinkStack;

void InitStack(LinkStack &S)
{
  S=NULL;
}

void Push(LinkStack &S,SElemType e){
  StackNode *p = new StackNode;
  if(e!=9999){
    p->data = e;
    p->next = S;
    S = p;
  }
}

void Pop(LinkStack &S,SElemType &e){
  e = S->data;
  std::cout<<"element:"<<e<<std::endl;
  StackNode *p = S;
  S = S->next;
  delete p;
}

int GetStackLength(LinkStack &S)
{
  StackNode *p;
  int i = 0;
  p=S;
  while(p){
    i++;
    p=p->next;
  }
  return i;
}

void Output(LinkStack &S){
  int stacklength = GetStackLength(S);
  while(stacklength!=0){
    SElemType e;
    Pop(S,e); std::cout<<"success"<<std::endl;
    stacklength--;
  }
}

bool StackEmpty(LinkStack S)
{
  if(S==NULL) return true;
  else return false;
}

#endif


