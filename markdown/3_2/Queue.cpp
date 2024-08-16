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

void Inverser(Stack &S,Queue &Q){
    while(!QueueEmpty(Q)){
        x=DeQueue(Q);
        Push(S,x);
    }
    while(!StackEmpty(S)){
        Pop(S,x);
        EnQueue(Q,x);
    }
}
int QueueEmpty(Stack S1,Stack S2){
    if(StackEmpty(S1)&&StackEmpty(S2))
        return 1;
    else
        return 0;
}

int StackOverflow(Stack S){
    if()
}

int EnQueue(Stack &S1,Stack &S2,ElemType e){
    if(!StackOverflow(S1)){
        Push(S1,e);
        return 1;
    }
    if(StackOverflow(S1)&&!StackEmpty(S2)){
        printf("队列满");
        return 0;
    }
    if(StackOverflow(S1)&&StackEmpty(S2)){
        while(!StackEmpty(S1)){
            Pop(S1,x);
            Push(S2,x);
        }
    }
    Push(S1,e);
    return 1;
}

void DeQueue(Stack &S1,Stack &S2,ElemType &x){
    if(!StackEmpty(S2)){
        Pop(S2,x);
    }
    else if(StackEmpty(S1)){
        printf("队列为空");
    }
    else{
        while(!StackEmpty(S1)){
            Pop(S1,x);
            Push(S2,x);
        }
        Pop(S2,x);
    }
}
