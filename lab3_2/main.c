#include <stdio.h>
#include <stdlib.h>
enum errors{
    MEMORY_ERROR=-1,
    INPUT_ERROR=-2,
    SUCCESS=-3,
    NOT_FOUND=-4
};
void printR(int *mass,int len){
    for(int i = 0;i < len;i++)
        printf("%d ", mass[i]);
    printf("\n");
}
long long fact(int n){
    if (n > 22)
        return INPUT_ERROR;
    else if (n == 0)
        return 1;
    else
        return (long long) n * fact(n - 1);
}

int mem_func1(int l, int k){
    long long a = fact(k), b = fact(l), c = fact(k - l);
    return (int) (a / (b*c));
}
int lower_bits(int kb){
    return (1<<(kb));
}
int upper_bits(int kb){
    return(1<<kb);
}

int searching(int l,int n,int mode){
    int amount = 0, result;
    //task 1
    if(!mode){
        while (n != 0) {
            amount += n&1;
            n >>= 1;
        }
    }
    //task 2
    else{
        while(n != 0){
            if(!(n&1)) {
                if (amount == l)
                    break;
                amount = 0;
            }
            else
                amount++;
            n >>= 1;
        }
    }
    result = (amount == l) ? 1 : 0;
    return result;
}
void f1(int l,int k,int **storage,int *size,int *status){
int i = lower_bits(l)-1, m = upper_bits(k),q = 0,temp;
int ms = mem_func1(l,k);
*storage=(int*)calloc(ms,sizeof(int));
if(!*storage)
    *status=MEMORY_ERROR;
for(;i < m;i++){
    temp = searching(l,i,0);
    if(temp){
        *(*storage+q) = i;
        q++;
    }
}
    *size=q;
    if(*size)
        *status=SUCCESS;
    else
        *status= NOT_FOUND;
}
void f2(int l,int k,int **storage,int *size,int *status){
    int i = lower_bits(l)-1, m = upper_bits(k),q = 0,temp;
    int ms=m-i;
    *storage=(int*)malloc(ms*sizeof(int));
    if(!*storage)
        *status=MEMORY_ERROR;
    for(;i<m;i++){
        temp=searching(l,i,1);
        if(temp){
            *(*storage+q)=i;
            q++;
        }
    }
    *size=q;
    if(*size)
        *status=SUCCESS;
    else
        *status=NOT_FOUND;
}
int main() {
    int *res1=NULL,*res2=NULL,size1=0,size2=0,l,k,stts1=0,stts2=0;
    printf("Welcome!\n");
    printf("Please,enter the amount of units\n");
    if(!scanf("%d",&l)){
        printf("Input error:Enter correct amount\n");
        return INPUT_ERROR;
    }
    printf("Please,enter the amount of bits\n");
    if(!scanf("%d",&k)){
        printf("Input error:Enter correct amount of bits\n");
        return INPUT_ERROR;
    }
    if(l>k){
        printf("Input error:Inappropriate input\n");
        return INPUT_ERROR;
    }
    if(l<0 || k<0){
        printf("Input error:Negative numbers\n");
        return INPUT_ERROR;
    }
    if(k>31){
        printf("Input error:Out of range\n");
        return INPUT_ERROR;
    }

    f1(l,k,&res1,&size1,&stts1);;
    if(stts1==SUCCESS){
        printf("Your first result:\n");
        printR(res1,size1);
        free(res1);
    }
    else if(stts1==MEMORY_ERROR){
        printf("Program error:Not enough memory\n");
        return MEMORY_ERROR;
    }
    else if(stts1==NOT_FOUND)
        printf("Nothing was found\n");

    f2(l,k,&res2,&size2,&stts2);
    if(stts2==SUCCESS){
        printf("Your second result:\n");
        printR(res2,size2);
        free(res2);
    }
    else if(stts2==MEMORY_ERROR){
        printf("Program error:Not enough memory\n");
        return MEMORY_ERROR;
    }
    else if(stts2==NOT_FOUND)
        printf("Nothing was found\n");
}
