typedef int ElemType;
typedef struct{
    ElemType *elem; //动态数组基址
    int TableLen;
}SSTable;

int Search_Seq(SSTable ST,ElemType key){
    int i;
    ST.elem[0]=key; //哨兵
    for(i=ST.TableLen;ST.elem[i]!=key;i--);
    return i;   //查找成功返回数组下标，失败返回0
}