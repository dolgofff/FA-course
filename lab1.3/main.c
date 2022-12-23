#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
enum messages{
    SUCCESS=-1,
    INPUT_ERROR=-2,
    FILE_ERROR=-3,
    MEMORY_ERROR=-4,
};
int func_d(FILE *f1,FILE *f2){
    int c;
    while ((c = fgetc(f1)) != EOF){
        if (!isdigit(c)){
            fputc(c, f2);
        }
    }
    return SUCCESS;
}
int func_i(FILE *f1,FILE *f2){
    int c, count =0;
    while((c = fgetc(f1))!=EOF){
        if(c!='\n' && isalpha(c))
            count++;
        else if(c == '\n'){
            fprintf(f2,"The amount is: %d",count);
            count = 0;
        }
    }
    return SUCCESS;
}
int func_s(FILE *f1,FILE *f2){
int c,count = 0;
while((c = fgetc(f1))!=EOF){
    if( (c!='\n') && (!isalpha(c)) && (!isdigit(c)) && (c!=' ')){
        fprintf(f2,"The amount is: %d",count);
    }
}
}
int func_a(FILE *f1,FILE *f2){
int c;
while((c = fgetc(f1))!=EOF){
    if(!isdigit(c)){
        fprintf(f2,"%d",(int)c);
    }
    else
        fputc(c,f2);
}
return SUCCESS;
}
int func_f(FILE *f1,FILE *f2){
int c,pc,pos=0;
while((c = fgetc(f1))!=EOF){
    if(isalnum(c) && !isalnum(pc))
        pos++;
    if(isalnum(c)){
        if(!(pos % 10)){
            isalpha(c) ? fprintf(f2,"%d",tolower(c)) : fprintf(f2,"%d",c);
        }
        else if(!(pos & 1)){
            isalpha(c) ? fputc(tolower(c),f2) : fputc(c,f2);
        }
        else if(!(pos % 5)){
            fprintf(f2,"%d",c);
        }
        else
            fputc(c,f2);
    }
    else
        fputc(c,f2);
    pc=c;
}
return SUCCESS;
}
int main(int argc,char* argv[]){
    FILE *f1=NULL,*f2=NULL;
    if(argc < 3 || argc > 4){
        printf("Input error: Incorrect amount of arguments\n");
        return INPUT_ERROR;
    }

    if((argv[1][0] == '/' || argv[1][0] == '-') && argv[1][1] == 'n'){
        if(argc != 4){
            printf("Input error: Incorrect amount of arguments!\n");
            return INPUT_ERROR;
        }
        f1 = fopen(argv[2],"r");
        if(f1 == NULL){
            printf("File error: Try with another one!\n");
            return FILE_ERROR;
        }
        f2 = fopen(argv[3],"w");
        if(f2 == NULL){
            printf("File error: Try with another one!\n");
            return FILE_ERROR;
        }
    }
    else if((argv[1][0] == '/' || argv[1][0] == '-') && strlen(argv[1]) == 2){
        if(argc != 3){
            printf("Input error: Incorrect amount of arguments!\n");
            return INPUT_ERROR;
        }
        f1= fopen(argv[2],"r");
        if(f1 == NULL){
            printf("File error: Try with another file!\n");
            return FILE_ERROR;
        }
        char *out = "out_";
        char *st = calloc(strlen(argv[2]) + 5, 1);
        if(!st){
            printf("Memory error!\n");
            return MEMORY_ERROR;
        }
        strcat(st, out);
        strcat(st, argv[2]);
        f2= fopen(argv[2],"w");
        if(f2 == NULL){
            printf("File error: Try with another file!\n");
            return FILE_ERROR;
        }

    }
    else{
        printf("Input error:Try with correct flag\n");
        return INPUT_ERROR;
    }
    if(strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "/d") == 0 || strcmp(argv[1], "/nd") == 0 || strcmp(argv[1], "-nd") == 0) {
        func_d(f1,f2);
    }
    else if(strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "/i") == 0 || strcmp(argv[1], "/ni") == 0 || strcmp(argv[1], "-ni") == 0) {
        func_i(f1,f2);
    }
    else if(strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "/s") == 0 || strcmp(argv[1], "/ns") == 0 || strcmp(argv[1], "-ns") == 0) {
        func_s(f1,f2);
    }
    else if(strcmp(argv[1], "-a") == 0 || strcmp(argv[1], "/a") == 0 || strcmp(argv[1], "/na") == 0 || strcmp(argv[1], "-na") == 0) {
        func_a(f1,f2);
    }
    else if(strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "/f") == 0 || strcmp(argv[1], "/nf") == 0 || strcmp(argv[1], "-nf") == 0) {
        func_f(f1,f2);
    }
    else{
        printf("Input error: Try with the correct arguments\n");
        return INPUT_ERROR;
    }
    fclose(f1);
    fclose(f2);
    return 0;
}