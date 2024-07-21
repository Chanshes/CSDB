#include "sqlist.h"


/// @brief 删除顺序表L中最小值元素节点，并通过引用型参数value返回其值
/// @param L 线性表L
/// @param value 获取被删除元素的值
/// @return 若删除成功则返回ture，否则返回false
bool Del_Min(Sqlist *L, ElemType *value)
{
    if(L->length==0)
        return false;
    value = L->data[0];
    int pos=0;
    for(int i=1;i<L->length;i++)
    {
        if(l->data)
    }
}