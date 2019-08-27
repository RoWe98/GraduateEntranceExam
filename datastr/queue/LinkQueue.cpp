#include "stdio.h"
#include "iostream"
#include "malloc.h"

typedef int QElemType;

typedef struct QNode{
  QElemType data;
  struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
  QueuePtr front;
  QueuePtr rear;
}LinkQueue;

bool InitQueue(LinkQueue &Q){
  Q.front = Q.rear = new QNode;
  if(!Q.front) return false;
  Q.front->next = NULL;
  return true;
}

bool Destroy(LinkQueue Q)
{
  while(Q.front){
    Q.rear = Q.front->next;
    delete Q.front;
    Q.front = Q.rear;
  }
  return true;
}

bool EnQueue(LinkQueue &Q){
  QNode *p = new QNode;
  int e=0;
  if(!p) return false;
  std::cout<<"nums:";
  while(std::cin>>e&&e!=9999){
    std::cout<<"nums:";
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
  }
  return true;
}

bool DeQueue(LinkQueue Q,QElemType &e){
  if(Q.front == Q.rear) return false;
  QNode *p = Q.front->next;
  e = p->data;
  std::cout<<"DeQueue element:"<<e<<std::endl;
  Q.front->next = p->next;
  if(Q.rear==p) Q.rear = Q.front;
  delete p;
  return true;
}


int QueueLength(LinkQueue Q){
  QNode *p;
  std::cout<<1<<std::endl;
  int i =0;
  int e = Q.front->next->data;
  p=Q.front->next->data;
  std::cout<<Q.rear->next;
  while(!p){
    i++;
    p=Q.front->next->data;
    std::cout<<i<<std::endl;
  }
  return i;
}

int main()
{
  int i=0;
  int e;
  int Queue_length = 0;
  LinkQueue Q;
  if(InitQueue(Q)) std::cout<<"InitQueue Success!"<<std::endl;
  std::cout<<"Enter the nums Quit with 9999"<<std::endl;
  if(EnQueue(Q)) 
    std::cout<<"insert success!"<<std::endl;
  Queue_length= QueueLength(Q);
  std::cout<<Queue_length<<std::endl;
  std::cout<<"DeQueue info:"<<std::endl;
  for(i=0;i<Queue_length;i++){
    if(DeQueue(Q,e))
      std::cout<<"DeQueue Success!;"<<std::endl;
  }
  return 0;
}
