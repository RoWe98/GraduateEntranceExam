#include<stdio.h>
#include<malloc.h>

#define InitSize 100

typedef int ElemType;

typedef struct
{
    /* data */
    ElemType *data;
    int MaxSize,length;
}SqList;

void InitList(SqList *L)
{
    L->data = (int*)malloc(sizeof(ElemType)*InitSize);
    L->length=0;
    L->MaxSize=100;
}


bool ListInsert(SqList *L,int i,ElemType e)
{
    int j = 0;
    if(i<1||i>L->length+1)
        return false;
    if(i>L->MaxSize+1)
        return false;
    for(j=L->length;j>=i;j--)
    {
        L->data[j]=L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
    return true;
}

bool ListDelete(SqList &L,int i)
{
  int j = 0;
  if(i<1||i>L.length)
    return false;
  for(j=i;j<=L.length-1;j++)
  {
    L.data[j-1]=L.data[j];
  }
  L.length --;
  return true;
}
void ListOutput(SqList *L)
{
    int i=0;
    for(i=0;i<L->length;i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}


int main()
{
    SqList L;
    int i = 0;
    InitList(&L);
    int num =0;
    int locate = 0;
    printf("input the num under 5:\n");
    for(i=0;i<5;i++)
    {
        printf("NUM:");
        scanf("%d",&num);
        if(ListInsert(&L,i+1,num))
        {
            continue;
        }
        else{
            break;
        }
    }
    printf("nums:");
    ListOutput(&L);
    printf("delete num locates:");
    scanf("%d",&locate);
    if(ListDelete(L,locate))
    {
      printf("delete success!\n");
      printf("Nums:\n");
      ListOutput(&L);
    }
    return 0;
}
