#include <stdio.h>

typedef struct{
    ElemType *elem;
    int TableLen;
}SSTable;

int Search_Seq(SSTable ST,ElemType key){
    ST.elem[0]=key;//引入它的目的是使得Search_Seq的循环不必判断数组是否越界
    for(int i=ST.TableLen;ST.elem[i]!=key;--i);
    return i;
}
