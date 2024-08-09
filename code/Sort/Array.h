#include <stdio.h>

typedef int ElemType;

void showArray(ElemType A[],int n)
{
    for(int i=0;i<=n;i++)
        printf("%d\t",A[i]);
    printf("\n");
}
