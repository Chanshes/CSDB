#include <stdio.h>

#define MaxSize 50

typedef int ElemType;
//最大长度为50的顺序表
typedef struct Llist{
    ElemType data[MaxSize];
    int length;
}Llist;

//打印数组
int Araay_print(int A[], int n){
    int i;
    printf("{");
    for(i=0;i<n-1;i++)
        printf("%d, ",A[i]);
    printf("%d }",A[i]);
    return i;
}
int Araay_print(Llist L){
    for(int i=0;i<L.length;i++){
        printf("%d\t",L.data[i]);
    }
    printf("\n");
    return L.length;
}
//Llist顺序表转数组
bool excLlisttoArray(Llist L,int A[],int &n){
    n=L.length;
    for(int i=0;i<=L.length;i++){
        A[i]=L.data[i];
    }
    return true;
}
//数组转顺序表Llist
bool excArraytoLlist(Llist &L,int A[],int n){
    L.length=n;
    for(int i=0;i<n;i++){
        L.data[i]=A[i];
    }
    return true;
}

//快排
int Partition(int A[],int low,int high){
    int pivot=A[low];
    while(low<high){
        while(low<high&&A[high]>=pivot) --high;
        A[low]=A[high];
        while(low<high&&A[low]<=pivot) ++low;
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}
void QuickSort(int A[],int low,int high){
    if(low<high){
        int pivotpos=Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}