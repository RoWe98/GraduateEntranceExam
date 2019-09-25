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

bool Create(ALGraph &G)
{
  cin >> G.vexnum >> G.arcnum;
  for(int i=0;i<G.vexnum;++i)
  {
    cin >> G.vertices[i].data;
    G.vertices[i].firstarc=NULL;
  }
  for(int k=0;k<G.arcnum;++k)
  {
    cin >> V1 >> V2;
  }
}
