#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "malloc.h"
#include "string.h"

using namespace std;

typedef struct{
	int weight;
	int parent,lch,rch;
}HTNode,*HuffmanTree;

typedef char **HuffmanCode;


void Select(HuffmanTree &HT,int Count,int &s1,int &s2)
{
  unsigned int temp1=0;
  unsigned int temp2=0;
  unsigned int temp3;
  for(int i=1;i<=Count;i++)
  {
    if(HT[i].parent==0)
    {
      if(temp1==0)
      {
        temp1=HT[i].weight;
        (s1)=i;
      }
      else
      {
        if(temp2==0)
        {
          temp2=HT[i].weight;
          (s2)=i;
          if(temp2<temp1)
          {
            temp3=temp2;
            temp2=temp1;
            temp1=temp3;
            temp3=(s2);
            (s2)=(s1);
            (s1)=temp3;
          }
        }
        else
        {
          if(HT[i].weight<temp1)
          {
            temp2=temp1;
            temp1=HT[i].weight;
            (s2)=(s1);
            (s1)=i;
          }
          if(HT[i].weight>temp1&&HT[i].weight<temp2)
          {
            temp2=HT[i].weight;
            (s2)=i;
          }
        }
      }
    }
  }
}

void OutputTree(HuffmanTree HT,int n)
{
	cout << "HT" << "\tweight"<<"\tparent "<<"\tlchild "<<"\trchild"<<endl;
	for(int i=1;i<=2*n-1;i++)
	{
		cout << i <<"\t"<<HT[i].weight<<"\t"<<HT[i].parent<<"\t";
		cout << HT[i].lch <<"\t"<<HT[i].rch<<endl;
	}
}

void CreateHuffmanTree(HuffmanTree &HT,int n,int &S1,int &S2)
{
    int m;
    int i;
    if(n<=1)
    {
		printf("叶子结点不足2个\n");
    	return;
	}
    m=2*n-1;
    HT=new HTNode[m+1];
    for(i=1;i<m;i++)
    {
        HT[i].parent=0;
        HT[i].lch=0;
        HT[i].rch=0;
    }
    for(i=1;i<=n;i++)
    {
        printf("请输入第%d个叶子结点的权值:",i);
        scanf("%d",&HT[i].weight);
    }
    /*初始化结束*/
    for(i=n+1;i<=m;i++)
    {
        Select(HT,i-1,S1,S2);
        HT[S1].parent=i;
        HT[S2].parent=i;
        HT[i].lch=S1;
        HT[i].rch=S2;
        HT[i].weight=HT[S1].weight+HT[S2].weight;
    }
    printf("哈夫曼树创建完成\n");
}

void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{
	int start,c,f;
    char *cd = (char*)malloc(n*sizeof(char));
	HC = new char*[n+1];
	cd[n-1]='\0';
	for(int i=1;i<n;++i)
	{
		start = n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
		{
			if(HT[f].lch==c) cd[--start]='0';
			else cd[--start]='1';
		}
		HC[i]=(char*)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	for(int i =0;i<n;i++)
	{
		cout << HC[i] <<endl;
	}
	free(cd);
}


int main()
{
	int S1,S2;
	int n;
	HuffmanTree HT;
	HuffmanCode HC;
	cout << "input the num of leaf:";
	cin >> n;
	CreateHuffmanTree(HT,n,S1,S2);
	OutputTree(HT,n);
	CreateHuffmanCode(HT,HC,n);
	return 0;
}


