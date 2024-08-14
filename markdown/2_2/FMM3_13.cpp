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
///@brief 以下是寻常逻辑查找最小未出现的最大正整数,但平均时间复杂度为O｛nlogn｝
//先将数组排序，然后直接查找到未出现的最小正整数
int FindMissMin(int A[],int n){
    QuickSort(A,0,n);   //快速排序
    int i=0,j=1;
    while(i<n){
        if(A[i]<0)
            i++;        //跳过负数
        else if(A[i]==j){
            i++;j++;    //j从1开始往后找
        }
        else
            break;
    }
    return j;
}

int main(){
    int A[] = {1,3,2,6,4,8,-2,-7};
    printf("数组");
    Araay_print(A,8);
    printf("中未出现的最小正整数：%d\n",FindMissMin(A,8));
    return 0;
}
