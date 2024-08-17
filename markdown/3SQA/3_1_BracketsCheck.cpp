//括号匹配
bool BracketCheck(char *str){
    InitStack(S);
    int i=0;
    char e;
    while(str[i]!='\0'){
        switch(str[i]){
            //左括号入栈
            case '{': Push(S,'{'); break;
            case '[': Push(S,'['); break;
            case '(': Push(S,'('); break;
            //遇到右括号检测栈顶
            case ')': Pop(S,e);
                if(e!='(') return false;
                break;
            case ']': Pop(S,e);
                if(e!='[') return false;
                break;
            case '}': Pop(S,e);
                if(e!='{') return false;
                break;
            default:break;
        }
        i++;
    }
    if(!IsEmpty(S)){
        printf("括号不匹配\n");
        return false;
    }
    else{
        printf("括号匹配\n");
        return true;
    }
}