#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int poww(double arg,double deg){
    if(deg==1){
        return arg;
    }
    return arg*poww(arg,deg-1);
}

int kolhoz_atoi(char* s_input){
    int c_output = 0;
    while(*s_input){
        if(!isdigit(*s_input)){
            printf("Input error:Please,enter the integer value\n");
            return 0;
        }
        c_output=(c_output * 10) + (*s_input - '0');
        if(c_output>INT_MAX/10){
            printf("Input error:Please,enter the smaller number\n");
            return 0;
        }
            *s_input++;
    }
    return c_output;
}

void func_h(int inp){
    int i=1;
    if(abs(inp)>100){
        printf("There are no numbers up to 100 multiples of the input\n");
        return;
    }
    while(i*inp<=100){
        printf("%d\n",i*inp);
        i++;
    }
}

void func_p(int inp){
    int count=2;
    if(inp==1){
        printf("Your number is not a prime or a composite.\n");
        return;
    }
    for(int i=2;i<=sqrt(inp);i++){
        if(inp % i ==0){
            count=count+2;
        }
        if(i%(inp/i)==0){
            count--;
        }
    }
    if(count>2){
        printf("Your number is composite\n");
    }
    else{
        printf("Your number is prime\n");
    }
}

void func_s(int inp){
    int length=0;
    int temp=inp;
    while(temp!=0){
        temp=temp/10;
        length++;
    }
    int divs=poww(10,length);
    while(inp>0){
        inp=inp%divs;
        divs=divs/10;
        printf("%d ",inp/divs);
    }

}

void func_e(int inp){
    long long res=1;
    if(inp>10){
        printf("Please,enter the number less than 10\n");
        return;
    }
    for(int i=1;i<=10;i++){
        for(int j=1;j<=inp;j++){
            res*=i;
            printf("%Id ",res);
        }
        res=1;
        printf("\n");
    }
}

void func_a(int inp){
    int sum=0;
    if(inp>65535){
        printf("Input error:Please,enter the number less than 65535\n");
    }
    else {
        if (inp % 2 == 0) {
            sum = ((1 + inp) / 2) * inp + inp * 0.5;
        } else {
            sum = ((1 + inp) / 2) * inp;
        }
        printf("%d\n", sum);
    }
}

void func_f(int inp){
    unsigned long fact=1;
    if(inp>20){
        printf("Input Error:Please,enter the number less than 21\n");
        return;
    }
    for(int i=1;i<=inp;i++){
        if(fact) {
            fact = fact * i;
        }
    }
    printf("%Id\n",fact);

}
int main(int argc,char* argv[]){
    if(argc!=3){
        printf("Input Error:Correct format is 'number -(key)'\n");
        return 0;
    }

    int num=0;
    num= kolhoz_atoi(argv[1]);
         if(num!=0) {
             if ((argv[2][0] == '/') || (argv[2][0] == '-')) {
                 if (argv[2][1] == 'h') {
                     func_h(num);
                 } else if (argv[2][1] == 'p') {
                     func_p(num);
                 } else if (argv[2][1] == 's') {
                     func_s(num);
                 } else if (argv[2][1] == 'e') {
                     func_e(num);
                 } else if (argv[2][1] == 'a') {
                     func_a(num);
                 } else if (argv[2][1] == 'f') {
                     func_f(num);
                 } else {
                     printf("Input error:Use the correct argument('h','p','s','e','a','f')\n");
                     return 0;
                 }
             } else {
                 printf("Input error:Use the correct first symbol('/' or '-')\n");
                 return 0;
             }
         }
         else{
             return 0;
         }
    return 0;
}
