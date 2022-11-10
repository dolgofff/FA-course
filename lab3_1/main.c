#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
enum error{
    SUCCESS=1,
    TYPE_ERROR=-2,
    VALUE_ERROR=-3,
    MEMORY_ERROR=-4,
    EXC=-5
};
int bit_sum(int a, int b){
    int res = 0,per = 0;
    res = a ^ b;
    per = (a & b) << 1;
    while (per) {
        int tmp = res;
        res = res ^ per;
        per = (tmp & per) << 1;
    }
    return res;
}
int difference(int a, int b) {
    return bit_sum(a, bit_sum(~b, 1));
}
int amo(int n, int osn){
    int res = 0;
    while(n>0){
        res = bit_sum(res, 1);
        n>>=osn;
    }
    return res;
}
int decimal_to_other(char **final,int n,int r){
char alphabet[]="0123456789ABCDEFGHIJKLMNOPQRSTUV";
int sign=0,ostatok,base[]={0,1,3,7,15,31};
if(n==0)
    return EXC;
if(n<0) {
    sign = 1;
    n = bit_sum(~n,1);
}
int cur_size = amo(n,r);
if(sign)
    cur_size = bit_sum(cur_size,2);
else
    cur_size = bit_sum(cur_size,1);
*final = (char*)calloc(cur_size, sizeof(char));
if(!*final)
    return MEMORY_ERROR;
int length = difference(cur_size,2);
if(sign)
    (*final)[0] = '-';
while(n!=0){
    ostatok = n & base[r];
    (*final)[length] = alphabet[ostatok];
    length = difference(length, 1);
    n = n>>r;
}
    (*final)[difference(cur_size,1)] = '\0';
return SUCCESS;
}

int main(){
    int degree,num=0,res;
    printf("Welcome!\n");
    printf("Please,enter the degree which belongs to the interval [1;5].\n");
    if(scanf("%d",&degree)!=1){
        printf("Input error:Please,enter the integer value!\n");
        return TYPE_ERROR;
    }
    if(degree<1 || degree>5){
        printf("Input error:Your degree does not belong to the interval[1;5].\n");
        return VALUE_ERROR;
    }

    printf("Please,enter the number which you would like to traverse.\n");
    if(scanf("%d",&num)!=1){
        printf("Input error:Please,enter the integer value!\n");
        return TYPE_ERROR;
    }
    char *str1 = NULL;
    res = decimal_to_other(&str1,num,degree);
    if(res == EXC){
        printf("Your result is %d",0);
    }
    else if(res == SUCCESS){
        printf("Your result is %s",str1);
        free(str1);
    }
    else{
        printf("Run out of memory!\n");
        return MEMORY_ERROR;
    }
    return SUCCESS;
}

