#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EPS 1e-9
enum errors{
MEMORY_ERROR=-1,
CANNOT_CALCULATE=-2,
};
float **matrix_gen(int *n,int *m){
    *n=rand()%10 + 1;
    *m=rand()%10 + 1;
    float **matrix = (float**)malloc(sizeof(float*) * *n);
    if(!matrix){
        return NULL;
    }
    for(int i = 0;i < *n;i++){
        matrix[i]=(float*)malloc(sizeof(float) * *m);
        if(!matrix[i]){
            return NULL;
        }
        for(int j = 0;j < *m;j++){
            matrix[i][j]=rand()%201 - 100;
        }
    }
    return matrix;
}

float **matrix_compose(float **matrix1,float **matrix2,int n1,int n2,int m1,int m2){
    float **matrix_res = NULL;
if(n1 == m2){
    matrix_res=(float**)malloc(sizeof(float*) * n1);
    if(!matrix_res){
        return NULL;
    }
    for(int i = 0; i < n1;i++){
        matrix_res[i]= (float*)malloc(sizeof(float) * m2);
        if(!matrix_res[i]){
            return NULL;
        }
    }
    for(int i = 0;i < n1;i++){
        for(int j = 0;j < m2;j++){
            for(int k =0;k<m1;k++){
                matrix_res[i][j] =matrix1[i][k]*matrix2[k][j];
            }
        }
    }
}
return matrix_res;
}

int determinant(float **matrix,int n,int m){
    if(n!=m){
        return CANNOT_CALCULATE;
    }
     else {
        int det = 1;
        float *tmp;
        for (int i = 0; i < n; i++) {
            int k = i;
            for (int j = i + 1; j < n; j++)
                if (fabs(matrix[j][i]) > fabs(matrix[k][i]))
                    k = j;
            if (fabs(matrix[k][i]) < EPS) {
                det = 0;
                break;
            }
            tmp = matrix[i];
            matrix[i] = matrix[k];
            matrix[k] = tmp;
            if (i != k)
                det = -det;
            det *= matrix[i][i];
            for (int j = i + 1; j < n; j++)
                matrix[i][j] /= matrix[i][i];
            for (int j = 0; j < n; ++j)
                if (j != i && fabs(matrix[j][i]) > EPS)
                    for (int k = i + 1; k < n; k++)
                        matrix[j][k] -= matrix[i][k] * matrix[j][i];
        }
        return det;
    }
}

void matrix_print(float **matrix,int n,int m){
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%9.1f",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrix_clear(float ***matrix,int n){
for(int i = 0;i<n;i++){
    free((*matrix)[i]);
}
free(*matrix);
*matrix = NULL;
}

int main() {
srand(time(NULL));
int nm1=0,mm1=0,nm2=0,mm2=0,det1,det2;

float **matrix1=matrix_gen(&nm1,&mm1);
if(matrix1 != NULL){
    printf("First matrix:\n");
    matrix_print(matrix1,nm1,mm1);
}
else{
    printf("Creation error:Failed to create 1st matrix\n");
}

float **matrix2=matrix_gen(&nm2,&mm2);
if(matrix2 != NULL){
    printf("Second matrix:\n");
    matrix_print(matrix2,nm2,mm2);
}
else{
    printf("Creation error:Failed to create 2st matrix\n");
}

float **matrixr =matrix_compose(matrix1,matrix2,nm1,mm1,nm2,mm2);
if(matrixr != NULL){
    printf("The result of multiplying your matrixs is:\n");
    matrix_print(matrixr,nm1,mm2);
    matrix_clear(matrixr,nm1);
}
else{
    printf("Multiplication error:Failed to multiply your matrixs\n");
}
det1=determinant(matrix1,nm1,mm1);
det2=determinant(matrix2,nm2,mm2);
if(det1 != CANNOT_CALCULATE){
    printf("Determinant of 1st matrix is: %d",det1);
}
else{
    printf("Determinant error:Cannot calculate current determinant\n");
}
if(det2 != CANNOT_CALCULATE){
    printf("Determinant of 2st matrix is: %d",det2);
}
else{
    printf("Determinant error:Cannot calculate current determinant\n");
}
matrix_clear(&matrix1,nm1);
matrix_clear(&matrix2,nm2);
}

