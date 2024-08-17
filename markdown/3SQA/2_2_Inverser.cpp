///@brief 将队列中的元素逆置
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
