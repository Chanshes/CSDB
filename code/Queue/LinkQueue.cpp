#include <stdio.h>
#include <malloc.h>
#include <LinkQueue.h>

///@brief 初始化带头结点的队列
///@param Q 链式队列
void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next=NULL;
}

void IsEmpty(LinkQueue Q){
    if(Q.front==Q.rear)
        return true;
    else
        return false;
}

void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
}

bool DeQueue(LinkQueue &Q,ElemType x){
    if(Q.front==Q.rear)
        return false;
    LinkNode *p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.rear=Q.front;
    free(p);
    return true;
}
