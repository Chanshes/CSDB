#include "sqlist.cpp"

bool Del_Min(SqList &L, ElemType &temp);

int main(void)
{
    SqList L;
    InitList(L);
    L.length = 5;
    L.data[0] = 8;
    L.data[1] = 1;
    L.data[2] = 2;
    L.data[3] = 3;
    L.data[4] = 5;
    ListInsert(L,5,2);
    OutputDataStream(L);
    printf("\n");
    ElemType e;
    for(int i=0;i<=6;i++)
    {
        if(Del_Min(L,e))
            printf("Min: %d\n",e);
        else
            printf("L is NULL!\n");
        OutputDataStream(L);
        printf("\n\n");
    }
    return 0;
}

bool Del_Min(SqList &L, ElemType &value)
{
    if(L.length==0)
        return false;
    value = L.data[0];
    int pos = 0;
    for(int i=1;i<L.length;i++)
    {
        if(L.data[i]<value)
        {
            value=L.data[i];
            pos=i;
        }
    }
    L.data[pos] = L.data[L.length-1];
    L.length--;
    return true;
}