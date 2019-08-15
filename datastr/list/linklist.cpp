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

bool creatList_tial(LinkList &L, int n)
{
  int i = 0;
  LNode* p;
  for(i=n;i>0;i--)
  {
    p = (LNode*)malloc(sizeof(LNode));
    printf("num:");
    scanf("%d",&p->data);
    p->next=L->next;
    L->next=p;
  }
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
  LinkList L;
  if(InitList(L))
  {
    std::cout << "Init Success!" << std::endl;
  }
  if(creatList_tial(L,5))
  {
    std::cout << "Insert Success!" << std::endl;
  }
  output(L);
}
