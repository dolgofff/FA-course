#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menu(){
    printf("Please,choose the option(write a/b/c/d/e)\n");
    printf("a) Rewrite numbers in odd positions\n");
    printf("b) Rewrite only EVEN numbers\n");
    printf("c) Find the furthest array value from the selected(choose the number)\n");
    printf("d) Add together the elements preceding the selected\n");
    printf("e) Add together the elements which are smaller than selected\n");
}
int cut_size(int a) {
    int size;
    if (a % 2 == 0) {
        size = a / 2;
    } else {
        size = (a - 1) / 2;
    }
    return size;
}
int main() {
int mass_inp[128];
int n=0,j=0,chet_col=0,l=0,index,sum=0,far=-1,fin;
char param;
FILE *fw= fopen("file8.txt","r");
if(!fw){
    printf("File error:Cannot open this file");
    return 0;
}
while(fscanf(fw,"%d",mass_inp + n)!=EOF){
    if(mass_inp[n]%2==0){
        chet_col++;
    }
    n++;
    if(n>128){
        printf("Input error:Enter the amount of elements less than 129");
        return 0;
    }
}
menu();
scanf("%s",&param);
    printf("Current Array: ");
    for(int z=0;z<n;z++){
        printf("%d ",mass_inp[z]);
    }
    printf("\n");

if(param=='a') {
    int size1 = cut_size(n);
    int mass_out1[size1];
    printf("New Array: ");
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            mass_out1[j] = mass_inp[i];
            printf("%d ", mass_out1[j]);
            j++;
        }
    }
}
else if(param=='b'){
int mass_out2[chet_col];
printf("New Array: ");
for(int k=0;k<n;k++){
    if(mass_inp[k]%2==0){
        mass_out2[l]=mass_inp[k];
        printf("%d ",mass_out2[l]);
        l++;
    }
}
}
else if(param=='c'){
int mass_out3[1];
printf("Please,enter the index of array element\n");
scanf("%d",&index);
int perm=mass_inp[index];
printf("New Array: ");
for(int r=0;r<n;r++){
    if(abs(mass_inp[r]-perm)>far){
        far=abs(mass_inp[r]-perm);
        fin=mass_inp[r];
    }
}
mass_out3[0]=fin;
printf("%d",mass_out3[0]);
}
else if(param=='d'){
    int mass_out4[1];
    printf("Please,enter the index of array element\n");
    scanf("%d",&index);
    printf("New Array: ");
    for(int m=0;m<index;m++){
        sum+=mass_inp[m];
    }
    mass_out4[0]=sum;
    printf("%d",mass_out4[0]);
}
else if(param=='e'){
    int mass_out5[1];
    printf("Please,enter the index of array element\n");
    scanf("%d",&index);
    int max=mass_inp[index];
    printf("New Array: ");
    for(int p=0;p<index;p++){
        if(mass_inp[p]<max){
            sum+=mass_inp[p];
        }
    }
    mass_out5[0]=sum;
    printf("%d",mass_out5[0]);
}
else{
    printf("Input error:Please,enter the correct parameter\n");
    return 0;
}
fclose(fw);
return 0;
}
