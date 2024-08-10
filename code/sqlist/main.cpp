#include "sqlist.cpp"

bool Reverse(SqList &L);

int main(void)
{
    SqList L;
    InitList(L);
    L.length = 7;
    L.data[0] = 81;
    L.data[1] = 15;
    L.data[2] = 27;
    L.data[3] = 34;
    L.data[4] = 58;
    L.data[5] = 13;
    L.data[6] = 75;
    OutputDataStream(L);

    Reverse(L);
    OutputDataStream(L);

    return 0;
}

bool Reverse(SqList &L){
    if(!L.length)
        return false;
    ElemType temp;
    int i=0;
    for(i=0;i<L.length/2;i++){
        temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
    }
    return true;
}