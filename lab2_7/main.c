#include <stdio.h>
#include <math.h>
#include <stdarg.h>
typedef struct aorta{
    int x;
    int y;
}aorta;
int mn_v(int vertex,...){
    int x1,y1,x2,y2,product,temp_sign,temp;
    //x2 less arguments than in input
    int j=vertex/2;
    aorta frame[j];
    if (vertex%2==0 && vertex > 5){
        va_list l;
        va_start(l,vertex);
        for (int i=0;i<j;i++){
            frame[i].x = va_arg(l,int);
            frame[i].y = va_arg(l,int);
        }
        va_end(l);
        for (int i=0;i<j;i++){
            //absciss
            x1=frame[(i+1)%j].x-frame[i%j].x;
            x2 = frame[(i+2)%j].x-frame[i%j].x;
            //ordinate
            y1=frame[(i+1)%j].y-frame[i%j].y;
            y2=frame[(i+2)%j].y-frame[i%j].y;

            product=(x1*y2)-(x2*y1);
            if(product>0)
                temp=1;
            else temp=0;

            if (i==0)
                temp_sign = temp;
            else if (temp_sign!=temp)
                return 0;
        }
        return 1;
    }
    return -1;
}
double f_p(double x,int n,...){
    double pol=0;
    va_list pt;
    va_start(pt,n);
    for(int i=0;i<=n;i++){
        pol=x*pol+ va_arg(pt,double);
    }
    va_end(pt);
    return pol;
}
int main() {
    int zn;
    zn=mn_v(5,2,1,3,4,5);
    if(zn==1)
      printf("Your polygon is convex\n");
    else if(zn==0)
        printf("Your polygon is not convex\n");
    else if(zn==-1)
        printf("Please,enter the correct convex\n");
    printf("The result is %lf: \n",f_p(3.,4,1.,2.,3.,4.));
    return 0;
}
