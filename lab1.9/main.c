#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define SIZE 50

enum error{
    INPUT_ERROR=-1,
};

int main() {
char num[SIZE],maxS[SIZE];
int sys,res = 0,max = INT_MIN,sign = 1,temp = 0;
printf("Please,enter the scale of notation(between 2 and 36)\n");
scanf("%d",&sys);
if(sys < 2 || sys > 36){
    printf("Input error:Please,enter the number which is between 2 and 36\n");
    return INPUT_ERROR;
}

printf("Please,enter your numbers.To interrupt the process enter 'Stop'\n");
while(strcmp(num,"Stop")){
    scanf("%s",num);
    temp++;
    if(!strcmp(num,"Stop") && temp == 1){
        printf("Where are numbers??\n");
        return INPUT_ERROR;
    }
    if(num[0] == '-')
        sign--;
    char *pb = num-sign;
    while(*++pb){
        if(((isdigit(*pb) && *pb - '0' >=sys) || (isalpha(*pb) && (*pb - 'A' + 10 >=sys))) && strcmp(num,"Stop")){
            printf("Incorrect input,try again!\n");
            return INPUT_ERROR;
        }
        res = res*sys + (isdigit(*pb) ? *pb - '0' : *pb - 'A' + 10);
        }
        if((res > max) && strcmp(num,"Stop")){
            max=res;
            strcpy(maxS,num);
    }
    res = 0;
}

printf("Maximal(module) number is %s\n",maxS);
char fin[SIZE];
for(int i = 9;i <= 36;i+=9){
int r,base = i,temp = max,j = 0;
while(temp){
    r = temp % base;
    fin[j] = (r > 9) ? (r - 10 + 'A') : (r + '0');
    temp /= base;
    j++;
}
    printf("scale of notation: %d", base);
    printf(" number: ");
    for (int n = j - 1; n >= 0; n--){
        printf("%c", fin[n]);
    }
    printf("\n");
}

    return 0;
}
