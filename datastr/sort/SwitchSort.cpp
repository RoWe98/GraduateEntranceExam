/*
这里包括交换排序的算法
1.冒泡排序
2.快速排序
*/

#include "iostream"

using namespace std;

#define MAXSIZE 10
typedef int KeyType;
typedef struct{
  KeyType key;
}RedType;

typedef struct{
  RedType r[MAXSIZE+1];
  int length;
}SqList;

void InitSqList(SqList &L)
{
  L.length =0;
}

void CreateSqList(SqList &L)
{
  int i=0;
  for(i=1;i<=MAXSIZE;i++)
  {
    cout << "num:";
    cin >> L.r[i].key;
    L.length++;
  }
}

//Bubble_Sort
void Bubble_Sort(SqList &L)
{
    int m,j,i;
    RedType x;
    for(m=1;m<=L.length-1;m++)
    {
        for(j=1;j<=L.length-m;j++){
            if(L.r[j].key>L.r[j+1].key){
                x=L.r[j];
                L.r[j]=L.r[j+1];
                L.r[j+1]=x;
            }
        }
    }
}

void Output(SqList &L)
{
  int i=0;
  for(i=1;i<=L.length;i++)
  {
    cout << L.r[i].key << " ";
  }
  cout << endl;
}

int main()
{
    SqList L;
    InitSqList(L);
    CreateSqList(L);
    cout << "BubbleSort:"<<endl;
    Output(L);
    Bubble_Sort(L);
    Output(L);
    return 0;
}

