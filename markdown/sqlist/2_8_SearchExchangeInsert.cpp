typedef int ElemType;
/// @brief 在表中查找数值为 x 的元素，若找到，则将其与后继元素位置相交换，若找不到，则将其插入表中并使表中元素仍递增有序。
/// @param A 数组
/// @param n 数值长度
/// @param x 查找值
void SearchExchangeInsert(ElemType A[], int n, ElemType x)
{
    int low = 0, high = n-1, mid;           //low 和 high 指向顺序表下界和上界的下标
    int temp;
    while (low <= high)
    {   
        mid = (low+high)/2;                 //找中间位置
        if (A[mid] == x) break;             //找到 x，退出 while 循环
        else if (A[mid] < x) low = mid+1;   //到中点 mid 的右半部去查
        else high = mid-1;                  //到中点 mid 的左半部去查
    }
    if (A[mid] == x && mid != n-1)          //若最后一个元素与x相等，则不存在与其后继交换的操作
    {
        temp = A[mid];
        A[mid] = A[mid+1];
        A[mid+1] = temp;
    }
    if (low > high)                         //查找失败，插入数据元素 x
    {
        for (int i = n-1; i > high; i--)    //后移元素
            A[i+1] = x;                     //插入 x
    }                                       //结束插入
}
