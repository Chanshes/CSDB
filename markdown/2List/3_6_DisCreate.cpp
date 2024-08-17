#include "linklist.cpp"

//分割成两个线性表
LinkList DisCreate_2(LinkList &A){
    LinkList B=(LinkList)malloc(sizeof(LNode));
    B->next=NULL;
    LNode *p=A->next,*q;
    LNode *ra=A;
    while(p!=NULL){
        ra->next=p;ra=p;
        p=p->next;
        if(p!=NULL){
            q=p->next;
            p->next=B->next;
            B->next=p;
            p=q;
        }
    }
    ra->next=NULL;
    return B;
}

int main(){
    LinkList L,R;
    List_HeadInsert(L);
    printLink(L);
    R=DisCreate_2(L);
    printf("\n");
    printLink(L);
    printf("\n");
    printLink(R);
    return 0;
}
