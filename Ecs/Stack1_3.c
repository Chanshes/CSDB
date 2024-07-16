#include <stdio.h>
#include <malloc.h>

#define ture 1
#define false 0

typedef int bool;

bool Judge(char A[]){
    int i;
    int j=0,k=0;
    while(A[i]!='\0'){
        switch(A[i]){
            case 'I':j++;break;
            case 'O':k++;
            	if(k>j){printf("序列非法\n");exit(0);}
        }
        i++;
    }
    if(j!=k){
        printf("序列非法\n");
        return false;
    }
    else{
        printf("序列合法\n");
        return ture;
    }
}
