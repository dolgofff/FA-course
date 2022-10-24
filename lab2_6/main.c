#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
enum error {
    SUBSTRING_IS_EMPTY=-2,
    ILLOGICAL_INPUT=-3,
    SUCCESS=1,
    FAILURE=-1,
    CANNOT_OPEN_THIS_FILE=-4,
    FAILURE_AMOUNT=-5
};
int KMP(char *str,char *substr){
    int i,j,n,m;
    n = strlen(str);
    m = strlen(substr);
    if(m == 0 || *substr == '\0')
        return SUBSTRING_IS_EMPTY;
    if(n < m || n == 0)
        return ILLOGICAL_INPUT;
    int *proc = (int*)malloc(m*sizeof(int));
    //Prefix-function evaluation
    *(proc) = 0;
    for( i = 1,j = 0;i < m;i++){
        while(j > 0 && *(substr + j) != *(substr + i))
            j = *(proc + j - 1);
        if(*(substr + j) == *(substr + i))
            j++;
        *(proc + i) = j;
    }
    //Searching for substr in str
    for(i = 0,j = 0;i < n;i++){
        while(j > 0 && *(substr + j) != *(str + i))
            j=*(proc + j - 1);
        if(*(substr + j)==*(str + i))
            j++;
        if(j == m){
            free(proc);
            return SUCCESS;
            //position is i-j+1
        }
    }
    free(proc);
    return FAILURE;
}
int acceptor(char *substr,int count,...) {
    if(count<=0)
        return FAILURE_AMOUNT;
    FILE *fw;
    int a;
    char str[BUFSIZ];
    char *fw_name;
    va_list curr;
    va_start(curr, count);
    for (int i = 0; i < count; i++) {
        fw_name = va_arg(curr, char*);
        if ((fw = fopen(fw_name, "r")) != NULL) {
        while (fgets(str, sizeof(str), fw) != NULL) {
            a = KMP(str,substr);
            if(a == FAILURE)
                continue;
            else if(a == SUCCESS)
                return KMP(str, substr);

            else
                return FAILURE;
    }
}
        else
            return CANNOT_OPEN_THIS_FILE;
        fclose(fw);
    }
    va_end(curr);
    return 0;
}
int main() {
    int t=acceptor("1 2  3   ",2,"f1.txt","f2.txt");

    if(t == FAILURE_AMOUNT) {
        printf("Not enough arguments\n");
        return 0;
    }
    else if(t == CANNOT_OPEN_THIS_FILE ){
        printf("File error");
        return 0;
    }
    if(t == SUCCESS)
        printf("Substring was found\n");
    else
        printf("Substring was not found\n");
    return 0;

}
