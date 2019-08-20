#include "iostream"
#include "malloc.h"
#include "stdio.h"

typedef int SElemType; 

typedef struct StackNode{
  SElemType data;
  struct StackNode *next;
}StackNode,*LinkStack;

bool InitStack(LinkStack &S)
{
  S=NULL;
  return true;
}

bool Push(LinkStack &S,SElemType e){
  StackNode *p = new StackNode;
  if(e!=9999){
    p->data = e;
    p->next = S;
    S = p;
    return true;
  }
  else{
    return false;
  }
}

bool Pop(LinkStack &S,SElemType &e){
  if(S==NULL) return false;
  e = S->data;
  std::cout<<"element:"<<e<<std::endl;
  StackNode *p = S;
  S = S->next;
  delete p;
  return true;
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
    int e;
    if(Pop(S,e)) std::cout<<"success"<<std::endl;
    stacklength--;
  }
}

int main()
{
  LinkStack S;
  int nums;
  if(InitStack(S)) std::cout<<"stack initlize Success!" << std::endl;
  std::cout<<"input the nums ends with 9999"<<std::endl;
  while(nums!=9999){
    std::cout<<"nums:";
    std::cin>>nums;
    if(Push(S,nums))
      std::cout<<"num added"<<std::endl;
  }
  Output(S);
  return 0;
}

