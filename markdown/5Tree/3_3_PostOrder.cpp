#include "TB.cpp"
#include "Stack.cpp"

void PostOrder(BiTree T){
    InitStack(S);
    BiTNode *p = T;
    BiTNode *r = NULL;
    while(p||!IsEmpty(S)){
        if(p){
            push(S,p);
            p=p->lchild;
        }
        else{
            GetTop(S,p);
            if(p->rchild&&p->rchild!=r)
                p=p->rchild;
            else{
                pop(S,p);
                visit(p->data);
                r=p;
                p=NULL;
            }
        }
    }
}