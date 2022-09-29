#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int kolhoz_atoi(char* s_input){
    int c_output = 0,znak=1,sm=0;
    if(s_input[0]=='-'){
        znak=-1;
        sm++;
    }
    for(int i=sm;s_input[i]!='\0';i++){
        c_output=(c_output * 10) + (s_input[i] - '0');
    }
    return c_output*znak;
}
double kolhoz_atof(char* s_inputD){
    int znak=1,sm=0,point_pos=0;
    double backp=0,free=1;
    if(s_inputD[0]=='-'){
        sm++;
        znak=-1;
    }
    for(int i=sm;s_inputD[i]!='\0';i++){
        if(point_pos){
            free=free/10;
            backp=backp+free*(s_inputD[i]-'0');
        }
        else{
            if(s_inputD[i]=='.'){
                point_pos=1;
            }
            else{
                backp=backp*10+(s_inputD[i]-'0');
            }
        }
    }
    return znak*backp;
}
void func_q(double a,double b,double c){
    double x1,x2,resh;
if(a==0){
    /*if(b==0 && c==0){
        printf("The solution of this equation are all numbers\n");}
    if(b!=0 && c!=0){
        double temp;
        temp=-c/b;
        printf("The solution of this equation is x=%f\n",temp);}
    if(b==0 && c!=0){
        printf("The are no solutions of this equation\n");}
    if(b!=0 && c==0){
        printf("The solution of this equation is x=0\n");}
*/
    printf("This equation is not square\n");
}
else{
   /* if(c==0 && b!=0){
        printf("The solutions of this equation are x=0 and x=%f\n",-b/a);}
    else if(b==0 && c!=0){
        if(c<0){
            double t=sqrt(-c/a);
            printf("The solutions of this equation are x=%f and x=+%f\n",t,-t);
        }
        else if(c>0){
            printf("There are no solutions of this equation\n");}
    }
    else if(b==0 && c==0){printf("The solution of this equation is x=0\n");}
    else if(b!=0 && c!=0){
        double discr=b*b-4*a*c;
        if(discr<0){
            printf("There are no solutions of this equation\n");
        }
        else if(discr==0){
            double resh= (-b)/(2*a);
            printf("The solution of this equation is x=%f\n",resh);
        }
        else if(discr>0){
            double resh1=(-b+sqrt(discr))/(2*a);
            double resh2=(-b-sqrt(discr))/(2*a);
            printf("The solutions of this equation are x=%f and x=%f\n",resh1,resh2);
        }
    }
    */
   double d=b*b-4*a*c;
   if(d<0){
       printf("There are no solutions of this equation\n");
   }
   if(d==0){
       resh=(-b)/(2*a);
       printf("The solution of this equation is x=%f\n",resh);
   }
   if(d>0){
       x1=(-b+sqrt(d))/(2*a);
       x2=(-b+sqrt(d))/(2*a);
       if(x1==x2){
           printf("The solution of this equation is x=%f\n",x2);
       }
       else {
           printf("The solutions of this equations are x1=%f x2=%f\n", x1,x2);
       }
   }
}

}
int func_m(int a,int b){
    if(a*b!=0){
        if(a % b==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 2;
    }
}
double func_t(double a,double b,double c){
    double temp;
if(a*b*c>0){
    if(a<b){temp=a;a=b;b=temp;}
    if(a<c){temp=a;a=c;c=temp;}
    if(b<c){temp=b;b=c;c=temp;}
    if(a*a==b*b+c*c){
        return 1;
    }
    else{
        return 0;
    }
}
}
int main(int argc,char* argv[]) {
    double ch1,ch2,ch3;
    int n1,n2;
    if(argv[1][1]=='t' || argv[1][1]=='q'){ /*Квадратное уравнение и стороны треугольника*/
        if((argv[1][0]=='/') || (argv[1][0]=='-')) {
            if (argc == 5) {
             ch1 = kolhoz_atof(argv[2]);
             ch2 = kolhoz_atof(argv[3]);
             ch3 = kolhoz_atof(argv[4]);
            if (argv[1][1] == 't') {
                if (func_t(ch1, ch2, ch3) == 1) {
                    printf("Your numbers can be sides of a right-angled triangle\n");
                } else if (func_t(ch1, ch2, ch3) == 0) {
                    printf("Your numbers can't be sides of a right-angled triangle\n");
                }
            } else if (argv[1][1] == 'q') {
                printf("First variation (a=%f,b=%f,c=%f)\n",ch1,ch2,ch3);
                func_q(ch1, ch2, ch3);
                printf("\n");

                printf("Second variation (a=%f,b=%f,c=%f)\n",ch1,ch2,ch3);
                func_q(ch1, ch3, ch2);
                printf("\n");

                printf("Third variation (a=%f,b=%f,c=%f)\n",ch1,ch2,ch3);
                func_q(ch2, ch1, ch3);
                printf("\n");

                printf("Fourth variation (a=%f,b=%f,c=%f)\n",ch1,ch2,ch3);
                func_q(ch2, ch3, ch1);
                printf("\n");

                printf("Fifth variation (a=%f,b=%f,c=%f)\n",ch1,ch2,ch3);
                func_q(ch3, ch2, ch1);
                printf("\n");

                printf("Sixth variation (a=%f,b=%f,c=%f)\n",ch1,ch2,ch3);
                func_q(ch3, ch1, ch2);
                printf("\n");

            }
        }
            else{
                printf("Input Error:Use the correct amount of arguments(3 numbers)\n");
                return 0;
            }
        }
        else{
            printf("Input error:Use the correct first symbol ('/' or '-')\n");
            return 0;
        }
    }
    else if(argv[1][1]=='m'){ /* Делимость */
        if ((argv[1][0] == '/') || (argv[1][0] == '-')) {
            if (argc==4) {
                n1= kolhoz_atoi(argv[2]);
                n2= kolhoz_atoi(argv[3]);
                if(func_m(n1,n2)==2){
                    printf("Input error:Your numbers should be positive or negative.\n");
                    return 0;
                }
                else if(func_m(n1,n2)==1){
                    printf("Number %d is a multiple of number %d\n",n1,n2);
                }
                else if(func_m(n1,n2)==0){
                    printf("Number %d is not a multiple of number %d\n",n1,n2);
                }
            }
            else{
                printf("Input error:Use the correct amount of arguments(two numbers)\n");
                return 0;
            }
            }
        else{
            printf("Input error:Use the correct first symbol ('/' or '-')\n");
            return 0;
        }
    }
    else{
        printf("Input error:Use the correct argument ('m','q','t')\n");
        return 0;
    }
    return 0;
}
