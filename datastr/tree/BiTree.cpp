#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "malloc.h"
#include "queue"

using namespace std;

typedef char TElemType;


//define the BiTNode of the Binary Tree
typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


//InitBiTree
bool InitBiTree(BiTree &T)
{
	T = new BiTNode;
	T->lchild=NULL;
	T->rchild=NULL;
	return true;
}

//CreateBiTree
bool CreateBiTree(BiTree &T)
{
	char ch;
	cin >> ch;
	if(ch=='#'){
		T=NULL;
	}else{
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return true;
}


//Visit()
void Visit(BiTree T){
	cout << T->data << " ";
}

bool PreOrderTraverse(BiTree T)
{
	if(T!=NULL){
		Visit(T);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
		return true;
	}else{
		return false;
	}
}

// InOrderTraverse
bool InOrderTraverse(BiTree T)
{
	if(T!=NULL){
		InOrderTraverse(T->lchild);
		Visit(T);
		InOrderTraverse(T->rchild);
		return true;
	}else{
		return false;
	}
}


//levelOrderTraverse

void levelOrderTraverse(BiTNode *T)
{
  queue<BiTNode *> queue;
  queue.push(T);
  while(!queue.empty()){
	T = queue.front();
    cout<<T->data<<" ";
	queue.pop();
    if(T->lchild!=NULL) queue.push(T->lchild);
    if(T->rchild!=NULL) queue.push(T->rchild);
  }
}

//PostOrderTraverse
bool PostOrderTraverse(BiTree T)
{
	if(T!=NULL)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		Visit(T);
		return true;
	}
	else
	{
		return false;
	}
}

//Depth of BiTree 
int Depth(BiTree T)
{
  if(T==NULL) return 0;
  else{
    int m = Depth(T->lchild);
    int n = Depth(T->rchild);
    if(m>n) return (m+1);
    else return (n+1);
  }
}


//NodeCount 
int NodeCount(BiTree T)
{
  if(T==NULL)
    return 0;
  else{
    return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
  }
}

//LeafCount 
int LeafCount(BiTree T)
{
  if(T==NULL)
    return 0;
  if(T->lchild==NULL&&T->rchild==NULL)
    return 1;
  else{
    return LeafCount(T->lchild)+LeafCount(T->rchild);
  }
}

int DuTwoCount(BiTree T)
{
  int s;
  if(T==NULL) return 0;
  s = (T->lchild!=NULL)&&(T->rchild!=NULL);
  return s+DuTwoCount(T->lchild)+DuTwoCount(T->rchild);
}

int main()
{
	BiTree T;
	int depth=0;
  int nodeCount = 0;
  int leafCount = 0;
  int du2Count=0;
  if(InitBiTree(T)) cout<<"init success!"<<endl;
	cout<<"input:";
	if(CreateBiTree(T)) cout<<"create binary tree success!"<<endl;
  depth = Depth(T);
  nodeCount = NodeCount(T);
  leafCount = LeafCount(T);
  du2Count = DuTwoCount(T);
  cout << "Depth:"<<depth<<" "<<"nodeCount:"<<nodeCount<<" "<<"leafCount:"<<leafCount<<" "<<"du2Count:"<<du2Count<<endl;
	cout << "PreOrderTraverse:";
	if(PreOrderTraverse(T))
	  cout <<endl;
	cout << "InOrderTraverse:";
	if(InOrderTraverse(T))
	  cout << endl;
	cout << "PostOrderTraverse:";
	if(PostOrderTraverse(T))
	  cout << endl;
	cout << "LevelOrderTraverse:";
	levelOrderTraverse(T);
		cout << endl;
	return 0;
}




