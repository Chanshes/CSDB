#include "seqlist.h"

/// @brief 从有序顺序表中删除所有其值重复的元素
/// @param L 线性表 L
bool Delete_Same(SeqList *L)
{
    if (L->length == 0)
        return false;
    int i, j;                           //i 存储第一个不相同的元素，j 为工作指针
    for (i = 0, j = 1; j < L->length; j++)
        if(L->data[i] != L->data[j])    //查找下一个与上一个元素值不同的元素
            L->data[++i] = L->data[j];  //找到后，将元素前移
    L->length = i+1;
    return true;
}

/// @brief 将两个有序顺序表合并为一个新的有序顺序表
/// @param A 有序顺序表
/// @param B 有序顺序表
/// @param C 新的有序顺序表
/// @return 
bool Merge(SeqList A, SeqList B, SeqList *C)
{
    if (A.length+B.length > C->MaxSize) //大于顺序表的最大长度
        return false;
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length)
    {
        if (A.data[i] <= B.data[j])
            C->data[k++] = A.data[i++];
        else
            C->data[k++] = B.data[j++];
    }
    while (i < A.length)                //还剩一个没有比较完的顺序表
        C->data[k++] = A.data[i++];
    while (j < B.length)
        C->data[k++] = B.data[j++];
    C->length = k;
    return true;    
}
