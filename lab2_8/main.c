#include <stdio.h>
#include <math.h>
double f(double x){
    return log(x)-6*x+16;
}
double dih(double l,double r,double zoom){
    double c;
    while(fabs(r-l)>zoom){
        c=(l+r)/2.0;
        if(f(l)*f(c)<0)
            r=c;
        else if(f(r)*f(c)<0)
            l=c;
        else{
            printf("The root of your function cannot be found.Try again.\n");
            printf("Attention:This method can't be used with functions like x^2.Reason:f(l)*f(c)>0,f(c)*f(r)>0\n");
            return 0;
        }
    }
    return c;
}
int main() {
    double a,b,eps;
    printf("Please,enter the left bound\n");
    scanf("%lf",&a);
    printf("Please,enter the right bound\n");
    scanf("%lf",&b);
    if (a > b) {
        // lower bytes
        *(int*)&a ^= *(int*)&b;
        *(int*)&b ^= *(int*)&a;
        *(int*)&a ^= *(int*)&b;

        // upper bytes
        *((int*)&a + 1) ^= *((int*)&b + 1);
        *((int*)&b + 1) ^= *((int*)&a + 1);
        *((int*)&a + 1) ^= *((int*)&b + 1);
    }
    printf("Please,enter the epsilon.\n");
    scanf("%lf",&eps);
    printf("%lf",dih(a,b,eps));

    return 0;
}
