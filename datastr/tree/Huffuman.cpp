#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "malloc.h"

using namespace std;

typedef struct{
	int weight;
	int parent,lch,rch;
}HTNode,*HuffmanTree;


void Select(HuffmanTree &HT,int m,int &S1,int &S2)
{
	int j;
	S1=0;
	S2=0;
	for(j=1;j<=m;j++)
	{
		while(HT[j].parent==0)
		{
			if(HT[j].weight<HT[S1].weight)
			{	
				S1=j;
				cout << S1 << endl;
			}
		}
	}

	for(j=1;j<=m;j++)
	{
		while(HT[j].parent==0&&j!=S1)
		{
			if(HT[j].weight<HT[S2].weight)
			{	
				S2=j;
				cout << S2 << endl;
			}
		}
	}
}

void CreateHuffmanTree(HuffmanTree &HT,int n,int &S1,int &S2)
{
	if(n<=1) 
	{
		cout << "leafs less than 2!" << endl;
		return;
	}
	int i = 0;
	int m=2*n-1;
	HT = new HTNode[m+1];
	for(i = 1;i<m;i++)
	{
		HT[i].lch=0;
		HT[i].rch=0;
		HT[i].parent=0;
	}

	for(i=1;i<=n;i++)
	{
		cout << "Please input the "<<i<<" leaf's weight:";
		cin >> HT[i].weight;
		cout << HT[i].weight<<endl;
	}
	cout<<1;
	for(i=n+1;i<=m;i++)
	{
		cout<<1;
		Select(HT,i-1,S1,S2);
		HT[S1].parent=i;
		HT[S2].parent=i;
		HT[i].lch=S1;
		HT[i].rch=S2;
		HT[i].weight=HT[S1].weight+HT[S2].weight;
	}
	cout << "Huffman Tree build success!"<<endl;
}

int main()
{
	int S1,S2;
	int n;
	HuffmanTree HT;
	cout << "input the num of leaf:";
	cin >> n;
	CreateHuffmanTree(HT,n,S1,S2);
	return 0;
}


