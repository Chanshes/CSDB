#include "BiTNode.h"
#include <malloc.h>
#include <stdio.h>

#define MaxSize 50

typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

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

typedef BiTNode* QElemType;
//实例化队列
typedef struct{
    QElemType data[MaxSize];
    int front,rear;
}SqQueue;
//初始化队列
void InitQueue(SqQueue &Q){
    Q.rear=Q.front=0;
}
//判队空
bool IsEmpty(SqQueue Q){
    if(Q.rear==Q.front)
        return true;
    else
        return false;
}
//入队
bool EnQueue(SqQueue &Q,QElemType x){
    if((Q.rear+1)%MaxSize==Q.front)
        return false;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}
//出队
bool DeQueue(SqQueue &Q,QElemType &x){
    if(Q.rear==Q.front)
        return false;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}
//得到队头元素
bool GetHead(SqQueue Q,QElemType &x){
    if(Q.rear==Q.front)
        return false;
    x=Q.data[Q.front];
    return true;
}

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
bool Insertchild(BiTree &T,int chi,ElemType e){
    BiTNode* B=(BiTNode*)malloc(sizeof(BiTNode));
    B->data=e;
    B->lchild=NULL;
    B->rchild=NULL;
    if(chi==0&&T->lchild!=NULL)
        T->lchild=B;
    else if(chi&&T->rchild!=NULL)
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
int BiTreeDepth(BiTree &T){
    if(T==NULL)
        return -1;
    else{
        int l=BiTreeDepth(T->lchild);
        int r=BiTreeDepth(T->rchild);
        return l>r?l+1:r+1;
    }
}


//输出当前结点值
ElemType visit(BiTree T){
    if(T->data!=0)
        printf("%d\t",T->data);
    return T->data;
}
//先序遍历
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
//中序遍历
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
//后序遍历
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}
//非递归中序遍历
void InOrderTraverse(BiTree T){
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
}
//非递归先序遍历
void PreOrderTraverse(BiTree T){
    SqStack S;
    InitStack(S);
    BiTree p=T;
    while(p||!IsEmpty(S)){
        if(p){
            visit(p);
            Push(S,p);
            p=p->lchild;
        }
        else{
            Pop(S,p);
            p=p->rchild;
        }
    }
}
//非递归后续遍历
void PostOrderTraverse(BiTree T){
    SqStack S;
    InitStack(S);
    BiTNode *p=T;
    BiTNode *r=NULL;
    while(p||!IsEmpty(S)){
        if(p){                          //走到最左边
            Push(S,p);
            p=p->lchild;
        }
        else{                           //向右
            GetTop(S,p);                //读栈顶结点（非出栈）
            if(p->rchild&&p->rchild!=r) //若右子树存在，且未被访问过
                p=p->rchild;            //转向右
            else{                       //否则弹出结点并访问
                Pop(S,p);               //将该结点弹出
                visit(p);
                r=p;                    //记录最近访问过的结点
                p=NULL;                 //结点访问完后重置p指针
            }
        }
    }
    //每次出栈访问完一个结点就相当于遍历完以该结点为根的子树，需将p置NULL。
}

//层次遍历
void LevelOrder(BiTree T){
    SqQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!IsEmpty(Q)){             //队列不空则循环
        DeQueue(Q,p);               //队头结点出队
        visit(p);
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);   //若左孩子不空，则左孩子入队
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);   //若右孩子不空，则右孩子入队
    }
}
