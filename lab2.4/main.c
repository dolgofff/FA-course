#include <stdio.h>
#include <math.h>
#include <stdarg.h>
void menu(){
    printf("Menu\n");
    printf("Please,chose the action which you prefer to do\n");
    printf("a)Calculate the geometric mean of the entered numbers\n");
    printf("b)Raise a number to a power\n");
}
double avg_geom(int count,...){
    double res=1.0;
    va_list l;
    va_start(l,count);
    for(int i=0;i<count;i++){
        res*=va_arg(l,double);
    }
    va_end(l);
    return pow(res,1./count);
}
double poww(double a,int n){
    if(n==0) return 1;
    else if(n<0){
        return 1.0/poww(a,-n);
    }
    else {
        if (n % 2 == 1)
            return a * poww(a, n - 1);
        else
            return pow(a * a, n / 2);
    }
}

int main() {
    char arg;
    double a;
    int n;
    menu();
    scanf("%s",&arg);
    if(arg=='a'){
        avg_geom(5,1,2,3,4,5);
    }
    else if(arg=='b'){
        printf("Please,enter the base\n");
        scanf("%lf",&a);
        printf("Please,enter the power\n");
        scanf("%d",&n);
        printf("The result is: %lf\n",poww(a,n));
    }
    else{
        printf("Please,enter the correct argument\n");
        return 0;
    }
    return 0;
}
