#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 50
enum errors{
    FILE_ERROR=-1,
    WRONG_BASE=-2
};
int find_the_smallest_number_system(char *str) {
    char *str_ptr;
    int smallest_system = 0;
    if(*str == '-') {
        str_ptr = str;
    } else {
        str_ptr = str-1;
    }
    while(*++str_ptr) {
        if(isdigit(*str_ptr) && (*str_ptr - '0' > smallest_system)) {
            smallest_system = *str_ptr - '0';
        }
        else if (isalpha(*str_ptr) && (toupper(*str_ptr) - 'A' + 10 > smallest_system)) {
            smallest_system = toupper(*str_ptr) - 'A' + 10;
        }
    }
    if(smallest_system == 0) {
        return 2;
    }
    return smallest_system+1;
}

int convert_to_10_system(char *str, int base) {
    if(base <= 1) {
        return WRONG_BASE;
    }
    if(strcmp(str, "0") == 0) {
        return 0;
    }
    int flag = 1, res=0;
    char *p_str;
    if (*str == '-') {
        flag = -1;
        p_str = str;
     } else {
        p_str = str-1;
    }
    while (*++p_str) {
        res = res * base + (isdigit(*p_str) ? (*p_str - '0') : (toupper(*p_str) - 'A' + 10));
    }
    return flag * res;
}
int main() {
    int decimal,scale;
    char buf[SIZE];
    FILE *fin, *fout;
    fin = fopen("in.txt", "r");
    if(fin == NULL){
        printf("File 1 error:Try again!\n");
        return FILE_ERROR;
    }
    fout = fopen("out.txt", "w");
    if(fout == NULL){
        printf("File 2 error:Try again!\n");
        free(fin);
        return FILE_ERROR;
    }
    while(!feof(fin)){
            fscanf(fin,"%s",buf);
            scale = find_the_smallest_number_system(buf);
            decimal = convert_to_10_system(buf,scale);
            fprintf(fout,"Number: %s, Minimal Scale: %d, In decimal: %d\n",buf,scale,decimal);
    }
    fclose(fin);
    fclose(fout);
}
