#include <stdio.h>

int main(){
    char ch[]="aaaaaadaacaaaab";
    int next[16];
    int i=1,j=0;
    next[1]=0;
    while(i<15){
        printf("ch[i:%d]=%c,ch[j:%d]=%c\n",i,ch[i],j,ch[j]);
        if(j==0||ch[i]==ch[j]){
            ++i; ++j;
            printf("++i:%d,++j:%d,next[i]:%c,next[j]:%c\n",i,j,next[i],next[j]);
            if(ch[i]!=ch[j]){
                next[i] = j;
                printf("next[i:%d]=j:%d\n",i,j);
            }
            else{
                next[i]=next[j];
                printf("next[i:%d]=next[j%d]:%d\n",i,j,next[j]);
            }
            
        }
        else{
            printf("else:next[j:%d]:%d\n",j,next[j]);
            j = next[j];
            printf("j = next[j]:%d\n",j);
        }
        for(int n=0;n<=15;n++)
            printf("%d \t",next[n]);
        printf("i:%d over\n\n",i);
    }
    return 0;
}