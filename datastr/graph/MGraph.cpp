#include "iostream"
#include "queue"
using namespace std;

#define MaxVertexNum 40

typedef char VertexType;
typedef struct{
	VertexType vexs[MaxVertexNum];
	int arcnum;
	int vexnum;
	bool visted[MaxVertexNum];
	int AdjMatrix[MaxVertexNum][MaxVertexNum];
}MGraph;

int LocateVex(MGraph &G, char vertex)
{
	int i;
	int locate=0;
	for (i = 0; i<G.vexnum; i++)
	{
		if (G.vexs[i] == vertex)
		{
			locate = i;
			//cout << i << endl;
		}
	}
	return locate;
}

//Create Graph
void CreateGraph(MGraph &G)
{
	int i, j,k;
	int weight=0;
	char v1;
	char v2; 
	cout << "input vexnum:";
	cin >> G.vexnum;
	cout << "input arcnum:";
	cin >> G.arcnum;
	for (i = 0; i<G.vexnum; i++)
	{
		cout << "input the vertex info:";
		cin >> G.vexs[i];
	}

	for (i = 0; i <G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			G.AdjMatrix[i][j] = 0;
		}
	}

	for (k = 0; k<G.arcnum; k++)
	{
		cout << "first vex and second vex:";
		cin >> v1 >> v2;
		cout << "The weight:";
		cin >> weight;
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		G.AdjMatrix[i][j] = weight;
		G.AdjMatrix[j][i] = weight;
	}
}

void Output(MGraph G)
{
	int i, j;
	for (i = 0; i<G.vexnum; i++)
	{
		for (j = 0; j<G.vexnum; j++)
		{
			cout << G.AdjMatrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void BFST(MGraph G)
{
	int v = 0;
	int i, j;
	cout << G.vexs[v] << " ";
	G.visted[v]=true;
	for(i=1;i<G.vexnum;i++)
	{
		G.visted[i]=false;
	}
	queue<int> Q;
	Q.push(v);
	while (!Q.empty())
	{
		i = Q.front();
		//cout << i << ":" << Q.size()<<endl;
		Q.pop();
		for (j = 0; j < G.vexnum; j++)
		{
			//cout << j<<endl;
			//cout << "G.adjmatrix:"<<G.AdjMatrix[i][j] << endl;
			//cout << "G.visted:"<<G.visted[j]<<endl;
			if (G.AdjMatrix[i][j] != 0 && G.visted[j] == 0)
			{
				G.visted[j] = true;
				//cout << G.AdjMatrix[i][j] << endl;
				//cout << "[i][j]:" << G.AdjMatrix[i][j]<<endl;
                cout << G.vexs[j] << " ";
				Q.push(j);
			}
		}
	}
}

int main()
{
	MGraph G;
	CreateGraph(G);
	Output(G);
	BFST(G);
	return 0;
}

