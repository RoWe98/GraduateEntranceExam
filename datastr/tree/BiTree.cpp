#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "malloc.h"

using namespace std;

typedef char TElemType;

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

bool InitBiTree(BiTree &T)
{
	T = new BiTNode;
	T->lchild=NULL;
	T->rchild=NULL;
	return true;
}

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
bool PrintElement(char e){
	cout << e << " ";
	return true;
}

bool PreOrderTraverse(BiTree T)
{
	if(T!=NULL){
		cout<<T->data<<" ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
		return true;
	}else{
		return false;
	}
}

bool InOrderTraverse(BiTree T)
{
	if(T!=NULL){
		InOrderTraverse(T->lchild);
		cout<<T->data<<" ";
		InOrderTraverse(T->rchild);
		return true;
	}else{
		return false;
	}
}

bool PostOrderTraverse(BiTree T)
{
	if(T!=NULL)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data<<" ";
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
	if(PreOrderTraverse(T));
	cout<<endl;
	cout << "InOrderTraverse:";
	if(InOrderTraverse(T));
	cout << endl;
	cout << "PostOrderTraverse:";
	if(PostOrderTraverse(T));
	cout << endl;
	return 0;
}




