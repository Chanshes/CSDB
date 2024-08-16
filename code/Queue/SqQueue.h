#define MaxSize 50

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q);

bool IsEmpty(SqQueue Q);

bool EnQueue(SqQueue &Q,ElemType x);

bool DeQueue(SqQueue &Q,ElemType &x);

bool GetHead(SqQueue Q,ElemType &x);