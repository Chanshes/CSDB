#include "seqlist.h"
#include <malloc.h>

SeqList L;                  //声明一个顺序表

void InitList(SeqList *L)
{
    L->data=(ElemType *)malloc(InitSize*sizeof(ElemType));//分配存储空间
    L->length=0;                //顺序表初始长度为0
    L->MaxSize=InitSize;        //初始存储量
}