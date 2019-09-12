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


int main()
{
	BiTree T;
	if(InitBiTree(T)) cout<<"init success!"<<endl;
	cout<<"input:";
	if(CreateBiTree(T)) cout<<"create binary tree success!"<<endl;
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




