# include<stdio.h>
# include<stdlib.h>
# include "math.h"
# define TYPE double

// 未释放的指针数量
static int noFreePointCount = 0;

// coords  二维坐标
typedef 
struct coords{
    int x;
    int y;
}
Coords;


// 三角矩阵
typedef
struct Matrix_tri{
    int m;
    int n;
    TYPE* matrix;
} Matrix_tri;

// 创建三角矩阵
Matrix_tri* c_tri_m(int m,int n){
    TYPE* res = (TYPE*)malloc(sizeof(double)*(m+1)*n);
    noFreePointCount++;
    Matrix_tri* x = (Matrix_tri*)malloc(sizeof(Matrix_tri));
    x->m = m;
    x->n = n;
    x->matrix = res;
    return x;
}

// 索引转换为三角矩阵
int sub2ind_tri(int m,int x,int y){
    int len = m;
    return (len+(len-x+1))*x/2+y-x;
}
// 获取矩阵值
TYPE get_tri_m(Matrix_tri* m,int x,int y){
    int len = m->m;
    int ind = sub2ind_tri(len,x,y);
    return m->matrix[ind];
}

// 写入矩阵值
void set_tri_m(Matrix_tri* m,TYPE value,int x,int y){
    int ind = sub2ind_tri(m->m,x,y);
    m->matrix[ind] = value;
}
// 销毁矩阵
void d_tri_m(Matrix_tri* x){
    free(x->matrix);
    free(x);
    noFreePointCount--;
}

// m*n的矩阵,矩阵索引从0开始,按列存储
typedef struct matrix{
    // 行数
    int m;
    // 列数
    int n;
    // 值
    TYPE* matrix;
} Matrix;

// 创建m * n的矩阵,按列存储
Matrix* c_m(int m,int n){
    noFreePointCount++;
    TYPE* matrix = (TYPE*)malloc(m*n*sizeof(TYPE));
    Matrix* res = (Matrix*)malloc(sizeof(Matrix));
    res->m = m;
    res->n = n;
    res->matrix = matrix;
    return res;
}
int m_check(Matrix* a,Matrix* b);
void set_m(Matrix* matrix,Coords c,TYPE value);

// 利用一维数组创建矩阵
Matrix* c_m_array(TYPE* array,int m){
    Matrix* res = c_m(m,1);
    for(int i = 0;i < m;i++){
        Coords coord = {0,i};
        set_m(res,coord,*(array+i));
    }
    return res;
}

// 下标转换,标准矩阵
int sub2ind_m(Matrix* m,Coords coords){
    int y = coords.y;
    int x = coords.x;
    return x*(m->m)+y;
}

// 下标转换,标准矩阵
Coords ind2sub_m(Matrix* matrix,int ind){
    int y = ind % matrix->n;
    int x = ind / matrix->n;
    Coords c;
    c.x = x;
    c.y = y;
    return c;
}
// 获取矩阵中的元素,标准矩阵
TYPE get_m(Matrix* matrix,Coords c){
    int ind = sub2ind_m(matrix,c);
    int m = matrix->m;
    int n = matrix->n;
    return *((matrix->matrix)+ind);
}

// 设置矩阵中的元素,标准矩阵
void set_m(Matrix* matrix,Coords c,TYPE value){
    int ind = sub2ind_m(matrix,c);
    matrix->matrix[ind] = value;
}

//对一列求和,如果range.y = -1计算整行
TYPE sum_i(Matrix* matrix,int i,Coords range){
    TYPE res =0;
    if (range.y == -1){
        range.y = matrix->m;
    }
    if (range.x - range.y == 0){
        return matrix->m >matrix->n?matrix->m:matrix->n;
    }
    for(int j = range.x;j < range.y;j++){
        Coords c = {i,j};
        res += get_m(matrix,c);
    }
    return res;
}

// 对一行求和,如果range.x = -1 计算整列
TYPE sum_j(Matrix* matrix,int j,Coords range){
    TYPE res = 0;
    if (range.y == -1){
        range.y = matrix->n;
    }
    if (range.x - range.y == 0){
        return matrix->m >matrix->n?matrix->m:matrix->n;
    }
    for(int i = range.x;i < range.y;i++){
        Coords c = {i,j};
        res += get_m(matrix,c);
    }
    return res;
}

// 销毁矩阵
void d_m(Matrix* m){
    free(m->matrix);
    free(m);
    noFreePointCount--;
}

// 转置矩阵
Matrix* t_m(Matrix* matrix){
    Matrix* res = c_m(matrix->n,matrix->m);
    for(int i = 0;i < matrix->n;i++){
        for(int j = 0;j< matrix->m;j++){
            Coords c = {i,j};
            Coords tc = {j,i};
            set_m(res,tc,get_m(matrix,c));
        }
    }
    d_m(matrix);
    return res;
}

// 矩阵相加
Matrix* add_m(Matrix* a,Matrix* b){
    if(m_check(a,b)){
        int m = a->m;
        int n = a->n;
        Matrix* res = c_m(m,n);
        for(int i = 0;i < n;i++){
            for (int j =0;j < m;j++){
                Coords coord = {i,j};
                set_m(res,coord,get_m(a,coord)+get_m(b,coord));
            }         
        }
        return res;
    }
    return NULL;
}

// 矩阵维度测试
int m_check(Matrix* a,Matrix* b){
    if (a->m ==b->m && a->n==b->n){
        return 1;
    }else
    {
        return 0;
    }
    
}

// 打印输出
void disp_m(Matrix* matrix){
    for(int j = 0;j<matrix->m;j++){
        for(int i = 0;i < matrix->n;i++){
            Coords c = {i,j};
            printf("%6.3lf\t",get_m(matrix,c));
        }
        printf("\n");
    }
}


Matrix* matrix_pow(Matrix* matrix,int p){
    Matrix* res = c_m(matrix->m,matrix->n);
    for(int i =0;i < (matrix->m)*(matrix->n);i++){
        Coords c = {0,i};
        set_m(res,c,pow(get_m(matrix,c),p));
    }
    return res;
}

// 水平扩充矩阵
Matrix* horicat (Matrix* a,Matrix* b){
    if(a->m == b->m){
        int m = a->m;
        int n = a->n+b->n;
        Matrix* res = c_m(m,n);
        for(int j = 0;j < m;j++){
            for (int i = 0;i < n;i++){
                if(i < a->n){
                    Coords c = {i,j};
                    set_m(res,c,get_m(a,c));
                }else{
                    Coords c = {i,j};
                    Coords bc = {i-a->n,j};
                    set_m(res,c,get_m(b,bc));
                }
            }
        }
        return res;
    }else{
        return NULL;
    }
}

// 矩阵点乘
Matrix* dot_times_m(Matrix* a,Matrix* b){
    if(m_check(a,b)){
        Matrix* res = c_m(a->m,a->n);
        for(int i =0;i < a->m*a->n;i++){
            Coords c = {0,i};
            set_m(res,c,get_m(a,c)*get_m(b,c));
        }
        return res;
    }else{
        return NULL;
    }
}

Matrix* times_m(Matrix* a,Matrix* b){
    if (a->m == b->n){
        Matrix* res = c_m(a->n,b->m);
        for(int i=0;i < b->m;i++){
            for(int j=0;j < a->n;j++){
                TYPE sum = 0;
                for(int k=0;k < a->m;k++){
                    Coords ac = {i,k};
                    Coords bc = {k,j};
                    sum += get_m(a,ac)*get_m(b,bc);
                }
                Coords c = {i,j};
                set_m(res,c,sum);
            }
        }
    }else{
        reutrn NULL;
    }
}

// 获取某一列
Matrix* sub_i(Matrix* mat,int j){
    Matrix* res = c_m(mat->m,1);
    for(int i=0;i < mat->m;i++){
        Coords ij = {i,j};
        Coords res_c = {0,j};
        set_m(res,res_c,get_m(mat,ij));
    }
    return res;
}


// 获取某一行
Matrix* sub_j(Matrix* mat,int i){
    Matrix* res = c_m(1,mat->n);
    for(int j = 0;j < mat->n;j++){
        Coords ij = {i,j};
        Coords res_c = {i,0};
        set_m(res,res_c,get_m(mat,ij));
    }
    return res;
}


// 生成1矩阵
Matrix* ones(int m,int n){
    Matrix* res = c_m(m,n);
    memset(res->matrix,1,m*n);
    return res;
}