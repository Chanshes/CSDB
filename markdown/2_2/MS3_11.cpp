#include <stdio.h>

///@brief 查找数组A与B有序并集的中位数
int M_Search(int A[], int B[], int n){
    int s1,d1,m1,s2,d2,m2;
    s1=0;d1=n-1;
    s2=1;d2=n-1;
    while(s1!=d1||s2!=d2){
        m1=(s1+d1)/2;
        m2=(s2+d2)/2;
        if(A[m1]==B[m2])
            return A[m1];
        if(A[m1]<B[m2]){
            if((s1+d1)%2==0){
                s1=m1;
                d2=m2;
            }
            else{
                s1=m1+1;
                d2=m2;
            }
        }
        else{
            if((s1+d1)%2==0){
                d1=m1;
                s2=m2;
            }
            else{
                d1=m1;
                s2=m2+1;
            }
        }
    }
    return A[s1]<B[s2]?A[s1]:B[s2];
}

//另解
int Mid_Search(int A[],int B[],int n){
    int i=0,j=0;
    while(i+j<n){
        if(A[i]<B[j])
            i++;
        else
            j++;
    }
    return A[i]<B[j]?A[i]:B[j]; //因为最后比较的元素就是中位数
}

int main(){
    int A[]={1,3,4,7,8};
    int B[]={2,3,7,8,9};
    printf("Mid=%d\n",M_Search(A,B,6));
    printf("Mid=%d\n",Mid_Search(A,B,6));
}