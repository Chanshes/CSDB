#include "SString.h"
#include <stdio.h>

int get_length(SString &T){
    int length=0;
    while(T.ch[length++]!='\0');
    T.length=length-1;
    return T.length;
}

void get_next(SString T, int next[]){
    int i=1,j=0;
    next[1]=0;
    while(i<T.length){
        if(j==0||T.ch[i]==T.ch[j]){
            i++;j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}

void get_nextval(SString T,int nextval[]){
    int i=1,j=0;
    nextval[1]=0;
    while(i<T.length){
        if(j==0||T.ch[i]==T.ch[j]){
            i++;j++;
            if(T.ch[i]!=T.ch[j])
                nextval[i]=j;
            else
                nextval[i]=nextval[j];
        }
        else
            j=nextval[j];
    }
}

///@param n返回匹配成功的位置
bool KMP_All(SString T,SString S,int n[]){
    return true;
}

int main(){
    SString T={"abcbbcabcbcabca"},S={"abc"};
    int n = get_length(T);
    for(int i=1;i<n;i++){
        printf("%c\t",T.ch[i]);
    }
    return 0;
}