#include <stdio.h>
#include <string.h>
#include <ctype.h>
int func_l(char *str){
    int count=0;
    while(*str++!='\0'){
        count++;
    }
    return count;
}
char* func_r(char *str){
    int len=func_l(str);char cup;
    for(int i=0;i<len/2;i++){
        cup=str[i];
        str[i]=str[len-1-i];
        str[len-1-i]=cup;
    }
    return str;
}
char* func_u(char *str){
    int count=0;
    while(*str++!='\0'){
        if(count%2==0){
            if (*str >= 'a' && *str <= 'z')
                *str=(char)toupper(*str);
        }
        count++;
    }
    return str;
}
char* func_c(char* str1,char* str2){
    char* ptr = str1 + strlen(str1);
    while (*str2 != '\0') {
        *ptr++ = *str2++;
    }
    *ptr = '\0';
    return str1;
}
char* func_n(char *str){
char s_let[BUFSIZ],s_symb[BUFSIZ],s_numb[BUFSIZ];
int size=func_l(str),j=0,k=0,q=0,t1=0,t2=0;
for(int i=0;i<size;i++){
    if(isalpha(str[i])){
        s_let[j]=str[i];
        j++;
    }
    else if(isdigit(str[i])){
        s_numb[k]=str[i];
        k++;
    }
    else{
        s_symb[q]=str[i];
        q++;
    }
}
for(int e=0;e<k;e++){
    str[e]=s_numb[e];
}
for(int z=k;z<k+j;z++){
    str[z]=s_let[t1];
    t1++;
}
for(int u=k+j;u<k+j+q;u++){
    str[u]=s_symb[t2];
    t2++;
}
return str;
}
int main(int argc,char *argv[]){
char *str1,*str2;
if(argc<3 || argc>4){
    printf("Input error:Please,enter the correct amount of arguments\n");
    return 0;
}
if(argv[1][0]=='-'){
    if(argc==3){
        str1=argv[2];
        if(argv[1][1]=='l'){
            printf("%d",func_l(str1));
        }
        else if(argv[1][1]=='r'){
            func_r(str1);
            printf("%s",str1);
        }
        else if(argv[1][1]=='u'){
            func_u(str1);
            printf("%s",str1);
        }
        else if(argv[1][1]=='n'){
            func_n(str1);
            printf("%s",str1);
        }
        else{
            printf("Input error:Please,enter the correct argument('l','r','u','n')\n");
            return 0;
        }
    }
    else if(argc==4){
    str2=argv[3];
    str1=argv[2];
    if(argv[1][1]=='c'){
        func_c(str1,str2);
        printf("%s",str1);
    }
    else{
        printf("Input error:Please,enter the correct argument('n)\n");
        return 0;
    }
}
}
else{
    printf("Input error:Use the correct first symbol('-')\n");
}
    return 0;
}
