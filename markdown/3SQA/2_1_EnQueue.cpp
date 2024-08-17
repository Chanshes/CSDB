#define MaxSize 50;

typedef int ElemType;
//添加tag区分队状态
typedef struct{
    ElemType data[MaxSize];
    int front,rear;
    int tag;
}SqQueue;

int EnQueue1(SqQueue &Q,ElemType x){
    if(Q.front==Q.rear&&Q.tag==1)
        return 0;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;
    Q.tag=1;
    return 1;
}
int DeQueue1(SqQueue &Q,ElemType &x){
    if(Q.front==Q.rear&&Q.tag==0)
        return 0;
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
    Q.tag=0;
    return 1;
}
