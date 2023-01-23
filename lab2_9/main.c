#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

enum errors{
    MEMORY_ERROR = -1,
    SUCCESS = -2,
    WRONG_NUMBER = -3,
};

int count_len(char *str) {
    int len=0;
    while(*str) {
        str++;
        len++;
    }
    return len;
}

int toNum(char ch) {
    int res = isdigit(ch) ? ch -'0' : toupper(ch) - 'A' + 10;
    return res;
}

char toChar(int num) {
    char res = num < 10 ? num + '0' : num - 10 + 'A';
    return res;
}

void add_zero(char *str) {
    char tmp1= str[0];
    char tmp2= str[1];
    for(int i = 1; str[i-1] != '\0'; i++) {
        str[i] = tmp1;
        tmp1 = tmp2;
        tmp2 = str[i+1];
    }
    str[0] = '0';
}

char *delete_start_zero(char *num) {
    if (num[0] != '0') {
        return num;
    }
    int counter = 0;
    int u = count_len(num);
    for (int x = 0; x < u; x++) {
        if (num[x] == '0') {
            counter++;
        } else {
            break;
        }
    }
    int numSize = u - counter;
    char *clear_number = (char *) malloc(sizeof(char) * (numSize + 1));
    if(!clear_number) {
        return MEMORY_ERROR;
    }
    strcpy(clear_number, num + counter);
    return clear_number;
}

int add_number_to_result(char *result, int base, char *num) {
    char *clear_number = delete_start_zero(num);
    if(clear_number == NULL) {
        return MEMORY_ERROR;
    }
    int number_index = count_len(clear_number)-1;
    int result_index = count_len(result)-1;
    int remember = 0;
    char addNum;
    while(result_index > 0 || number_index>= 0) {
        if(number_index < 0) {
            addNum = '0';
        } else {
            addNum = clear_number[number_index];
        }
        int sum = toNum(addNum) + toNum(result[result_index]) + remember;
        result[result_index] = toChar(sum % base);
        remember = sum / base;
        result_index--;
        if(result_index < 0) {
            add_zero(result);
            result_index++;
        }
        number_index--;
    }
    if(remember) {
        result[result_index] = toChar(remember);
    }
    if(num != clear_number) {
        free(clear_number);
    }
    return SUCCESS;
}

int realloc_res(char* number, int* size) {
    *size *= 2;
    char* newRes = (char*)realloc(number, sizeof(char) * *size);
    if(newRes != NULL) {
        number = newRes;
    } else {
        free(number);
        free(newRes);
        return MEMORY_ERROR;
    }
    return SUCCESS;
}

int check_number(int base, char* num) {
    for(int i=0; num[i] != '\0'; i++) {
        if(!(isdigit(num[i]) || ('A' <= num[i] && num[i] <= 'Z'))) {
            return WRONG_NUMBER;
        }
        if(base <= 10) {
            if(!('0' <= num[i] && num[i] <= toChar(base - 1))) {
                return WRONG_NUMBER;
            }
        } else if(!(isdigit(num[i])||('A' <= num[i] && num[i] <= toChar(base - 1)))) {
            return WRONG_NUMBER;
        }
    }
    return SUCCESS;
}

int is_number_with_zero(char* str) {
    for (int i = 0; str[i]; ++i)
        if (str[i] != '0')
            return 1;
    return 0;
}

char* sum(int *err, int base, int numbers, ...) {
    va_list args;
    va_start(args, numbers);
    int size = 2;
    char* res = (char*)malloc(size * sizeof(char));
    if(!res){
        return MEMORY_ERROR;
    }
    res[0]='0';
    res[1]= '\0';
    for(int i = 0; i < numbers; i++) {
        char *number = va_arg(args, char*);
        if(!is_number_with_zero(number)) {
            continue;
        }
        if(check_number(base, number) != SUCCESS) {
            *err = WRONG_NUMBER;
            free(res);
            return NULL;
        }
        if(count_len(number) > size) {
            size = count_len(number);
            if(realloc_res(res, &size) == MEMORY_ERROR) {
                *err = MEMORY_ERROR;
                free(res);
                return NULL;
            };
        }
        if(add_number_to_result(res,base,number) == MEMORY_ERROR) {
            *err = MEMORY_ERROR;
            free(res);
            return NULL;
        }
    }
    va_end(args);
    if(!is_number_with_zero(res)) {
        return res;
    } else {
        char* newRes = delete_start_zero(res);
        return newRes;
    }
}

int main(int argc, char * argv[]) {
    int err=0, base = 16, amount = 2;
    char* result = sum(&err, base, amount, "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", "1");
    if(err == MEMORY_ERROR ){
        printf("Memory error:Try again!\n");
        free(result);
        return MEMORY_ERROR;
    }
    else if(err == WRONG_NUMBER) {
        printf("Wrong number:Try again!\n");
        free(result);
        return WRONG_NUMBER;
    } else {
        printf("Your result is : %s\n", result);
        free(result);
    }
    return 0;
}