#include "sqlist.cpp"
#include <math.h>
#include <ctime>

bool Reverse(SqList &L);
bool BubbleSort(SqList &L);

int main(void)
{
    SqList L;
    InitList(L);
    L.length = 8;
    srand(time(nullptr));
    for(int i=0;i<8;i++)
        L.data[i]=rand()%99;

    OutputDataStream(L);
    BubbleSort(L);
    //Reverse(L);
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

bool BubbleSort(SqList &L){
    ElemType temp;
    for(int i=0;i<L.length-1;i++){
        bool flag=false;
        for(int j=L.length-1;j>i;j--){
            if(L.data[j-1]>L.data[j]){
                temp=L.data[j-1];
                L.data[j-1]=L.data[j];
                L.data[j]=temp;
                flag=true;
            }
        }
        OutputDataStream(L);
        if(flag==false){
            return true;
        }
    }
    return true;
}