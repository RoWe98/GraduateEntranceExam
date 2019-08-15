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
  S.base = new SElemType;

}
