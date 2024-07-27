#include "sqlist.h"

/// @brief 删除顺序表 L 中最小值元素节点，并通过引用型参数 value 返回其值
/// @param L 线性表 L
/// @param value 获取被删除元素的值
/// @return 若删除成功则返回 ture，否则返回 false
bool Del_Min(SqList &L, ElemType &value)
{
    if (L.length == 0)
        return false;                   //表空，终止操作并返回
    value = L.data[0];
    int pos = 0;                          //假定0号元素的值最小
    for (int i = 1; i < L.length; i++)        //循环寻找具有最小值的元素
    {
        if (L.data[i] < value)          //让value记忆当前具有最小值的元素
        {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length-1];//空出的位置由最后一个元素填补
    L.length--;
    return true;                        //此时，value即为最小值
}

/// @brief 将顺序表 L 的所有元素逆置
/// @param L 线性表
void Reverse(SqList &L)
{
    ElemType temp;                      //辅助变量
    for (int i = 0; i < L.length/2; i++)
    {
        temp = L.data[i];              //交换L.data[i]与L.data[L.length-i-1]
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
    }
}

/// @brief 删除顺序表 L 中所有值为 x 的数据元素
/// @param L 顺序表
/// @param x 需删除的值
void del_x_1(SqList &L, ElemType x)
{
    int k = 0, i;                       //记录值不等于x的元素个数
    for (i = 0; i<L.length; i++)
        if (L.data[i] != x)
        {
            L.data[k] = L.data[i];
            k++;                        //不等于x的元素增1
        }
    L.length = k;                      //顺序表L的长度等于k
}

/// @brief 删除顺序表 L 中所有值为 x 的数据元素
/// @param L 顺序表
/// @param x 需删除的值
void del_x_2(SqList &L, ElemType x)
{
    int k = 0, i = 0;                   //k记录值等于x的元素个数
    while (i < L.length)
    {
        if (L.data[i] == x)
            k++;
        else
            L.data[i-k] = L.data[i];  //当前元素前移k个位置
        i++;
    }
    L.length = L.length-k;            //顺序表L的长度递减
}
/// @brief 删除顺序表 L 中值在给定值 s 和 t 要求 s<t 之间的所有元素
/// @param L 线性表 L
/// @param s 前缀 s
/// @param t 后缀 t
/// @return 删除完毕返回 true，线性表为空或 s、t 不合法，返回 false
bool Del_s_t(SqList &L,ElemType s, ElemType t)
{
    int i, k = 0;
    if (L.length == 0 || s >= t)
        return false;                   //线性表为空或 s、t 不合法，返回
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] >= s && L.data[i] <= t)
            k++;
        else
            L.data[i-k] = L.data[i];  //当前元素前移k个位置
    }   //for
    L.length -= k;                     //长度减小
    return true;
}
