#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
typedef int KeyType;
typedef struct BSTNode{
    ElemType data;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BiTree;

BSTNode *BST_Search(BiTree T, ElemType key){
    while(T!=NULL&&T->data!=key){
        if(key<T->data) T=T->lchild;
        else T=T->rchild;
    }
    return T;
}

int BST_Insert(BiTree &T, KeyType k){
    if(T==NULL){
        T=(BiTree)malloc(sizeof(BSTNode));
        T->data=k;
        T->lchild=T->rchild=NULL;
        return 1;
    }
    else if(k==T->data)     //树中存在相同关键字的节点
        return 0;
    else if(k<T->data)
        return BST_Insert(T->lchild,k);
    else
        return BST_Insert(T->rchild,k);
}

void Create_BST(BiTree &T,KeyType str[],int n){
    T=NULL;
    int i=0;
    while(i<n){
        BST_Insert(T,str[i]);
        i++;
    }
}

bool Delete_BST(BiTree &T,KeyType k){
    BiTree p,q,s;
    p = BST_Search(T,k);
    if(p==NULL)
        return false;
    if(!p->rchild){
        q = p;
        p = p->lchild;
        free(q);
    }
    else if(!p->lchild){
        q = p;
        p = p->rchild;
        free(q);
    }
    else{
        q = p;
        s = p->lchild;
        while(s->rchild){
            q = s;
            s = s->rchild;
        }
        p->data=s->data;
        if(q!=p)q->rchild=s->rchild;
        else q->lchild = s->lchild;
        free(s);
    }
    return true;
}
