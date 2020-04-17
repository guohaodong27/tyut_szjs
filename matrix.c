#define TYPE double

static int noFreePointCount =0;

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

