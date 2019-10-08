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
  int maxlen;
}SSTable;

void InitSSTable(SSTable &ST)
{
  int len = 0;
  cout << "length of elem:";
  cin >> len;
  ST.elem = new ElemType[len];
  ST.length=0;
  ST.maxlen = len;
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


// 顺序查找
int Search_Seq(SSTable ST,KeyType key)
{
  int i=0;
  ST.elem[0].key=key;
  for(i=ST.length;ST.elem[i].key!=key;--i);
  return i;
}

//折半查找
int Search_Bin(SSTable ST,KeyType key,int low,int high)
{
  if(low>high) return 0;
  int mid = (low+high)/2;
  if(key==ST.elem[mid].key) return mid;
  else if(key<ST.elem[mid].key){
    Search_Bin(ST,key,low,mid-1);
  }
  else{
    Search_Bin(ST,key,mid+1,high);
  }
}


int main()
{
  int key=0;
  int position=0;
  SSTable ST;
  InitSSTable(ST);
  ElemType e;
  for(int i=1;i<=ST.maxlen;i++)
  {
    cout<<"Num:";
    cin >> e.key;
    SSTableInsert(ST,i+1,e);
  }
  cout << "InistSucess! "<<"length:"<<ST.length<<endl;
  for(int i=1;i<=ST.length;i++)
  {
    cout << ST.elem[i].key << " ";
  }
  cout << endl;
  
  cout << "顺序查找"<<endl;
  cout << "search num:";
  cin >> key;
  int locate = Search_Seq(ST,key);
  cout << "location is:"<<locate<<endl;
  cout << "折半查找" << endl;
  position = Search_Bin(ST,key,1,ST.length);
  if(position==0){
    cout << "Didn't found any elem values "<<key<<endl;
  }else{
    cout << "elem found position is "<<position<<endl;
  }
  return 0;
}


