/*
这里包括交换排序的算法
1.简单选择排序
2.堆排序
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

typedef SqList HeapType;

//整理堆
void HeapAdjust(HeapType &H,int s,int m)
{
    int j;
    RedType rc=H.r[s];
    for(j=2*s;j<=m;j*=2){
        if(j<m&&H.r[j].key<H.r[j+1].key) ++j;
        if(rc.key>H.r[j].key) break;
        H.r[s]=H.r[j];s=j;
    }
    H.r[s]=rc;
}

//HeapSort
void HeapSort(HeapType &H)
{
    int i;
    RedType x;
    for(i=H.length/2;i>0;--i)
    {
        HeapAdjust(H,i,H.length);
    }
    for(i=H.length;i>1;--i)
    {
        x=H.r[1];
        H.r[1]=H.r[i];
        H.r[i]=x;
        HeapAdjust(H,1,i-1);
    }
}


//直接选择排序
void SelectSort(SqList &L)
{
    int i,k,j;
    RedType x;
    for(i=1;i<L.length;++i){
        k=i;
        for(j=j+1;j<=L.length;j++){
            if(L.r[j].key<L.r[k].key) k=j;
        }
        if(k!=i){
            x=L.r[k];
            L.r[k]=L.r[i];
            L.r[i]=x;
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
    HeapType H;
    InitSqList(H);
    CreateSqList(H);
    cout << "HeapSort:"<<endl;
    HeapSort(H);
    Output(H);
    cout << "SelectSort:"<<endl;
    SelectSort(H);
    Output(H);
    return 0;
}