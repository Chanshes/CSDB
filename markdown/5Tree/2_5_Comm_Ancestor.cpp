/**
*   按顺序存储空节点为0
*/
#include <stdio.h>
#define MAXSIZE 50
typedef int ElemType;

typedef struct SqTree{
    ElemType data[MAXSIZE];
    int length;
}SqTree;

ElemType Comm_Ancestor(SqTree T,int i,int j){
    if(T.data[i]!=0&&T.data[j]!=0){
        while(i!=j){
            if(i>j)
                i=i/2;
            else
                j=j/2;
        }
        return T.data[i];
    }
}

int main(){
    int A[]{1,2,3,4,5,6,0,8,0,10,11,0,13,0,0,0,17,0,0,20,21};
    SqTree T;
    T.length=21;
    int i=0;
    while(i<T.length){
        T.data[i]=A[i++];
    }
    printf("%d\n",Comm_Ancestor(T,17,21));
    return 0;
}