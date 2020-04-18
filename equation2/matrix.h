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
    if(mat->val != NULL){
        free(mat->val);
        if(NULL != mat){
            free(mat);
        }
    }
    noFreePointCount--;
}

// 批量销毁矩阵
void distory(Matrix** mats,int len){
    for(int i =0;i < len;i++){
        m_distory(*(mats+i));
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

// 矩阵乘法
Matrix* times(Matrix* a,Matrix* b){
    Matrix* res = m_create(a->m,b->n);
    
    for(int i =0;i < a->m;i++){
        for(int j = 0;j < b->n;j++){
            double val = 0;
            for(int k = 0;k < a->n;k++){
                val += m_get(a,i,k) * m_get(b,k,j);
            }
            m_set(res,i,j,val);
        }
    }
    return res;
}

// 矩阵加法
Matrix* add(Matrix* a,Matrix* b){
    Matrix* res = m_create(a->m,a->n);
    for(int i=0;i < res->m;i++){
        for(int j=0;j < res->n;j++){
            m_set(res,i,j,m_get(a,i,j)+m_get(b,i,j));
        }
    }
    return res;
}

// 切比雪夫范数
double norm(Matrix* mat){
    double max = 0;
    for(int j = 0;j < mat-> n;j++){
        double sum = 0;
        for(int i =0;i < mat-> m ;i++){
            sum += m_get(mat,i,j);
        }
        if(max < sum){
            max = sum;
        }
    }
}

// 逆矩阵(目前只能对下三角阵使用)
Matrix* inv(Matrix* mat){
    Matrix* res = m_create(mat->m,mat->n);

    memset(res->val,0,sizeof(double)*mat->m*mat->n);
    for(int d = 0;d < mat->m;d++){
        m_set(res,d,d,1);
    }

    double r;
    for (int j = 0;j < mat->m;j++){
        // 对角线化为1,k:对角元素值
        r = m_get(mat,j,j);
        for(int k =0;k < mat->n;k++){
            m_set(res,j,k,m_get(res,j,k) / r);
            m_set(mat,j,k,m_get(mat,j,k) / r);
        }
        // 同一列化为0
        for(int i =j+1;i < mat->n;i++){
            // r: 待消0元素值
            r = m_get(mat,i,j);
            for(int k =0;k < mat->n;k++){
                m_set(mat,i,k,m_get(mat,i,k) - m_get(mat,j,k)*r);
                m_set(res,i,k,m_get(res,i,k) - m_get(res,j,k)*r);
            }
        }
    }
    return res;
}

// 矩阵数乘
Matrix* scalar_times(Matrix* a,double lambda){
    Matrix* res = m_create(a->m,a->n);
    for(int i = 0;i < a->m*a->n;i++){
        m_set(res,0,i,m_get(a,0,i) * lambda);
    }
    return res;
}