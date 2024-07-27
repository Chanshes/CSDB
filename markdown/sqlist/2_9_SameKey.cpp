//使用三个下标变量从小到大遍历数组。当三个下标变量指向的元素相等时，输出并向前推进指针，
//否则仅移动小于最大元素的下标变量，直到某个下标变量移除数组范围，即可停止。
#include <stdio.h>
#include <math.h>

void samekey(int A[], int B[], int C[])
{
    int i=0,j=0,k=0;                    //定义三个工作指针
    int n = min(min(sizeof(A)/4,sizeof(B)/4),sizeof(C)/4);
    while (i < n && j < n && k < n)     //相同则输出，并集体后移
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            printf("%d\n", A[i]);
            i++;j++;k++;
        }
        else
        {
            int maxNum=max(A[i],max(B[j],C[k]));
            if (A[i] < maxNum) i++;
            if (B[j] < maxNum) j++;
            if (C[k] < maxNum) k++;
        }
    }
}

int min(int A, int B)
{
    return A < B ? A : B;
}

int max(int A, int B)
{
    return A > B ? A : B;
}