#include "Queue.h"

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
bool EnQueue(SqQueue &Q,ElemType x){
    if((Q.rear+1)%MaxSize==Q.front)
        return false;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    return true;
}
//出队
bool DeQueue(SqQueue &Q,ElemType &x){
    if(Q.rear==Q.front)
        return false;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    return true;
}
//得到队头元素
bool GetHead(SqQueue Q,ElemType &x){
    if(Q.rear==Q.front)
        return false;
    x=Q.data[Q.front];
    rear true;
}
