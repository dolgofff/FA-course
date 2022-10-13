#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n,m,far=INT_MAX,temp,add;

    printf("Please,enter the size of Array A: ");
    scanf("%d",&n);
    printf("\n");
    printf("Please,enter the size of Array B: ");
    scanf("%d",&m);
    printf("\n");
    int A[n],B[m],C[n];

    printf("Array A: ");
    for(int i=0;i<n;i++){
        A[i]=rand();
        printf("%d ",A[i]);
    }
    printf("\n");
    printf("Array B: ");
    for(int j=0;j<m;j++){
        B[j]=rand();
        printf("%d ",B[j]);
    }
    printf("\n");

    for(int l=0;l<n;l++){
        for(int p=0;p<m;p++){
            temp=abs(A[l]-B[p]);
            if(temp<far){
                far=temp;
                add=B[p];
            }
        }
        C[l]=A[l]+add;
        far=INT_MAX;
    }

    printf("Array C: ");
    for(int f=0;f<n;f++){
        printf("%d ",C[f]);
    }
    return 0;
}
