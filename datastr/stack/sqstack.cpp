#include "iostream"
#include "stdio.h"
#include "malloc.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType;

typedef struct{
  SElemType *base;
  SElemType *top;
  int stacksize;
}SqStack;

bool InitStack(SqStack &S)
{
  S.base = new int[STACK_INIT_SIZE];
  if(!S.base) return false;
  S.top = S.base;
  S.stacksize = STACK_INIT_SIZE;
  return true;
}

bool Push(SqStack &S, SElemType e)
{
  if(S.top-S.base>=S.stacksize)
  {
    return false;
  }
  if(!S.base) return false;
  *S.top = e;
  S.top ++;
  return true;
}

bool Pop(SqStack &S, SElemType &e)
{
  if(S.top==S.base) return false;
  --S.top;
  e = *S.top;
  std::cout << "pop element:"<<e<<std::endl;
  return true;
}

void Output(SqStack S)
{
  int stack_length = S.top-S.base;
  std::cout<<"stack_length:"<<stack_length<<std::endl;
  while(stack_length!=0){
    int e;
    //std::cout<<"num:"<<e<<std::endl;
    //S.top--;
    if(Pop(S,e)) std::cout<<"success!"<<std::endl;
    stack_length--;
  }
}

int main()
{
  SqStack stack;
  int nums;
  if(InitStack(stack)) std::cout << "stack init Success!"<<std::endl;
  for(int i=0;i<5;i++)
  {
    std::cout<<"input nums:";
    std::cin>>nums;
    if(Push(stack,nums))
      std::cout<<"num added"<<std::endl;
  }
  Output(stack);
  return 0;
}
