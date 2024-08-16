typedef int ElemType;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

//初始化队列
void InitQueue(LinkQueue &Q);
//判队空
bool IsEmpty(LinkQueue Q);
//入队
bool EnQueue(LinkQueue &Q,ElemType x);
//出队
bool DeQueue(LinkQueue &Q,ElemType x);
