/*由于队列的顺序存储会导致最后不允许
  存储新的元素，会导致数组越界
  但是这种情况又不可以向链表的顺序存储那样扩大存储空间
  所以队列的顺序存储我们一般使用循环队列
*/

#include "iostream"
#include "stdio.h"
#include "malloc.h"


#define MAXQSIZE 100
typedef int QElemType;

typedef struct{
  QElemType *base;
  int front;
  int rear;
}SqQueue;

bool InitQueue(SqQueue &Q)
{
  Q.base = new QElemType[MAXQSIZE];
  if(!Q.base) return false;
  Q.front = Q.rear = 0;
  return true;
}

int QueueLength(SqQueue Q)
{
  return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

bool EnQueue(SqQueue &Q, QElemType e)
{
  if((Q.rear+1) % MAXQSIZE == Q.front) return false;
  if(e!=9999){
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXQSIZE;
  }
  return true;
}

bool DeQueue(SqQueue &Q,QElemType &e)
{
  if(Q.front == Q.rear) return false;
  e = Q.base[Q.front];
  std::cout<<"DeQueue num:"<<e<<std::endl;
  Q.front = (Q.front+1) % MAXQSIZE;
  return true;
}



int main()
{
  SqQueue Q;
  int nums = 0;
  int e;
  int queue_length = 0;
  if(InitQueue(Q))
    std::cout<<"Queue init success!" << std::endl;
  
  std::cout<<"Enter the number.Quit with 9999"<<std::endl;
  while(nums!=9999)
  {
    std::cout<<"nums:";
    std::cin>>nums;
    if(EnQueue(Q,nums)) std::cout<<"insert success!"<<std::endl;
  }
  queue_length = QueueLength(Q);
  for(int i=0;i<queue_length;i++)
  {
    if(DeQueue(Q,e)) std::cout<<"DeQueue Success!" << std::endl;
  }
  return 0;
}

