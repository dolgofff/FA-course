#include <stdio.h>
#include <stdlib.h>
enum errors{
    FILE_ERROR=-1,
    ARGUMENT_ERROR=-2,
    SUCCESS= 1,
    INPUT_ERROR=-3
};
int mode_fi(char *files){
    FILE *source,*element,*out;
    char filename[200],c;
    int flag = 1;
    source = fopen(files,"r");
    if(!source){
        printf("File error:Try with another.\n");
        return FILE_ERROR;
    }
    out = fopen("out.txt","w");
    if(!out){
        printf("File error:Try with another.\n");
        free(source);
        return FILE_ERROR;
    }
    while(!feof(source)){
        fscanf(source,"%s",filename);
        element = fopen(filename,"r");
        if(!element){
        printf("File error:Try with another.\n");
        free(source);
        free(out);
        return FILE_ERROR;
        }
        if(!flag) {
            fputc('\n', out);
        } else {
            flag = 0;
        }
        while(c=fgetc(element) != EOF){
            fputc(c,out);
        }
        fclose(element);
    }
    fclose(source);
    fclose(out);
    return SUCCESS;
}
int mode_cin(){
    FILE *element,*out;
    char filename[200],c;
    int flag = 1;
    out=fopen("out.txt","w");
    if(!out){
        printf("File error:Try again.\n");
        return FILE_ERROR;
    }
    printf("Please,enter your file names\n");
    scanf("%s",filename);
    while(!feof(stdin)){
        element = fopen(filename,"r");
        if(!element){
        printf("File error:Try again.\n");
        free(out);
        return FILE_ERROR;
        }
        if(!flag) {
            fputc('\n', out);
        } else {
            flag = 0;
        }
        while(c=fgetc(element) != EOF){
            fputc(c,out);
        }
        fclose(element);
        scanf("%s",element);
    }
    fclose(out);
    return SUCCESS;
}
int mode_arg(int argc,char* argv[]){
FILE *element,*out;
char c;
out = fopen("out.txt","w");
if(!out){
    printf("File error:Try again.\n");
    return FILE_ERROR;
}
for(int i = 0;i < argc;i++){
    element = fopen(argv[i],"w");
    if(!element){
        printf("File error:Try again.\n");
        free(out);
        return FILE_ERROR;
    }
    while(c = fgetc(element) != EOF){
        fputc(c,out);
        }
    fclose(element);
        if(i != argc-1){
            fputc("\n",out);
        }
}
fclose(out);
return SUCCESS;
}

int main(int argc,char* argv[]){
    if(argc == 1) {
        return ARGUMENT_ERROR;
    }
    if(strcmp(argv[1], "-fi") == 0) {
        if (argc != 3){
            return INPUT_ERROR;
        }
        mode_fi(argv[2]);
    }
    else if(strcmp(argv[1], "-cin") == 0) {
        mode_cin();
    }
    else if(strcmp(argv[1], "-arg") == 0) {
        if (argc < 3) {
            return  INPUT_ERROR;
        }
        mode_arg(argv, argc);
    }
    else {
        return ARGUMENT_ERROR;
    }
}
