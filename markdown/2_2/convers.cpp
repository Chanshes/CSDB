#include <stdio.h>

int size;

int Araay_print(int A[]){
    int i;
    for(i=0;i<size;i++)
        printf("%d\t",A[i]);
    printf("\n");
    return i;
}

//时间复杂度O(n^2)
bool convers(int A[],int p){
    if(size==0)
        return false;
    int temp;
    for(int i=0;i<p;i++){
        temp=A[(p-i)%size];
        Araay_print(A);
        printf("i=%d,temp=%d\n",i,temp);
        for(int j=0;j<size;j++){
            printf("A[%d]=A[%d]\n",(p-i+j)%size,(p-i+j+1)%size);
            A[(p-i+j)%size]=A[(p-i+j+1)%size];  //循环顺序表前移一位
            Araay_print(A);
        }
        A[(p-i-1)%size]=temp;
        printf("\n");
    }
    Araay_print(A);
    return true;
}

bool Reverse(int R[],int from,int to){
    if(size==0)
        return false;
    int i,temp;
    for(i=0;i<(to-from+1)/2;i++){
        temp = R[from+i];
        R[from+i]=R[to-i];
        R[to-i]=temp;
    }
    return true;
}
bool Converse(int R[],int p){
    if(size==0)
        return false;
    Reverse(R,0,(p-1)%size);
    Reverse(R,p%size,size-1);
    Reverse(R,0,size-1);
    return true;
}
//另解
bool converse(int R[],int p){
    int Ar[p];
    for(int i=0;i<p;i++){
        Ar[i]=R[i];
    }
    for(int i=p;i<size;i++){
        R[i-p]=R[i];
    }
    for(int i=size-p,j=0;i<size&&j<p;i++,j++){
        R[i]=Ar[j];
    }
    return true;
}

int main(){
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    int n;
    size=sizeof(A)/sizeof(int);
    printf("%d\n",size);
    scanf("%d",&n);
    converse(A,n%size);
    Araay_print(A);
    return 0;
}
