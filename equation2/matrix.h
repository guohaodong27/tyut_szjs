#include <stdio.h>
#include <stdlib.h>
#define TYPE double


// 定义矩阵(mxn矩阵)
typedef struct matrix
{
    int m;
    int n;
    TYPE* val;
} Matrix;
static int noFreePointCount = 0;

// 创建矩阵
Matrix* m_create(int m,int n){
    noFreePointCount++;
    TYPE* matrix = (TYPE*)malloc(m*n*sizeof(TYPE));
    Matrix* res = (Matrix*)malloc(sizeof(Matrix));
    res->m = m;
    res->n = n;
    res->val = matrix;
    return res;
}
// 线性偏移量获取
int offset_ind(Matrix* mat,int i,int j){
    return (i*mat->n)+j;
}
// 获取元素值
double m_get(Matrix* mat,int i,int j){
    int offset = offset_ind(mat,i,j);
    return *((mat->val)+offset);
}
// 设置元素值
void m_set(Matrix* mat,int i,int j,double val){
    int offset = offset_ind(mat,i,j);
    *((mat->val)+offset) = val;
}


// 通过mxn的数组创建矩阵
Matrix* array2mat(TYPE* array,int m,int n){
    Matrix* res = m_create(m,n);
    for (int i = 0;i < m*n;i++){
        *((res->val)+i) = *(array+i);
    }
    return res;
}

// 打印输出
void disp_m(Matrix* matrix){
    for(int i = 0;i<matrix->m;i++){
        for(int j = 0;j < matrix->n;j++){
            printf("%6.3lf\t",m_get(matrix,i,j));
        }
        printf("\n");
    }
}

// 销毁矩阵
void m_distory(Matrix* mat){
    if(mat != NULL){
        free(mat);
        if(mat->val != NULL){
            free(mat->val);
        }
    }
    
}

// 交换行
void change_i(Matrix* mat,int a,int b){
    for(int j = 0;j < mat->n;j++){
        double aj = m_get(mat,a,j);
        double bj = m_get(mat,b,j);
        m_set(mat,b,j,aj);
        m_set(mat,a,j,bj);
    }
}

// 交换列
void change_j(Matrix* mat,int a,int b){
    for(int i = 0;i < mat->m;i++){
        double ia = m_get(mat,i,a);
        double ib = m_get(mat,i,b);
        m_set(mat,i,a,ib);
        m_set(mat,i,b,ia);
    }
}