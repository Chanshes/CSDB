#include "linklist.cpp"

ElemType min(ElemType e1,ElemType e2){
    return e1<e2?e1:e2;
}
ElemType max(ElemType e1,ElemType e2){
    return e1>e2?e1:e2;
}

void RangeDelete(LinkList &L,ElemType e1,ElemType e2){
    LNode *p=L->next,*pre=p,*q;
    while(p!=NULL){
        if(p->data>min(e1,e2)&&p->data<max(e1,e2)){
            q=p;
            p=p->next;
            pre->next=p;
            free(q);
        }
        else{
            pre=p;
            p=p->next;
        }
    }
}

int main(){
    LinkList L;
    List_HeadInsert(L);
    printLink(L);
    RangeDelete(L,6,2);
    printf("\n");
    printLink(L);
    return 0;
}