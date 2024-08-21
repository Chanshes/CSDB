typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//先序遍历
void PreOrder(BiTree T);
//中序遍历
void InOrder(BiTree T);
//后序遍历
void PostOrder(BiTree T);
