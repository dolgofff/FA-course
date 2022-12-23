#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 16
enum errors{
    FILE_ERROR=-1,
    MEMORY_ERROR=0,
    SUCCESS=1,
};
char* start_size(int size){
    char *buf = (char*)malloc(sizeof(char)*size);
    memset(buf,0,size);
    return buf;
}
char* str_realloc(char* from, int curr_size){
    char* res = start_size(curr_size);
    strcpy(res, from);
    free(from);
    return res;
}
int mem_errors(char* buf){
    if(!buf)
        return MEMORY_ERROR;
    return SUCCESS;
}

int main(int argc,char* argv[]){
    int cur_size = SIZE,num=0,sizes=0;
    char c,pr_c=0;

    FILE *f1 = fopen(argv[1],"r");
    if(f1 == NULL){
        printf("File error:Try with another first!\n");
        return FILE_ERROR;
    }
    FILE *f2 = fopen("should_rename.txt","w");
    if(f2 == NULL){
        printf("File error:Try with another second!\n");
        free(f1);
        return FILE_ERROR;
    }

    char* buf1 = start_size(cur_size);
    char* buf2 = start_size(cur_size);
    char* buf3 = start_size(cur_size);
    char* temp1 = NULL;
    if(!mem_errors(buf1) && !mem_errors(buf2) && !mem_errors(buf3)){
        printf("Memory error:Try again!\n");
        return MEMORY_ERROR;
    }

    while(!feof(f1)){
        c=fgetc(f1);
        if(isalnum(c) && !isalnum(pr_c)){
            num++;
            sizes=0;
            cur_size = SIZE;
        }
        if(isalnum(c)){
            if(num == 1){
                if(sizes == cur_size - 2){
                    buf1[sizes] = '\0';
                    temp1=str_realloc(buf1,cur_size*=2);
                if(!temp1){
                    free(buf1);
                    return MEMORY_ERROR;
                }
                else{
                *buf1 = temp1;   
                }
                }
                buf1[sizes++] = c;
            }
            if(num == 2){
                if(sizes == cur_size - 2){
                    buf2[sizes] = '\0';
                    temp1=str_realloc(buf2,cur_size *=2);
                if(!temp1){
                    free(buf2);
                    return MEMORY_ERROR;
                }
                else{
                *buf2 = temp1;
                }
                }
                buf2[sizes++] = c;
            }
            if(num == 3){
                if(sizes == cur_size - 2) {
                    buf3[sizes] = '\0';
                    temp1 = str_realloc(buf3, cur_size *= 2);
                if(!temp1){
                    free(buf3);
                    return MEMORY_ERROR;
                }
                else{
                *buf3=temp1;
                }
                }
                buf3[sizes++] = c;
            }
        }
        else if(!isalnum(c) && isalnum(pr_c) && c != '\n' && c!=EOF){
            if(num == 1){
                if(sizes == cur_size - 2){
                    buf1[sizes] = '\0';
                    temp1=str_realloc(buf1,cur_size + 1);
                if(!temp1){
                    free(buf1);
                    return MEMORY_ERROR;
                }
                else{
                *buf1=temp1;
                }
                }
                buf1[sizes] = '\0';
            }
            if(num == 2){
                if(sizes == cur_size - 2){
                    buf2[sizes] = '\0';
                    temp1=str_realloc(buf2,cur_size + 1);
                if(!temp1){
                    free(buf2);
                    return MEMORY_ERROR;
                }
                else{
                *buf2=temp1;
                }
                }
                buf2[sizes] = '\0';
            }
            if(num == 3){
                if(sizes == cur_size - 2){
                    buf3[sizes] = '\0';
                    temp1=str_realloc(buf3,cur_size + 1);
                if(!temp1){
                    free(buf3);
                    return MEMORY_ERROR;
                }
                else{
                *buf3=temp1;
                }
                }
                buf3[sizes] = '\0';
        }
        }
        else if(c == '\n' || c == EOF){
            fprintf(f2,"%s %s %s",buf3,buf1,buf2);
            c != EOF ? fputc('\n',f2) : fputc(' ',f2);
            free(buf1);
            free(buf2);
            free(buf3);
            free(temp1);
            if(c != EOF){
                buf1 = start_size(cur_size);
                buf2 = start_size(cur_size);
                buf3 = start_size(cur_size);
            }
            num = 0;
        }
        pr_c = c;
    
    }
    fclose(f1);
    fclose(f2);
    remove(argv[1]);
    rename("should_rename.txt", argv[1]);
    return 0;
}
