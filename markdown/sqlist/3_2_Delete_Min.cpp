#include "linklist.cpp"

//删除单链表中值最小的结点
ElemType delete_Min(LinkList &L){
    LNode *p=L->next,*minp=p,*pre=L,*minpre=pre;
    while(p->next!=NULL){
        if(p->next->data<minp->data){
            minp=p->next;
            minpre=p;
        }
        pre=p;
        p=p->next;
    }
    int m=minp->data;
    minpre->next=minp->next;
    free(minp);
    return m;
}
//时间复杂度O（n）
LinkList Delete_Min(LinkList &L){
    LNode *pre=L,*p=pre->next;
    LNode *minpre=pre,*minp=p;  //保存最小值结点及前驱
    while(p!=NULL){
        if(p->data<minp->data){
            minp=p;
            minpre=pre;
        }
        pre=p;
        p=p->next;
    }
    minpre->next=minp->next;
    free(minp);
    return L;
}
//不带头结点的删除
LinkList Delete_Min_NoHead(LinkList &L){
    LNode *pre=L,*p=L;
    LNode *minpre=pre,*minp=p;
    while(p!=NULL){
        if(p->data<minp->data){
            minp=p;
            minpre=pre;
        }
        pre=p;
        p=p->next;
    }
    minpre->next=minp->next;
    free(minp);
    return L;
}

int main(){
    LinkList L;
    List_HeadInsert(L);
    printLink(L);
    while(L->next!=NULL){
        printf("\nmin: %d\n",delete_Min(L));
        printLink(L);
    }
    return 0;
}
