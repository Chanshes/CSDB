//静态分配
#include <stdio.h>

#define MaxSize 50              //定义线性表的最大长度
typedef int ElemType;

//静态分配的顺序表存储结构
typedef struct 
{
    ElemType data[MaxSize];     //顺序表的元素
    int length;                 //顺序表的当前长度
} SqList;                        //顺序表的类型定义

//初始化表。构造一个空的线性表。
void InitList(SqList &L);
//求表长。返回线性表L的长度，即L中数据元素的个数。
int Length(SqList L);
//按值查找操作。在表L中查找具有给定关键字值的元素。
int LocateElem(SqList L, ElemType e);
//按位查找操作。获取表L中第i个位置的元素的值。
ElemType GetElem(SqList &L, int i);
//插入操作。在表L中的第i个位置上插入指定的元素e。
bool ListInsert(SqList &L, int i, ElemType e);
//删除操作。删除表L中的第i个位置的元素，并用e返回删除元素的值。
bool ListDelete(SqList &L, int i, ElemType &e);
//输出操作。按前后顺序输出线性表L的所有元素值。
void PrintList(SqList L);
//判空操作。若L为空表，则返回ture，否者返回false
bool Empty(SqList L);
//销毁操作。销毁线性表，并释放线性表L所占用的内存空间。
void DestroyList(SqList L);
