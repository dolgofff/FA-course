#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum error{
    RUN_OUT_OF_ATTEMPTS=-1,
    MEMORY_ERROR=-2,
    NORMAL_EXIT=-3,
    SUCCESS=-4,
};

typedef struct{
    unsigned int id;
    char *text;
    unsigned int byte_size;
} message;

int filename_gen(char **name,int size){
    int cur=0;
    *name = (char*)calloc(size,sizeof(char));
    if(!*name)
        return MEMORY_ERROR;
    int real_size=size-1;
    for(int i=0;i<real_size;i++){
        cur= rand() & 1;
        switch(cur){
            case 0:
                (*name)[i] = rand() % 26 + 97;
                break;
            case 1:
                (*name)[i] = rand() % 10 + 48;
        }
    }
    (*name)[real_size] = '\0';
    return SUCCESS;
}

int current_message(message **mess){
    *mess=(message*)malloc(sizeof(message));
    if(!*mess)
        return MEMORY_ERROR;
    (*mess)->id=1;
    (*mess)->byte_size=2;
    (*mess)->text=(char*)malloc((*mess)->byte_size*sizeof(char));
    if(!(*mess)->text)
        return MEMORY_ERROR;
    return SUCCESS;
}

int message_flow(message **mess){
    free((*mess)->text);
    (*mess)->id++;
    (*mess)->byte_size=2;
    (*mess)->text=(char*)malloc((*mess)->byte_size*sizeof(char));
    if(!*mess)
        return MEMORY_ERROR;
    return SUCCESS;
}

int main(int argc,char *argv[]) {
 srand(time(NULL));
    return 0;
}





/*char choice;
int attempts=0,cur=0;
srand(time(NULL));

printf("You're welcome!\n");
printf("Would you like to enter your message?\n@Y\n@N\n");
scanf("%c",&choice);
while((choice != "Y" && choice != "N") && (attempts < 3)){
    attempts++;
    printf("Please,follow the given instruction:Your have %d attempt(s) left",3-attempts);
    scanf("%c",&choice);
}
if(attempts == 3){
    printf("Your attempts are left!\n");
    return RUN_OUT_OF_ATTEMPTS;
}
*/