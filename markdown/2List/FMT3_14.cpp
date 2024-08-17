#include <stdio.h>

#define INT_MAX 0x7fffffff

int abs_(int a)             //计算绝对值
{
    if(a < 0) return -a;
    else return a;
}
bool xls_min(int a, int b, int c)   //a是否是三个数中的最小值
{
    if(a <= b && a <= c) return true;
    return false;
}
///@brief 计算三元组中的最小距离
int findMinofTrip(int A[], int n, int B[], int m, int C[], int p)
{
    //D_min用于记录三元组的最小距离，初值赋为INT_MAX
    int i=0,j=0,k=0,D_min=INT_MAX,D;
    while (i<n && j<m && k<p && D_min>0)
    {
        D=abs_(A[i]-B[j])+abs_(B[j]-C[k])+abs_(C[k]-A[i]);//计算D
        if (D<D_min) D_min=D;                   //更新D
        if(xls_min(A[i],B[j],C[k])) i++;        //更新a
        else if (xls_min(B[j],C[k],A[i])) j++;
        else k++;
    }
    return D_min;
}

int main(){
    int S1[]={-1,0,9};
    int S2[]={-25,-10,10,11};
    int S3[]={2,9,17,30,41};
    printf("%d\n",findMinofTrip(S1,3,S2,4,S3,5));
}