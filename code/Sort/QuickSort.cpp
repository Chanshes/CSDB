#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Maxsize 100

long Partition(int A[],long low,long high){
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

void QuickSort(int A[],long low,long high){
    if(low<high){
        long pivotpos=Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}

long partition(int A[],long low,long high){
    int pivot=A[low];
    while(low<high){
        while(low<high&&A[high]>=pivot) --high;
        A[low++]=A[high];
        while(low<high&&A[low]<=pivot) ++low;
        A[high--]=A[low];
    }
    A[low]=pivot;
    return low;
}

void quicksort(int A[],long low,long high){
    if(low<high){
        long pivotpos=partition(A,low,high);
        quicksort(A,low,pivotpos-1);
        quicksort(A,pivotpos+1,high);
    }
}

void array_print(int A[],long n){
    for(long i=0;i<n;i++){
        printf("%d  ",A[i]);
    }
}

int main(){
    int A[Maxsize],B[Maxsize];
    long n=Maxsize;
    for(long i=0;i<n;i++){
        A[i]=rand()%100;
        B[i]=A[i];
    }
    clock_t time1=clock();
    QuickSort(A,0,n);
    clock_t time2=clock();
    printf("\n%ld\n",time2-time1);
    clock_t time3=clock();
    quicksort(B,0,n);
    clock_t time4=clock();
    printf("\n%ld\n",time4-time3);
    array_print(A,n);
    return 0;
}