#include "SString.h"

int Index(SString S, SString T){
    int i=1,j=1;
    while(i <= S.length && j <= T.length){
        if (S.ch[i]==T.ch[j]){
            ++i; ++j;
        }
        else{
            i=i-j+2; j=1;
        }
        if(j > T.length) return i-T.length;
        else return 0;
    }
}
