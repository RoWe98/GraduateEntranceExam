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

bool EnQueue(LinkQueue &Q, QElemType e){
  QNode *p = new QNode;
  if(!p) return false;
  if(e!=9999){
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return true;
  }else{
    return false;
  }
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
  int i =0;
  p=Q.front->next;
  while(p){
    i++;
    p=Q.front->next;
  }
  return i;
}

int main()
{
  int i=0;
  int e;
  int nums;
  int Queue_length = 0;
  LinkQueue Q;
  if(InitQueue(Q)) std::cout<<"InitQueue Success!"<<std::endl;
  std::cout<<"Enter the nums Quit with 9999"<<std::endl;
  while(nums!=9999){
    std::cout<<"nums:";
    std::cin>>nums;
    if(EnQueue(Q,nums))
      std::cout<<"Insert Success!"<<std::endl;
  }
  Queue_length = QueueLength(Q);
  std::cout<<"DeQueue info:"<<std::endl;
  for(i=0;i<Queue_length;i++){
    if(DeQueue(Q,e))
      std::cout<<"DeQueue Success!;"<<std::endl;
  }
  return 0;
}
