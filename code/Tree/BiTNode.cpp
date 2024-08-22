#include "BiTNode.h"
#include <malloc.h>
#include <stdio.h>
#include <iostream>
using namespace std;
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
    T=(BiTNode*)malloc(sizeof(BiTNode));
    return true;
}
//销毁二叉树
bool DestroyBiTree(BiTree &T){
    if(T!=NULL){
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
    }
    free(T);
    ///@issues 释放内存空间后还存在
    T=NULL;
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
//按先序遍历构造二叉树T
bool CreateBiTree(BiTree &T){
    T=(BiTNode*)malloc(sizeof(BiTNode));
    T->lchild=NULL;
    T->rchild=NULL;
    int x=0;
    printf("输入结点：");
    scanf("%d",&x);
    if(x!=0){
        T->data=x;
        printf("输入%d的左孩子：",T->data);
        CreateBiTree(T->lchild);
        printf("输入%d的右孩子：",T->data);
        CreateBiTree(T->rchild);
    }
    return true;
}

//清空树
bool ClearTree(BiTree &T){
    if(T->lchild!=NULL){
        ClearTree(T->lchild);
    }
    else if(T->rchild!=NULL){
        ClearTree(T->rchild);
    }
    else
        free(T);
    return true;
}
//判树空
bool TreeEmpty(BiTree &T){
    if(T!=NULL){
        return false;
    }
    else
        return true;
}
//返回树的深度
///@brief 直接用栈遍历一遍，栈的最大深度即为树深
///@var deep 保留当前树的最大深度 temp当前子树的深度
int TreeDepth(BiTree &T){
    if(T==NULL)
        return 0;
    int deep,temp;


    return ;
}
//输出当前结点值
ElemType visit(BiTree T){
    if(T->data!=0)
        printf("%d\t",T->data);
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
//非递归中序遍历
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
    InitBiTree(T);
    CreateBiTree(T);
    PreOrder(T);
    cout<<DestroyBiTree(T)<<endl;
    PreOrder(T);
    return 0;
}