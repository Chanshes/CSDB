typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList &L);

int Length(LinkList L);

LNode *GetElem(LinkList L,int i);

LNode *LocateElem(LinkList &L, ElemType e);

bool ListInsert(LinkList &L,int i,ElemType e);

bool ListDelete(LinkList &L,int i,ElemType &e);

LinkList List_HeadInsert(LinkList &L);

LinkList List_TailInsert(LinkList &L);
