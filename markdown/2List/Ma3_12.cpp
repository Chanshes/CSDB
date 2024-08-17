#include <stdio.h>

///@brief 求数组A[]中出现次数大于 数组长度/2 的元素
int Majority(int A[],int n){
    int i,c,count=1;
    c=A[0];
    for(i=1;i<n;i++){
        if(A[i]==c)
            count++;
        else{
            if(count>0)
                count--;
            else{
                c=A[i];
                count=1;
            }
        }
    }
    if(count>0){
        for(i=count=0;i<n;i++)
            if(A[i]==c)
                count++;
    }
    if(count>n/2) return c;
    else return -1;
}

//另解
///@brief 先排序再记大于n/2的元素
//采用快排
int Partition(int A[],int low,int high){
    int pivot=A[low];
    while(low<high){
        while(low<high&&A[high]>=pivot) --high;
        A[low]=A[high];
        while(low<high&&A[low]<=pivot) ++low;
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}
void QuickSort(int A[],int low,int high){
    if(low<high){
        int pivotpos=Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}
//将相同元素最大次数记录到count2，并将该元素的下标存在pos里
int Majority2(int A[],int n){
    QuickSort(A,0,n);
    int count1=1,count2=1,i,pos;
    for(i=0;i<n;i++){
        if(A[i+1]==A[i])
            count1++;
        else{//若count1大于当前记录值则覆盖之前最大记录
            if(count1>count2){
                count2=count1;
                count1=1;
                pos=i-1;
            }
            else{
                count1=1;
            }
        }
    }
    return count2>(n/2)?A[pos]:-1;
}

int main(){
    int A[] = {3,1,3,5,3,4,3};
    printf("Major: %d\n", Majority(A,7));
    printf("Major: %d\n", Majority2(A,7));
    return 0;
}
