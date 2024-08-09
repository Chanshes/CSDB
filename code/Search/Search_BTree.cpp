#include <stdio.h>

#define m 3         //B-树的阶
typedef int KeyType;
typedef int Record;
typedef struct BTNode{
    int keynum;         //结点中关键字个数，即结点的大小
    struct BTNode *parent;      //指向双亲结点
    KeyType key[m+1];           //关键字向量，0号单元未用
    struct BTNode *ptr[m+1];    //子树指针向量
    Record *recptr[m+1];        //记录指针向量，0号单元未用
}BTNode, *BTree;                //B-树结点和B-树的类型

typedef struct{
    BTNode *pt;                 //指向找到的结点
    int i;                      //1..m，在结点中的关键字序号
    bool tag;                   //true：查找成功
}Result;                        //B-树的查找结果类型

int Search(BTree p,KeyType K)
{
    
}

///@brief 在 m 阶 B-树 T 上查找关键字 K，返回结果(pt,i,tag)
Result Search_BTree(BTree T, KeyType K){
    BTree p = T, q = NULL;
    bool found = false;
    int i=0;
    while(p && !found){
        i=Search(p,K);
        if(i>0 && p->key[i]==K) found = true;
        else{
            q=p;
            p=p->ptr[i];
        }
    }
    if(found) return (p,i,true);
    else return (q,i,false);
}