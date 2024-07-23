///@brief 从前向后扫描数组元素，标记出一个可能成为主元素的元素Num。然后重新计数，确认Num是否是主元素。
///@param A 数组A
///@param n 数组长度
///@return c 确认候选主元素 @return -1 不存在主元素
int Majority(int A[], int n)
{
    int i, c, count=1;              //用c来保存候选主元素，count用来计数
    c = A[0];                       //设置A[0]为候选主元素
    for (i = 1; i < n; i++)         //查找候选主元素
    {
        if (A[i] == c)              //对A中的候选主元素计数
            count++;
        else
        {
            if (count > 0)          //处理不是候选主元素的情况
                count--;
            else                    //更换候选主元素，重新计数
            {
                c = A[i];
                count = 1; 
            }
        }
    }
    if (count > 0)
        for (i = count = 0; i < n; i++) //统计候选主元素的实际出现次数
            if (A[i] == c)
                count++;
    if(count > n/2) return c;       //确认候选主元素
    else return -1;                 //不存在主元素
}
