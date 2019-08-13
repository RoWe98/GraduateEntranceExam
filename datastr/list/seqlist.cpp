#include<stdio.h>
#include<malloc.h>

#define InitSize 100

typedef int ElemType;

typedef struct
{
    ElemType *data;
    int MaxSize,length;
}SqList;

bool InitList(SqList *L)
{
    L->data = (int*)malloc(sizeof(ElemType)*InitSize);
    L->length=0;
    L->MaxSize=100;
    return true;
}


bool ListInsert(SqList *L,int i,ElemType e)
{
    if(i<1||i>L->length+1)
        return false;
    if(i>L->MaxSize+1)
        return false;
    for(int j=L->length;j>=i;j--)
    {
        L->data[j]=L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
    return true;
}

void ListOutput(SqList *L)
{
    int i;
    for(i=0;i<L->length;i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}


int main()
{
    SqList L;
    int num =0;
    if(InitList(&L));
        printf("初始化成功！\n");
    printf("input the num under 5:\n");
    for(int i=0;i<5;i++)
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
    return 0;
}
