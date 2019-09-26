#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "malloc.h"

using namespace std;

#define MAX_VERTEX_NUM 20

typedef int InfoType;
typedef char VertexType;

typedef struct ArcNode{
  int adjvex;
  struct ArcNode *nextarc;
  InfoType *info;
}ArcNode;

typedef struct VNode{
 VertexType data;
 ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct{
  AdjList vertices;
  int vexnum,arcnum;
  int kind;
}ALGraph;

int LocateVex(ALGraph G,char vetex)
{
  int locate;
  for(int i=0;i<G.vexnum;++i)
  {
    if(vetex==G.vertices[i].data)
      locate = i;
    else 
      continue;
  }
  return locate;
}

bool Create(ALGraph &G)
{
  char V1,V2;
  cout << "input the vexnum and arcnum:";
  cin >> G.vexnum >> G.arcnum;
  for(int i=0;i<G.vexnum;++i)
  {
    cout << "input the data of vex:";
    cin >> G.vertices[i].data;
    G.vertices[i].firstarc=NULL;
    cout << endl;
  }
  for(int k=0;k<G.arcnum;++k)
  {
    cout << "input the info the vetex:";
    cin >> V1 >> V2;
    int i = LocateVex(G,V1);
    int j = LocateVex(G,V2);
    ArcNode *p1 = new ArcNode;
    p1->adjvex=j;
    p1->nextarc = G.vertices[i].firstarc;
    G.vertices[i].firstarc=p1;
    cout << endl;
  }
  return true;
}



int main()
{
  ALGraph G;
  if(Create(G))
    cout << "create graph success!" << endl;
  return 0;
}

