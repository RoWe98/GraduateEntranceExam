#include "iostream"
#include "malloc.h"
#include "cstring"

using namespace std;

typedef int KeyType;

typedef struct {
    KeyType key;
}ElemType;

typedef struct BSTNode{
    ElemType data;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//SearchBST
bool SearchBST(BSTree T,KeyType key,BSTree f,BSTree &p)
{
    if(!T){
        p=f;
        return false;
    }
    else if(key==T->data.key){
        p=T;
        return true;
    }
    else if(key<T->data.key){
        return SearchBST(T->lchild,key,T,p);
    }
    else{
        return SearchBST(T->rchild,key,T,p);
    }
}

//Insert BSTree
bool InsertBSTree(BSTree &T,ElemType e)
{
    BSTNode *p;
    BSTNode *s;
    if(!SearchBST(T,e.key,NULL,p)){
        s = new BSTNode;
        s->data=e;
        s->lchild=s->rchild=NULL;
        if(!p){
            T=s;
        }
        else if(e.key<p->data.key){
            p->lchild=s;
        }
        else{
            p->rchild=s;
        }
        return true;
    }
    else{ 
        return false;
    }
}

//Visit()
void Visit(BSTree T){
	    cout << T->data.key << " ";
    
}

// InOrderTraverse
bool InOrderTraverse(BSTree T)
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


int main()
{
    BSTree T;
    ElemType e;

    while(e.key!=999){
        cout << "input:";
        cin >> e.key;
        if(e.key!=999){
            if(InsertBSTree(T,e)){
                cout << "insert Success!" << endl;
            }
        }
        else{
            break;
        }
    }
    cout << "BSTree:"<<endl;
    if(InOrderTraverse(T))
        cout << endl;
    return 0;
}
