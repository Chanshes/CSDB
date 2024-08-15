#include "linklist.cpp"

///@brief 删除给定值的结点
void Del_X_1(LinkList &L,ElemType x){
    LNode *p=L->next,*pre=L,*q;
    while(p!=NULL){
        if(p->data==x){
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

void Del_X_2(LinkList &L,ElemType x){
    LNode *p=L->next,*r=L,*q;
    while(p->data!=NULL){
        if(p->data!=x){
            r->next=p;
            r=p;
            p=p->next;
        }
        else{
            q=p;
            p=p->next;
            free(q);
        }
    }
    r->next=NULL;
}

int main(){
    LinkList L;
    int x;
    InitList(L);
    List_HeadInsert(L);
    printLink(L);
    printf("\ndel:");
    scanf("%d",&x);
    Del_X_1(L,x);
    printLink(L);
}
