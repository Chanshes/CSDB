#include <stdio.h>

#define MaxSize 50

typedef int ElemType;
typedef struct Llist{
    ElemType data[MaxSize];
    int length;
}Llist;

int Araay_print(int A[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",A[i]);
    printf("\n");
    return i;
}

bool excLlisttoArray(Llist L,int A[],int &n){
    n=L.length;
    for(int i=0;i<=L.length;i++){
        A[i]=L.data[i];
    }
    return true;
}

bool excArraytoLlist(Llist L,int A[],int n){
    return true;
}

//时间复杂度O(n^2)
bool convers(int A[], int n, int p){
    if(n==0)
        return false;
    int temp;
    for(int i=0;i<p;i++){
        temp=A[(p-i)%n];
        for(int j=0;j<n;j++){
            A[(p-i+j)%n]=A[(p-i+j+1)%n];    //循环顺序表前移一位
        }
        A[(p-i-1)%n]=temp;                  //每次循环将temp插入到左移一位后的空位
    }
    return true;
}

//最优解
bool Reverse(int R[],int n,int from,int to){
    if(n==0)
        return false;
    int i,temp;
    for(i=0;i<(to-from+1)/2;i++){
        temp = R[from+i];
        R[from+i]=R[to-i];
        R[to-i]=temp;
    }
    return true;
}
bool Converse(int R[],int n,int p){
    if(n==0)
        return false;
    Reverse(R,n,0,(p-1)%n);
    Reverse(R,n,p%n,n-1);
    Reverse(R,n,0,n-1);
    return true;
}

//另解
bool converse(int R[],int n,int p){
    int Ar[MaxSize];
    for(int i=0;i<p;i++){
        Ar[i]=R[i];
    }
    for(int i=p;i<n;i++){
        R[i-p]=R[i];
    }
    for(int i=n-p,j=0;i<n&&j<p;i++,j++){
        R[i]=Ar[j];
    }
    return true;
}

int main(){
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    int x,n;
    n=sizeof(A)/sizeof(int);
    printf("%d\n",n);
    scanf("%d",&x);
    converse(A,n,x%n);
    Araay_print(A,n);
    return 0;
}
