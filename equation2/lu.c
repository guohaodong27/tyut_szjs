#include "../matrix.h"

/** LU分解 doolittle
 * @param mat 增广矩阵
 */
void lu(Matrix* mat){
    // 根据对角线循环
    for(int d = 0; d < mat->m;d++){
        if(d == 0){
            // U[0][0] = mat[0][0] 不设置
            for(int k = 1;k < mat->m;k++){
                m_set(mat,k,0,m_get(mat,k,0) / m_get(mat,0,0));
            }
            continue;
        }
        // u
        for(int j = d;j < mat->m;j++){
            // <d,j>
            double sum =0;
            for(int i = 0;i < d;i++){
                sum += m_get(mat,i,j) * m_get(mat,d,i);
            }
            double val = (m_get(mat,d,j)-sum);
            m_set(mat,d,j,val);
        }
        // l
        for(int i = d+1;i < mat->m;i++){
            // <i,d>
            double sum  = 0;
            // ind表示的是累加的j值
            for(int j = 0;j < d;j++){
                sum += m_get(mat,i,j) * m_get(mat,j,d);
            }
            double val = (m_get(mat,i,d) - sum) / m_get(mat,d,d);
            m_set(mat,i,d,val);
        }
    }
}

Matrix* lu_res(Matrix* mat,int* swap){
    // 获取U矩阵
    Matrix* U = m_create(mat->m,mat->n);
    for (int i = 0; i < mat->m; i++) {
        for (int j = 0; j < mat->n - 1; j++) {
            if (i <= j) {
                m_set(U,i,j,m_get(mat,i,j));
            }
        }
    }
    // 计算y并放入U中,组成增广矩阵
    for(int i = 0;i < mat->m;i++){
        double sum = 0;
        for(int k = 0 ;k < i;k++){
            sum += m_get(U,k,mat->n-1) * m_get(mat,i,k);
        }
        double val = m_get(mat,i,mat->n-1) - sum;
        m_set(U,i,U->n-1,val);
    }

    Matrix* res = get_result(U,swap);
    m_distory(U);
    return res;
}
int main(){
    double a[][4] = {{2,8,2,14},{1,6,-1,13},{2,-1,2,5}};
    Matrix* mat = array2mat((double*)a,3,4);
    lu(mat);
    disp_m(mat);
    // 解的顺序
    int swap[] = {0,1,2,3};
    Matrix* x = lu_res(mat,swap);
    disp_m(x);
}