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

void InsertSort(SqList &L)
{
  int i,j;
  for(i=2;i<=L.length;++i)
  {
    if(L.r[i].key<L.r[i-1].key){
      L.r[0]=L.r[i];
      for(j=i-1;L.r[0].key<L.r[j].key;--j)
      {
        L.r[j+1]=L.r[j];
      }
      L.r[j+1]=L.r[0];
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
  cout << "now SqList data: "<<endl;
  Output(L);
  InsertSort(L);
  cout << "Current SqList data after InsertSort: "<<endl;
  Output(L);
  return 0;
}
