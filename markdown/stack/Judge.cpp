bool Judge(char []){
    int i=0;
    int j=k=0;
    while(A[i]!='\0'){
        switch(A[i]){
            case 'I': j++; break;
            case 'O': k++;
                if(k>j){
                    printf("序列非法\n");exit(0);
                }
        }
        i++;
    }
    if(j!=k){
        printf("序列非法\n");
        return false;
    }
    else{
        printf("序列合法\n");
        return true;
    }
}
