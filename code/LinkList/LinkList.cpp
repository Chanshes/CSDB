#include <stdio.h>
#include <malloc.h>
#include "LinkList.h"

bool InitList(LinkList &L){
    if(L!=NULL)
        return false;
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    return true;
}

bool InitList_NoHead(LinkList &L){
    if(L!=NULL)
        return false;
    L=NULL;
    return true;
}

int Length(LinkList L){   
    int len=0;
    LNode *p=L;
    while(p->next!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

int Length_NoHead(LinkList &L){
    int len=0;
    LNode *p=L;
    while(p!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

LNode *GetElem(LinkList L,int i){
    LNode *p=L;
    int j=0;
    while(p!=NULL&&j<i){
        p=p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LinkList &L,ElemType e){
    LNode *p=L->next;
    while(p!=NULL&&p->data!=e){
        p=p->next;
    }
    return p;
}

bool ListInsert(LinkList &L,int i,ElemType e){
    LNode *p=L;
    int j=0;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL)
        return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

bool ListDelete(LinkList &L,int i,ElemType &e){
    LNode *p=L;
    int j=0;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL||p->next==NULL)
        return false;
    LNode *q=p->next;
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}

bool ListDeletep(LinkList &L,LNode* &q){
    LNode *p=L;
    while(p!=NULL&&p->next!=q){
        p=p->next;
    }
    if(p==NULL||p->next==NULL)
        return false;
    LNode *s=q->next;
    p->next=s;
    free(q);
    return true;
}

LinkList List_HeadInsert(LinkList &L){
    LNode *s;int x;
    L=(LNode*)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
}

LinkList List_HeadInsert_NoHead(LinkList &L){
    LNode *s;
    int x;
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L;
        L=s;
        scanf("%d",&x);
    }
    return L;
}

LinkList List_TailInsert(LinkList &L){
    int x;
    L=(LNode*)malloc(sizeof(LNode));
    LNode *s,*r=L;
    scanf("%d",&x);
    while(x!=9999){
        s=(LNode)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}
