#include "BiTNode.h"
#include <malloc.h>
#include <stdio.h>


#define MaxSize 50
//实例化Stack为存储BiTree指针的栈
typedef  BiTNode* SElemType;
typedef struct{
    SElemType data[MaxSize];
    int top;
}SqStack;
void InitStack(SqStack &S){
    S.top=-1;
}
bool IsEmpty(SqStack S){
    if(S.top==-1)
        return true;
    else
        return false;
}
bool Push(SqStack &S,SElemType x){
    if(S.top==MaxSize-1)
        return false;
    S.data[++S.top]=x;
    return true;
}
bool Pop(SqStack &S, SElemType &x){
    if(S.top==-1)
        return false;
    x=S.data[S.top--];
    return true;
}
bool GetTop(SqStack S,SElemType &x){
    if(S.top==-1)
        return false;
    x=S.data[S.top];
    return true;
}



enum child{lchild,rchild};
//构造空二叉树
bool InitBiTree(BiTree &T){
    if(T==NULL)
        return false;
    T=(BiTNode*)malloc(sizeof(BiTNode))
    return true;
}
//销毁二叉树
bool DestroyBiTree(BiTree &T){
    if(T!=NULL){
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
    }
    return true;
}
//构造二叉树左右子树
bool Insertchild(BiTree &T,child chi,ElemType e){
    BiTNode* B=(BiTNode*)malloc(sizeof(BiTNode));
    B->data=e;
    B->lchild=NULL;
    B->rchild=NULL;
    if(chi==lchild&&T->lchild!=NULL)
        T->lchild=B;
    else if(chi==rchild&&T->rchild!=NULL)
        T->rchild=B;
    else
        return false;   
    return true;
}
//按definition构造二叉树T
bool CreateBiTree(BiTree &T){
    return true;
}

ElemType visit(BiTree T){
    printf("%d",T->data);
    return T->data;
}

void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

bool InOrderTraverse(BiTree T){
    SqStack S;
    InitStack(S);
    BiTree p=T;
    while(p!=NULL||!IsEmpty(S)){
        if(p!=NULL){
            Push(S,p);
            p=p->lchild;
        }
        else{
            Pop(S,p);
            visit(p);
            p=p->rchild;
        }
    }
    return true;
}

int main(){
    BiTree T;
    return 0;
}