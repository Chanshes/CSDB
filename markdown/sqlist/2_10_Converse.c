///@brief 将下标为from与to之间的元素逆置
///@param R 操作数组
///@param from 待转换元素的起始位置
///@param to 待转换元素的末尾位置
void Reverse(int R[], int from, int to)
{
    int i, temp;
    for (i = 0; i < (to-from+1)/2; i++)
    {
        temp = R[from+i];
        R[from+i] = R[to-i];
        R[to-i] = temp;
    }
}
///@brief 用p将数组R分割为ab，分别将a、b逆置得到a^(-1)b^(-1)，最后将整个逆置得到ba 
///@param R 数组
///@param n 数组长度
///@param p 分割指针
void Converse(int R[], int n, int p)
{
    Reverse(R,0,p-1);
    Reverse(R,p,n-1);
    Reverse(R,0,n-1);
}