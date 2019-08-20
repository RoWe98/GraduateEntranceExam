#include<iostream>
#include<stdio.h>
#include<malloc.h>

typedef int ElemType;

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList &L)
{
  L = new LNode;
  L->next=NULL;
  return true;
}

bool insertList_head(LinkList &L)
{
  int x;
  LNode *p;
  std::cout<<"input the data ends with 9999" << std::endl;
  while(x!=9999)
  {
    p = (LNode*)malloc(sizeof(LNode));
    printf("num:");
    scanf("%d",&x);
    if(x!=9999){
      p->data=x;
    }
    else{
      continue;
    }
    p->next=L->next;
    L->next=p;
  }
  return true;
}

bool insertList_tial(LinkList &L)
{
  int x;
  L = new LNode;
  LNode *s,*r=L;
  std::cout<<"input the data ends with 9999" << std::endl;
  while(x!=9999)
  {
    std::cout<<"nums:";
    scanf("%d",&x);
    s = new LNode;
    if(x!=9999){
      s->data=x;
    }else{
      continue;
    }
    r->next=s;
    r=s;
  }
  r->next=NULL;
  return true;
}

void output(LinkList L)
{
  LinkList p = L->next;
  while(p!=NULL)
  {
    std::cout << p->data << " ";
    p = p->next;
  }
  std::cout << std::endl;
}


int main()
{
  LinkList L1,L2;
  if(InitList(L1))
  {
    std::cout << "Init Success!" << std::endl;
  }
  printf("insert form head\n");
  if(insertList_head(L1))
  {
    std::cout << "Insert Success!" << std::endl;
  }
  output(L1);
  if(InitList(L2))
    std::cout<<"Init Success!" << std::endl;
  printf("insert from tial\n");
  if(insertList_tial(L2))
  {
    std::cout<<"Insert Success!"<<std::endl;
  }
  output(L2);
  return 0;
}
