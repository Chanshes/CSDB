#include "linklist.cpp"
//头插法实现结点逆置
LinkList Reverse_1(LinkList &L){
    LNode *p, *r;
    p=L->next;
    L->next=NULL;
    while(p!=NULL){
        r=p->next;
        p->next=L->next;
        L->next=p;
        p=r;
    }
    return L;
}
//让所有指针逆置，注意头尾结点处理
LinkList Reverse_2(LinkList &L){
    LNode *pre,*p=L->next,*r=p->next;
    p->next=NULL;
    while(r!=NULL){
        pre=p;
        p=r;
        r=r->next;
        p->next=pre;
    }
    L->next=p;
    return L;
}

int main(){
    LinkList L;
    List_HeadInsert(L);
    printLink(L);
    Reverse_2(L);
    printf("\n");
    printLink(L);
    return 0;
}
