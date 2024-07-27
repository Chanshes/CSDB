typedef int DataType;

//逆转(aleft,aleft+1,aleft+2...,aright)为(aright,aright-1,...,aleft)
void Reverse(DataType A[], int left, int right, int arraySize)
{
    if (left >= right || right >= arraySize)
        return;
    int mid = (left+right)/2;
    for (int i = 0; i <= mid-left; i++)
    {
        DataType temp = A[left+i];
        A[left+i] = A[right-i];
        A[right-i] = temp;
    }
}

//数组 A[m+n]中，从 0 到 m-1 存放顺序表 (a1, a2, a3,...,am),从 m 到 m+n-1 存放顺序表（b1, b2, b3,...,bn)，算法将这两个表的位置互换
void Exchange(DataType A[], int m, int n, int arraySize)
{
    Reverse(A,0,m+n-1,arraySize);
    Reverse(A,0,n-1,arraySize);
    Reverse(A,n,m+n-1,arraySize);
}