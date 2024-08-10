typedef struct{
    ElemType data[MaxSize];
    int top;
}SeqStack;

void InitStack(SqStack &S);

bool StackEmpty(SqStack S);

bool Push(SqStack &S, ElemType x);

bool Pop(SqStack &S,ElemType &x);

bool GetTop(SqStack S,ElemType &x);