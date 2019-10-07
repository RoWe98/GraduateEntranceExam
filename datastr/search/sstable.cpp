#include "iostream"
#include "cstring"
#include "cstdio"

using namespace std;
typedef int KeyType;

typedef struct {
  KeyType key;
}ElemType;

typedef struct{
  ElemType *elem;
  int length;
}SSTable;

void InitSSTable(SSTable &ST)
{
  ST.elem = new ElemType[10];
  ST.length=0;
  //return true;
}

void SSTableInsert(SSTable &ST,int i,ElemType e)
{
  for(int j=ST.length;j>=i;j--)
  {
    ST.elem[j].key=ST.elem[j-1].key;
  }
  ST.elem[i-1]=e;
  ST.length++;
}

int Search_Seq(SSTable ST,KeyType key)
{
  int i=0;
  ST.elem[0].key=key;
  for(i=ST.length;ST.elem[i].key!=key;--i);
  return i;
}

int main()
{
  int key=0;
  SSTable ST;
  InitSSTable(ST);
  ElemType e;
  for(int i=1;i<=10;i++)
  {
    cout<<"Num:";
    cin >> e.key;
    SSTableInsert(ST,i+1,e);
  }
  cout << endl;
  for(int i=1;i<=ST.length;i++)
  {
    cout << ST.elem[i].key << " ";
  }
  cout << endl;
  
  cout << "search num:";
  cin >> key;
  int locate = Search_Seq(ST,key);
  cout << "location is:"<<locate<<endl;
  return 0;
}



