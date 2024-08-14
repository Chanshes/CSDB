#include <stdio.h>
#include <malloc.h>
#include "pub.cpp"

//初始化数组
void menset(int B[],int e,int n){
    for(int i=0;i<n;i++)
        B[i]=e;
}
//查找未出现的最小正整数
int findMissMin(int A[],int n){
    int i,*B;
    B=(int *)malloc(sizeof(int)*n);
    menset(B,0,n);
    for(i=0;i<n;i++){
        if(A[i]>0&&A[i]<=n)
            B[A[i]-1]=1;
    }  
    for(i=0;i<n;i++)
        if(B[i]==0) break;
    return i+1;
}

int main(){
    int A[] = {1,2,-3,4,5,9,7,8};
    printf("数组");
    Araay_print(A,8);
    printf("中未出现的最小正整数：%d\n",findMissMin(A,8));
    return 0;
}
