#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
int main() {
    int n=0;
    srand(time(NULL));
    int max=INT_MIN;
    int min= INT_MAX;
    int pos_min,pos_max,cup;
    printf("Please,enter the size of your array\n");
    scanf("%d",&n);
    int mass[n];
    for(int i=0;i<n;i++){
        mass[i]=rand();
        if(mass[i]>max){
            max=mass[i];
            pos_max=i;
        }
        if(mass[i]<min){
            min=mass[i];
            pos_min=i;
        }
    }
    for(int j=0;j<n;j++){
        printf("%d ",mass[j]);
    }
    printf("\n");

    printf("Maximum element:%d Position:%d\n",max,pos_max);
    printf("Minimum element:%d Position:%d\n",min,pos_min);

    cup=mass[pos_min];
    mass[pos_min]=mass[pos_max];
    mass[pos_max]=cup;

    for(int k=0;k<n;k++){
        printf("%d ",mass[k]);
    }
    printf("\n");
    return 0;
}
