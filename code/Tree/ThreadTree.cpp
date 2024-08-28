#include "ThreadTree.h"

//中序遍历二叉树线索化
void InThread(ThreadTree &p,ThreadTree &pre){
    if(p!=NULL){
        InThread(p->lchild,pre);
        if(p->lchild==NULL){
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre!=NULL&&pre->rchild==NULL){
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        InThread(p->rchild,pre);
    }
}

//通过中序遍历建立中序线索二叉树
void CreateInThread(ThreadTree T){
    ThreadTree pre=NULL;
    if(T!=NULL){
        InThread(T,pre);
        pre->rchild=NULL;
        pre->rtag=1;
    }
}

//线索树中序第一个结点
ThreadNode *Firstnode(ThreadNode *p){
    while(p->ltag==0) p=p->lchild;
    return p;
}
//求结点p在中序序列下的后继
ThreadNode *Nextnode(ThreadNode *p){
    if(p->rtag==0) return Firstnode(p->rchild); //右子树中最左下的结点
    else return p->rchild;                      //若rtag==1则直接返回后继线索
}

//输出当前结点值
ElemType visit(ThreadTree T){
    if(T->data!=0)
        printf("%d\t",T->data);
    return T->data;
}
//不含头结点的中序线索二叉树的中序遍历
void Inorder(ThreadNode *T){
    for(ThreadNode *p=Firstnode(T);p=Nextnode(p))
        visit(p);
}
