#include "sqlist.h"

SqList L;                   //声明一个顺序表

//顺序表的初始化
void InitList(SqList &L)
{
    L.length = 0;             //顺序表初始长度为0
}

/// @brief 插入操作 在顺序表L的第i（1<=i<=L.length+1）个位置插入新元素e。若i的输入不合法，则返回false，表示插入失败；
/// 否者，将第i个元素及其后的所有元素依次往后移动一个位置，腾出一个空位置插入新元素e，顺序表长度增加1，插入成功，返回true。
/// @param L 顺序表L
/// @param i 第i个位置
/// @param e 插入新元素e
/// @return 若i的输入不合法，则返回false；插入成功，返回true
bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length+1)          //判断i的范围是否有效
        return false;
    if (L.length >= MaxSize)          //当前存储空间已满，不能插入
        return false;
    for (int j = L.length; j >= i; j--)   //将第i个元素及之后的元素后移
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;                 //在位置i处放入e
    L.length++;                    //线性表长度加1
    return true;
}

/// @brief 删除操作 删除顺序表L中第i（1<=i<=L.length）个位置的元素，用引用变量e返回。若i的输入不合法，则返回false；
/// 否者，将被删除的元素赋给引用变量e，并将第i+1个元素及其后的所有元素依次往前移动一个位置，返回true。
/// @param L 
/// @param i 
/// @param e 
/// @return 若i的输入不合法，则返回false；删除成功，返回true
bool ListDelete(SqList &L,int i,ElemType &e)
{
    if (i < 1 || i > L.length)            //判断i的范围是否有效
        return false;
    e = L.data[i-1];                 //将被删除的元素赋值给e
    for (int j = i; j < L.length; j++)    //将第i个位置后的元素前移
        L.data[j-1] = L.data[j];
    L.length--;                //线性表长度减1
    return true;
}
/// @brief 按值查找（顺序查找） 在顺序表L中查找第一个元素值等于e的元素，并返回其位序。
/// @param L 
/// @param e 
/// @return 下标为i的元素值等于e，返回其位序i+1
int LocateElem(SqList L, ElemType e)
{
    int i;
    for (i=0; i < L.length; i++)
        if (L.data[i] == e)
            return i+1;         //下标为i的元素值等于e，返回其位序i+1
    return 0;                   //退出循环，说明查找失败
}