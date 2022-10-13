#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu(){
    printf("Menu\n");
    printf("a)Change positions of maximum and minimum elements\n");
    printf("b)Create a new array which continues the unique elements from current Array\n");
}
int chg(int *i1,int *i2){
    int temp;
    temp=*i2;
    *i2=*i1;
    *i1=temp;
}
int main() {
    srand(time(NULL));
    char s;int max=0,min=0,r1,r2,n,counter=0,p=0;

    printf("Please,enter the size of your Array\n");
    scanf("%d",&n);
    printf("Please,enter the bounds for random\n");
    scanf("%d %d",&r1,&r2);
    int mass[n];
    printf("Current Array: ");
    for(int i=0;i<n;i++){
        mass[i]=rand() %(r2-r1 +1)+r1;
        printf("%d ",mass[i]);
    }
    printf("\n");
    menu();
    scanf("%s",&s);
    if(s=='a'){
        for(int j=0;j<n;j++){
            if(mass[j]>mass[max]){
                max=j;
            }
            if(mass[j]<mass[min]){
                min=j;
            }
        }
        chg(&mass[max],&mass[min]);
        printf("New Array: ");
        for(int k=0;k<n;k++){
            printf("%d ",mass[k]);
        }
    }
    else if(s=='b'){
        int massN[n];
        printf("New Array: ");
        for(int k=0;k<n;k++){
            counter=0;
            for(int u=0;u<n;u++){
                if(mass[k]==mass[u]){
                    counter++;
                }
            }
            if(counter==1){
                massN[p]=mass[k];
                printf("%d ",massN[p]);
                p++;
            }
        }
        if(p==0){
            printf("There are no unique elements");
        }
    }
    else{
        printf("Input error:Please,enter the correct argument('a'/'b')\n");
        return 0;
    }
    return 0;
}
